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
	int one, v;
	cout << "length first number " << endl;
	cin >> one;
	//set the sizes
	
	cout << "VVOD number " << endl;
	cin >> v;
	Decimal DFirs(one, v);
	
	int two,R;
	cout << "length  second number " << endl;
	cin >> two;
	//set the sizes
	
	cout << "VVOD number " << endl;
	cin >> R;
Decimal DSec(two, R);
	//operathion---------------------------
	//int K;
	//if (one >= two)//choose the desired size
	//	 K = one;
	//else
	//	K = two;

  //  Decimal Dec(one);
	//Dec = 
	cout << " sum= " <<  DFirs + DSec<< endl;
//	Dec =;
	cout << " differ= " <<  DFirs - DSec << endl;
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