#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int gcd(int a,int b){
	if( b > a )  swap(a,b);
	if( b == 0 )  return a;
	return gcd(b,a%b);
}

int main(int argc,char ** argv){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
