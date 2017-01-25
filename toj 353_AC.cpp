//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[5005][5005];
char x[5005],y[5005];
int main()
{
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	x[0]=y[0]=' ';
	scanf("%s%s",x+1,y+1);
	int n=strlen(x)-1,m=strlen(y)-1;

	for(int i=1;i<=n;++i) dp[i][0]=dp[i-1][0]+B;
	for(int i=1;i<=m;++i) dp[0][i]=dp[0][i-1]+A;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int tp=min(abs(x[i]-y[j]),26-abs(x[i]-y[i]))*C;
			//tp=min(tp,A+B);
			dp[i][j]=min({dp[i-1][j]+B,dp[i][j-1]+A,dp[i-1][j-1]+tp});
		}
	}
	printf("%d\n",dp[n][m]);
}
/*
4 2 3
DOMEN
DOMAIN

1 1 1
DOMEN
ABDOMEN

3 2 1
DOMEN
DOORS
*/
