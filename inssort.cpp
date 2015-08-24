#include<iostream>
using namespace std;
void inssort(int [],int);
void swp(int *xp,int *yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
int main()
{
    int arr[]={43,65,23,72,1,9,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" Given array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    inssort(arr,n);
    cout<<" Sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
void inssort(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j-=1;
        }arr[j+1]=key;
    }
}
