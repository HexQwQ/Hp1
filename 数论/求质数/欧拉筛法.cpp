#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int vis[100010];
vector<int> prim;

void Get_prim(int n){
	int i,j,k;
	for(i=2;i<=n;i++)
	{
		if( !vis[i] )  prim.push_back(i);
		for(j=0;j<prim.size()&&i*prim[j]<=n;j++)
		{
			vis[prim[j]*i] = true;
			if( i%prim[j] == 0 )  break;
		}
	}
}

int main(int argc,char ** argv){
	int n;
	cin>>n;
	Get_prim(n);
	for(int i=0;i<prim.size();i++)
	  cout<<prim[i]<<" ";
	return 0;
} 
