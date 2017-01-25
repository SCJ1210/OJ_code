//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 5005
#define INF 0x3f3f3f3f
int n,m,T;
struct Edge{
	int to,cost;
};
vector<Edge> G[maxn];
int dp[maxn][maxn];
int nx[maxn][maxn];
bool used[maxn];
void dfs(int v)
{
	if(used[v]) return ;
	used[v]=1;
	for(Edge e:G[v])
	{
		if(!used[e.to]) dfs(e.to);
		for(int k=2;k<=n;++k)
		{
			int tp=dp[e.to][k-1]+e.cost;
			if(dp[v][k]<tp) continue;
			dp[v][k]=tp;nx[v][k]=e.to;
		}
	}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	cin>>n>>m>>T;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
	}
	memset(dp,INF,sizeof(dp));
	dp[n][1]=0;
	dfs(1);
	int k;
	for(k=n;k>0;--k) if(dp[1][k]<=T) break;
	cout<<k<<endl;
	for(int v=1;v!=n;v=nx[v][k],--k)
		cout<<v<<' ';
	cout<<n<<endl;
}
