#include "BigNumber.h"
#include <limits>
#include "math.h"

// исключающее или
bool XOR(bool a, bool b)
{
	return (a || b) && (!(a && b));
}

bool BigNumber::GetBit(int position) const
{
	if (position <= 31)  // если принадлежит младшей части 
	{
		// побитово сдвинуть на position позиций вправо
		// побитовое И полученного числа с маской вида 0000...001
		// вернет значение указанного бита
		return (m_lower_part >> position) & 1;
	}
	else if (position <= 63)  // если принадлежит старшей части 
	{
		// аналогично со старшей частью
		return (m_upper_part >> (position - 32)) & 1;
	}
	// любой бит вне числа нулевой
	return false;
}

// при выходе за границы числа, оно не изменяется
void BigNumber::SetBit(int position, bool b)
{
	if (position <= 31)   //младшая часть
	{
		if (b)  // если нужно установить 1
		{
			// побитовое ИЛИ числа с маской типа 000..00100..0
			// где 1 занимает позицию position в результате установит 1 в нужное место
			m_lower_part = m_lower_part | (int) pow(2, position);
		}
		else // если нужно установить 0
		{
			// побитовое И числа с маской типа 111..11011..111
			// где 0 стоит в позиции position установит 0 в нужное место
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
		// инвертируем все биты
		res.SetBit(i, !(this->GetBit(i)));
	}
	res = res + BigNumber("1");  // увеличим на 1
	return res;
}

BigNumber BigNumber::operator+(const BigNumber & num)
{
	BigNumber res;
	bool carry = false;   // перенос разряда
	bool sum = false;     // значение для текующего бита
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
	// умножение на 0
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
	BigNumber res("0");   // cчетчик
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
	// просто копирование соответствующих битов из одного числа в другое
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
	int symb; // текущий символ десятичным числом
	// обнулить все биты
	m_lower_part = m_upper_part = 0;
	pt = Hex;
	int len = HexNum.length();
	for (int i = len - 1; i >= 0; i--) 
		//проходим по всем символам в строке в обратном порядке
	{
		// находим число (переводим в десятичное число)
		if (HexNum[i] <= '9' && HexNum[i] >= '0') symb = HexNum[i] - '0';
		else if (HexNum[i] <= 'F' && HexNum[i] >= 'A') symb = HexNum[i] - 'A' + 10;
		else symb = 0;  // не является 16-ичным символом
		// переводим в двоичную
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

// вывод на экран
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
		// пропускаем незначащие нули
		
		while (!num.GetBit(i)) i--;
		// первый пробел не ставится
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
		// перевод в Hex путем перевода отдельных тетрад (полубайтов)
		// пропускаем незначащие тетрады [0000]
		int tet,     // счетчик тетрад, начиная с 1, справа налево (всего их 8*2 = 16)
			offset,  // отступ от начала тетрады
			sum;     // сумма текущей тетрады в десятичном представлении
		char ch;     // hex цифра текущей тетрады
		for (tet = 16; tet >= 1; tet--)
		{
			sum = 0;
			for (offset = 0; offset <= 3; offset++)
			{
				sum += (int) num.GetBit(tet * 4 - offset - 1);
			}
			if (sum) break;  // если очередная тетрада не нулевая перестаем их пропускать 
		}
		// выводим оставшиеся тетрады
		for (; tet >= 1; tet--)
		{
			sum = 0;
			//высчитываем десятичное значение очередной тетрады
			for (offset = 0; offset <= 3; offset++)
			{
				if (num.GetBit(tet * 4 - offset - 1)) // если очередной бит не пустой
				{
					sum +=(int) pow(2, 3 - offset);
				}	
			}
			// находим соответствующий hex символ
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
