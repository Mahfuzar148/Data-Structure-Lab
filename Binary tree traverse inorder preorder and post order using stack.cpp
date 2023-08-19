#include<bits/stdc++.h>
using namespace std;
class Node{
   public :
   int val;
   Node *left;
   Node *right;
   Node(int val)
   {
       this->val = val;
       this->left = nullptr;
       this->right = nullptr;
   }

};
Node *make_tree()
{
    int val;
    cin>>val;
    Node *root;
    if(val ==-1)
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
        Node *parent = q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node *left_child,*right_child;
        if(l==-1)
        {
            left_child = nullptr;
        }
        else
        {
            left_child = new Node(l);
        }
        if(r==-1)
        {
            right_child = nullptr;
        }
        else
        {
            right_child = new Node(r);
        }

         parent->right = right_child;
         parent->left = left_child;
         if(parent->left)
         {
              q.push(parent->left);
         }
         if(parent->right)
         {
              q.push(right_child);
         }


    }
    return root;

}
void print(Node *root)
{
    if(root==nullptr) return;

    queue<Node*>q;
    stack<int>s;
    q.push(root);
    while(!q.empty())
    {
        Node *f = q.front();
        q.pop();
        s.push(f->val);
        if(f->right)
           {
               q.push(f->right);
           }
        if(f->left)
        {
            q.push(f->left);
        }

    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
void postorderPrint(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
       

        if (current->left)
            s1.push(current->left);
        if (current->right)
            s1.push(current->right);
    }
   

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}


void printPreorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->val << " ";

        if (current->right)
            s.push(current->right);

        if (current->left)
            s.push(current->left);
    }
}

void printInorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->val << " ";
        current = current->right;
    }
}


int main()
{
    Node *root = make_tree();
    cout<<"post_order : "<<endl;
    postorderPrint(root);
    cout<<endl;
    cout<<"in_order : "<<endl;
    printInorder(root);
    cout<<endl;
    cout<<"pre_order : "<<endl;
    printPreorder(root);
    cout<<endl;

    return 0;
}

