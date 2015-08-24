#include<iostream>
using namespace std;
int binsearch(int [],int,int);
int main()
{
    int arr[]={1,24,32,65,72,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=24;
    int res=binsearch(arr,n,x);
    cout<<" 24 found at index "<<res;
}
int binsearch(int arr[],int n,int x)
{int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            r=mid-1;
        else l=mid+1;
    }return -1;
}
