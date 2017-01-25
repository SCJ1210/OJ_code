//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
int dp[1000][1000],type[1000][1000];//ins=1 , del=2 ,rep=3
struct P{
	int ty,pos;
	char ch;
};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
//	freopen("526.in","r",stdin);
//	freopen("526.out","w",stdout);
	string a,b;
	bool fir=0;
	while(getline(cin,a))
	{
		getline(cin,b);
		a=" "+a;b=" "+b;
		if(fir) cout<<endl;
		fir=1;
		memset(dp,INF,sizeof(dp));dp[0][0]=0;;
		memset(type,0,sizeof(type));
		int n=a.size(),m=b.size();
		n=max(n,1);m=max(m,1);
		int ins=1,del=1,rep=1;
		for(int i=1;i<n;++i) dp[i][0]=i,type[i][0]=2;
		for(int j=1;j<m;++j) dp[0][j]=j,type[0][j]=1;
		//cout<<"type[0][2]="<<type[0][2]<<endl;
		for(int i=1;i<n;++i)
		{
			for(int j=1;j<m;++j)
			{
				if(a[i]==b[j]){
					dp[i][j]=dp[i-1][j-1];
					type[i][j]=0;
				}
				else if(dp[i][j]>dp[i-1][j-1]+rep)
				{
					dp[i][j]=dp[i-1][j-1]+rep;
					type[i][j]=3;
				}
				if(dp[i][j]>dp[i-1][j]+del){
					dp[i][j]=dp[i-1][j]+del;
					type[i][j]=2;
				}
				if(dp[i][j]>dp[i][j-1]+ins){
					dp[i][j]=dp[i][j-1]+ins;
					type[i][j]=1;
				}
			}
		}
		//cout<<"type[0][2]="<<type[0][2]<<endl;
		int x=n-1,y=m-1;
		cout<<dp[n-1][m-1]<<endl;
		stack<P> st;
		for(;x!=1||y!=1;)
		{
			//cout<<"x="<<x<<"  y="<<y<<' ';

			int tp=type[x][y];
			//cout<<tp<<endl;
			if(tp==0){
				x--;y--;
			}
			else if(tp==1){
				st.push({tp,y,b[y]});
				//cout<<" Insert "<<y<<","<<b[y]<<endl;
				y--;
			}
			else if(tp==2){
				st.push({tp,x-1});
				//cout<<" Delete "<<x<<endl;
				x--;
			}
			else{
				st.push({tp,y,b[y]});
				//cout<<" Replace "<<y+1<<","<<b[y]<<endl;
				x--;y--;
			}
			//if(x<0&&y<0) break;
		}
		int cnt=1;
		while(st.size())
		{
			P p=st.top();st.pop();
			if(p.ty==1){
				cout<<cnt++<<" Insert "<<p.pos<<","<<p.ch<<endl;
			}
			else if(p.ty==2){
				cout<<cnt++<<" Delete "<<p.pos<<endl;
			}
			else{
				cout<<cnt++<<" Replace "<<p.pos<<","<<p.ch<<endl;
			}
		}
	}
}
