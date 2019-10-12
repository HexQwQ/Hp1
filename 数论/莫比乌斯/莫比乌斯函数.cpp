#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

const int SIZE = 100010; 

using namespace std;

int vis[SIZE],mu[SIZE];
vector<int> prim;

void get_mu(int n){
	int i,j,k;
	mu[1] = 1;
	for(i=2;i<=n;++i)
	{
		if( !vis[i] )
		{
			prim.push_back(i);
			mu[i] = -1;
		}
		for(j=0;j<prim.size()&&i*prim[j]<=n;j++)
		{
			vis[i*prim[j]] = true;
			if( i%prim[j] == 0 )  break;
			mu[i*prim[j]] = -1*mu[i];
		}
	}
}

int main(int argc,char ** argv){
	int n;
	cin>>n;
	get_mu(n);
	for(int i=2;i<=n;i++)
	  cout<<i<<" | "<<vis[i]<<" "<<mu[i]<<endl;
	return 0;
}
