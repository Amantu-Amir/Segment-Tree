#include <bits/stdc++.h>
#define mx 100005
using namespace std;
typedef long long ll;



ll n, tree[mx*4], prop[mx*4], color[mx*4];

void build(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 0;
        color[node] = b;      ///leaf node
        return;
    }

    ll left = node << 1;
    ll right = left + 1;
    ll mid = (b + e) >> 1;

    build(left, b, mid);
    build(right, mid+1, e);
    color[node] = -1;       ///without leaf node
}



void propagate(ll node, ll b, ll e)
{
    tree[node] += (e-b+1)*prop[node];
    //cout << tree[node] << endl;
    ll left = node << 1;
    ll right = left + 1;

    if(b != e)
    {
        prop[left] += prop[node];
        prop[right] += prop[node];

        if(color[node] != -1)
        {
            color[left] = color[node];
            color[right] = color[node];
        }
    }
    prop[node] = 0;
}



void update(ll node, ll b, ll e, ll x, ll y, ll c)
{
    propagate(node, b, e);
    if(y < b or e < x) return;
    if(b >= x and e <= y and color[node] != -1)
    {
        //cout << node << endl;

        prop[node] += abs(color[node] - c);
        color[node] = c;
        propagate(node, b, e);
        return;
    }

    ll left = node << 1;
    ll right = left + 1;
    ll mid = (b + e) >> 1;

    update(left, b, mid, x, y, c);
    update(right, mid+1, e, x, y, c);

    tree[node] = tree[left] + tree[right];
    //cout << node << " " << tree[node] << endl;
    color[node] = (color[left] == color[right])? color[left] : -1;
    //cout << color[node] << " color " << color[left] << endl;
}



ll query(ll node, ll b, ll e, ll x, ll y)
{
    propagate(node, b, e);

    if(y < b or e < x) return 0;
    if(b >= x and e <= y) return tree[node];

    ll mid = (b + e) / 2;
    ll left = node << 1;
    ll right = left + 1;

    ll q1 = query(left, b, mid, x, y);
    ll q2 = query(right, mid+1, e, x, y);

    return q1+q2;
}


int main()
{
    ll q, op, x, y, c;
    cin >> n >> q;

    build(1, 1, n);

    while(q--)
    {
        cin >> op >> x >> y;
        if(op == 1)
        {
            cin >> c;                       //scanf("%I64d", &c);
            update(1, 1, n, x, y, c);
        }
        else cout << query(1, 1, n, x, y) << endl;
    }
    return 0;
}
