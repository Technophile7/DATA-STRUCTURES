#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

//   Creating a NODE Structure
struct node
{
   int data;  // data
   node *next;  // link to next node and previous node
};

// Creating a class LIST
class list
{
    node *start;
   public:
      void create(); // to create a list
      void show();   // show
      void merge(list,list);  // Merge two list's
};

// Main function
int main()
{
   list l1,l2,l3;
   cout<<"Enter Elements in ascending order.";
   l1.create(); // to create a first list
   cout<<"Enter Elements in ascending order.";
   l2.create(); // to create a second list
   l1.show();
   l2.show();
   l3.merge(l1,l2);
   l3.show();
   return 0;
}

//    Functions

// Creating a new node
void list::create()
{
   struct node *new_node,*pre_node;
   int value,no,i;
   start=new_node=pre_node=NULL;
   cout<<"How many Elements : ";
   cin>>no;
   cout<<"Enter "<<no<<" Elements: ";
   for(i=1;i<=no;i++)
   {
      cin>>value;
      new_node=new node;
      new_node->data=value;
      new_node->next=NULL;
      if(start==NULL)
	 start=new_node;
      else
	 pre_node->next=new_node;
      pre_node=new_node;
   }
}

// Displaying LIST
void list::show()
{
   struct node *ptr=start;
   cout<<"\nThe List is : ";
   while(ptr!=NULL)
   {
      cout<<ptr->data<<" -> ";
      ptr=ptr->next;
   }
   cout<<"NULL";
}

void list::merge(list l1,list l2)
{
   struct node *new_node,*pre_node,*pptr,*qptr;
   int dat;
   pptr=l1.start;
   cout<<pptr;
   qptr=l2.start;
   cout<<qptr;
   start=new_node=pre_node=NULL;
   while(pptr!=NULL && qptr!=NULL)
   {
      if(pptr->data<=qptr->data)
      {
	 dat=pptr->data;
	 pptr=pptr->next;
      }
      else
      {
	 dat=qptr->data;
	 qptr=qptr->next;
      }
      new_node=new node;
      new_node->data=dat;
      new_node->next=NULL;
      if(start==NULL)
	 start=new_node;
      else
	 pre_node->next=new_node;
      pre_node=new_node;
   }

   if(pptr==NULL)
   {
      while(qptr!=NULL)
      {
	 new_node=new node;
	 new_node->data=qptr->data;
	 new_node->next=NULL;
	 if(start==NULL)
	    start=new_node;
	 else
	    pre_node->next=new_node;
	 pre_node=new_node;
	 qptr=qptr->next;
      }
   }
   else if(qptr==NULL)
   {
      while(pptr!=NULL)
      {
	 new_node=new node;
	 new_node->data=pptr->data;
	 new_node->next=NULL;
	 if(start==NULL)
	    start=new_node;
	 else
	    pre_node->next=new_node;
	 pre_node=new_node;
	 pptr=pptr->next;
      }
   }
    return;
}


