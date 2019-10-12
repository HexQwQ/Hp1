// luogu-judger-enable-o2
#include<bits/stdc++.h>
#include<tr1/unordered_map>

typedef long long ll;

const int Maxn = 5000010;

void read(int &p){
    int t=0;
    char c;
    c=getchar();
    while( c < '0' || c > '9' )
      c=getchar();
    while( c >= '0' && c <= '9' )
    {
        t=t*10+c-'0';
        c=getchar();
    }
    p=t;
}

using namespace std;

bool vis[Maxn];
int mu[Maxn],sum1[Maxn];
ll phi[Maxn],sum2[Maxn];
int cnt,prim[Maxn];
int e,e1;

tr1::unordered_map<ll,ll> Phi;
tr1::unordered_map<int,int> Mu;

void get(int n){
    phi[1] = 1;
    mu[1] = 1;
    int i,j,k;
    cnt = 0;
    for(i=2;i<=n;++i)
    {
        if( !vis[i] )
        {
            prim[++cnt] = i;
            mu[i] = -1;
            phi[i] = i-1;
        }
        for(j=1;j<=cnt&&i*prim[j]<=n;++j)
        {
            vis[i*prim[j]] = true;
            if( i%prim[j] == 0 )
            {
                phi[i*prim[j]] = phi[i]*prim[j];
                break;
            }
            else 
                phi[i*prim[j]] = phi[i]*(prim[j]-1),
                mu[i*prim[j]] = -mu[i];
        }
    }
    for(i=1;i<=n;++i)
    {
        sum1[i] = sum1[i-1] + mu[i];
        sum2[i] = sum2[i-1] + phi[i];
    }
}

int MU(int x){
    if( x <= Maxn - 10 )  return sum1[x];
    if( Mu[x] )  return Mu[x];
    int ans = 1;
    for(int l=2,r;l<=x;l=r+1)
    {
        r = x/(x/l);
        ans -= (r-l+1)*MU(x/l);
    }
    Mu[x] = ans;
    return Mu[x];
}

ll PHI(ll x){
    if( x <= Maxn-10 )  return sum2[x];
    if( Phi[x] )  return Phi[x];
    ll ans = x*(x+1)/2;
    for(ll l=2,r;l<=x;l=r+1)
    {
        r = x/(x/l);
        ans -= (r-l+1)*PHI(x/l);
    }
    return Phi[x] = ans;
}

int main(){
    int T,n;
    get(Maxn-10);
    read(T);
    while( T-- ){
        read(n);
        printf("%lld %d\n",PHI(n),MU(n));
    }
}
