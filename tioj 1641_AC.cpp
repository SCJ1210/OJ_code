//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 10004
#define INF 1e305
long double d[maxn];
struct P{
	int to;
	long double cost;
	bool operator < (P const x)const{
		return cost>x.cost;
	}
};
vector<P> G[maxn];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	priority_queue<P> pq;
	for(int i=0;i<=n;++i) d[i]=INF;
	d[s]=1;
	cout<<"D[2]="<<d[2]<<endl;
	pq.push({s,0});
	while(pq.size())
	{
		P r=pq.top();pq.pop();
		int v=r.to;
		if(d[v]<r.cost) continue;
		for(P e:G[v])
		{
			if(d[e.to]<=d[v]+d[v]*e.cost) continue;
			d[e.to]=d[v]+d[v]*e.cost;
			pq.push({e.to,d[e.to]});
		}
	}
	cout<<scientific<<setprecision(2)<<d[t]<<endl;
}
