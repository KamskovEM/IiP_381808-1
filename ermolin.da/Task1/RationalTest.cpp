#include <iostream>
#include <locale.h>
#include "Rational.h"

using namespace std;

int main() 
{
int a, b;//Переменные для сторон
setlocale(LC_CTYPE, "Russian");//Подключение русских символов
Rational Sum1(13,6), Sum2(12,6);
cout << "Введите 2 дроби\n";
cin >> Sum1>>Sum2;
cout << "Сумма: " << Sum1 + Sum2 << endl;
cout << "Разность: " << Sum1 - Sum2 << endl;
cout << "Произведение: " << Sum1 * Sum2 << endl;
cout << "Деление: " << Sum1 / Sum2 << endl;
cout << "Сравнение дробей" << endl;
if (Sum1 == Sum2) { cout << "Дроби равны"; }
else if (Sum1 > Sum2) { cout << Sum1 << " > " << Sum2; }
	else { cout << Sum1 << " < " << Sum2; }
return 0;
}