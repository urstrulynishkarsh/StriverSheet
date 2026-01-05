#include<iostream>
#include<vector>
#include<math.h>
#include<numeric>
using namespace std;

int sumFourDivisors(vector<int> &nums)
{
int sum=0;
    for(int val:nums)
    {
        vector<int> ans;
        for(int j=1;j*j<=val;j++)
        {
            if(val%j==0)
            {
                ans.push_back(j);
                if(j!=val/j)
                {
                    ans.push_back(val/j);
                }
            }
            if(ans.size()>4)
            {
                break;
            }
        }
         if (ans.size() == 4) {   // ✅ missing condition
                sum += accumulate(ans.begin(), ans.end(), 0);
            }
    }
    return sum;
    }
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    cout<<sumFourDivisors(nums);
}