//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string tra(int x,int len)
{
	string s="";
	while(x)
	{
		s=(char)(x%2+'0')+s;
		x>>=1;
	}
	while(s.size()<len) s="0"+s;
	return s;
}
string strs[1000000];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n=0;
	while(getline(cin,strs[n++]));
	for(int r=0;r<n-1;)
	{
		string head=strs[r++];
		string all="";
		while(1)
		{
			string s=strs[r++];
			bool bi=0;
			for(int i=0;i<s.size();++i)
				if(s[i]!='0'&&s[i]!='1') bi=1;
			if(bi||r==n) {r--;break;}
			all+=s;
		}
		unordered_map<string,char> mp;
		int ct=0;
		for(int i=0;;++i)
		{
			for(int j=0;j<(1<<i+1)-1;++j)
			{
				mp[tra(j,i+1)]=head[ct++];
				if(ct==head.size()) break;
			}
			if(ct==head.size()) break;
		}
		for(int k=0;k<all.size();)
		{
			int len=0;
			if(all[k++]=='1') len+=4;
			if(all[k++]=='1') len+=2;
			if(all[k++]=='1') len+=1;
			while(1)
			{
				string tp="";
				bool fill_one=1;
				for(int i=0;i<len;++k,++i)
				{
					if(all[k]=='0') fill_one=0;
					tp+=all[k];
				}
				if(fill_one) break;
				cout<<mp[tp];
			}
		}
		cout<<endl;
	}
}
