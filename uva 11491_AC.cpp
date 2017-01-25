//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,m;
	while(cin>>n>>m,n!=0)
	{
		string s;cin>>s;
		string ans;
		ans.resize(n);
		int r=-1,tp=n-m;
		for(char c:s)
		{
			while(r>-1&&ans[r]<c&&m) --r,--m;
			ans[++r]=c;
		}
		for(int i=0;i<tp;++i) cout<<ans[i];cout<<endl;
	}
}
