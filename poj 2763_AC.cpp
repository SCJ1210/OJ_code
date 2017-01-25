//By SCJ
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define endl '\n'
#define maxn 100005
struct Edge{
	int to,cost,Eid;
	Edge(int a,int b,int c){to=a;cost=b;Eid=c;}
};
vector<Edge> G[maxn];
int n,q,s,bit[maxn*2],dep[maxn],now[maxn*2];
int in[maxn],ck=0;
int pos[maxn],neg[maxn];
int p[20][maxn];
void add(int i,int c)
{
	while(i<=2*n)
	{
		bit[i]+=c;
		i+=(i&-i);
	}
}

int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=bit[i];
		i-=(i&-i);
	}
	return res;
}
bool used[maxn];
void dfs(int v,int _dep,int cost)
{
//	cout<<v<<' '<<ck<<endl;
	used[v]=1;
	in[v]=++ck;
	dep[v]=_dep;
	now[ck]=cost;
	for(int i=0;i<G[v].size();++i)
	{
		Edge e=G[v][i];
		if(used[e.to]) continue;
		pos[e.Eid]=ck+1;
		dfs(e.to,_dep+1,e.cost);
		p[0][e.to]=v;
		neg[e.Eid]=++ck;
		now[ck]=-e.cost;
	}
//	cout<<"end v="<<v<<endl;
}

int lca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);//dep[a]>dep[b]
	for(int i=16;i>=0;--i)
		if(dep[a]-(1<<i)>=dep[b]) a=p[i][a];
	if(a==b) return a;
	for(int i=16;i>=0;--i)
		if(p[i][a]!=p[i][b]) a=p[i][a],b=p[i][b];
	return p[0][a];
}

int main()
{
//ios::sync_with_stdio(0);
//cin.tie(0);

//	while(~scanf("%d%d%d",&n,&q,&s))
//	while(cin>>n>>q>>s)
//	{
		scanf("%d%d%d",&n,&q,&s);

		for(int i=0;i<=n;++i) G[i].clear();
		memset(bit,0,sizeof(bit));
		memset(used,0,sizeof(used));
		for(int i=1;i<n;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
//			cin>>a>>b>>c;
			G[a].push_back(Edge(b,c,i));
			G[b].push_back(Edge(a,c,i));
		}
		memset(p,-1,sizeof(p));
		dfs(1,0,0);
		for(int i=1;i<=ck;++i) add(i,now[i]);
		for(int i=0;i<16;++i)
			for(int j=1;j<=n;++j)
			{
				if(p[i][j]!=-1) p[i+1][j]=p[i][p[i][j]];
			}
		while(q--)
		{
			int type;
			scanf("%d",&type);
//			cin>>type;
			if(type)
			{
				int a,b;
				scanf("%d%d",&a,&b);
//				cin>>a>>b;
				int x=pos[a],y=neg[a];
				add(x,b-now[x]);now[x]=b;
				add(y,-b-now[y]);now[y]=-b;
			}
			else
			{
				int to;
				scanf("%d",&to);
//				cin>>to;
				int LCA=lca(s,to),ans=0;
				ans+=sum(in[s])-sum(in[LCA]);
				ans+=sum(in[to])-sum(in[LCA]);
				printf("%d\n",ans);
//				cout<<ans<<endl;
				s=to;
			}
	//	cout<<"bit : ";
	//	for(int i=1;i<=ck;++i) cout<<sum(i)<<' ';cout<<endl;
		}

//	}

}
/*
6 6 1
1 2 2
2 4 5
2 5 3
5 6 1
1 3 4
*/
