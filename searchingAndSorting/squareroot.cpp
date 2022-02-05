#include<bits/stdc++.h>
using namespace std;

  

 
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int ans=1;
        long long int si=1;
    long long int ei=x;
    long long int mid=si+(ei-si)/2;
    while(si<=ei){
        if(mid*mid==x){
            return mid;
        }else if(mid*mid>x){
            ei=mid-1;
        }else{
            ans=mid;
            si=mid+1;
            
        }
        mid=si+(ei-si)/2;
    }
    return ans;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
 