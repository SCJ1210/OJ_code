//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100005
#define endl '\n'
int B,MOD,n,m;
int seg[maxn*4],POW[maxn]={1};

void update(int l,int r,int i,int x,int c)
{
	if(l==r)
	{
		seg[i]=c;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(l,mid,i*2,x,c);
	else update(mid+1,r,i*2+1,x,c);
	seg[i]=(seg[i*2]*POW[r-mid]%MOD+seg[i*2+1])%MOD;
}
int query(int l,int r,int i,int ql,int qr)
{
	if(l>=ql&&r<=qr) return seg[i];
	int mid=(l+r)/2;
	if(qr<=mid) return query(l,mid,i*2,ql,qr);
	if(ql>mid) return query(mid+1,r,i*2+1,ql,qr);
	return ( query(l,mid,i*2,ql,qr)*POW[min(qr,r)-mid]%MOD
			+query(mid+1,r,i*2+1,ql,qr))%MOD;
}
main()
{
ios::sync_with_stdio(0);
cin.tie(0);

	while(cin>>B>>MOD>>n>>m,B|MOD|n|m)
	{
		memset(seg,0,sizeof(seg));
		for(int i=1;i<=n;++i) POW[i]=(POW[i-1]*B)%MOD;
//		for(int i=0;i<=n;++i) cout<<POW[i]<<' ';cout<<endl;
		for(int i=0;i<m;++i)
		{
			char type;cin>>type;
			int a,b;cin>>a>>b;
			if(type=='E') b%=MOD,update(1,n,1,a,b);
			else cout<<query(1,n,1,a,b)<<endl;
		}
		cout<<"-"<<endl;
	}
}

/*
20 139 5 100
E 1 12
E 2 14
E 3 2
E 4 2
E 5 4
H 2 5
E 2 14

10 1000000 5 100
E 1 1
E 2 2
E 3 3
E 4 4
E 5 5


*/
