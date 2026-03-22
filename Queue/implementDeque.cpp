#include<iostream>
using namespace std;
class Dequeue{
    public:
    int n;
    int *arr;
    int rear;
    int front;


    Dequeue(int size)
    {
        this->n=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }
    void pushfront(int val)
    {
        if(front==0)
        {
            cout<<"overflow"<<endl;
        }
        else if(front==-1 && rear==-1)
            {
                front++;
                rear++;
                arr[rear]=val;
            }
        else{
            front--;
            arr[front]=val;
        }
    }
    void pushback(int val){
          if(rear==n-1)
            {
                cout<<"overflow: "<<endl;
            }
            else if(front==-1 && rear==-1)
            {
                front++;
                rear++;
                arr[rear]=val;
            }
            else{
                rear++;
                arr[rear]=val;
            }
    }
    void popfront()
    {
        if(front==-1 && rear==-1)
            {
                cout<<"underflow"<<endl;
            }
            else if(front==rear)
            {
                arr[rear]=-1;
                rear=-1;
                front=-1;
            }
            else{
                arr[front]=-1;
                front++;
            }
    }
    void popback()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"underflow"<<endl;
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            arr[rear]=-1;
            rear--;
        }
    }
};

int main()
{
    Dequeue dq(10);
    dq.pushback(1);
    
}