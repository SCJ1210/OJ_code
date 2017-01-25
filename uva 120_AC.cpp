//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[50];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		stringstream ss(s);
		int tp,n=0;
		deque<int> dq;
		while(ss>>tp)
		{
			a[n++]=tp;
			dq.push_back(tp);
		}
		for(int i=0;i<n;++i)
		{
			if(i) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		sort(a,a+n);
		for(int i=n-1;i>=0;--i)
		{
//			cout<<"i="<<i<<endl;
//			for(int k:dq) cout<<k<<' ';cout<<endl;
			if(dq[i]==a[i]) continue;
			int r=0;
			if(dq[0]!=a[i])
			{
				for(r=0;r<i;++r)
				{
					if(dq[r]==a[i]) break;
				}
				cout<<n-r<<' ';
			}
			cout<<n-i<<' ';
			for(int j=0;j<=r/2;++j) swap(dq[j],dq[r-j]);
			for(int j=0;j<=i/2;++j) swap(dq[j],dq[i-j]);
		}
		cout<<0<<endl;
	}
}
