//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 100005
struct Edge{
	int to,cost,id;
};
vector<Edge> G[maxn];
int n,q,s,in[maxn],out[maxn],now[maxn*2];
int bit[maxn*2],en[maxn],ck=0;
bool used[maxn];
void add(int x,int c)
{
	while(x<=n*2)
	{
		bit[x]+=c;
		x+=(x&-x);
	}
}
int sum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=(x&-x);
	}
	return res;
}
void dfs(int v,int cost)
{
	used[v]=1;
	in[v]=++ck;
	now[ck]=cost;
	for(Edge e:G[v])
	{
		if(used[e.to]) continue;
		dfs(e.to,e.cost);
		en[e.id]=e.to;
	}
	out[v]=++ck;
	now[ck]=-cost;
}
int main()
{
//ios::sync_with_stdio(0);
//cin.tie(0);
	cin>>n>>q>>s;
	for(int i=1;i<n;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c,i});
		G[b].push_back({a,c,i});
	}
	dfs(1,0);
	for(int i=1;i<=ck;++i)
		add(i,now[i]);
		cout<<"en : ";
	for(int i=1;i<n;++i) cout<<en[i]<<' ';cout<<endl;
	while(q--)
	{
		int type;cin>>type;
		if(type)
		{
			int a,b;cin>>a>>b;
			int u=in[en[a]];
			add(u,b-now[u]);
			now[u]=b;
		}
		else
		{
			int to;cin>>to;
			cout<<sum(out[to]-1)-sum(in[s]+1)<<endl;
			s=to;
		}
	}
}
