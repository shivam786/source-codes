#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
        if(!(t&(t-1)))
            cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    return 0;
}
