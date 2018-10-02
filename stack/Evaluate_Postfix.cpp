#include<iostream>
#include<stack>
#include<string>
using namespace std;

int Post_Eval(string expression);

bool IsNumber(char C);

int main()

{
	string expression;

	getline(cin,expression);

    cout<<Post_Eval(expression);

}

int Post_Eval(string expression)

{

	stack<int> S; int result;

	for(int i = 0;i< expression.length();i++)

        {
            if(IsNumber(expression[i])){

			int operand = 0;

			while(i<expression.length() && IsNumber(expression[i])) {

				operand = (operand*10) + (expression[i] - '0');

				i++;

			}

			i--;

			S.push(operand);

		}

        else if(expression[i] == '+' || expression[i]== '-' || expression[i] == '*' || expression[i] == '/')

        {

			int operand2 = S.top(); S.pop();

			int operand1 = S.top(); S.pop();

			if(expression[i] == '+') result= operand1 +operand2;

            else if(expression[i] == '-') result=operand1 - operand2;

            else if(expression[i] == '*') result= operand1 * operand2;

            else if(expression[i]== '/') result=operand1 / operand2;

            S.push(result);

		}
		else  if(expression[i] == ' ' || expression[i] == ',') continue;

	}
	return S.top();

}

bool IsNumber(char C)

{

	if(C >= '0' && C <= '9') return true;

	return false;

}

