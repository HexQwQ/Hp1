#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6;

ll M[maxn+10],C[maxn+10],n;

ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b,a%b);  
}

ll exgcd(ll a,ll b,ll &x,ll &y){
	if( b == 0 )
	{
		x = 1,y = 0;
		return a;
	}
	ll r = exgcd(b,a%b,x,y),tmp;
	tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return r;
}

ll inv(ll a,ll b){
	ll r,x,y;
	r = exgcd(a,b,x,y);
	while( x < 0 )  x+=b;
	return x;
}

int main(int argc,char ** argv){
	int T = 1;
//	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll i,j,k;
		for(i=1;i<=n;i++)
			scanf("%lld %lld",&M[i],&C[i]);
		bool flag = true;
		for(i=2;i<=n;i++)
		{
			ll M1 = M[i-1],M2 = M[i],C1 = C[i-1],C2 = C[i],t = gcd(M1,M2);
			if( (C2-C1)%t != 0 )
			{
				flag = false;
				break;
			}
			M[i] = M1/t*M2;
			C[i] = ( (inv(M1/t,M2/t))*(C2-C1)/t )%(M2/t)*M1+C1;
			C[i] = (C[i]%M[i]+M[i])%M[i];
		}
		printf("%lld\n",flag?C[n]:-1);
	}
	return 0;
}
