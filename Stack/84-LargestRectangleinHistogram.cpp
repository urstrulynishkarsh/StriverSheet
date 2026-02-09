#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


vector<int> prevSmallerElementIndex(vector<int>& heights)
    {
        stack<int> st;
        int size=heights.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++)
        {
            int curr=heights[i];
            while(!st.empty() && heights[st.top()]>=curr)
            {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElementIndex(vector<int>& heights)
    {
        stack<int> st;
        int size=heights.size();
        vector<int> result(size);
        for(int i=size-1;i>=0;i--)
        {
            int curr=heights[i];
            while(!st.empty() && heights[st.top()]>=curr)
            {
                st.pop();
            }
            result[i]=st.empty()?size:st.top();
            st.push(i);
        }
        return result;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=prevSmallerElementIndex(heights);
        vector<int> next=nextSmallerElementIndex(heights);
        int maxarea=INT_MIN;
        int size=heights.size();
        for(int i=0;i<size;i++)
        {
            int length=heights[i];
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    

    

    cout<<largestRectangleArea(arr);

    return 0;
    
   
}