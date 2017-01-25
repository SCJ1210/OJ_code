//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	string s;
	bool fg=0;
	while(getline(cin,s))
	{

		for(int i=0;i<s.size();++i)
		{
			if(s[i]=='"')
			{
				if(fg==0) cout<<"``";
				else cout<<"''";
				fg^=1;
			}
			else cout<<s[i];
		}
		cout<<endl;
	}
}
