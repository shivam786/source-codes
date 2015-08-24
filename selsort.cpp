#include<iostream>
using namespace std;
void selsort(int [],int);
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
    selsort(arr,n);
    cout<<" Sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
void selsort(int arr[],int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
               min_idx=j;
        }swp(&arr[min_idx],&arr[i]);
    }
}
