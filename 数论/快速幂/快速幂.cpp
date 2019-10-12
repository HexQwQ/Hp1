#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long ll;

using namespace std;

ll mypow(ll a,ll b,ll m){
	ll inv = 1;
	while( b ){
		if( b&1 )  inv = inv*a%m;
		a = a*a%m;
		b>>=1;
	}
	return inv;
}

int main(int argc,char ** argv){
	ll a,b,m;   // a^b%m
	cin>>a>>b>>m;
	cout<<mypow(a,b,m); 
	return 0;
}
