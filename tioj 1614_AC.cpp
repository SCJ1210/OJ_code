//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[100005],b[100005];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<m;++i) cin>>b[i];
	sort(b,b+n);
	int ans=0;
	for(int i=0;i<n;++i)
	{
		int x=a[i];
		int dis=lower_bound(b,b+m,x)-b;
		if(dis==m) ans++;
		else if(b[dis]!=x&&(m-dis)%2==0) ans++;
	}
	cout<<ans<<endl;
}
