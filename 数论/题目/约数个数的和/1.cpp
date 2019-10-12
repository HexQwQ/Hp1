#include<bits/stdc++.h>

using namespace std;

int main(int argc,char ** argv){
	int n;
	scanf("%d",&n);
	long long ans = 0;
	for(int l=1,r;l<=n;l=r+1)
	{
		r = n/(n/l);
		ans += 1LL*(n/l)*(r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
