#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

//   Creating a NODE Structure
struct node
{
   int data;  // data
   node *next;  // link to next node
};

// Creating a class LIST
class list
{
    node *start;
   public:
      void create(); // to create a list
      void show();   // show
      void reverse(list);  // Reverse the list
};

// Main function
int main()
{
   list l1;
   cout<<"Enter Elements in ascending order.";
   l1.create(); // to create a first list
   cout<<"Original List : "<<l1.show()<<"\n";
   
   list l2 = l1;
   l1.reverse(l2);
   cout<<"Reversed List : <<l2.show()<<"\n";
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

void list::reverse(list& l2)
{
    struct node *prevNode = NULL, *currNode = l2, *nextNode = NULL;
    
    while(currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    
    l2 = prev;
}
