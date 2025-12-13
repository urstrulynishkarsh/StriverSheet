#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int maxlength=1;
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        unordered_set<int> st;
        for(int val:nums)
        {
            st.insert(val);
        }

        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end())
                {
                    count++;
                    x++;
                }
                maxlength=max(maxlength,count);
            }
        }
        return maxlength;

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

    

    cout<<longestConsecutive(arr);

    return 0;
    
   
}