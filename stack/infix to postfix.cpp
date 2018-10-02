#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100
int top=-1;
void push(char a[],char item)
{
    if(top==MAX-1)
    {
        cout<<"Overflow\n";
    }
    else
    {
        top++;
        a[top]=item;
    }
}
void pop(char a[])
{
    int ele;
    if(top==-1)
        cout<<"Underflow\n";
    else
    {
        ele=a[top];
        top--;
    }
}
int checkprec(char a,char b)
{
    if(a=='^')
        a='3';
    else if(a=='*'||a=='/')
        a='2';
    else
        a='1';
    if(b=='^')
        b='3';
    else if(b=='*'||b=='/')
        b='2';
    else
        b='1';
        if(b<=a)
            return 0;
        else
            return 1;
}
int main()
{
        char str[100],operand[100],operators[100],k=0,j=0,i;
        int len,prec;
        cout<<"Enter the infix expression\n";
        cin>>str;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
               operand[k++]=str[i];
            else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'||str[i]=='(')
            {
                if(top==-1)
                push(operators,str[i]);
                else if(str[i]=='(')
                            push(operators,str[i]);
                else
                {
                    prec=checkprec(operators[top],str[i]);
                    if(prec==1)
                          push(operators,str[i]);
                    else
                    {
                        while(top!=-1)
                        {
                            if(operators[top]=='(')
                                break;
                            operand[k++]=operators[top];
                            pop(operators);
                        }
                        push(operators,str[i]);
                    }
                }
            }
            else if(str[i]==')')
            {
                while(operators[top]!='(')
                {
                    operand[k++]=operators[top];
                    pop(operators);
                }
                pop(operators);
            }

        }
        while(top!=-1)
        {
            operand[k++]=operators[top];
            pop(operators);
        }
        for(i=0;i<k;i++)
        {
            cout<<operand[i];
        }
}
