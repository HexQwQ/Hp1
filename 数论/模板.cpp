#include<bits/stdc++.h>
#include<tr1/unordered_map> 

using namespace std;

const int Maxn = 1e7;
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

int tol,N;
ll phi[Maxn+10],mu[Maxn+10],prim[Maxn+10];
bool vis[Maxn+10];
tr1::unordered_map<ll,ll> Phi;
tr1::unordered_map<int,int> Mu;

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
	for(i=1;i<=20;i++)
	  cout<<mu[i]<<"    "<<phi[i]<<endl;
}

int main(){
	Get(Maxn);
	return 0;
} 
