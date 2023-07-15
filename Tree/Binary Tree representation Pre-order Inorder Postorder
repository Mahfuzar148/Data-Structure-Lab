#include<bits/stdc++.h>
using namespace std;
#define M 10000
 int binaryTree[M];
 void makeTree(int item)
 {
     int root = 0;
     queue<int>nodes;
     if(binaryTree[root]==-1)
     {
         binaryTree[root] = item;
         return ;
     }
     nodes.push(root);
     while(nodes.size()!=0)
     {
         int currentNode = nodes.front();
         nodes.pop();
         int left = 2*currentNode + 1,right = 2*currentNode+2;
         if(binaryTree[left]==-1)
         {
             binaryTree[left] = item;
             break;
         }
         else if(binaryTree[right] == -1)
         {
             binaryTree[right] = item;
             break;
         }
         else
         {
             nodes.push(left);
             nodes.push(right);
         }
     }
 }
 void printTreePreorder(int currentRoot)
 {
     if(binaryTree[currentRoot] == -1)
     {
         return;
     }
     cout<<binaryTree[currentRoot]<<" ";

     printTreePreorder(currentRoot*2+1);
     printTreePreorder(currentRoot*2+2);
 }

 void printTreeInorder(int currentRoot)
 {
     if(binaryTree[currentRoot] == -1)
     {
         return;
     }
     printTreeInorder(currentRoot*2+1);

     cout<<binaryTree[currentRoot]<<" ";

     printTreeInorder(currentRoot*2+2);
 }
 void printTreePostorder(int currentRoot)
 {
     if(binaryTree[currentRoot] == -1)
     {
         return;
     }

     printTreePostorder(currentRoot*2+1);
     printTreePostorder(currentRoot*2+2);

     cout<<binaryTree[currentRoot]<<" ";
 }

int main()
{

   memset(binaryTree,-1,sizeof(binaryTree));
   int arr[] = {5 , 6 , 1 , 2 , 4 , 3} ;
   int sz = sizeof(arr)/sizeof(arr[0]);
   for(int i =0;i<sz;i++)
   {
       makeTree(arr[i]);
   }

   int root = 0;
   cout<<"Pre-order : ";
   printTreePreorder(root);
   cout<<endl;

   cout<<"In-order :";
   printTreeInorder(root);
   cout<<endl;

   cout<<"Post-order :";
   printTreePostorder(root);
   cout<<endl;
   
   return 0;


}
