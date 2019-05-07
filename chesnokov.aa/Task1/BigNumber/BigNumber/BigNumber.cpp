#include "BigNumber.h"
#include <limits>
#include "math.h"

// isklyuchaushee ili
bool XOR(bool a, bool b)
{
	return (a || b) && (!(a && b));
}

bool BigNumber::GetBit(int position) const
{
	if (position <= 31)  // esli prinadlejit mladshei chasti 
	{
		// pobitovo sdvinyt` na position pozicii vpravo
		// pobitovoe I polychennogo chisla s maskoi vida 0000...001
		// dast znachenie ykazanogo bita
		return (m_lower_part >> position) & 1;
	}
	else if (position <= 63)  // esli prinadlejit starshey chasti
	{
		return (m_upper_part >> (position - 32)) & 1;
	}
	// luboi bit vne chisla nylevoi
	return false;
}

// pri vihode za granici, chislo ne izmenitsya
void BigNumber::SetBit(int position, bool b)
{
	if (position <= 31)
	{
		if (b)  // esli nyzhno ystanovit` 1
		{
			// pobitovoe ILI s msakoi tipa 000..00100..0,
			// gde 1 zanimaet poziciu position, ystanovit 1 v nyzhnoe mesto
			m_lower_part = m_lower_part | (int) pow(2, position);
		}
		else // esli nyzhno ystanovit` 0
		{
			// pobitovoe I s maskoi tipa 111..11011..111,
			// gde 0 stoit v pozicii position, ystanovit 0 v neznoe mesto
			m_lower_part = m_lower_part & ( std::numeric_limits<int>::max() - (int) pow(2,position));
		}
	}
	else if (position <= 63)  
	{
		if (b)  
		{
			m_upper_part = m_upper_part | (int)pow(2, position - 32);
		}
		else 
		{
			m_upper_part = m_upper_part & (std::numeric_limits<int>::max() - (int)pow(2, position - 32));
		}
	}
}

void BigNumber::HalfAdder(bool inA, bool inB, bool & outSum, bool & outC)
{
	outSum = XOR(inA, inB);
	outC = inA && inB;
}

void BigNumber::Adder(bool inC, bool inA, bool inB, bool & outSum, bool & outC)
{
	bool _outSum, _outC1, _outC2;
	HalfAdder(inA, inB, _outSum, _outC1);
	HalfAdder(inC, _outSum, outSum, _outC2);
	outC = _outC1 || _outC2;
}

BigNumber BigNumber::Invert() const
{
	BigNumber res;
	for (int i = 0; i < 64; i++)
	{
		// invertiryem vse biti
		res.SetBit(i, !(this->GetBit(i)));
	}
	res = res + BigNumber("1");  // yvelichim na 1
	return res;
}

BigNumber BigNumber::operator+(const BigNumber & num)
{
	BigNumber res;
	bool carry = false;   // perenos razryada
	bool sum = false;     // znachenie dlya tekyshego bita
	for (int i = 0; i < 64; i++)
	{
		Adder(carry, this->GetBit(i), num.GetBit(i), sum, carry);
		res.SetBit(i, sum);
	}
	return res;
}

BigNumber BigNumber::operator-(const BigNumber & num)
{
	BigNumber res;
	res = *this + num.Invert();
	return res;
}

bool BigNumber::operator<(const BigNumber num)
{
	for (int i = 63; i >= 0; i--)
	{
		if (this->GetBit(i) < num.GetBit(i)) return true;
		else if (this->GetBit(i) > num.GetBit(i)) return false;
	}
	return false;
}

bool BigNumber::operator>(const BigNumber num)
{

	for (int i = 63; i >= 0; i--)
	{
		if (this->GetBit(i) > num.GetBit(i)) return true;
		else if (this->GetBit(i) < num.GetBit(i)) return false;
	}
	return false;
}

BigNumber BigNumber::operator*(const BigNumber & num)
{
	// ymnozhenie na 0
	if (((*this) == BigNumber("0")) || (num == BigNumber("0"))) return BigNumber("0");
	BigNumber i("1"), res("0");
	res = *this;
	for (; i < num; i = i + BigNumber("1"))
	{
		res = res + (*this);
	}
	return res;
}

