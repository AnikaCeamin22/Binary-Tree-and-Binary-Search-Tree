#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};

vector<int>pre,in,post;
void PreInPostTraversal(Node* root)
{
    if(root==NULL) return;
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL) st.push({it.first->left,1});
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL) st.push({it.first->right,1});
        }
        else post.push_back(it.first->data);
    }
    return;
}

void Solve()
{
    int n=7;
    //cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    Node* root=new Node(v[0]);
    root->left=new Node(v[1]);
    root->right=new Node(v[2]);
    root->left->left=new Node(v[3]);
    root->left->right=new Node(v[4]);
    root->right->left=new Node(v[5]);
    root->right->right=new Node(v[6]);

    PreInPostTraversal(root);

    for(int i=0; i<(int)pre.size(); i++) cout<<pre[i]<<" ";
    cout<<endl;
    for(int i=0; i<(int)in.size(); i++) cout<<in[i]<<" ";
    cout<<endl;
    for(int i=0; i<(int)post.size(); i++) cout<<post[i]<<" ";
    cout<<endl;
}

int main()
{
    int T=1;
    //cin>>T;
    while(T--)
    {
        Solve();
    }
    return 0;
}
