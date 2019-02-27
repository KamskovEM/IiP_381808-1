#include <iostream>
#include <cmath>
#include <algorithm>
#include "BigNumber.h"
#include <locale.h>
#include <fstream>
using namespace std;
int main() 
{
	//vvod-------------------------
	int one;
	cout << "length first number " << endl;
	cin >> one;
	Decimal DFirs(one);
	cout << "VVOD number " << endl;
	cin >> DFirs;
	int two;
	cout << "length  second number " << endl;
	cin >> two;
	Decimal DSec(two);
	cout << "VVOD number " << endl;
	cin >> DSec;
	//operathion---------------------------
    Decimal Dec(one);
	Dec = DFirs + DSec;
	cout << " sum= " << Dec << endl;
	Dec = DFirs - DSec;
	cout << " differ= " << Dec << endl;
	///////////////////////////////
	cout <<  " First Numder == Second Number ";
	if (DFirs == DSec) 
	{
		cout << "THIS TRUE" << endl; ;
	}
	else 
	{
		cout << "THIS FALSE" << endl;
	}
	/////////////////////////
	cout << " First Numder != Second Numder ";
	if (DFirs != DSec)
	{
		cout << "THIS TRUE" << endl;
	}
	else 
	{
		cout << "THIS FALSE" << endl;
	}
	//////////////////////
	cout << " First Numder > Second Numder ";
	if (DFirs > DSec)
	{
		cout << "THIS TRUE" << endl;
	}
	else 
	{
		cout << "THIS FALSE" << endl;
	}
	/////////////////////////
	cout << " First Numder>= Second Numder ";
	if (DFirs >= DSec) 
	{
		cout << "THIS TRUE" << endl;
	}
	else
	{
		cout << "THIS FALSE" << endl;
	}
	//////////////////
	cout << "First Numder<= Second Numder ";
	if (DFirs <= DSec)
	{
		cout << "THIS TRUE" << endl; ;
	}
	else 
	{
		cout << "THIS FALSE" << endl;
	}
	/////////////
	cout << "First Numder < Second Numder ";
	if (DFirs < DSec) 
	{
		cout << "THIS TRUE" << endl;
	}
	else 
	{
		cout << "THIS FALSE" << endl;
	}
	return 0;
}