///**Bismillahir Rahmanir Rahim.**
///Accepted

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
const int N = 30050;
const int mod = 1e9+7;

pair<int, int>tree[4*N];
int a[N];
int n;

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = mp(a[b], b);
        return;
    }

    int mid=(b+e)/2;
    int left=2*mid;
    int right=2*mid+1;

    build(left, b, mid);
    build(right, mid+1, e);
    tree[node] = min(tree[left], tree[right]);
}

pair<int, int> query(int node, int b, int e, int l, int r)
{
    if(b > r or e < l) return pair<int, int> (N*2, N*2);
    if(b >= l and e <= r)
        return tree[node];

    int mid=(b+e)/2;
    int left=2*mid;
    int right=2*mid+1;

    pair<int, int> p1 = query(left, b, mid, l, r);
    pair<int, int> p2 = query(right, mid+1, e, l, r);
    return min(p1, p2);
}


ll solve(int l, int r)
{
    if(l > r) return -1;
    pair<int, int> q = query(1, 1, n, l, r);
    ll p1 = (r-l+1)*q.F;
    ll p2 = max(solve(l, q.S-1), solve(q.S+1, r));
    return max(p1, p2);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //fast;
    int tcase, cas = 0;
    scanf("%d", &tcase);
    while(tcase--)
    {
        scanf("%d", &n);
        rep(i, 1, n+1)
        scanf("%d", &a[i]);

        build(1, 1, n);
        printf("Case %d: %lld\n", ++cas, solve(1, n));
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//

