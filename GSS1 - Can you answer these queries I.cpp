///**Bismillahir Rahmanir Rahim.**

#include <bits/stdc++.h>
#define mem(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
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
const int N = 200050;
const int mod = 1e9+7;




ll v[N], tmp, tmp2;
ll tree[N*4], tree2[N*4];


void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(v[b] >= 0)
        {
            tree[node] = v[b];
            tree2[node] = INT_MIN;
        }
        else
        {
            tree2[node] = v[b];
            tree[node] = v[b];
        }
        return;
    }

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);

    if(tree[left] < 0)
        tmp = 0;
    else tmp = tree[left];

    if(tree[right] < 0)
        tmp2 = 0;
    else tmp2 = tree[right];

    tree[node] = tmp + tmp2;
    tree2[node] = max(tree2[left], tree2[right]);
    //cout << "2 " << node << " " << tree2[node] << endl;
    tree[node] = max(tree[node], tree2[node]);
    //cout << node << " " << tree[node] << endl;

}


ll query(ll node, ll b, ll e, ll l, ll r)
{
    if(b > r or e < l or b > e)
        return INT_MIN;

    if(b >= l and e <= r)
        return tree[node];

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, l, r);
    ll p2 = query(right, mid+1, e, l, r);
    //cout << p1 << " " << p2 << endl;
    return max(p1, p2);
}



int main()
{

//freopen("test.txt", "r", stdin);

    int tcase = 1, cas = 1;
    while(tcase--)
    {
        ll n, q;
        sfl(n);

        for(int i = 1; i <= n; i++)
            sfl(v[i]);

        init(1, 1, n);
        sfl(q);
        printf("Case %d:\n", cas);
        while(q--)
        {
            ll l, r;
            sffl(l, r);
            printf("%lld", query(1, 1, n, l, r));
            if(q) printf("\n");
        }



        //cout << "Case " << cas << ": " << ans << endl;
        cas++;
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
