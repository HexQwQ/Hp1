#include<bits/stdc++.h>

using namespace std;

int n,prim[233];
bool book[233];
long long m, ans = 0;

bool dfs(long long x,int f,int p){
	if( x <= m/prim[p] )  ans += m/x/prim[p]*f;
	else return false;
	for(int i=p+1;i<=n;i++)
	{
		book[i] = true;
		bool flag = dfs(x*prim[p],f*(-1),i);
		book[i] = false;
		if( flag == false )  return true;
	}
	return true;
}

int main(int argc,char ** argv){
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&prim[i]);
	sort(prim+1,prim+1+n);
	for(int i=1;i<=n;i++)
	{
		book[i] = true;
		dfs(1,1,i);
		book[i] = false;
	}
	printf("%lld",ans);
	return 0;
}
/*
1 7 11 13 17 19 23 29 
*/
