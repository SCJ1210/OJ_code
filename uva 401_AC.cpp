//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
char mi[128];
string tpaz="Axxx3xxHILxJMxOxxx2TUVWXY5";
string tp19="1SExZxx8x";
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	//cout<<(int)'0'<<endl;
	for(int i='A';i<='Z';++i)
		mi[i]=tpaz[i-'A'];
	for(int i='1';i<='9';++i)
		mi[i]=tp19[i-'1'];
	//cout<<mi['S']<<endl;
	string s;
	while(cin>>s)
	{
		bool pal=1,mir=1;
		string rev=s;
		for(int i=0;i<s.size();++i)
			rev[i]=mi[rev[i]];
		for(int i=0;i<s.size();++i)
			if(s[i]!=s[s.size()-i-1]) pal=0;
		for(int i=0;i<s.size();++i)
		{
			if(rev[i]=='x') mir=0;
			if(rev[i]!=s[s.size()-i-1]) mir=0;
		}

		cout<<s;
		if(pal==0&&mir==0) cout<<" -- is not a palindrome.";
		else if(pal==1&&mir==0) cout<<" -- is a regular palindrome.";
		else if(pal==0&&mir==1) cout<<" -- is a mirrored string.";
		else cout<<" -- is a mirrored palindrome.";
		cout<<endl<<endl;
	}
}
