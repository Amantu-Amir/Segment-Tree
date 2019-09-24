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
const int N = 200150;
const int mod = 1e9+7;


ll lazy[N*4];
vector <ll> v(N);

void propagate(int node, int b, int e)
{
    int left = node*2;
    int right = left+1;
    if(b != e)
    {
        lazy[left] = max(lazy[left], lazy[node]);
        lazy[right] = max(lazy[right], lazy[node]);
    }
    else
    {
        v[b] = max(v[b], lazy[node]);
    }
    lazy[node] = 0;
}

void update(int node, int b, int e, int idx, ll val)
{
    if(lazy[node] != 0)
        propagate(node, b, e);

    if(b == e)
    {
        v[b] = val;
        return;
    }

    int mid = (b+e)/2;
    if(idx <= mid)
        update(node*2, b, mid, idx, val);
    else update(node*2+1, mid+1, e, idx, val);
}

void update2(int node, int b, int e, ll val)
{
    lazy[node] = val;
    propagate(node, b, e);
    return;
}

void query(int node, int b, int e, int idx)
{
    if(lazy[node] != 0)
        propagate(node, b, e);
    if(b == e)
    {
        cout << v[b] << " ";
        return;
    }

    int mid = (b+e)/2;
    if(idx <= mid)
        query(node*2, b, mid, idx);
    else query(node*2+1, mid+1, e, idx);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fast;

    int tcase = 1, cas = 0;
    while(tcase--)
    {
        int n;
        cin >> n;

        rep(i, 1, n+1)
        cin >> v[i];

        int q;
        cin >> q;
        while(q--)
        {
            int op, x, y;
            cin >> op >> x;
            if(op == 1)
            {
                cin >> y;
                update(1, 1, n, x, y);
            }
            else update2(1, 1, n, x);
        }

        rep(i, 1, n+1)
        query(1, 1, n, i);


        //printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//

