#include<iostream>
#include<cmath>

using namespace std;

int a[2333][2333];

int main(){
	int n;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
		a[i][1] = 1,a[i][i] = 1;
	for(i=3;i<=n;i++)
	  for(j=2;j<i;j++)
	    a[i][j] = a[i-1][j] + a[i-1][j-1];
	int _2=0,_1=0,_ans1=0,_ans2=0; 
	for(i=1;i<=n;i++,cout<<"     "<<_2<<" "<<_1<<" "<<_ans1<<" "<<_ans2<<endl,_2=0,_1=0)
	  for(j=1;j<=i;j++)
	  {
	  	cout<<a[i][j]<<" ";
	  	if( a[i][j]&1 )  _1++,_ans1++;
	  	else _2++,_ans2++;
	  } 
	    
	return 0;
}
