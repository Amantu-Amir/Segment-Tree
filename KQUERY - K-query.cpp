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

struct greaters
{
    bool operator()(const long& a, const long& b) const
    {
        return a > b;
    }
};

//-----------------------------------***********************----------------------------------------------//


typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 50050;
const int mod = 1e9+7;

int a[N];
vector <int> tree[N*4];


void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].pb(a[b]);
        return;
    }

    int mid = (b+e)/2;
    build(node*2, b, mid);
    build(node*2+1, mid+1, e);

    tree[node].resize(tree[node*2].size() + tree[node*2+1].size());
    merge(tree[node*2].begin(), tree[node*2].end(),
          tree[node*2+1].begin(), tree[node*2+1].end(), tree[node].begin());
}

int query(int node, int b, int e, int l, int r, int val)
{
    if(b > r or e < l) return 0;
    if(b >= l and e <= r)
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);

    int mid = (b+e)/2;
    return query(node*2, b, mid, l, r, val) + query(node*2+1, mid+1, e, l, r, val);
}


int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //fast;

    int tcase = 1, cas = 0;
    while(tcase--)
    {
        int n;
        sf(n);
        rep(i, 1, n+1)
        sf(a[i]);

        build(1, 1, n);

        int q;
        sf(q);
        int ans = 0;
        while(q--)
        {
            int l, r, val;
            sff(l, r);
            sf(val);
            ans = query(1, 1, n, l, r, val);
            printf("%d\n", ans);
        }


        //printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
