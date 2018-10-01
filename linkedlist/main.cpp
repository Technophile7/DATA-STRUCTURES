


#include <iostream>
#include <stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list *next;
};
struct list *start=NULL;

void insertbeg(int item)
{
    struct list *ptr;
    ptr=new list;
    
    if(start==NULL)
    {
        start=ptr;
        ptr->info=item;
        ptr->next=NULL;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        start=ptr;
    }
}
void insertend(int item)
{
    struct list *ptr,*temp;
    ptr=new list;
    
    if(start==NULL)
    {
        start=ptr;
        ptr->info=item;
        ptr->next=NULL;
    }
    else
    {
        ptr->info=item;
        ptr->next=NULL;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void traverse()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
    }
}
void deletebeg()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else
    {
        temp=start;
        start=temp->next;
        delete temp;
    }
}
void deleteend()
{
    struct list *temp,*temp1;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start->next==NULL)
    {
        temp=start;
        start=temp->next;
        delete temp;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        delete temp;
    }
}
int main()
{
    int n,item;
    while (1)
    {
        cout<<"enter the choice"<<endl;
        cout<<"1 for insertion at beginning "<<endl;
        cout<<"2 for insertion at end  "<<endl;
        cout<<"3 for traversing  "<<endl;
        cout<<"4 for deletion at begg. "<<endl;
        cout<<"5 for deletion at end"<<endl;
		cin>>n;
        switch(n)
        {
            case 1:
                cout<<"enter an item";
                cin>>item;
                insertbeg(item);
                break;
            case 2:
                cout<<"enter an item";
                cin>>item;
                insertend(item);
                break;
            case 3:
                traverse();
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            default:
                exit(0);
                
                }
        
        
    }
}


