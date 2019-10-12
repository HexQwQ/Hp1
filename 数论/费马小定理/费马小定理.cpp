#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long ll;

using namespace std;

// 求逆元 

ll mypow(ll a,ll b,ll m){
	ll inv = 1;
	while( b ){
		if( b&1 )  inv = inv*a%m;
		a *= a%m;
		b>>=1;
	}
	return inv;
}

int main(int argc,char ** argv){
	ll k,m;    // 求 k 在 MOD m情况下的 逆元  , m为质数 
	cin>>k>>m;
	cout<<mypow(k,m-2,m);
	return 0;
}
