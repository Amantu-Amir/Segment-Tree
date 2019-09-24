/**Bismillahir Rahmanir Rahim.**/
#include <bits/stdc++.h>
#define mem(a, v)           memset(a, v, sizeof a)
#define vec(m)              vector<ll>m
#define ast(v)              sort(v.begin(),v.end())
#define dst(v)              sort(v.begin(),v.end(), greater <int> ())
#define ass(tmp, v)         tmp.assign(v.begin(), v.end())
#define for(i, l, r)        for (int i = l; i < r; i++)
#define rep(i, l, r)        for (int i = l-1; i >= r; i--)
#define sf(n)               scanf("%d", &n)
#define sff(n, m)           scanf("%d %d",&n,&m)
#define sfl(n)              scanf("%lld", &n)
#define sfu(n)              scanf("%llu", &n)
#define sffl(n, m)          scanf("%lld %lld",&n,&m)

#define pf(n)               printf("%d", n)
#define sp                  printf(" ")
#define nl                  printf("\n")
#define prln(n)             printf("%d\n", n)
#define pfl(n)              printf("%lld", n)
#define pfu(n)              printf("%llu", n)
#define pb                  push_back
#define pp                  pair<ll,ll>
#define mp                  make_pair
#define mod                 1e9+7
#define T                   true
#define F                   false
#define S                   second
#define f                   first
#define PI                  3.1415926

//-----------------------------------***********************----------------------------------------------//

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 100010;

char s[N];
struct info
{
    ll sum, prop;
} tree[N*4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].sum = s[b-1]-'0';
        return;
    }

    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}


ll query(ll node, ll b, ll e, ll l, ll carry = 0)
{
    if(b > l or e < l or b > e)
        return 0;

    if(b == l and e == l)
        return tree[node].sum + (carry*(e-b+1));

    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;

    ll p1 = query(left, b, mid, l, carry+tree[node].prop);
    ll p2 = query(right, mid+1, e, l, carry+tree[node].prop);

    return p1+p2;
}


void update(ll node, ll b, ll e, ll l, ll r)
{
    if(b > r or e < l)
        return;

    if(b >= l and e <= r)
    {
        tree[node].sum += (e-b+1)*1;
        tree[node].prop += 1;
        return;
    }

    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;

    update(left, b, mid, l, r);
    update(right, mid+1, e, l, r);

    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}



int main()
{

//freopen("test.txt", "r", stdin);

    int tcase, cas = 1;
    sf(tcase);

    while(tcase--)
    {
        scanf("%s", s);
        ll len = strlen(s);

        mem(tree, 0);
        init(1, 1, len);

        ll q;
        sfl(q);

        ll l, r;
        char op[2];
        printf("Case %d:\n", cas);

        for(i, 0, q)
        {
            scanf("%s", op);
            if(op[0] == 'I')
            {
                sffl(l, r);
                update(1, 1, len, l, r);
            }
            else
            {
                sfl(l);
                pfl(query(1, 1, len, l)%2);
                nl;
            }
        }

        cas++;
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
