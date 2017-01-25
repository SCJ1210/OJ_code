//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 105
#define INF 0x3f3f3f3f
int n,dis[maxn][maxn];
vector<int> G[maxn];
int lx[maxn],ly[maxn],match_y[maxn],slack_y[maxn];
bool vx[maxn],vy[maxn];
bool dfs(int x)
{
	vx[x]=1;
	for(int y:G[x])
	{
		if(dis[x][y]==INF) continue;
		if(vy[y]) continue;
		int d=lx[x]+ly[y]-dis[x][y];
		if(d==0){
			vy[y]=1;
			if(match_y[y]==-1||dfs(match_y[y]))
			{
				match_y[y]=x;
				return true;
			}
		}
		else slack_y[y]=min(slack_y[y],d);
	}
	return false;
}

int KM()
{
	memset(match_y,-1,sizeof(match_y));
	memset(lx,-INF,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int x=1;x<=n;++x)
		for(int y=1;y<=n;++y)
			lx[x]=max(lx[x],(dis[x][y]==INF?-INF:dis[x][y]));
	for(int x=1;x<=n;++x)
	{
		memset(slack_y,INF,sizeof(slack_y));
		while(1)
		{
			memset(vx,0,sizeof(vx));
			memset(vy,0,sizeof(vy));
			if(dfs(x)) break;
			int MIN=INF;
			for(int i=1;i<=n;++i)
				if(!vy[i]) MIN=min(MIN,slack_y[i]);
			if(MIN==INF) return INF;
			for(int i=1;i<=n;++i) if(vx[i]) lx[i]-=MIN;
			for(int i=1;i<=n;++i) if(vy[i]) ly[i]+=MIN;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans+=lx[i]+ly[i];
	return ans;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	while(cin>>n,n!=0)
	{
		memset(dis,INF,sizeof(dis));
		for(int i=1;i<=n;++i)
		{
			int a,b;
			while(cin>>a,a!=0)
			{
				cin>>b;
				if(dis[i][a]==INF) dis[i][a]=-b;
				else dis[i][a]=max(-b,dis[i][a]);
				G[i].push_back(a);
			}
		}
		int ans=KM();
		if(ans==INF) cout<<"N"<<endl;
		else cout<<-ans<<endl;
	}
}
/*
3
2 2 3 1 0
1 1 3 2 0
1 3 2 7 0
8
2 3 3 1 0
3 3 1 1 4 4 0
1 2 2 7 0
5 4 6 7 0
4 4 3 9 0
7 4 8 5 0
6 2 5 8 8 1 0
6 6 7 2 0
3
2 1 0
3 1 0
2 1 0
0
*/
