//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 1000002
int n,m,ans=0,tp,d[maxn],a[maxn];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	cin>>n>>m;
	string A,B;cin>>A>>B;
	for(int i=0;i<n;++i) if(A[i]!=B[i]) a[i+1]=1;
	for(int i=1;i<=n-m+1;++i)
	{
		tp+=d[i];
		if((tp&1)^a[i]) d[i+m]--,ans++,tp++;
	}
	bool flag=0;
	for(int i=n-m+2;i<=n;++i)
	{
		tp+=d[i];
		if((tp&1)^a[i]){flag=1;break;}
	}
	if(flag) cout<<"No Way!!"<<endl;
	else cout<<ans<<endl;
}
