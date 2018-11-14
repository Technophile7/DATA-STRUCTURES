#include <iostream>
#include<math.h>
#include<stdio.h>
#define MAX 10
using namespace std;
class stack1
{  char a[20];
   int top=0;
   int arr[MAX];
   int top1=-1;
public:
    void push(char b)
    {
        a[top]=b;
        top=top+1;
    }
    void push1(int x)
    {
        if(top1 == MAX - 1)
        cout<<"Overflow"<<endl;
        else
        {
          top1 ++;
          arr[top1] = x;
        }
    }
    int pop1()
   {
    if(top1 == -1)
        cout<<"Underflow"<<endl;
    else
       top1--;
    return arr[top1+1];
   }
   void  peep()
  {
    if(top1 == -1)
        cout<<"Stack Empty"<<endl;
    else
        cout<<arr[top1]<<endl;
  }
    void infix_postfix(char *e)
    {
        char x;
        while(*e!='\0')
        {   if(isalnum(*e))
           {
              cout<<*e;
           }
           else if(*e=='(')
            {
                push(*e);
            }
            else if(*e==')')
            {
                x=pop();
                while(x!='(')
                {
                    cout<<x;
                    x=pop();
                }
            }
            else
            {
               if(priority(a[top-1])>=priority(*e))
               {
                  while(priority(a[top-1])>=priority(*e))
                {
                    cout<<pop();

                }
                push(*e);
               }
               else
               {
                   push(*e);
               }


            }
            e=e+1;

           }

        while(top!=0)
        {
            cout<<pop();
        }
    }
    int priority(char p)
    {
         if(p=='+'||p=='-')
            return 1;
        else if(p=='*'||p=='/')
            return 2;
        else if(p=='^')
            return 3;
        else
            return -1;

    }
    char pop()
    {
        char n;
        n=a[top-1];
        top=top-1;
        return n;
    }

};
int main()
{   stack1 s;
    int c;
    do
    {
        cout<<"\n1. Postfix Exp\n2. Postfix Evaluation\n3. Exit\n";
        cin>>c;
        switch(c)
        {
        case 1:
            {
                 char str[20];
                 cout<<"enter exp :\n";
                 cin>>str;
                 s.infix_postfix(str);
                 break;
            }
        case 2:
            {
                 int res = 0;
                 string ch;
                 cout<<"enter exp :\n";
                 cin>>ch;
                 int i=0;
                 while( ch[i]!= '\0')
                 {
                   if(isdigit(ch[i]))
                   {
                     s.push1(ch[i]-'0');
                   }
                  else
                  {
                    int a = s.pop1();
                    int b = s.pop1();
                    switch(ch[i])
                   {
                       case '+' : res = int(a) + int(b);
                       break;
                       case '-' : res = int(b) - int(a);
                       break;
                       case '*' : res = int(b) * int(a);
                       break;
                       case '/' : res = int(b) / int(a);
                       break;
                       case '^' : res = pow(b,a);
                       break;
                   }
                  s.push1(res);
                  }
                 i++;
                }
                 s.peep();
                 break;
            }
        }

    }while(c!=3);

    return 0;
}
