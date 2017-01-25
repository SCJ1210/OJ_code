//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 1005
struct P{
	int t,x,y;
}p[maxn];
int n,my[maxn];
vector<int> G[maxn];
bool used[maxn];
bool dfs(int v)
{
	for(int u:G[v])
	{
		if(used[u]) continue;
		used[u]=1;
		if(my[u]==-1||dfs(my[u]))
		{
			my[u]=v;return true;
		}
	}
	return false;
}
int max_match()
{
	memset(my,-1,sizeof(my));
	int res=0;
	for(int i=1;i<=n;++i)
	{
		memset(used,0,sizeof(used));
		if(dfs(i)) res++;
	}
	return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<maxn;++i) G[i].clear();
		for(int i=1;i<=n;++i)
			cin>>p[i].t>>p[i].x>>p[i].y;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j&&abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)+p[i].t<=p[j].t) G[i].push_back(j);
		cout<<n-max_match()<<endl;
	}
}
