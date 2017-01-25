//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		string s;cin>>s;
		string ans=s;
		for(int r=0;r<s.size();++r)
		{
			string tp=s;
			for(int i=0;i<s.size()-1;++i)
			{
				tp[i]=tp[i+1];
			}
			tp[s.size()-1]=s[0];
			s=tp;
			ans=min(ans,tp);
		}
		cout<<ans<<endl;
	}
}
