#include <iostream>

using namespace std;
class sort1
{
    int a[20];
    int n;
public:
    sort1()
    {
        cout<<"Size : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void insertion_sort()
    {
        int key,j;
        for(int i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>key)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
    }
    void add_sequence(int num)
    {
        a[n]=num;
        n=n+1;
        insertion_sort();
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    sort1 s;
    int num;
    s.insertion_sort();
    cout<<"Enter a Number : ";
    cin>>num;
    s.display();
    s.add_sequence(num);
    cout<<"After inserting an element in sequence \n";
    s.display();
    return 0;
}
