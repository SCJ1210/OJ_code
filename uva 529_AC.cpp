//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,a[10000]={1},P[30]={1},maxd;

bool dfs(int k)
{
	if(a[k-1]==n) return true;
	if(P[(maxd-k)]*a[k-1]<n) return false;
	for(int i=0;i<k;++i)
	{
		a[k]=a[k-1]+a[i];
		if(dfs(k+1)) return true;
	}
	return false;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	for(int i=1;i<30;++i) P[i]=P[i-1]*2;
	while(cin>>n,n!=0)
	{
		for(maxd=1;;maxd++)
		{
			if(dfs(1)) break;
		}
		for(int i=0;i<maxd;++i)
			if(i) cout<<' '<<a[i];
			else cout<<a[i];
		cout<<endl;
	}
}
