#include<bits/stdc++.h>

using namespace std;

int main(int argc,char ** argv){
	for(int i=1;i<=4;i++){
		int temp = 1 << i;
		for(int t=0;t<temp;t++,cout<<endl)
		{
			cout<<t<<"     ";
			for(int j=0;j<i;j++)
			  if( t&(1<<j) )cout<<1;
			  else cout<<0;
		}
	}
	  
	return 0;
} 
