#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int n;
     int *arr;
     int front;
     int rear;

    CircularQueue(int size)
    {
         this->n=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }

    void push(int val)
    {
        if((front==0 && rear==n-1)||rear==front-1)
        {
            cout<<"Overflow"<<endl;
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        else if(rear==n-1 && front!=0)
        {
            rear=0;
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
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==n-1)
        {
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    int getfront()
    {
        if(front==-1)
        {
            cout<<"queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }

    int getsize()  
    {
        if(front==-1 && rear==-1)
        {
            return 0;
        }
        else if(rear>=front)
        {
            rear-front+1;
        }
        else if(rear==front)
        {
            return 1;
        }
        else{
            return n-rear+front+1;
        }
    }

    bool isempty()
    {
        if(front==-1 && rear==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    CircularQueue q(10);
    q.push(1);
}