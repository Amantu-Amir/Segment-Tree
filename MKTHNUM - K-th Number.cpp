//Accepted
#include<bits/stdc++.h>
#define int long long int
#define all(v) v.begin(),v.end()
using namespace std;
const int N = 2e5+50;
const int mod = 1e9+7;
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

vector<int>v;
vector<int>tree[N*3];
void build(int node, int b, int e){
    if(b==e){
        tree[node].push_back(v[b]);
        return;
    }
    build(node*2,b,b+(e-b)/2);
    build(node*2+1,(b+(e-b)/2)+1,e);
    merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

int query(int node, int b, int e, int l, int r, int val){
    if(b>r || e<l || b>e) return 0;
    if(b>=l && e<=r){
        return (lower_bound(all(tree[node]),val)-tree[node].begin());
        //return tree[node].size() - (upper_bound(all(tree[node]),k)-tree[node].begin());
    }
    int mid = b+(e-b)/2;
    int q1 = query(node*2, b, mid, l, r, val);
    int q2 = query(node*2+1, mid+1, e, l, r, val);
    return q1+q2;
}

int32_t main(){
    //fast();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,q; cin>>n>>q;
    v.clear();v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    build(1,0,n-1);
    sort(all(v));
    for(int i=0; i<q; i++){
        int l, r, k; cin>>l>>r>>k;
        int idx, b=0, e=n-1;
        l-=1; r-=1; k-=1;
        while(b<=e){
            int mid = b+(e-b)/2;
            int check = query(1,0,n-1,l,r,v[mid]);
            if(check <= k){
                idx = mid;
                b = mid+1;
            }
            else{
                e = mid-1;
            }
        }
       cout<<v[idx]<<"\n";
    }
    return 0;
}



