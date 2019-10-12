#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

const int SIZE = 10010;

using namespace std;

int vis[SIZE],mu[SIZE];
vector<int> prim;

void get_prim(int n){
	int i,j,k;
	mu[1] = 1;
	for(i=2;i<=n;i++)
	{
		if( !vis[i] ) 
		{
			prim.push_back(i);
			mu[i] = -1;
		}
		for(j=0;j<prim.size()&&i*prim[j]<=n;j++)
		{
			vis[prim[j]*i] = true;
			if( i%prim[j] == 0 )
			  break;
			else mu[i*prim[j]] = -1*mu[i];
		}
	}
	for(i=2;i<=n;i++)
	{
		cout<<i<<" "<<vis[i]<<" "<<mu[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	get_prim(n);
	return 0;
} 
