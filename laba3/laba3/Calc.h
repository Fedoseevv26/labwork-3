#pragma once

#include "Calc.h"
#include "TStack.h"
#include <string>

using namespace std;

class Calc
{
private:
	string oper = "+-*/()";
	int priority[5] = { 1,1,2,2,0 };
	int *sign;
	int *num;
	int countSign;
	int countNum;
	int cs = 0; //счетчик скобок
	string Postfix;
	int result;
public:
	Calc(string q);
	int Calculations();
	bool StrokeCheck(string q);
	void getPostfix();
	~Calc();
};