#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int Queue[MAX];
int rear = -1,front = -1;
void enqueue(int value)
{
    if(rear>= MAX-1)
    {
        cout<<"Overflow"<<endl;
    }
    else if(rear==-1&&front==-1)
    {
        rear = front = 0;
        Queue[rear] = value;
    }
    else
    {
        rear++;
        Queue[rear] = value;
    }
}

int Deque()
{
    if(rear==-1&&front == -1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(rear == front)
    {
        return Queue[front];
        rear = front =-1;
    }
    else
    {
        int x = Queue[front];
        front++;
        return x;
    }
}

  void Display()
    {
        if(rear==-1&&front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            for(int i = front;i<=rear;i++)
            {
                cout<<Queue[i]<<" ";
            }
            cout<<endl;
        }
    }
int main()
{
    cout<<"Enter the number of element of the Queue = ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" number :"<<endl;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        enqueue(value);
    }
    cout<<Deque()<<" has been popped from the Queue "<<endl;

    cout<<"Again enter a value = ";
    int val;
    cin>>val;
    enqueue(val);

    cout<<"All elements of the Queue :"<<endl;
    Display();

    return 0;

}

