#include<bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

typedef long long ll;

const int maxn = 5e6;

int mu[maxn+10],prim[maxn+10],d[maxn+10],nums[maxn+10],s[maxn+10],tol;
bool vis[maxn+10];

tr1::unordered_map<int,int> S;

void get(int n){
	mu[1] = 1;
	int i,j,k;
	for(i=2;i<=n;++i)
	{
		if( !vis[i] )
		{
			mu[i] = -1;
			prim[++tol] = i;
			nums[i] = 1;
			d[i] = 2;
		}
		for(j=1;j<=tol&&i*prim[j]<=n;++j)
		{
			vis[i*prim[j]] = true;
			if( i%prim[j] == 0 )
			{
				nums[i*prim[j]] = nums[i] + 1;
				d[i*prim[j]] = d[i]/(nums[i]+1)*(nums[i*prim[j]]+1);
				break;
			}
			mu[i*prim[j]] = -mu[i];
			d[i*prim[j]] = d[i]*d[prim[j]];
			nums[i*prim[j]] = 1;
		}
	}	
	for(i=2;i<=n;++i)
	  d[i] += d[i-1];
}

void get_s(int n){
	int i,j,k;
	for(i=1;i<=n;++i)
	  for(j=i;j<=n;j+=i)
	    s[j] += mu[i]*mu[j/i];
}

ll Sn(ll n){
	if( n <= maxn )  return s[n];
	if( S.count(n) )  return S[n];
	ll ans = 2*n;
	for(ll l=2,r;l<=n;l=r+1)
	{
		r = n/(n/l);
		ans -= ()
	}
}

int main(int argc,char ** argv){
	get(maxn);
	get_s(maxn);
	Sn(1e10);
	return 0;
}
