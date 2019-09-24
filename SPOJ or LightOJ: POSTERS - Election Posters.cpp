#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e4+7;
vector< pair<int, int> > p(maxn);
map<int, int> comp;
map<int, int> :: iterator it;

int tree[4*maxn];
int lazy[4*maxn];

void propagate(int node, int b, int e)
{
    tree[node] = lazy[node];
    if(b != e)
    {
        lazy[2*node]  = lazy[node];
        lazy[2*node+1]  = lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int left, int right, int lq, int rq, int val)
{
    if(lazy[node])
    {
        propagate(node, left, right);
    }
    if(left > rq || right < lq)
        return ;
    if(left >= lq && right <= rq)
    {
        tree[node] = val;
        if(left != right)
        {
            lazy[2*node]  = val;
            lazy[2*node+1]  = val;
        }
        lazy[node] = 0;
        return;
    }

    int mid = (left+right)/2;
    update(2*node, left, mid, lq, rq, val);
    update(2*node+1,mid+1,right, lq,rq, val);
    tree[node] = val;
}


int query(int node, int left, int right, int lq, int rq)
{
    if(lazy[node])
    {
        propagate(node, left, right);
    }

    if(left > rq || right < lq)
        return -1;
    if(left >= lq && right <= rq)
    {
        return tree[node];
    }

    int mid = (left+right)/2;
    return max(query(2*node, left, mid, lq, rq), query(2*node+1, mid+1, right, lq, rq));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        comp.clear();
        p.clear();

        for(int i = 0; i < 4*maxn; i++)
            tree[i] = lazy[i] = 0;

        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].first, &p[i].second);
            comp[p[i].first] = comp[p[i].second] = 1;
        }

        int a = 0;
        for(it = comp.begin(); it != comp.end(); it++)
            it->second = a++;

        for(int i = 0; i < n; i++)
        {
            update(1, 0, maxn-1, comp[p[i].first], comp[p[i].second], i+1);
        }

        set<int> ans;
        for(int i = 0; i < maxn-1; i++)
        {
            ans.insert(query(1, 0, maxn-1, i, i));
        }

        int k = ans.size();
        if(ans.find(0) != ans.end())
            k--;

        printf("%d\n", k);
    }
    return 0;
}
