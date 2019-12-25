#include <iostream>
#include <string>
#include "TStack.h"
#include "Calc.h"



using namespace std;

int main()
{
	string q;
	getline(cin, q);
	Calc c(q);
	if (c.StrokeCheck(q) == 1) cout << "ok" << endl;
	else throw "error";
	cout << "infix : " << q << endl;
	cout << "result : " << c.Calculations() << endl;
	c.getPostfix();

	system("pause");
	return 0;
}