#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *createnode(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

node* ins(node *root,int value)
{
    if(root==NULL)
    {
        root=createnode(value);
    }
    else if(value < root->data)
        root->left=ins(root->left,value);
    else if(value > root->data)
        root->right=ins(root->right,value);

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

node* searchnode(node *root,int x)
{
    if(root==NULL){
        cout<<"Node not found";
        return NULL;
    }
    else if(root->data==x)
    {
        cout<<"\nNode exists\n";
        return NULL;
    }
    else if(x < root->data)
        root->left=searchnode(root->left,x);
    else
        root->right=searchnode(root->right,x);
}

node* delnode(node *root,int x)
{
    if(root==NULL)
        cout<<"Node not found";
    else if(root->data==x && root->right==NULL && root->left==NULL)
    {
        delete root;
        root=NULL;
        return root;
    }
    else if(x < root->data)
        root->left=delnode(root->left,x);
    else
        root->right=delnode(root->right,x);
}

int findheight(node *root)
{
    int lh,rh;
    if(root==NULL)
        return 0;
    else
    {
        lh=findheight(root->left);
        rh=findheight(root->right);
        if(lh > rh)
            return (lh+1);
        else
            return (rh+1);
    }
}

int findsize(node *root)
{
    if(root==NULL)
        return 0;
    else
        return (findsize(root->left)+1+findsize(root->right));
}

int checkbst(node *root)
{
    if(root==NULL)
        return 1;
    if(root->left!=NULL && root->left->data > root->data)
        return 0;
    if(root->right!=NULL && root->right->data < root->data)
        return 0;
    if(!checkbst(root->left) || !checkbst(root->right))
        return 0;
    return 1;
}
int count=0;
int childnodes(node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        count++;
    else{
    childnodes(root->left);
    childnodes(root->right);
    }
    return count;
}
int internalnodes(node *root)
{
    if(root==NULL)
        return 0;
    if(root->left!=NULL || root->right!=NULL)
        count++;
    childnodes(root->left);
    childnodes(root->right);
    return count;
}

node* heightofnode(node *root,int x)
{
    if(root==NULL){
        cout<<"Node not found";
        return NULL;
    }
    else if(root->data==x)
    {
        int x=findheight(root);
        cout<<"\nHeight of the node is: "<<x-1<<endl;
        return NULL;
    }
    else if(x < root->data)
        root->left=heightofnode(root->left,x);
    else
        root->right=heightofnode(root->right,x);
}



int main()
{
    node *root = NULL;
    node *ptr;
    int x,n,ch;
    cout<<"Enter choice\n1.Insert\n2.Search\n3.Traverse\n4.Delete\n5.Height or Depth of tree\n6.Size of the tree\n7.BST or not\n8.No of child nodes\n9.No of internal nodes\n10.Height of node\n";
    cin>>ch;
    while(ch)
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter the no of nodes: ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>x;
                root=ins(root,x);
            }
            break;
        case 2:
            cout<<"\nEnter an element you want to search: ";
            cin>>x;
            ptr=root;
            ptr=searchnode(ptr,x);
            break;
        case 3:
            ptr=root;
            cout<<"Inorder:  ";
            inorder(ptr);
            cout<<"\nPreorder:  ";
            preorder(ptr);
            cout<<"\nPostorder:  ";
            postorder(ptr);
            break;
        case 4:
            cout<<"\nEnter an element you want to delete: ";
            cin>>x;
            ptr=root;
            delnode(ptr,x);
            break;
        case 5:
            ptr=root;
            int h;
            h=findheight(ptr);
            cout<<"Height of the tree is: "<<h-1<<endl;
            break;
        case 6:
            ptr=root;
            x=findsize(ptr);
            cout<<"Size of the tree: "<<x<<endl;
            break;
        case 7:
            ptr=root;
            x=checkbst(ptr);
            if(x==0)
                cout<<"\nTree is not a BST\n";
            else
                cout<<"\nIt is a BST\n";
            break;
        case 8:
            ptr=root;
            x=childnodes(ptr);
            if(x==0)
                cout<<"\nNo child nodes present\n";
            else
                cout<<"Child nodes are: "<<x<<endl;
            count=0;
            break;
        case 9:
            ptr=root;
            x=internalnodes(ptr);
            if(x==0)
                cout<<"\nEmpty tree\n";
            else
                cout<<"\nInternal nodes are: "<<x+1<<endl;
            count=0;
            break;
        case 10:
            cout<<"\nEnter the node you want to find the path for: ";
            cin>>x;
            ptr=root;
            heightofnode(ptr,x);
            break;
        }
        cout<<"\nEnter choice: ";
        cin>>ch;
    }
    return 0;
}
