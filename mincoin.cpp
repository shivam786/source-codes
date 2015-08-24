#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define INF 1000000
using namespace std;
int ks(int s,vector<int> cn)
{
    int m[cn.size()+1];
    for(int i=0;i<cn.size()+1;i++)
        m[i]=INF;
    m[0]=0;
    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<cn.size();j++)
        {
            if(cn[j]<=i&&m[i-cn[j]]+1<m[i])
                m[i]=m[i-cn[j]]+1;
        }
    }
    return m[s];
}
int main()
{
    vector<int> cn={1,3,5};
    int  s = 11;
    int n=cn.size();
    cout<<ks (s, cn);
    return 0;
}
