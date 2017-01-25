//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	char c;
	int x=0,y=0;
	while(cin>>c,c!='E')
	{
		if(c=='B') continue;
		int a;cin>>a;
		if(c=='X') x=a;
		else if(c=='Y') y=a;
		else if(c=='U') y+=a;
		else if(c=='D') y-=a;
		else if(c=='R') x+=a;
		else if(c=='L') x-=a;
	}
	cout<<x<<endl<<y<<endl;
}
