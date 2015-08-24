#include<bits/stdc++.h>
using namespace std;
int dissect(int num)
{
    int ans=0;
    while(num)
    {
        int t=num%10;
        ans+=t*t;
        num/=10;
    }
    return ans;
}
int main()
{
    int num,cnt=0,hit=1;
    int arr[1000]={0};
    cin>>num;
    while(1)
    {
        int temp;
        temp=dissect(num);
        if(arr[temp]==0)
        {
            num=temp;
            arr[temp]=1;
            cnt++;
        }
        else{
            hit=0;
            break;}
        if(num==1)
            break;
    }
    if(hit)
        cout<<cnt<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
