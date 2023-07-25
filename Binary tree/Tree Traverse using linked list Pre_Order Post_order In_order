#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node*right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node*input_tree()
{
    int val;
    cin>>val;
    Node *root;
    if(val==-1)
        root=NULL;
    else root=new Node(val);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {

        int l,r;
        cin>>l>>r;
        Node*par=q.front();
        q.pop();
        Node*myleft;
        Node*myright;
        if(l==-1)
            myleft=NULL;
        else myleft=new Node(l);
        if(r==-1)
            myright=NULL;
        else myright=new Node(r);
        par->left=myleft;
        par->right=myright;
        if(par->left)
            q.push(par->left);
        if(par->right)
        q.push(par->right);

    }
    return root;
}
void inordertraverse(Node*root)
{
 if(root==NULL)return;
 inordertraverse(root->left);
 cout<<root->val<< " ";
 inordertraverse(root->right);
}
void preordertraverse(Node*root)
{
   if(root==NULL)return;
   cout<<root->val<< " ";
 inordertraverse(root->left);
 inordertraverse(root->right);
}
void postordertraverse(Node*root)
{
   if(root==NULL)return;
 inordertraverse(root->left);
 inordertraverse(root->right);
 cout<<root->val<< " ";
}
int main()
{
    Node *root=input_tree();
    inordertraverse(root);
    preordertraverse(root);
    postordertraverse(root);
}
