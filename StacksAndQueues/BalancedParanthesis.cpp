#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        stack<char>s1;
        int i=0;
        for(int i=0;i<n;i++){
            if(x[i]=='{' || x[i]=='[' || x[i]=='('){
                s1.push(x[i]);
            }else{
                if(s1.size()==0){
                    return false;
                }else if(x[i]=='}'){
                    if(s1.top()=='{'){
                        s1.pop();
                    }else{
                        return false;
                    }
                }else if(x[i]==']'){
                    if(s1.top()=='['){
                        s1.pop();
                    }else{
                        return false;
                    }
            }else if(x[i]==')'){
                    if(s1.top()=='('){
                        s1.pop();
                    }else{
                        return false;
                    }
        }
    }
  }
  if(s1.empty()){
      return true;
  }
  return false;
}
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends