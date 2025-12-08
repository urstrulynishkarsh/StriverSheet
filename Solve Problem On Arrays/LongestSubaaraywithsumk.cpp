#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int LongestSubarraywithsumK(vector<int>& nums, int k) {
        
    unordered_map<int,int> hashmap;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<nums.size();i++)
    {   
        sum+=nums[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(hashmap.find(rem)!=hashmap.end())
        {
            int len=i-hashmap[rem];
            maxlen=max(maxlen,len);
        }
        // don't update again and again so apply condition  here
        // hashmap[sum]=i;

        if(hashmap.find(sum)==hashmap.end())
        {
            hashmap[sum]=i;
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    

    cout<<LongestSubarraywithsumK(arr,k);
   

    return 0;
    
   
}