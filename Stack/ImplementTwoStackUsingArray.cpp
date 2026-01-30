#include<iostream>
using namespace std;

class Stack{
    public:
    int top1;
    int top2;
    int *arr;
    int size;

    Stack(int size)
    {
        arr=new int[size];
        top1=-1;
        top2=size;
        this->size=size;
    }

    void push1(int data)
    {
        if(top2-top1==1)
        {
            cout<<"stack is overflow";
            return;
        }
        else{
            top1++;
            arr[top1]=data;
        }  
    }

    void push2(int data)
    {
        if(top2-top1==1)
        {
            cout<<"stack is overflow";
            return;
        }
        else{
            top2--;
            arr[top2]=data;
        }  
    }

    void pop1()
    {
        if(top1==-1)
        {
            cout<<"stack is underflow";
            return;
        }
        else{
            top1--;
        }

    }

    void pop2()
    {
        if(top2==size)
        {
            cout<<"stack is underflow";
            return;
        }
        else{
            top2++;
        }
        
    }


};

int main()
{
    Stack s(10);

    s.push1(10);
    s.push2(20);

    

}