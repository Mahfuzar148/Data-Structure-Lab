
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class LinkedList{
    public :
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }

    void push(int val)
    {
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }
};
class Graph{
public :
    int vertice;
    LinkedList* adjlist;
    Graph(int v)
    {
        vertice = v;
        adjlist = new LinkedList[v+1];
    }

    void addNode(int x,int y)
    {
        adjlist[x].push(y);
        adjlist[y].push(x);
    }
    void print()
    {
       for(int i=0;i<=vertice;i++)
       {
           Node* tmp = adjlist[i].head;
           cout<<i<<" -> ";
           while(tmp!=nullptr)
           {
               cout<<tmp->data<<" ";
               tmp = tmp->next;
           }
           cout<<endl;
       }
    }

};
int main()
{
    int edge ,vertex;
    cout<<"Enter the number of vertex and edge = ";
    cin>>vertex>>edge;
    Graph graph(vertex);
    for(int i=0;i<edge;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph.addNode(v1,v2);
    }
    graph.print();
    return 0;
}
