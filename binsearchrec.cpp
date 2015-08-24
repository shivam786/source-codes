#include<iostream>
using namespace std;
int binsearch(int [],int,int,int);
int main()
{
    int arr[]={1,24,32,65,72,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=24;
    int res=binsearch(arr,0,n,x);
    cout<<" 24 found at index "<<res;
}
int binsearch(int arr[],int l,int r,int x)
{
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            return binsearch(arr,l,mid-1,x);
        else
            return binsearch(arr,mid+1,r,x);
    }return -1;
}
