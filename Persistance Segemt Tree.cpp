#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005

int arr[mx];
struct Node{
    Node* left;
    Node* right;
    int val;
    Node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
}*root[mx];

void build(Node* curr, int low, int high){
    if(low == high){
        curr -> val = arr[low];
        return;
    }
    int mid = (low+high)/2;
    curr -> left = new Node();
    curr -> right = new Node();
    build(curr -> left, low, mid);
    build(curr -> right, mid+1, high);
    curr -> val = (curr -> left -> val + curr -> right -> val);
}

void update(Node* preNode, Node* currNode, int low, int high, int idx, int value){
    if(idx > high || idx < low || low > high) return;
    if(low == high){
        currNode -> val = (preNode -> val + value);
        return;
    }
    int mid = (low+high)/2;
    if(idx <= mid){
        currNode -> right = preNode -> right;
        currNode -> left = new Node();
        update(preNode->left, currNode->left, low, mid, idx, value);
    }
    else{
        currNode -> left = preNode -> left;
        currNode->right = new Node();
        update(preNode->right, currNode->right, mid+1, high, idx, value);
    }
    currNode -> val = (currNode -> left -> val + currNode -> right -> val);
}

int query(Node* curr, int low, int high, int l, int r){
    if(l>high || r<low || low>high) return 0;
    if(low>=l && high<=r)
        return curr->val;
    int mid = (low+high)/2;
    int ret1 = query(curr->left, low, mid, l, r);
    int ret2 = query(curr->right, mid+1, high, l, r);
    return (ret1+ret2);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    root[0] = new Node();
    build(root[0], 1, n);

    int q, idx, pos, v, l, r, id = 0, typ;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &typ);
        if(typ == 1){
            scanf("%d%d%d", &idx, &pos, &v);
            root[++id] = new Node(); //current node
            update(root[idx], root[id], 1, n, pos, v);
        }
        else{
            scanf("%d%d%d",&idx,&l,&r);
            int ans = query(root[idx],1,n,l,r);
            printf("%d\n",ans);
        }
    }
}