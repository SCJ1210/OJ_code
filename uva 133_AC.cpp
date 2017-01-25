//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void pf(int x)
{
	if(x>=10) cout<<" "<<x;
	else cout<<"  "<<x;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,k,m;
	while(cin>>n>>k>>m)
	{
		if(n==0) break;
		bool a[30];
		memset(a,0,sizeof(a));
		int tol=n-1,tor=0,cnt=0;
		while(1)
		{
			if(cnt==n) break;

			int tp=0;
			for(;;tor=(tor+1)%n)
			{
				if(a[tor]) continue;
				//cout<<"tor ="<<tor<<" i="<<i<<endl;
				tp++;if(tp==k) break;
			}
			tp=0;
			for(;;tol=(tol-1+n)%n)
			{
				if(a[tol]) continue;
				//cout<<"tol ="<<tol<<" i="<<i<<endl;
				tp++;if(tp==m) break;
				//tol=(tol-1+n)%n;
			}
			a[tor]=a[tol]=1;
			if(tor==tol) pf(tor+1),cnt++;
			else pf(tor+1),pf(tol+1),cnt+=2;
			if(cnt!=n) cout<<",";
			//cout<<endl;
		}
		cout<<endl;
	}
}
