

#include<bits/stdc++.h>
using namespace std;


 

class Solution{
    public:
    
    int countBitsFlip(int a, int b){
        
       int c=a^b;
       int cnt=0;
       while(c!=0){
           c&=(c-1);
           cnt++;
       }
        return cnt;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		int a,b;
		cin>>a>>b; 

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  