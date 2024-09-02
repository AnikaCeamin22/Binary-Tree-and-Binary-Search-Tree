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

//preorder using recusion:O(N)
void preorder(Node* node)
{
    if(node==NULL) return;

    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);

    return;
}

//preorder  using iterative
 vector<int> interPreorder(Node* root)
 {
     vector<int>ans;
     if(root==NULL) return ans;
     stack<Node* >st;
     st.push(root);
     while(!st.empty())
     {
         Node* top=st.top();
         st.pop();
         ans.push_back(top->data);
         if(top->right!=NULL) st.push(top->right);
         if(top->left!=NULL) st.push(top->left);
     }
     return ans;
 }

//inorder using recusion:O(N)
void inorder(Node* node)
{
    if(node==NULL) return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);

    return;
}

//inorder using interative
vector<int> interInorder(Node* root)
{
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node* >st;
    Node* node=root;
    while(1)
    {
        if(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        else
        {
            if(st.empty()) break;
            node =st.top();
           st.pop();
           ans.push_back(node->data);
           node=node->right;
        }
    }
    return ans;
}



//postorder using recusion:O(N)
void postorder(Node* node)
{
    if(node==NULL) return;

    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";

    return;
}

//postorder  using iterative
 vector<int> interPostorder(Node* root)
 {
     vector<int>ans;
     if(root==NULL) return ans;
     stack<Node* >st;
     st.push(root);
     while(!st.empty())
     {
         Node* top=st.top();
         st.pop();
         ans.push_back(top->data);
         if(top->left!=NULL) st.push(top->left);
         if(top->right!=NULL) st.push(top->right);
     }
    reverse(ans.begin(),ans.end());
     return ans;
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

    cout<<"Recursion"<<endl;

    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    cout<<"Interative"<<endl;
   vector<int>ans1=interPreorder(root);
   for(int i=0; i<(int)ans1.size(); i++) cout<<ans1[i]<<" ";
   cout<<endl;

   vector<int>ans3=interInorder(root);
   for(int i=0; i<(int)ans3.size(); i++) cout<<ans3[i]<<" ";
   cout<<endl;

   vector<int>ans2=interPostorder(root);
   for(int i=0; i<(int)ans2.size(); i++) cout<<ans2[i]<<" ";
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
