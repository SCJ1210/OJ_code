//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 50005
#define INF 1000000000
vector<int> G[maxn],rG[maxn];
bool used[maxn],in[maxn];
int mv[maxn],scc[maxn],ck=0,sccnum=0,cnt=0;//ck,sccnum -> start with 1
stack<int> st;
void dfs(int v)
{
	used[v]=1;
	for(int u:G[v])
		if(!used[u]) dfs(u);
	mv[++ck]=v;
}
void rdfs(int v)
{
	used[v]=1;cnt++;
	st.push(v);
	scc[v]=sccnum;
	for(int u:rG[v])
		if(!used[u]) rdfs(u);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int a,b;cin>>a>>b;
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;++i)
	{
		if(used[i]) continue;
		dfs(i);
	}
	memset(used,0,sizeof(used));
	memset(in,0,sizeof(in));
	int MAX=0,ans1=INF,ans2=0,startv;
	for(int i=n;i>0;--i)
	{
		if(used[mv[i]]) continue;
		sccnum++;cnt=0;
		rdfs(mv[i]);
		if(MAX==cnt)
		{
			while(st.size()) ans1=min(ans1,st.top()),st.pop();
		}
		else if(MAX<cnt)
		{
			MAX=cnt;
			ans1=INF;
			while(st.size()) ans1=min(ans1,st.top()),st.pop();
		}
	}
	for(int i=1;i<=n;++i)
		for(int u:G[i]) in[scc[u]]=1;
	for(int i=1;i<=sccnum;++i)
		if(!in[i]) ans2++;
	if(!in[scc[ans1]]) ans2--;
	cout<<ans1<<' '<<ans2<<endl;
}
