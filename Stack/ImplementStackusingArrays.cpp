#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int size;

        Stack(int size)
        {
            arr=new int[size];
            this->size=size;
            top=-1;
        }


        void push(int data)
        {
            if(size-top>1)
            {
                top++;
                arr[top]=data;
            }
            else{
                cout<<"stack is overflow";
                return;
            }
        }

        void pop()
        {
            if(top==-1)
            {
                cout<<"stack is underflow";
                return;
            }
            else{
                top--;
            }
        }

        int getsize()
        {
            return top+1;
        }

        bool isempty(){
            if(top==-1)
            {
                return true;
            }
            else{
                return false;
            }
        }

        int topelement()
        {
            if(top==-1)
            {
                cout<<"stack is empty";
            }
            else{
                return arr[top];
            }
        }
};


int main()
{
    Stack s(10);
    cout<<s.topelement();
    cout<<endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.getsize();
    
}