//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 100000000
bool A[20][20],a[20][20];
bool count(int i,int j)
{
	return a[i][j-1]^a[i][j+1]^a[i-1][j]^a[i+1][j];
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int ca=1;ca<=T;++ca)
	{
		memset(A,0,sizeof(A));
		int n;cin>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) cin>>A[i][j];
		int S=(1<<n);
		int cnt=0,ans=INF;
		for(int r=0;r<S;++r)
		{
			int tp=r;cnt=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					a[i][j]=A[i][j];
			bool tt=1;
			for(int i=1;i<=n;++i)
			{
				if(tp&1)
				{
					if(a[1][i]) {tt=0;break;}
					cnt++,a[1][i]^=1;
				}
				tp>>=1;
			}
			if(tt==0) continue;
			for(int i=2;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(count(i-1,j))
					{
						if(a[i][j]) {tt=0;break;}
						cnt++,a[i][j]^=1;
					}
				}
				if(tt==0) break;
			}
			bool flag=0;
			for(int j=1;j<=n;++j)
				if(count(n,j)) flag=1;
			if(flag==0&&tt==1) ans=min(ans,cnt);
		}
		cout<<"Case "<<ca<<": ";
		if(ans==INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
