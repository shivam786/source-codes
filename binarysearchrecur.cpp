#include<iostream>
using namespace std;
int binarySearch(int [],int,int,int);
int main()
{
    int arr[]={2,3,4,10,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=10;
    cout<<" Given array is ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int result=binarySearch(arr,0,n-1,x);
    (result==-1)?cout<<" Element not present in array ":cout<<" Element present at : "<<result;
    return 0;
}
int binarySearch(int arr[], int l, int r, int x)
{
   if (l<r)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        else if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        else return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}
