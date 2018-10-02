#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<iostream>
#define MAX 10
int top = -1;
int stk[MAX];
void push(char);
char pop();
int main()
{
char exp[MAX],temp;
int i,flag=1;
std::cout <<"Enter Expression";
gets(exp);
for(i=0;i<strlen(exp);i++)
{
if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
push(exp[i]);
 if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
 if(top == -1)
 flag=0;
else
 {
  temp=pop();
  if(exp[i]==')' && (temp=='{' || temp=='['))
  flag=0;
  if(exp[i]== '}' && (temp=='(' || temp=='['))
  flag=0;
  if(exp[i]== ']' && (temp='(' || temp=='{'))
  flag=0;
 }
}
if(top>=0)
flag=0;
if(flag==1)
std::cout<<"Valid expression";
else
std::cout<<"Invalid expression";
}
void push(char c)
{
if(top==(MAX-1))
std::cout<<"stack overflow\n";
else
{
top=top+1;
stk[top]=c;
}
}
char pop()
{
if(top == -1)
std::cout<<"\n stack overflow";
else
return(stk[top--]);
}
