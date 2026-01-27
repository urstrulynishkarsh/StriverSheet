#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

string largestNumber(vector<int>& nums) {
        vector<string> number;
        for(int num:nums)
        {
            number.push_back(to_string(num));
        }
        sort(number.begin(),number.end(),[](string &s1, string &s2){
            string t1=s1+s2;
            string t2=s2+s1;
            return t1>t2;
        });
        if(number[0]=="0")
        {
            return "0";
        }
        string ans;
        for(string str:number)
        {
           ans+=str;
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

    

    cout<<largestNumber(arr);

    return 0;
    
   
}