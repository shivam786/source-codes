#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll inv_cnt=0;
void merg(ll [],ll,ll,ll);
void mergesort(ll arr[],ll l,ll r)
{
    if(l<r)
    {
        ll m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merg(arr,l,m,r);
    }
}
void merg(ll arr[],ll l,ll m,ll r)
{
    ll i,j,k;
    ll n1=m-l+1;
    ll n2=r-m;
    ll *L,*R;
    L=new ll[n1];
    R=new ll[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            inv_cnt += (n1-i);
        }k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;k++;
    }
}
int main()
{ll t;
    cin>>t;
    ll* arr;
    while(t--)
    {ll n;
        cin>>n;
        arr=new ll[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        mergesort(arr,0,n-1);
        cout<<inv_cnt<<endl;
        inv_cnt=0;
    }return 0;
}