BigNumber BigNumber::operator/(const BigNumber & num)
{
	if (num == BigNumber("0")) throw "Dividing by zero exception";
	BigNumber res("0");   // schetchik
	BigNumber tmp;
	tmp = *this;
	while (tmp >= num)
	{
		tmp = tmp - num;
		res = res + BigNumber("1");
	}
	return res;
}

BigNumber & BigNumber::operator=(const BigNumber & num)
{
	// prosto kopirovanie bitov
	for (int i = 0; i < 64; i++)
	{
		SetBit(i, num.GetBit(i));
	}
	return *this;
}

BigNumber::BigNumber()
{
	m_lower_part = 0;
	m_upper_part = 0;
	pt = Hex;
}

BigNumber::BigNumber(std::string HexNum)
{
	int symb; // tekyshii simvol desyatichim chislom
	// obnylit` vse biti
	m_lower_part = m_upper_part = 0;
	pt = Hex;
	int len = HexNum.length();
	for (int i = len - 1; i >= 0; i--) 
		// prohodim po vsem simvolam v obratnom poryadke
	{
		//nahodim chislo (perevodim v desyatichnoe)
		if (HexNum[i] <= '9' && HexNum[i] >= '0') symb = HexNum[i] - '0';
		else if (HexNum[i] <= 'F' && HexNum[i] >= 'A') symb = HexNum[i] - 'A' + 10;
		else symb = 0;  // ne yavlyaetsy 16-im simvolom
		// perevodim v 2-yu sistemy
		int j = 0;
		while (symb > 0)
		{
			SetBit((len - i - 1) * 4 + j, symb % 2);
			j++;
			symb /= 2;
		} 
	}
}

BigNumber::~BigNumber()
{
	m_lower_part = m_upper_part = 0;
}

std::ostream& operator<< (std::ostream& out, const BigNumber& num)
{
	if (num.m_lower_part == 0 && num.m_upper_part == 0)
	{
		out << 0;
		return out;
	}
	int i = 63;
	switch (num.pt)
	{
	case (Binar):
		// propyskaem neznachashie biti
		
		while (!num.GetBit(i)) i--;
		// pervii probel ne stavitsya
		out << num.GetBit(i);
		i--;
		for (; i >= 0; i--)
		{
			if (i % 4 == 3)
			{
				out << " " << num.GetBit(i);
			}
			else
			{
				out << num.GetBit(i);
			}
		}
		break;
	case (Hex):
		// perevod v Hex pytem perevoda otdel`nih tetrad (polybaitov)
		// propysk neznachyashih tetrad [0000]

		
		int tet,     //schetchik tetrad
			offset,  // otstyp ot nachala tetradi
			sum;     // symma tekyshei tetradi
		char ch;     // hex cifra tekyshei tetradi
		for (tet = 16; tet >= 1; tet--)
		{
			sum = 0;
			for (offset = 0; offset <= 3; offset++)
			{
				sum += (int) num.GetBit(tet * 4 - offset - 1);
			}
			if (sum) break;  // esli ocherednaya tetrada ne nylevaya perestayom propyskat`
		}
		// vivod ostavshihsya tetrad
		for (; tet >= 1; tet--)
		{
			sum = 0;
			//vichislenie 10-ogo znachenia tetradi
			for (offset = 0; offset <= 3; offset++)
			{
				if (num.GetBit(tet * 4 - offset - 1)) // esli ocherednoi bit ne pystoi
				{
					sum +=(int) pow(2, 3 - offset);
				}	
			}
			// nahodim sootvetstvyushii simvol
			if (sum >= 0 && sum <= 9)
			{
				ch = '0' + sum;
			}
			else
			{
				sum -= 10;
				ch = 'A' + sum;
			}
			out << ch;
		}
		break;
		default:
			break;
	}
	return out;
}

bool operator==(const BigNumber numL, const BigNumber numR)
{
	for (int i = 0; i < 64; i++)
	{
		if (numL.GetBit(i) != numR.GetBit(i))
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const BigNumber numL, const BigNumber numR)
{
	return !(numL == numR);
}
