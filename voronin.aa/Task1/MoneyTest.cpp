#include <iostream>
#include "Money.h"
using namespace std;
//test
int main() {
	Money ans1 ,  ans2 , ans3, ans4 , ans5 ;
	Money test1('-', 22,70);
	Money test2('+',22,60);
	Money test3(test2);
	Money test4;
	cout << "Enter example" << endl;
	cin >> test4;
	ans1 = test1 + test2;
	ans2 = test1 - test2;
	ans3 = test1 * 10.12;
	ans4 = test1 / 10.56;
	ans2 = test1;
	cout << "ans1= " << ans1 << ' ' << endl
		<< "ans2= " << ans2 << ' ' << endl 
		<< "ans3= " << ans3 << ' ' << endl 
		<< "ans4= " << ans4 << ' ' << endl 
		<< "ans5= " << ans5 << ' ' << endl 
		<< "test3= " << test3 << ' ' << endl 
		<< "test4=" << test4 << ' ';
	system("pause");
	return 0;
}