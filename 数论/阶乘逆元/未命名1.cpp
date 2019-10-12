#include<bits/stdc++.h>

const int maxn = 2555;
const int Mod = 1000000007;
typedef long long ll;

using namespace std;

ll c[maxn],f[maxn];
ll inv[maxn],fac[maxn];

ll mypow(ll a,ll b,ll m){
	ll inv = 1;
	while( b ){
		if( b&1 )  inv = inv*a%m;
		a = a*a%m;
		b>>=1;
	}
	return inv;
}

int n,m;

void getF(){
	fac[0] = inv[0] = 1;
	int i,j,k;
	for(i=1;i<=m;++i)
	{
		fac[i] = fac[i-1]*i%Mod;
		inv[i] = mypow(fac[i],Mod-2,Mod);
	}
}

ll getC(int a){
	return (fac[m] * inv[a]) %Mod *inv[m-a] %Mod;
}

int main(){
	cin>>n>>m;
	int i,j,k;
	getF();
	for(i=0;i<=m;i++)
	{
		c[i] = getC(i);
	}
	for(i=1;i<=m;i++)
	{
		f[i] = (ll)i*mypow(i-1,n-1,Mod)%Mod;
	}
	ll ans = 0,t = 1;
	for(i=0;i<m;i++)
	{
		ans = ( ans + (t*f[m-i]*c[i])%Mod + Mod )%Mod;
		t *= -1;
	}
	cout<<ans<<endl;
	return 0;
}

