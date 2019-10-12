#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>

using namespace std;

multiset<int> a;
multiset<int>::iterator it;

int In(int x){
	a.insert(x);
}

int main(int argc,char ** argv){
	it = a.begin();
	cout<<it;
	
	return 0;
}
