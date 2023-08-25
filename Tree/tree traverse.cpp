#include<bits/stdc++.h>
using namespace std;
class Node{
   public :
       int val;
       Node* left;
       Node* right;
       Node(int item)
       {
           val = item;
           left = nullptr;
           right = nullptr;
       }
};
Node* make_tree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1)
    {
        root = nullptr;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        if(l==-1)
           {
               parent->left = nullptr;
           }
           else
            {
                parent->left = new Node(l);
                q.push(parent->left);
            }
         if(r==-1)
         {
             parent->right = nullptr;
         }
         else
         {
             parent->right = new Node(r);
             q.push(parent->right);
         }


    }
    return root;
}
void preorder(Node* root)
{
    if(root==nullptr)
    {
        return ;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void print_preorder(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node* f = s.top();
        s.pop();
        cout<<f->val<<" ";
       if(f->right) s.push(f->right);
       if(f->left)  s.push(f->left);
    }
}
void postorder(Node* root)
{
     if(root == nullptr) return ;

    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node *f= s1.top();
        s1.pop();
        s2.push(f);
        if(f->left) s1.push(f->left);
        if(f->right) s1.push(f->right);
    }
    while(!s2.empty())
    {
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
}
void postorder1(Node* root)
{
     if(root == nullptr) return ;
     postorder1(root->left);
     postorder1(root->right);
     cout<<root->val<<" ";

}
void print_inorder(Node* root)
{
    if(root==nullptr) return ;
    stack<Node*>s;
    Node* current = root;
    while(current!=nullptr||!s.empty())
    {
        while(current!=nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->val<<" ";
        current = current->right;
    }
    cout<<endl;
}

int main()
{
    // 1 2 3 -1 4 5 6 -1 -1 -1 -1 -1 -1
    Node* root = make_tree();
    preorder(root);
    cout<<endl;
    print_preorder(root);
    cout<<endl;
    cout<<"Post order : "<<endl;
    postorder1(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<" Inorder : "<<endl;
    print_inorder(root);
    return 0;

}
