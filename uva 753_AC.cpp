//By SCJ
//pay attention: type not a char. FUCK YOU !!!!!!!!!!!!!!!!!!!!!!!!!
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 10000000
#define maxn 1005
unordered_map<string,int> mp;
int CNT=0;
int ID(string s)
{
	if(mp[s]==0) mp[s]=++CNT;
	return mp[s];
}
const int S=0;
const int T=1000;

struct Edge{
	int to,cap,rev;
};
vector<Edge> G[maxn];
void add_edge(int from,int to,int cap)
{
//	cout<<"  add  from="<<from<<"  to="<<to<<"  cap="<<cap<<endl;
	G[from].push_back({to,cap,G[to].size()});
	G[to].push_back({from,0,G[from].size()-1});
}
bool floyd[maxn][maxn],used[maxn],HA[maxn],HB[maxn];

int dfs(int v,int f)
{
//	cout<<"  dfs v="<<v<<endl;
	if(v==T) return f;
	used[v]=1;
	for(Edge &e:G[v])
	{
//		cout<<v<<"   "<<e.to<<"  "<<e.cap<<"  used[e.to]="<<used[e.to]<<endl;
		if(used[e.to]||e.cap<=0) continue;
		int d=dfs(e.to,min(f,e.cap));
		if(d){
			e.cap-=d;
			G[e.to][e.rev].cap+=d;
			return d;
		}
	}
	return 0;
}

int max_flow()
{
	int res=0,d;
	while(1){
		memset(used,0,sizeof(used));
		d=dfs(S,INF);
		if(d==0) break;
		res+=d;
	}
	return res;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("753.in","r",stdin);
//freopen("753.out","w",stdout);
	int test;cin>>test;
	while(test--)
	{
		CNT=0;
		int n,m,k;cin>>n;
		mp.clear();
		memset(HA,0,sizeof(HA));
		memset(HB,0,sizeof(HB));
		memset(floyd,0,sizeof(floyd));
		for(int i=0;i<maxn;++i) G[i].clear();
		for(int i=0;i<n;++i)
		{
			string s;cin>>s;
			int d=ID(s);HB[d]=1;
			add_edge(d+500,T,1);
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			string s,c;
			cin>>s>>c;
			int d=ID(c);HA[d]=1;
			add_edge(S,d,1);
		}
		cin>>k;
		for(int i=0;i<k;++i)
		{
			string aa,bb;cin>>aa>>bb;
			int a=ID(aa),b=ID(bb);
			floyd[a][b]=1;
		}
		for(int i=1;i<maxn/2;++i) floyd[i][i]=1;
		for(int k=1;k<maxn/2;++k)
			for(int i=1;i<maxn/2;++i)
				for(int j=1;j<maxn/2;++j)
					floyd[i][j]|=(floyd[i][k]&&floyd[k][j]);
		for(int i=1;i<maxn/2;++i)
		{
			if(HA[i]==0) continue;
			for(int j=1;j<maxn/2;++j)
			{
				if(HB[j]==0) continue;
				if(floyd[i][j]) add_edge(i,j+500,INF);
			}
		}
		cout<<m-max_flow()<<endl;
		if(test) cout<<endl;
	}
}
