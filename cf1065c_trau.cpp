#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K,H[200010],cnt[200010];
LL ans = 0;

int main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++)scanf("%d",&H[i]),cnt[H[i]]++;
    LL now = 0, S = 0;
    for (int i=200000;i>=1;i--)
    {
        now += cnt[i];
        if (now == N)
        {
            ans++;
            break;
        }
        if (S + now > K)
        {
            //printf("fuck %d\n",i);
            ans++;
            S = now;
        }
        else
        {
            S += now;
        }
    }
    printf("%lld\n",ans);
}