#include <iostream>

using namespace std;
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return (i+1);
}
void quicksort(int a[],int low,int high)
{
    if(low < high)
    {
        int b = partition(a,low,high);
        quicksort(a,low,b-1);
        quicksort(a,b+1,high);
    }
}
int main()
{
       int a[20];
       int n;
        cout<<"Size : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        quicksort(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    return 0;
}
