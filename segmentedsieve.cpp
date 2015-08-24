#include<bits/stdc++.h>
using namespace std;
int prime[10000],primes;
void init_primes()
{
     static int isprime[32000];
     int i,j;
     for(i=2;i<32000;i++)
        isprime[i]=1;
     for(i=2;i <sqrt(32000);i++)
     {if(isprime[i])
         for(j=i*i;j<32000;j+=i)
            isprime[j]=0;
     }
     primes=0;
     for(i=2;i<32000;i++)
    {
        if(isprime[i])
            prime[primes++]=i;
    }
}
int sieve[100001];
void find_sieve(int l,int h)
{
    int i,j,p,n;
    for(i=0;i<=h-l;i++)
        sieve[i]=1;
        for(j=0;;j++)
        {
            p=prime[j];
            if(p>sqrt(h))
                break;
        n=(l/p)*p;
        if(n<l)
            n+=p;
        if(n==p)
            n+=p;
        for(;n<=h;n+=p)
            sieve[n-l]=0;
        }
}
int main()
{
    int t,l,u;
    init_primes();
    cin>>t;
    while(t--)
    {
        cin>>l>>u;
        if(l<2)
            l=2;
        find_sieve(l,u);
        for(int i=0;i<=u-l;i++)
        {
            if(sieve[i])
                cout<<l+i<<endl;
        }
    }return 0;
}
