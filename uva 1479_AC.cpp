//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxm 60004
#define maxn 20004
#define maxq 2000005
#define int long long
int n,m;
stack<int> sta[maxn];
struct Edge{
	int x,y;
}es[maxm];
bool dont[maxm];

struct Qry{
	char type;
	int x,y;
}QY[maxq];

struct treap;
treap *nul;
struct treap{
	treap *l,*r;
	int key,pri,sz;
	treap(int _key)
	{
		l=r=nul;
		key=_key;
		pri=rand();
		sz=1;
	}

	void up()
	{
		sz=l->sz+r->sz+1;
	}
}*treaps[maxn];

treap *merge(treap *a,treap *b)
{
	if(a==nul) return b;
	if(b==nul) return a;
	if(a->pri > b->pri){
		a->r=merge(a->r,b);
		a->up();
		return a;
	}
	else{
		b->l=merge(a,b->l);
		b->up();
		return b;
	}
}

void split(treap *t,int k,treap *&a,treap *&b)
{
	if(t==nul) {a=b=nul;return ;}
	//t->down();
	int asz=t->l->sz+1;
	if(asz<=k){
		a=t;
		split(t->r,k-asz,a->r,b);
	}
	else{
		b=t;
		split(t->l,k,a,b->l);
	}
	t->up();
}

int get_rank(int x,treap *t)
{
	if(t==nul) return 1;
	int asz=t->l->sz+1;
	if(t->key==x) return asz;
	if(t->key > x) return get_rank(x,t->l);
	return get_rank(x,t->r)+asz;
}

void del(int x,treap *&t)
{
	int k=get_rank(x,t);
	treap *tl,*tr;
	split(t,k-1,tl,t);
	split(t,1,t,tr);
	t=merge(tl,tr);
}

void ins(int x,treap *&t)
{
	int k=get_rank(x,t);
	treap *tl=nul,*tr=nul;
 	split(t,k-1,tl,tr);
	t=merge(tl,merge(new treap(x),tr));
}

void ins_treap(treap *a,int b)
{
	if(a==nul) return ;
	ins(a->key,treaps[b]);
	ins_treap(a->l,b);
	ins_treap(a->r,b);
}

int pa[maxn];

int find(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=find(pa[x]);
}

void U(int x,int y)
{
	x=find(x);y=find(y);
	if(treaps[x]->sz > treaps[y]->sz) swap(x,y);
	ins_treap(treaps[x],y);
	pa[x]=y;
}
void tra(treap *t)
{
	if(t==nul) return ;
	tra(t->l);
	cout<<t->key<<' ';
	tra(t->r);
}

void init()
{
	for(int i=1;i<=n;++i)
		pa[i]=i,treaps[i]=new treap(sta[i].top());
	for(int i=1;i<=m;++i)
	{
		if(dont[i]) continue;
		int x=es[i].x,y=es[i].y;
		if(find(x)==find(y)) continue;
		U(x,y);
	}
}


main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	srand(1234);
	nul=new treap(0);
	nul->sz=0;
	int ca=1;
	while(cin>>n>>m)
	{
		if(n==0) break;
		for(int i=1;i<=n;++i)
		{
			int x;cin>>x;
			while(sta[i].size()) sta[i].pop();
			sta[i].push(x);
		}
		memset(dont,0,sizeof(dont));
		for(int i=1;i<=m;++i) cin>>es[i].x>>es[i].y;
		char tpc;
		int Qcnt=0;
		while(cin>>tpc)
		{
			int x,y;
			if(tpc=='E') break;
			if(tpc=='D'){
				cin>>x;
				dont[x]=1;
			}
			else if(tpc=='Q'){
				cin>>x>>y;

			}
			else{// tpc=='C'
				cin>>x>>y;
				sta[x].push(y);
			}
			QY[Qcnt++]={tpc,x,y};
		}
		init();

		double ans=0,QQ=0;
		for(int i=Qcnt-1;i>=0;--i)
		{
			Qry t=QY[i];
			if(t.type=='D'){
				Edge e=es[t.x];
				if(find(e.x)==find(e.y)) continue;
				U(e.x,e.y);
			}
			else if(t.type=='Q'){
				QQ++;
				int x=find(t.x),k=t.y;
				treap *tl,*tr,*&t=treaps[x];
				if(k>t->sz) continue;
				k=t->sz-k+1;
				split(t,k-1,tl,t);
				split(t,1,t,tr);
				ans+=t->key;
				t=merge(tl,merge(t,tr));
			}
			else{
				sta[t.x].pop();
				del(t.y,treaps[find(t.x)]);
				ins(sta[t.x].top(),treaps[find(t.x)]);
			}
		}
		cout<<"Case "<<ca++<<": ";
		cout<<fixed<<setprecision(6)<<ans/QQ<<endl;
//		tra(treaps[2]);cout<<endl;
	}
}
/*
4 4
10 20 30 40
1 2
2 3
3 4
4 1
Q 1 1
Q 1 2
Q 1 3
Q 1 4
C 1 50
C 2 60
Q 1 1
Q 1 2
Q 1 3
Q 1 4
Q 1 100
E
0 0

2 1
10 20
1 2
C 1 50
Q 1 2
E
0 0

*/
