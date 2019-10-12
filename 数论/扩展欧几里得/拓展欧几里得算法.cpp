#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int exgcd(int a,int b,int &x,int &y){
	if( b == 0 )
	{
		x = 1;
		y = 0;
		return a;
	}
	  
	int d = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t-a/b*y;
	return d;
}

int main(int argc,char ** argv){
	int a,b,x,y;
	cin>>a>>b;
	cout<<exgcd(a,b,x,y)<<endl;
	cout<<x<<" "<<y;
	return 0;
}
