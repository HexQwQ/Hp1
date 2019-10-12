#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include <tr1/unordered_map>
typedef long long ll;
using namespace std;
using namespace std::tr1;
 
const int P=1000000007;
const int maxn=10000000;
 
int prime[1000000],num;
int vst[maxn+5],miu[maxn+5];
 
inline void Pre(){
  miu[1]=1;
  for (int i=2;i<=maxn;i++){
    if (!vst[i]) prime[++num]=i,miu[i]=-1;
    for (int j=1;j<=num && (ll)i*prime[j]<=maxn;j++){
      vst[i*prime[j]]=1;
      if (i%prime[j]==0){
	miu[i*prime[j]]=0;
	break;
      }
      miu[i*prime[j]]=miu[i]*miu[prime[j]];
    }
  }
  for (int i=1;i<=maxn;i++) miu[i]=(miu[i]+miu[i-1]+P)%P;
}
 
unordered_map<ll,int> S;
 
inline int Sum(ll n){
  if (n<=maxn) return miu[n];
  if (S.find(n)!=S.end()) return S[n];
  int tem=1; ll l,r;
  for (l=2;l*l<=n;l++) (tem+=P-Sum(n/l))%=P;
  for (ll t=n/l;l<=n;l=r+1,t--)
    r=n/t,(tem+=P-(r-l+1)*Sum(t)%P)%=P;
  return S[n]=tem;
}
 
inline ll sum(ll n){
  ll tem=0; ll l,r;
  for (l=1;l*l<=n;l++) (tem+=n/l)%=P;
  for (ll t=n/l;l<=n;l=r+1,t--)
    r=n/t,(tem+=(r-l+1)*(n/l)%P)%=P;
  return (ll)tem*tem%P;
}
 
int main(){
  ll n,l,r; ll Ans=0;
//  freopen("t.in","r",stdin);
//  freopen("t.out","w",stdout);
  Pre();
  scanf("%lld",&n);
  for (l=1;l*l<=n;l++) (Ans+=(ll)(Sum(l)+P-Sum(l-1))%P*sum(n/l)%P)%=P;
  for (ll t=n/l;l<=n;l=r+1,t--)
    r=n/t,(Ans+=(ll)(Sum(r)+P-Sum(l-1))%P*sum(n/l)%P)%=P;
  printf("%d\n",Ans);
  return 0;
}

