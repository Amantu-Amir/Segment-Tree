///**Bismillahir Rahmanir Rahim.**

#include <bits/stdc++.h>
#define mem(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(tmp, v)           tmp.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sf(n)                 scanf("%d", &n)
#define sff(n, m)             scanf("%d %d",&n,&m)
#define sfl(n)                scanf("%lld", &n)
#define sfu(n)                scanf("%llu", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfff(n, m, o)         scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define sp                    printf(" ")
#define nl                    printf("\n")
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld", n)
#define pfu(n)                printf("%llu", n)
#define pb                    push_back
#define pp                    pair<ll,ll>
#define mp                    make_pair
#define S                     second
#define F                     first
#define PI                    3.1415926

//-----------------------------------***********************----------------------------------------------//


typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 1000000;
const int mod = 1e9+7;


ll lazy[N*4], tree[N*4], cnt[N*4];
vector <ll> v(N);
void propagate(int node, int b, int e){
    int left = node*2;
    int right = left+1;
    if(b != e){
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        cnt[left] += cnt[node];
        cnt[right] += cnt[node];
        lazy[node] = 0;
        cnt[node] = 0;
    }
}

void update(int node, int b, int e, int l, int r){
    if(lazy[node] != 0)
        propagate(node, b, e);
    if(b>r or e<l){
        return;
    }
    if(b>=l and e<=r){
        lazy[node] += l;
        cnt[node]++;
        return;
    }
    int mid = (b+e)/2;
    update(node*2, b, mid, l, r);
    update(node*2+1, mid+1, e, l, r);
}

void query(int node, int b, int e, int idx){
    if(lazy[node] != 0)
        propagate(node, b, e);
    if(b == e){
        //cout<<cnt[node]<<"\n";
        ll ans = ((idx+1)*cnt[node])-lazy[node];
        cout<<ans<<"\n";
        return;
    }
    int mid = (b+e)/2;
    if(idx <= mid)
        query(node*2, b, mid, idx);
    else query(node*2+1, mid+1, e, idx);
}

int main(){
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tcase = 1, cas = 0;
    while(tcase--){
        int n;
        cin >> n;
        int q;
        cin >> q;
        while(q--){
           int l,r; cin>>l>>r;
            update(1, 1, n, l, r);
        }
        int qq; cin>>qq;
        while(qq--){
            int idx; cin>>idx;
            query(1,1,n,idx);
        }
    }
    return 0;

}
