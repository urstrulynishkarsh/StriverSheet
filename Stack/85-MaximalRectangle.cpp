#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

 vector<int> NSL(vector<int>& heights)
    {
        vector<int> ans;
        stack<pair<int,int> >st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<heights[i])
            {
                ans.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                {
                    st.pop();
                }
                 if(st.empty())
                {
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        return ans;
    }

    vector<int> NSR(vector<int>& heights)
    {
        vector<int> ans;
        stack<pair<int,int> >st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(heights.size());
            }
            else if(st.size()>0 && st.top().first<heights[i])
            {
                ans.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                {
                    st.pop();
                }
                 if(st.empty())
                {
                    ans.push_back(heights.size());
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


int solve(vector<int> &heights)
{
    int maxi=INT_MIN;
    vector<int> prev=NSL(heights);
    vector<int> next=NSR(heights);

    for(int i=0;i<heights.size();i++)
    {
        int length=heights[i];
        int width=next[i]-prev[i]-1;
        int area=length*width;
        maxi=max(maxi,area);
    }
    return maxi;
}


int maximalRectangle(vector<vector<char>>& matrix, int row, int col) {
    int maxArea=INT_MIN;
    vector<int> heights(col,0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]=='1')
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
    int n;
    cout<<"Enter the row : ";
    cin>>n;
    int m;
    cout<<"Enter the col: ";
    cin>>m;
    vector<vector<char> > matrix(n,vector<char> (m));
    cout<<"Enter the element in the matrix: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<maximalRectangle(matrix,n,m);


}