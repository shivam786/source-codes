#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
    cin>>t;
    while(t--)
    {int z=0,n;
        cin>>n;
        for(int i=5;i<=n;i*=5)
            z+=n/i;
        cout<<z<<endl;
    }
}
