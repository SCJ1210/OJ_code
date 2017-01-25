//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define maxn 1005
#define INF 0x3f3f3f3f3f3f3f3f
int N,L,U,K;
int dx[maxn],dy[maxn],mz[maxn][maxn];
int lx[maxn],ly[maxn],slack_y[maxn],match_y[maxn];
bool ux[maxn],uy[maxn];
bool dfs(int x)
{
	ux[x]=1;
	for(int y=1;y<=N;++y)
	{
		if(mz[x][y]==INF||uy[y]) continue;
		int d=lx[x]+ly[y]-mz[x][y];
		if(d==0){
			uy[y]=1;
			if(match_y[y]==-1||dfs(match_y[y])){
				match_y[y]=x;return true;
			}
		}
		else slack_y[y]=min(slack_y[y],d);
	}
	return false;
}

void KM()
{
	memset(match_y,-1,sizeof(match_y));
	for(int x=1;x<=N;++x)
	{
		memset(slack_y,INF,sizeof(slack_y));
		while(1)
		{
			memset(ux,0,sizeof(ux));
			memset(uy,0,sizeof(uy));
			if(dfs(x)) break;
			int MIN=INF;
			for(int i=1;i<=N;++i)
				if(!uy[i]) MIN=min(MIN,slack_y[i]);
			if(MIN==INF){
				cout<<"no"<<endl;return ;
			}
			for(int i=1;i<=N;++i) if(ux[i]) lx[i]-=MIN;
			for(int i=1;i<=N;++i) if(uy[i]) ly[i]+=MIN;
		}

	}
	//int ans=0;
	__int128 ans=0;
	for(int i=1;i<=N;++i) ans+=lx[i]+ly[i];ans=-ans;
	stack<int> st;
	while(ans) st.push(ans%10),ans/=10;
	if(st.size()==0) cout<<0;
	while(st.size()) cout<<st.top(),st.pop();
	cout<<endl;
//	for(int i=1;i<=N;++i) cout<<lx[i]<<' ';cout<<endl;
//	for(int i=1;i<=N;++i) cout<<ly[i]<<' ';cout<<endl;
//	return ans;
}

main()
{
//freopen("toj 303.in","r",stdin);
//freopen("toj 303.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
	int test;cin>>test;
	while(test--)
	{
		cin>>N>>L>>U>>K;
		memset(mz,0,sizeof(mz));
		memset(lx,-INF,sizeof(lx));
		memset(ly,0,sizeof(ly));
		for(int i=0;i<K;++i)
		{
			int x,y;cin>>x>>y;
			mz[x][y]=INF;
		}
		for(int i=1;i<=N;++i) cin>>dx[i];
		for(int i=1;i<=N;++i) cin>>dy[i];
		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<=N;++j)
			{
				if(mz[i][j]==INF) continue;
				int tp=dx[i]+dy[j];
				if(tp>L) mz[i][j]=-min(tp-L,U-L);
//				cout<<"  mz["<<i<<"]["<<j<<"]="<<mz[i][j]<<endl;

				lx[i]=max(lx[i],mz[i][j]);
			}
		}
		KM();
//		int ans=KM();
//		if(ans==INF) cout<<"no"<<endl;
//		else cout<<-ans<<endl;
	}

}
/*
2
5 2 100 0
4 1 3 2 5
9 7 8 10 6
5 2 100 5
1 1
1 2
1 3
1 4
1 5
4 1 3 2 5
9 7 8 10 6

1
2 1 100 0
7 22
5 18


3
5 6 100 0
1 7 8 9 10
1 2 3 4 5
5 6 100 1
1 5
1 7 8 9 10
1 2 3 4 5
5 6 100 2
1 4
1 5
1 7 8 9 10
1 2 3 4 5

2
5 2 9000000000000000002 0
4000000000000000003 4000000000000000003 4000000000000000002 4000000000000000002 4000000000000000002
5000000000000000003 5000000000000000003 5000000000000000002 5000000000000000002 5000000000000000002
5 2000000000000000 100000000000000000 5
1 1
1 2
1 3
1 4
1 5
4000000000000000 1000000000000000 3000000000000000 2000000000000000 5000000000000000
9000000000000000 7000000000000000 8000000000000000 10000000000000000 6000000000000000
*/
