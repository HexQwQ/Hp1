#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

const int MOD = 1000003;

typedef long long ll;

using namespace std;

void mypow(ll a,ll b,ll m){
	ll inv = 1,ai = 1;
	while( b ){
		
	}
}

ll _2[55],_3[55];
vector<ll> num;
int main(int argc,char ** argv){
	ll n;
	cin>>n;
	ll i,j;
	ll k;
	k = n;
	_2[0] = 1,_3[0] = 1;
	for(i=1;i<=50;i++)
		_2[i] = 2*_2[i-1],
		_3[i] = 3*_3[i-1]%MOD;
	ll ans=0;
	for(i=50;i>=0;i--)
	{
		if( n - _2[i] >= 0 )
		{
			num.push_back(i);
			n -= _2[i];
//			ans += _3[i];
//			ans %= MOD;
		}
		if( n == 0 )
		  break;
	}
	ll _i2 = 1;
	for(i=0;i<num.size();i++)
	{
		ans += _i2*_3[num[i]]%MOD;
		_i2 *= 2;
		ans %= MOD;
	}
	k = ( ( ( (k%MOD) * ((k+1)%MOD) )%MOD)* 500002 + MOD )%MOD;
//	cout<<k<<endl;
	cout<<(k-ans+MOD)%MOD<<endl;
//	for(i=0;i<num.size();i++)
//	  cout<<num[i]<<" ";
	return 0;
}
