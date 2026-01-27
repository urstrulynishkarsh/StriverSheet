#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l1;
        vector<int> ans;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n)
        {
            // calculation
            while(l1.size()>0 && l1.back()<nums[j])
            {
                l1.pop_back();
            }
            l1.push_back(nums[j]);

            if(j-i+1<k)
            {
                j++;
            }

            else if(j-i+1==k)
            {
                // ans of calculation
                ans.push_back(l1.front());

                // shift window
                if(l1.front()==nums[i])
                {
                    l1.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    vector<int> result=maxSlidingWindow(arr,k);
    for(int val:result)
    {
        cout<<val<<" ";
    }
}