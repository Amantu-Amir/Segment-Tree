///**Bismillahir Rahmanir Rahim.**
#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
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
#define pii                   pair<int,int>
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
const int N = 150050;
const int mod = 1e9+7;

struct info
{
    ll sum, val;
} tree[N*4];


void update(ll node, ll b, ll e, ll idx, ll val)
{
    if(b == e)
    {
        tree[node].sum = 1;
        tree[node].val = val;
        return;
    }

    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(idx <= mid)
        update(left, b, mid, idx, val);
    else
        update(right, mid+1, e, idx, val);
    tree[node].sum = tree[left].sum + tree[right].sum;
}



ll query(ll node, ll b, ll e, ll idx)
{
    tree[node].sum--;
    if(b == e)
        return tree[node].val;

    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(idx <= tree[left].sum)
        return query(left, b, mid, idx);
    else
        return query(right, mid+1, e, idx-tree[left].sum);
}


void reset(){
  clr(tree, 0);
}


int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fast;
    int tcase, cas = 0;
    sf(tcase);
    while(tcase--)
    {
        reset();
        ll n, q;
        sffl(n, q);
        ll limit = n*q;

        ll a;
        rep(i, 1, n+1)
        {
            sfl(a);
            update(1, 1, limit, i, a);
        }

        printf("Case %d:\n", ++cas);
        while(q--)
        {
            getchar();
            char op;
            ll army;
            scanf("%c", &op);
            sfl(army);

            if(op == 'c')
            {
                if(tree[1].sum < army) printf("none\n");
                else printf("%lld\n", query(1, 1, limit, army));
            }
            else
            {
                n++;
                update(1, 1, limit, n, army);
            }
        }
        ///printf("Case %d: %lld\n", ++cas, ans);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
