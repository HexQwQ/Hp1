#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[20] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},T;
ll n;
int dfs(ll num,int pos,int k,int ans) { //numΪ��ǰ����ֵ��posΪ��ǰ������λ�ã�kΪ��ǰ�����ĸ���,ansΪ��ǰ���ӵĸ���
	if(pos>15) return 0;
	int ret=ans;
	for(int i=1; i<=k; ++i) {
		if(n/p[pos]<num) break;//�����
		num*=p[pos];
 
		ret=max(ret,dfs(num,pos+1,i,ans*(i+1)));
	}
	return ret;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		printf("%d\n",dfs(1,1,64,1));
	}
	return 0;

}
