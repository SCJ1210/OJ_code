//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
int n,m,k,lcm=1;
int q[505][505],p[505][505];
int lx[505],ly[505],my[505],slack_y[505];
bool ux[505],uy[505];
bool dfs(int x)
{
	ux[x]=1;
	for(int y=1;y<=m;++y)
	{
		if(uy[y]) continue;
		int d=lx[x]+ly[y]-q[x][y];
		if(d==0){
			uy[y]=1;
			if(my[y]==-1||dfs(my[y]))
			{
				my[y]=x;
				return true;
			}
		}
		else slack_y[y]=min(slack_y[y],d);
	}
	return false;
}

int KM()
{
	n=m=max(n,m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			lx[i]=max(lx[i],q[i][j]);
	memset(my,-1,sizeof(my));
	for(int x=1;x<=n;++x)
	{
		memset(slack_y,INF,sizeof(slack_y));
		while(1)
		{
			memset(ux,0,sizeof(ux));
			memset(uy,0,sizeof(uy));
			if(dfs(x)) break;
			int MIN=INF;
			for(int i=1;i<=m;++i) if(!uy[i]) MIN=min(MIN,slack_y[i]);
			for(int i=1;i<=n;++i) if(ux[i]) lx[i]-=MIN;
			for(int i=1;i<=m;++i) if(uy[i]) ly[i]+=MIN;
		}
	}
	int res=0;
	for(int i=1;i<=n;++i) res+=lx[i];
	for(int i=1;i<=m;++i) res+=ly[i];
	return res;
}

main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		memset(q,0,sizeof(q));
		memset(p,0,sizeof(p));
		cin>>n>>m>>k;
		for(int i=0;i<k;++i)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			q[a][b]=c;p[a][b]=d;
			lcm*=(d/__gcd(d,lcm));
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(p[i][j]!=0) q[i][j]*=lcm/p[i][j];
		int ans=KM();
		cout<<ans/__gcd(ans,lcm)<<' '<<lcm/__gcd(ans,lcm)<<endl;
	}
}
/*
1
4 3
6
1 1 1 1
1 2 2 1
2 1 2 1
2 2 4 1
3 3 10 1
4 3 15 1

1
3 4 5
1 2 1 2
1 3 1 2
2 1 1 6
2 3 3 4
3 4 2 5

1
2 2 4
1 1 1 1
1 2 2 1
2 1 2 1
2 2 4 1

1
2 2 4
1 1 1 1
1 2 1 1
2 1 1 1
2 2 1 1

3
3 4 5
1 2 1 2
1 3 1 2
2 1 1 6
2 3 3 4
3 4 2 5
2 2 4
1 1 1 1
1 2 2 1
2 1 2 1
2 2 4 1
2 2 4
1 1 1 1
1 2 1 1
2 1 1 1
2 2 1 1
*/
