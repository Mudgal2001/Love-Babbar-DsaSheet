#include<bits/stdc++.h>
using namespace std;

 
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
       int num=0;
       for(int i=0;i<nums.size();i++){
           num^=nums[i];
       }
       vector<int>ans;
       int b=num;
       int num1=1;
       while(!(b&1)){
           b>>=1;
           num1<<=1;
       }
       int n1=0;
       for(int i=0;i<nums.size();i++ ){
           if(nums[i]&num1){
               n1^=nums[i];
           }
       }
       int n2=n1^num;
       int n3=n2^num;
       ans.push_back(min(n2,n3));
       ans.push_back(max(n2,n3));
       return ans;
    }
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  