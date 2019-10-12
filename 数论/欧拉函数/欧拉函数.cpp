#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

const int MAXN = 40010;

void read(int &p){
    int t=0,u=1;
    char c;
    c=getchar();
    while( c != '-' && ( c < '0' || c > '9' ) )
      c=getchar();
    if( c == '-' ){
        u = -1;
        c=getchar();
    }
    while( c >= '0' && c <= '9' )
    {
        t=t*10+c-'0';
        c=getchar();
    }
    p = t*u;
}

using namespace std;

vector<long long> prim;
long long phi[MAXN];
bool vis[MAXN];

void OUT(int n){
    for(int i=1;i<=n;++i)
      cout<<phi[i]<<" ";
}

void Prim(int n){
    int i,j,k;
    phi[1] = 1;
    for(i=2;i<=n;++i)
    {
        if( !vis[i] )  prim.push_back(i),phi[i]=i-1;
        for(j=0;j<prim.size()&&i*prim[j]<=n;++j)
        {
            vis[i*prim[j]] = true;
            if( i%prim[j] == 0 )
            {
                phi[i*prim[j]] = phi[i]*prim[j];
                break;
            }
            else
              phi[i*prim[j]] = phi[i]*(prim[j]-1);
        }
    }
}

int main()
{
    int n,m;
    read(n);
    if( n == 1 )
    {
        cout<<0<<endl;
        return 0;
    }
    Prim(n);
    for(int i=1;i<=n;i++)
	  cout<<phi[i]<<"\n"; 

    return 0;
}
