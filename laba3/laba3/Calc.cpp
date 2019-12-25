#include "Calc.h"
#include "TStack.h"
#include <string>

using namespace std;

Calc::Calc(string q)
{
	sign = new int[q.size()];
	num = new int[q.size()];
	for (int i = 0; i < q.size(); ++i)
	{
		int c = 0;
		int fl = 0;
		while (q[i] >= '0' && q[i] <= '9')
			fl = 1, c = c * 10 + (q[i++] - '0');
		if (fl) num[countNum++] = c;
		fl = oper.find(q[i]);
		if (fl != -1)
			sign[countSign++] = fl;
	}

}
bool Calc::StrokeCheck(string q)
{
	string sign_ = "+-*/)";
	int count1 = 0, count2 = 0;
	if (sign_.find(q[0]) != -1)  return 0;  //проверка начинается ли строка с оператора
	for (int i = 0; i < countSign; i++) //проверка количества скобок
	{
		if (sign[i] == 4) { count1++; cs++; }
		if (sign[i] == 5) { count2++; if (count2 > count1) return 0; cs++; }
	}
	if (count1 != count2) return 0;
	if (countNum != (countSign - cs + 1)) return 0; //проверка лишних операторов
	return 1;
}
int Calc::Calculations()
{
	TStack<int> operands(countNum);
	TStack<int> operators(countSign);
	int i = 0; //счетчик чисел	
	int j = 0; //счетчик знаков
	int k = 0;
	int state = 0;
	int a;
	int b;
	int c;
	while (k != countNum + countSign)
	{
		if (state == 0)
		{
			operands.sPush(num[i]);
			Postfix += to_string(num[i]);
			Postfix += ' ';
			i++;
			state = 1;
			k++;
		}
		if (operators.isEmpty())
		{
			operators.sPush(sign[j]);
			if (sign[j] == 4) state = 1;
			else state = 0;
			j++;
			k++;
		}
		if (state == 1 && j != countSign)
		{
			if (sign[j] == 4)
			{
				operators.sPush(sign[j]);
				j++;
				k++;
			}
			if (j < countSign && priority[operators.sTop()] <= priority[sign[j]] && sign[j] != 5 && sign[j] != 4)
			{
				operators.sPush(sign[j]);
				j++;
				state = 0;
				k++;
			}
			if (state == 1 && (j < countSign && priority[operators.sTop()] > priority[sign[j]] && sign[j] != 5 && sign[j] != 4))
			{
				while ((!operators.isEmpty()) && (priority[operators.sTop()] > priority[sign[j]]))
				{
					if (operators.sTop() == 4) {
						operators.sPush(sign[j]);
						j++;
					}
					a = operands.sTop();
					operands.Pop();
					b = operands.sTop();
					operands.Pop();
					switch (operators.sTop()) {
					case 0:
						c = a + b;
						Postfix += '+';
						Postfix += ' ';
						break;
					case 1:
						c = b - a;
						Postfix += '-';
						Postfix += ' ';
						break;
					case 2:
						c = a * b;
						Postfix += '*';
						Postfix += ' ';
						break;
					case 3:
						c = b / a;
						Postfix += '/';
						Postfix += ' ';
						break;
					}
					operands.sPush(c);
					operators.Pop();
				}
			}
			if ((state == 1 && sign[j] == 5))
			{
				while (operators.sTop() != 4)
				{
					a = operands.sTop();
					operands.Pop();
					b = operands.sTop();
					operands.Pop();
					switch (operators.sTop()) {
					case 0:
						c = a + b;
						Postfix += '+';
						Postfix += ' ';
						break;
					case 1:
						c = b - a;
						Postfix += '-';
						Postfix += ' ';
						break;
					case 2:
						c = a * b;
						Postfix += '*';
						Postfix += ' ';
						break;
					case 3:
						c = b / a;
						Postfix += '/';
						Postfix += ' ';
						break;
					}
					operands.sPush(c);
					operators.Pop();
				}
				state = 1;
				j++;
				k++;
				operators.Pop();
			}
		}
	}
	while (!operators.isEmpty())
	{
		a = operands.sTop();
		operands.Pop();
		b = operands.sTop();
		operands.Pop();
		switch (operators.sTop()) {
		case 0:
			c = a + b;
			Postfix += '+';
			Postfix += ' ';
			break;
		case 1:
			c = b - a;
			Postfix += '-';
			Postfix += ' ';
			break;
		case 2:
			c = a * b;
			Postfix += '*';
			Postfix += ' ';
			break;
		case 3:
			c = b / a;
			Postfix += '/';
			Postfix += ' ';
			break;
		}
		operands.sPush(c);
		operators.Pop();
	}
	result = operands.sTop();
	return result;
}
void Calc::getPostfix()
{
	cout << Postfix << endl;
}
Calc::~Calc()
{
	delete[] sign;
	delete[] num;
}