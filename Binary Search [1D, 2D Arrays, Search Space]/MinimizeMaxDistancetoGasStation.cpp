#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


bool checkSolution(vector<int> &stations, int k, double mid)
    {
        int count=0;
        for(int i=1;i<stations.size();i++)
        {
            int diff=stations[i]-stations[i-1];
            if(diff>mid)
            {
                count+=diff/mid;
            }
        }
        if(count>k)
        {
            return false;
        }
        else{
            return true;
        }
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        double s=0;
        int n=stations.size();
        double e=stations[n-1]-stations[0];
        double ans=0;
        while(s<=e)
        {
            double mid=s+(e-s)/2;
            if(checkSolution(stations,K,mid))
            {
                ans=mid;
                e=mid-0.000001;
            }
            else{
                s=mid+0.000001;
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

    cout<<(double)minMaxDist(arr,k);

    return 0;
    
   
}