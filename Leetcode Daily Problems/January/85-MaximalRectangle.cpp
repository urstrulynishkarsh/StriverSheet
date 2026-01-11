#include<iostream>
#include<vector>
using namespace std;

vector<int> prevSmallerElementIndex(vector<int> &heights)
    {
        vector<int> ans(heights.size());
        stack <int> st;
        for(int i=0;i<heights.size();i++)
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

    vector<int> nextSmallerElementIndex(vector<int> &heights)
    {
         vector<int> ans(heights.size());
        stack <int> st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            int curr=heights[i];
            while(!st.empty() && heights[st.top()]>=curr)
            {
                st.pop();
            }
            ans[i]=st.empty()?heights.size():st.top();
            st.push(i);
        }
        return ans;
    }
    int solve(vector<int> &heights)
    {
        vector<int> prev=prevSmallerElementIndex(heights);
        vector<int> next=nextSmallerElementIndex(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int length=heights[i];
            int width=next[i]-prev[i]-1;
            maxArea=max(maxArea,length*width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> heights(col);
        int maxArea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==1)
                {
                    heights[j]+=1;
                }
                else{
                    heights[j]=0;
                }
            }
            maxArea=max(maxArea,solve(heights));
        }
        return maxArea;
    }
int main()
{
    int n,m;
    cout<<"Enter the size of row: ";
    cin>>n;
    cout<<"Enter the size of col: ";
    cin>>m;

    vector<vector<int> >matrix(n,vector<int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
   

  
    cout<<maximalRectangle(matrix);




    

}