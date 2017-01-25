//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
deque<int> dq;
int n,maxd,P[30]={1};
bool dfs(int dep)
{
	if(dep==maxd) return false;
	if(P[maxd-dep]*dq[dep]<n) return false;
	if(dq[dep]<n){
		for(int i=0;i<=dep;++i)
		{
			int x=dq[dep]+dq[i];
			//printf("i=%d  x=%d\n",i,x);
			//if(st.find(x)!=st.end()) continue;
			if(x==n) return true;
			dq.push_back(x);
			if(dfs(dep+1))return true;
			dq.pop_back();
		}
	}

	for(int i=0;i<=dep;++i)
	{
		int x=dq[dep]-dq[i];
		//if(st.find(x)!=st.end()) continue;
		if(x==n) return true;
		dq.push_front(x);
		if(dfs(dep+1))return true;
		dq.pop_front();
	}
	return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

	for(int i=1;i<30;++i) P[i]=P[i-1]*2;
	while(cin>>n,n!=0)
//	for(n=1;n<=1000;++n)
	{
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(maxd=1;;maxd++)
		{
			dq.clear();dq.push_back(1);
			if(dfs(0)){
				cout<<maxd<<endl;
				break;
			}
		}
	}
}
