#include<iostream>
using namespace std;
void bubsort(int [],int);
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
    bubsort(arr,n);
    cout<<" Sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
void bubsort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
     {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swp(&arr[j],&arr[j+1]);
        }
    }
}
