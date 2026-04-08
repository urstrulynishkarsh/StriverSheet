#include<iostream>
using namespace std;

class Heap{
    public:
    int capacity;
    int *arr;
    int index;


    Heap(int capacity)
    {
        this->capacity=capacity;
        arr=new int[capacity];
        index=0;
    }

    void print()
    {
        cout<<"printing the heap: ";
        for(int i=0;i<capacity;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int value)
    {
        if(index>=capacity-1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        index=index+1;
        arr[index]=value;
        int i=index;
        while(i>1)
        {
            int parentindex=i/2;
            if(arr[i]>arr[parentindex])
            {
                swap(arr[i],arr[parentindex]);
                i=parentindex;
            }
            else{
                break;
            }
        }
    }

    void deletefromheap()
    {
        swap(arr[1],arr[index]);
        index--;
        heapify(arr,index,1);
    }

    void heapify(int *arr, int n, int currentindex)
    {
        int i=currentindex;
        int leftindex=2*i;
        int rightindex=2*i+1;

        int largestkaindex=i;

        if(leftindex<n && arr[leftindex]>arr[largestkaindex])
        {
            largestkaindex=leftindex;
        }
        if(rightindex<n && arr[rightindex]>arr[largestkaindex])
        {
            largestkaindex=rightindex;
        }

        if(largestkaindex!=i)
        {
            swap(arr[i],arr[largestkaindex]);
            i=largestkaindex;
            heapify(arr,n,i);
        }



    }
};

void heapify(int *arr, int n, int currentindex)
    {
        int i=currentindex;
        int leftindex=2*i;
        int rightindex=2*i+1;

        int largestkaindex=i;

        if(leftindex<n && arr[leftindex]>arr[largestkaindex])
        {
            largestkaindex=leftindex;
        }
        if(rightindex<n && arr[rightindex]>arr[largestkaindex])
        {
            largestkaindex=rightindex;
        }

        if(largestkaindex!=i)
        {
            swap(arr[i],arr[largestkaindex]);
            i=largestkaindex;
            heapify(arr,n,i);
        }



    }

    void buildheap(int *arr, int n)
    {
        for(int i=n/2;i>0;i--)
        {
            heapify(arr,n,i);
        }
    }



    void heapsort(int *arr, int n)
    {
        int e=n-1;
        while(e>1)
        {
            swap(arr[1],arr[e]);
            e--;
            heapify(arr,e+1,1);
        }
    }

int main()
{
    Heap pq(10);
    pq.arr[0]=-1;
    pq.insert(100);
    pq.insert(50);
    pq.insert(60);


    pq.print();


    pq.insert(110);
    pq.print();


    pq.deletefromheap();
    pq.print();

    int arr[]={-1,10,20,30,40,50};
    int n=6;
    buildheap(arr,n);
    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
     for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}