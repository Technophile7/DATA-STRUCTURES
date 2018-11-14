#include<iostream>
using namespace std;
void max_heapify(int a[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest;
    if(l<n&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<n&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,largest,n);
    }
}
void build(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        max_heapify(a,i,n);
}
void heapsort(int a[],int n)
{
    int s=n;
    build(a,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        s=s-1;
        max_heapify(a,0,s);
    }
}
int main()
{
    int n,i;
    int a[20];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    heapsort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

}
