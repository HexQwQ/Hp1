#include<bits/stdc++.h>
#include<tr1/unordered_map> 

using namespace std;
/*

*************************
* 507寝室长是一个大菜鸡 *
*************************   

*/
const int Maxn = 50050;
const int Mod = 1e9+7;

typedef long long ll; 
 
inline void read(int &p){
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

inline ll pow_2(ll a){
	return a*a%Mod;
}

inline ll mypow(ll a,ll b){
	ll inv = 1;
	while( b ){
		if( b&1 )  inv = inv*a%Mod;
		a = pow_2(a);
		b >>= 1;
	}
	return inv;
}

inline ll add(ll a,ll b){
	return a+b>=Mod ? a+b-Mod : a+b;
}

inline ll del(ll a,ll b){
	return a-b>=0 ? a-b : a-b+Mod;
}

int mu[Maxn],phi[Maxn],prim[Maxn],tol;
ll Ans[Maxn];
bool vis[Maxn];

inline void Get(int n){
	int i,j,k;
	phi[1] = 1;
	mu[1] = 1;
	for(i=2;i<=n;++i)
	{
		if( !vis[i] )
			prim[++tol] = i,
			mu[i] = -1,
			phi[i] = i-1;
		for(j=1;j<=tol&&i*prim[j]<=n;j++)
		{
			vis[i*prim[j]] = true;
			if( i%prim[j] == 0 )
			{
				phi[i*prim[j]] = phi[i]*prim[j];
				break;
			}
			else 
				mu[i*prim[j]] = -mu[i],
				phi[i*prim[j]] = phi[i]*(prim[j]-1);
		}
	}
	for(i=2;i<=n;i++)
	  mu[i] += mu[i-1];
	ll ans;
	int l,r;
	for(i=1;i<=n;++i)
	{
		ans = 0;
		for(l=1;l<=i;l=r+1)
		{
			r = i/(i/l);
			ans += (ll)((r-l+1)*(i/l));
		}
		Ans[i] = ans;
	}
}

int main(){
	int T;
	read(T);
	int n,m,Min,nn,mm;
	int i,j,k,d,l,r;
	ll ans;
	Get(Maxn-50); 
	while( T-- )
	{
		read(n),read(m);
		Min = min(n,m);
		ans = 0;
		for(l=1;l<=Min;l=r+1)
		{
			r = min( n/(n/l) , (m/(m/l)) );
			ans += (ll)((mu[r]-mu[l-1])*(ll)(Ans[n/l])*(ll)(Ans[m/l]));
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
