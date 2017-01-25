//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 2500
#define INF 0x3f3f3f3f
int n,m;
struct Edge{
	int to,cost,cap,rev;
};
vector<Edge> G[maxn];
void add_edge(int from,int to,int cost,int cap)
{
	G[from].push_back({to,cost,cap,G[to].size()});
	G[to].push_back({from,-cost,0,G[from].size()-1});
}
int prevv[maxn],preve[maxn],dis[maxn];
int min_cost_flow(int S,int T,int limit)//min_cost_flow
{
	int ans=0;
	while(1)
	{
		if(limit==0) break;
		memset(dis,INF,sizeof(dis));dis[S]=0;
		for(int r=0;r<n*2;++r)
		{
			for(int i=1;i<=n*2;++i)
			{
				for(int j=0;j<G[i].size();++j)
				{
					Edge e=G[i][j];
					if(e.cap<=0) continue;

					if(dis[e.to]>dis[i]+e.cost){
						dis[e.to]=dis[i]+e.cost;
						prevv[e.to]=i;preve[e.to]=j;
					}
				}
			}
		}
		if(dis[T]==INF) break;
		int f=INF,cost=0;
		for(int i=T;i!=S;i=prevv[i])
		{
			f=min(f,G[prevv[i]][preve[i]].cap);
			cost+=G[prevv[i]][preve[i]].cost;
		}
		for(int i=T;i!=S;i=prevv[i])
		{
			Edge &e=G[prevv[i]][preve[i]];
			e.cap-=f;G[e.to][e.rev].cap+=f;
		}
		ans+=f*cost;
		limit-=f;
	}
	return ans;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

	while(cin>>n>>m)
	{
		for(int i=0;i<maxn;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int a,b,c;cin>>a>>b>>c;
			add_edge(a+n,b,c,1);
		}
		for(int i=1;i<=n;++i) add_edge(i,i+n,0,1);
		cout<<min_cost_flow(1+n,n,2)<<endl;
	}
}
/*
6 11
1 2 23
1 3 12
1 4 99
2 5 17
2 6 73
3 5 3
3 6 21
4 6 8
5 2 33
5 4 5
6 5 20
*/
