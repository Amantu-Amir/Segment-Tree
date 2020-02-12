#include<bits/stdc++.h>
#define int long long int
#define all(v) v.begin(), v.end()
using namespace std;
const int N=5e5+50;

vector<int>G[N];
vector<int>tree(N*3);
vector<int>a, ar(N), st(N), et(N);
bool vis[N];
int n, t;

void dfs(int root){
	vis[root] = true; st[root] = ++t;
	ar[t] = (a[root]*a[root]);
	for(auto child:G[root]){
        if(vis[child]==false)
            dfs(child);
	}
	et[root] = t;
}

void build(int node, int b, int e){
    if(b==e){
        tree[node] = ar[b];
        return;
    }
    int mid = b+(e-b)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    tree[node] = tree[node*2]+tree[node*2+1];
}

void update(int node, int b, int e, int idx, int val){
    if(b==e){
        tree[node] = val*val;
        return;
    }
    int mid = b+(e-b)/2;
    if(idx<=mid){
        update(node*2,b,mid,idx,val);
    }
    else{
        update(node*2+1,mid+1,e,idx,val);
    }
    tree[node] = tree[node*2]+tree[node*2+1];
}

int query(int node, int b, int e, int l, int r){
    if(b>r or e<l or b>e) return 0;
    if(b>=l and e<=r){
        return tree[node];
    }
    int mid = b+(e-b)/2;
    int q1 = query(node*2, b, mid, l, r);
    int q2 = query(node*2+1, mid+1, e, l, r);
    return q1+q2;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("CodeChef.txt","r",stdin);

	int u,v; cin>>n;
	a.resize(n+1);
	for(int i=1; i<=n; i++){
        cin>>a[i];
	}
	for(int i=1; i<n; i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
    build(1,1,n);
    int q; cin>>q;
    for(int i=1; i<=q; i++){
        int op; cin>>op;
        if(op == 1){
            int ver,val; cin>>ver>>val;
            update(1,1,n,st[ver],val);
        }
        else{
            int ver; cin>>ver;
            int res = query(1,1,n,st[ver],et[ver]);
            cout<<res<<"\n";
        }
    }
	return 0;
}






