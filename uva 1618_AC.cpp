//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 5005
int n,aa[maxn],a[maxn],pos[maxn],MAX[15][maxn],MIN[15][maxn],tp[maxn];
void build()
{
//	map<int,int> mp;
//	sort(aa+1,aa+n+1);
//	for(int i=1;i<=n;++i) mp[aa[i]]=i;
//	for(int i=1;i<=n;++i) a[i]=mp[a[i]],pos[a[i]]=i;

	sort(aa+1,aa+n+1);
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(aa+1,aa+n+1,a[i])-aa,pos[a[i]]=i;
//	cout<<"build : ";
//	for(int i=1;i<=n;++i) cout<<a[i]<<' ';cout<<endl;
	for(int j=1;j<=n;++j) MAX[0][j]=pos[j],MIN[0][j]=a[j];
	for(int i=1;i<15;++i)
		for(int j=1;j<=n;++j)
			MAX[i][j]=max(MAX[i-1][j],MAX[i-1][j+(1<<(i-1))]),
			MIN[i][j]=min(MIN[i-1][j],MIN[i-1][j+(1<<(i-1))]);
}
int query_max(int l,int r)
{
	int lg=log2(r-l+1);
	return max(MAX[lg][l],MAX[lg][r-(1<<lg)+1]);
}
int query_min(int l,int r)
{
	int lg=log2(r-l+1);
	return min(MIN[lg][l],MIN[lg][r-(1<<lg)+1]);
}

bool solve()
{
	for(int p=1;p<=n;++p)
		for(int q=p+1;q<=n-1;++q)
			if(a[p]<a[q])
			{
				if(a[p]>=a[q]-1) continue;
				int s=query_max(a[p]+1,a[q]-1);
				if(s<=q+1) continue;
				int r=query_min(q+1,s-1);
				if(r<a[p]) 	return true;
			}
	return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int test;cin>>test;
	while(test--)
	{
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i],tp[i]=aa[i]=a[i];
		build();
		bool ans=0;
		if(solve()) ans=1;
		else{
			for(int i=1;i<=n;++i) aa[i]=a[i]=tp[n-i+1];
			build();
			if(solve()) ans=1;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
