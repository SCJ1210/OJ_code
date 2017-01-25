//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void ext_gcd(int a,int b,int& d,int& x,int& y)
{
	if(!b){d=a;x=1;y=0;}
	else{ext_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int main()
{
//ios::sync_with_stdio(0);
//cin.tie(0);
	int a,b;
	while(cin>>a>>b)
	{
		int x,y,d;
		ext_gcd(a,b,d,x,y);
		printf("d=%d x=%d y=%d a*x+b*y=%d\n",d,x,y,a*x+b*y);
	}
}
