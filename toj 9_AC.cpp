//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 10004
#define INF 0x1f1f1f1f
int x[maxn],MIN,n,m,s;
vector<int> G[maxn];
int dfs(int v)
{
	if(x[v]==MIN) return 0;
	int to=v;
	for(int u:G[v])
		if(x[u]<x[to]) to=u;
	if(to==v) return INF;
	return dfs(to)+1;
}
int d[maxn];
int bfs()
{
	memset(d,INF,sizeof(d));d[s]=0;
	queue<int> Q;Q.push(s);
	while(Q.size())
	{
		int to=Q.front();Q.pop();
		if(x[to]==MIN) return d[to];
		for(int u:G[to])
			if(d[u]==INF) d[u]=d[to]+1,Q.push(u);
	}
	return INF;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int ca=1;ca<=T;++ca)
	{
		cin>>n>>m>>s;
		MIN=INF;
		for(int i=0;i<n;++i) cin>>x[i],MIN=min(MIN,x[i]);
		for(int i=0;i<m;++i)
		{
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int x=dfs(s),y=bfs();
		cout<<"Case #"<<ca<<": ";
		if(y>=INF) cout<<"Call 119!"<<endl;
		else if(x>=INF) cout<<y*6<<endl;
		else cout<<abs(x-y*6)<<endl;
		for(int i=0;i<n;++i) G[i].clear();
	}
}
