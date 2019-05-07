#include "Menu.h"

Menu::Menu()
{
	count = current = 0;
	arr = nullptr;
}
Menu::Menu(int n) : count(n), current(0)
{
	arr = new string[n];
	for (int i = 0; i < count; i++) arr[i] = string();
}
Menu::Menu(const Menu &M)
{
	arr = new string[M.count];
	for (int i = 0; i < M.count; i++)
	{
		arr[i] = M.arr[i];
	}
}
Menu::Menu(istream& stream)
{
	if (!stream.fail()) {
		stream >> count;
		arr = new string[count];
		current = 0;
		string tmp;
		stream.ignore();
		for (int i = 0; i < count; i++)
		{
			getline(stream, tmp);
			arr[i] = ' ' + tmp + ' ';
		} 
	}
	else
	{
		throw InvalidStream;
	}
}
Menu::~Menu()
{
	count = current = 0;
	delete[] arr;
	arr = nullptr;
}
void Menu::SetItem(int n, const string& str)
{
	if (n >= count) throw OutOfRange;
	else
	{
		string tmp = ' ' + str + ' ';
		arr[n] = tmp;
	}
}
void Menu::Show(int x, int y) 
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if ((x == -1) && (y = -1))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		GetConsoleScreenBufferInfo(console, &consoleInfo);

		currentPosition.X = 0;
		currentPosition.Y = consoleInfo.dwCursorPosition.Y + 1;		
	}
	else {
		currentPosition.X = (short)x;
		currentPosition.Y = (short)y;
	}
	COORD position = currentPosition;	
	for (int i = 0; i < count; i++)
	{
		SetConsoleCursorPosition(console, position);
		if (i == current)		
			SetConsoleTextAttribute(console, (WORD)((15 << 4) | 0));
		 else
			SetConsoleTextAttribute(console, (WORD)((0 << 4) | 15));
		cout << arr[i];
		position.X += arr[i].length();
	}
	SetConsoleTextAttribute(console, (WORD)((0 << 4) | 15));
	SetConsoleCursorPosition(console, COORD{ 0, currentPosition.Y + 1 });
}
int Menu::Input() 
{
	while (true)
	{
		int press;
		if (_kbhit())
		{
			press = _getch();
			switch (press)
			{
			case 75: //Стрелка вправо
				if (((int)current - 1) >= 0)
				{
					current--;
					Show(currentPosition.X, currentPosition.Y);
				}
				break;

			case 77: //Стрелка влево
				if ((int)current + 1 < count)
				{
					current++;
					Show(currentPosition.X, currentPosition.Y);
				}
				break;

			case VK_RETURN:
				return current;
				break;
			}
		}
	}

}
std::ostream& operator<<(std::ostream & stream, const Menu & M)
{
	stream << M.count;
	for (int i = 0; i < M.count; i++)
	{
		stream << M.arr[i];
	}
	return stream;
	
}
std::istream& operator>>(std::istream& stream, Menu & M)
{
	stream >> M.count;
	for (int i = 0; i < M.count; i++)
	{
		getline(stream, M.arr[i]);
	}
	return stream;


}
