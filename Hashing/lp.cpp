#include<iostream>
using namespace std;
#define ts 10
int hashtable[ts];
void lp(int key)
{
    int pos,i;
pos=key%ts;
if(hashtable[pos]==-1)
    hashtable[pos]=key;
else{
    for(i=pos+1;i%ts!=pos;i++)
    {
        if(hashtable[i%ts]==-1)
        {
            hashtable[i%ts]=key;
            break;
        }
    }
}
if(i%ts==pos)
    cout<<"overflow";
}
int main()
{
    int n,i,item;
    cout<<"enter the number of elements";
    cin>>n;
    for(i=0;i<ts;i++)
        hashtable[i]=-1;
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
