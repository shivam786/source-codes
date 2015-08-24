#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;
int n, m, i, j, ret, dp[26][26];
int pw (int k) {
    if (!k) return 1;
    if (k == 1) return 2;
    int q = pw(k / 2);
    q = (1LL * q * q) % 1000000007;
    cout<<q<<" ";
    if (k % 2) return (q + q) % 1000000007; else return q;
}
int main (int argc, char * const argv[]) {
    scanf("%d %d", &n, &m);
    if ((n < 25 && m < 25) || ((n > 25 || m > 25) && abs(n - m) != 2) || (n == 24 && m == 25) || (n == 25 && m == 24) || (n == m)) {
        printf("0\n");
        return 0;
    }
    dp[0][0] = 1;
    for(i = 0; i <= 25; i++)
        for(j = 0; j <= 25; j++)
            if (i + j) {
                if (i) dp[i][j] += dp[i - 1][j];
                if (j) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= 1000000007;
                }
    /*for(i = 0; i <= 25; i++)
        {for(j = 0; j <= 25; j++)
            cout<<dp[i][j]<<" ";
    cout<<endl;}*/
    if (n < m) swap(n, m);
    if ((n == 25 && n > m)) {
        printf("%d\n", dp[n - 1][m]);
        return 0;
    }
    ret = dp[24][24];
    ret = (1LL * ret * pw(min(n, m) - 24)) % 1000000007;
    printf("%d\n", ret);
    return 0;
}
