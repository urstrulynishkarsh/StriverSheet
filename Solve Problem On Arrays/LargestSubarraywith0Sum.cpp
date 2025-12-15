#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int LongestSubarraywithsum0(vector<int>& nums) {
        
    unordered_map<int,int> hashmap;
    int prefix=0;
    int maxlen=0;
    hashmap[0]=-1;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        prefix+=nums[i];
        if(hashmap.find(prefix)!=hashmap.end())
        {
            int length=i-hashmap[prefix];
            maxlen=max(maxlen,length);
        }
        else{
            hashmap[prefix]=i;
        }
    }
    return maxlen;
    

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
   
    

    cout<<LongestSubarraywithsum0(arr);
   

    return 0;
    
   
}