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
/**
Read the value val for the root node.
If val is -1, set root as nullptr.
Otherwise, create a new Node with value val and assign it to root.
Initialize a queue with root.
Loop until the queue is not empty:
Dequeue a node parent from the queue.
Read the values l and r for left and right children.
If l is not -1, create a new node left_child with value l and assign it to parent->left.
If r is not -1, create a new node right_child with value r and assign it to parent->right.
If left_child is not nullptr, enqueue it.
If right_child is not nullptr, enqueue it.
This shorter algorithm outlines the key steps you need to follow to create a binary tree using level-order traversal. 
You can use this as a guide to write the code in your preferred programming language.
 */
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
/**
Algorithm
Remove the top element from stack 1.
Push that element to stack 2.
Check if the stack has left and right elements present. 
If present, push them onto stack 1, first pushing the left child and then the right child
*/
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
/**
Following is a simple stack based iterative process to print Preorder traversal.
Create an empty stack nodeStack and push root node to stack.
Do the following while nodeStack is not empty. 
Pop an item from the stack and print it. 
Push right child of a popped item to stack. 
Push left child of a popped item to stack.
  
 */


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
/**
Create an empty stack (say S).
Initialize the current node as root.
Push the current node to S and set current = current->left until current is NULL
If current is NULL and the stack is not empty then:
Pop the top item from the stack.
Print the popped item and set current = popped_item->right 
Go to step 3.
If current is NULL and the stack is empty then we are done.
*/
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

