//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
   {
       vector<int> vect,vect1;
       if(k==0)
           return vect;
       priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
       for(int i=0;i<k;i++)
       {
           q.push({arr[i][0],i});
           vect1.push_back(0);
       }
       int count = 0;
       while(count != k*k)
       {
          pair<int,int> p = q.top();
          vect.push_back(p.first);
          count++;
          q.pop();
          vect1[p.second]++;
          if(vect1[p.second] >= k)
               continue;
          q.push({arr[p.second][vect1[p.second]],p.second});
       }
      return vect; 
   }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends