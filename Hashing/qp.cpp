#include<iostream>
using namespace std;
int hashtable[100];
#define ts 10
void lp(int key)
{
    int i;
    int pos,pos1;
i=1;
pos=key%ts;
if(hashtable[pos]==-1)
    hashtable[pos]=key;
else{
    do{
        pos1=(pos+(i*i))%ts;
        if(hashtable[pos1]==-1)
        {
            hashtable[pos1]=key;
            break;
        }
        i++;
    }while(i<=((ts-1)/2)+1);
}
}
int main()
{
    int n,i,item;
    for(i=0;i<10;i++)
    hashtable[i]=-1;
    cout<<"enter the number of elements";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>item;
        lp(item);
    }
    for(i=0;i<ts;i++)
    {
        if(hashtable[i]==-1)
            continue;
        else
        cout<<hashtable[i]<<" ";
    }
}
