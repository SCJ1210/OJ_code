//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 200005
#define MOD 1000000007
int P[maxn]={1},dep[maxn];
vector<int> G[maxn];
bool used[maxn];
int cnt=0,circle;
void traval(int v)
{
	used[v]=1;cnt++;
	for(int i:G[v])
		if(used[i]==0) traval(i);
}
void dfs(int v,int depth,int pa)
{
	if(dep[v])
	{
		circle=depth-dep[v];
		return ;
	}
	bool firpa=1;dep[v]=depth;
	for(int i:G[v])
	{
		if(firpa&&i==pa){firpa=0;continue;}
		dfs(i,depth+1,v);
		if(circle) return ;
	}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;++i) P[i]=(P[i-1]*2)%MOD;
	for(int i=1;i<=n;++i)
	{
		int to;cin>>to;
		G[i].push_back(to);
		G[to].push_back(i);
	}
	long long ans=1;
	for(int i=1;i<=n;++i)
	{
		if(used[i]) continue;
		cnt=circle=0;
		traval(i);
		dfs(i,1,-1);
		int tp=((P[cnt]-P[cnt-circle]*2)%MOD+MOD)%MOD;
		ans=(ans*tp)%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
}
