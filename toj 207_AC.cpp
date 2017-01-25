//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 20005
#define maxm 130005
#define INF 1000000000
struct EDGE{
	int a,b,cost;
	bool operator < (EDGE const &rhs)const{
		return cost<rhs.cost;
	}
}es[maxm];
struct GEdge{
	int to,cost;
}pa[20][maxn];
vector<GEdge> G[maxn];
bool us[maxm];
int p[maxn],dep[maxn];
int find(int x)
{
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
void U(int x,int y)
{
	x=find(x);y=find(y);
	p[x]=y;
}
void dfs(int v,int fa,int _dep)
{
	dep[v]=_dep;
	for(GEdge e:G[v])
	{
		if(e.to==fa) continue;
		dfs(e.to,v,_dep+1);
		pa[0][e.to]={v,e.cost};
	}
}
int lca(int a,int b)//return max_value
{
	if(dep[a]<dep[b]) swap(a,b);//dep[a]>=dep[b]
	int res=0;
	for(int i=19;i>=0;--i)
		if(pa[i][a].to!=-1&&dep[ pa[i][a].to ]>= dep[b] )
			res=max(res,pa[i][a].cost),a=pa[i][a].to;
	if(a==b) return res;
	for(int i=19;i>=0;--i)
	{
		if(pa[i][a].to!=pa[i][b].to)
		{
			res=max({res,pa[i][a].cost,pa[i][b].cost});
			a=pa[i][a].to,b=pa[i][b].to;
		}
	}
	res=max({res,pa[0][a].cost,pa[0][b].cost});
	return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		for(int i=0;i<maxn;++i) G[i].clear();
		int n,m;cin>>n>>m;
		for(int i=0;i<m;++i) cin>>es[i].a>>es[i].b>>es[i].cost;
		for(int i=0;i<=n;++i) p[i]=i;
		memset(us,0,sizeof(us));
		sort(es,es+m);
		for(int i=0;i<m;++i)
		{
			EDGE e=es[i];
			if(find(e.a)==find(e.b)) continue;
			U(e.a,e.b);us[i]=1;
			G[e.a].push_back({e.b,e.cost});
			G[e.b].push_back({e.a,e.cost});
		}
		for(int i=0;i<20;++i)
			for(int j=0;j<=n;++j) pa[i][j].to=-1;
		dfs(0,-1,0);
		for(int i=1;i<20;++i)
			for(int j=0;j<n;++j){
				pa[i][j].to=pa[i-1][pa[i-1][j].to].to;
				pa[i][j].cost=max(pa[i-1][pa[i-1][j].to].cost,pa[i-1][j].cost);
			}
		int ans=INF;
		for(int i=0;i<m;++i)
		{
			if(us[i]) continue;
			EDGE e=es[i];
			int tp=e.cost-lca(e.a,e.b);
			if(tp) ans=min(ans,tp);
		}
		cout<<ans<<endl;
	}
}
/*
1
4 6
0 1 1
2 0 2
3 1 8
3 0 7
1 2 6
2 3 10

1
3 4
0 1 3
2 1 4
0 2 6
1 2 5

2
3 4
0 1 3
2 1 4
0 2 6
1 2 5
5 5
0 1 1
1 2 3
3 2 4
3 4 8
0 4 10

1
6 7
0 1 1
0 2 2
1 3 3
1 4 4
2 5 5
5 3 6
1 3 7
*/
