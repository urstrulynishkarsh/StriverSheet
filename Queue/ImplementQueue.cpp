#include<iostream>
using namespace std;

class Queue{
    public:
        int n;
        int front;
        int rear;
        int *arr;

        Queue(int size)
        {
            arr=new int[size];
            n=size;
            front=-1;
            rear=-1;
        }
        void push(int val)
        {
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
        void pop()
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
        int getRear(){
            if(rear==-1)
            {
                cout<<"Queue is Empty"<<endl;
            }
            else{
                return arr[rear];
            }
        }
        int getFront(){
            if(front==-1)
            {
                cout<<"Queue is Empty"<<endl;
            }
            else{
                return arr[front];
            }
        }
        int getSize(){
            if(front==-1 && rear==-1)
            {
                return 0;
            }
            else{
                return rear-front+1;
            }
        }

        bool isEmpty()
        {
            if(front==-1 && rear==-1)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    Queue q(10);
    q.push(10);
    q.push(20);
    cout<<q.getSize();

}