//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 100005
int x[maxn];
struct Node{
	int L,R,lans,mans,rans;
	void up(Node ls,Node rs)
	{
		lans=ls.lans;rans=rs.rans;mans=max(ls.mans,rs.mans);
		if(x[ls.R]+1==x[rs.L]){
			if(ls.R-ls.L+1==ls.lans) lans=ls.lans+rs.lans;
			if(rs.R-rs.L+1==rs.rans) rans=rs.rans+ls.rans;
			mans=max((ls.rans+rs.lans),mans);
		}
		mans=max(max(lans,rans),mans);
	}
}seg[maxn*4];

void build(int l,int r,int i)
{
	seg[i]={l,r,1,1,1};
	if(l==r){ cin>>x[r]; return ;}
	int mid=(l+r)/2;
	build(l,mid,i*2);
	build(mid+1,r,i*2+1);
	seg[i].up(seg[i*2],seg[i*2+1]);
}

void update(int l,int r,int i,int x)
{
	if(l==r) return ;
	int mid=(l+r)/2;
	if(x<=mid) update(l,mid,i*2,x);
	else update(mid+1,r,i*2+1,x);
	seg[i].up(seg[i*2],seg[i*2+1]);
}

Node query(int l,int r,int i,int ql,int qr)
{
	if(l>=ql&&r<=qr) return seg[i];
	int mid=(l+r)/2;
	if(qr<=mid) return query(l,mid,i*2,ql,qr);
	if(ql>mid) return query(mid+1,r,i*2+1,ql,qr);

	Node res={max(l,ql),min(r,qr),1,1,1};
	res.up(	query(l,mid,i*2,ql,qr) ,
			query(mid+1,r,i*2+1,ql,qr) );
	return res;
}

main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;cin>>n;
	build(1,n,1);
	int q;cin>>q;
	while(q--)
	{
		int t,a,b;cin>>t>>a>>b;
		if(t==1)
			x[a]=b,update(1,n,1,a);
		else
			cout<<query(1,n,1,a,b).mans<<endl;

	}
}

/*
5
1 2 2 3 4
6
2 1 4
1 3 3
2 1 5
1 5 5
1 4 4
2 1 5

5
5 4 3 2 1
3
2 1 5
1 3 5
2 2 4

9
1 2 3 4 5 6 7 8 9
100
2 3 8
*/
