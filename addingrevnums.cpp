#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int a,b;
    vector<int> v1,v2;
        cin>>a>>b;
        while(a)
        {
            v1.push_back(a%10);
            a/=10;
        }
        while(b)
        {
            v2.push_back(b%10);
            b/=10;
        }a=0,b=0;
        for(int i=0;i<v1.size();i++)
            a=a*10+v1[i];
        for(int i=0;i<v2.size();i++)
            b=b*10+v2[i];
        int c=a+b;
        int res=0;
        while(c)
        {
            res*=10;
            res+=c%10;
            c/=10;
        }cout<<res<<endl;
    }return 0;}
