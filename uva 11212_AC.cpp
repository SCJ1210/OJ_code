//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
unordered_map<string , int> mp;
string S;
int maxd,n;
int check()
{
	int res=0;
	for(int i=1;i<n;++i)
		if(S[i]!=S[i-1]+1) res++;
	return res;
}
bool dfs(int dep)
{
	if(mp.find(S)!=mp.end() && mp[S]<=dep) return false;
	mp[S]=dep;
	int cnt=check();
	if((maxd-dep)*3<cnt) return false;
	if(dep==maxd)
	{
		if(cnt==0) return true;
		return false;
	}

	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			string tp=S;
			for(int k=j;k<n;++k)//insert after
			{
				int e=0;
				for(int r=0;r<i;++r) S[e++]=tp[r];
				for(int r=j+1;r<=k;++r) S[e++]=tp[r];
				for(int r=i;r<=j;++r) S[e++]=tp[r];
				for(int r=k+1;r<n;++r) S[e++]=tp[r];
				if(dfs(dep+1))return true;
				S=tp;
			}
		}
	}
	return false;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int ca=1;
	while(cin>>n,n!=0)
	{
		S.resize(n);
		for(int i=0;i<n;++i) cin>>S[i];
		for(maxd=0;;maxd++)
		{
			mp.clear();
			if(dfs(0)){
				cout<<"Case "<<ca++<<": "<<maxd<<endl;
				break;
			}
		}
	}
}
