//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
struct Edge{
	int x,y,cost,inid;
}es[2005];
bool cmp(Edge a,Edge b)
{
	return a.cost<b.cost;
}
struct PA{
	int to,Eid;
}pa[1005];
vector<PA> G[1005];
int dep[1005];
bool used[1005];
void dfs(int v,int _dep)
{
	used[v]=1;
	dep[v]=_dep;
	for(PA p:G[v])
	{
		if(used[p.to]) continue;
		pa[p.to]={v,p.Eid};
		dfs(p.to,_dep+1);
	}
}
long long ans=0;
void cal(int &a,int &c)
{
	if(es[ pa[a].Eid ].cost> c )
	{
		ans+=es[ pa[a].Eid ].cost-c;
		es[ pa[a].Eid ].cost=c;
	}
	a=pa[a].to;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b,c;cin>>a>>b>>c;
		es[i]={a,b,c,i};
	}
	sort(es,es+m,cmp);
	for(int i=0;i<m;++i)
	{
		if(es[i].inid<n-1){
			int a=es[i].x,b=es[i].y;
			G[a].push_back({b,i});
			G[b].push_back({a,i});
		}
	}
	dfs(0,0);
	for(int r=0;r<m;++r)
	{
		int a=es[r].x,b=es[r].y,c=es[r].cost;
		if(dep[a]<dep[b]) swap(a,b);
		while(dep[a]!=dep[b]) cal(a,c);
		while(a!=b) cal(a,c),cal(b,c);
	}
	cout<<ans<<endl;
}
/*
5 6
0 1 5
0 2 6
1 3 7
1 4 8
2 1 5
0 3 8

4 4
0 3 10
0 1 11
1 2 12
2 3 2

*/
