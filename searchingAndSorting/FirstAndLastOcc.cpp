#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}




int firstOcc(int arr[],int si,int ei,int k){
    int mid=si+(ei-si)/2;
    int ans=-1;
    while(si<=ei){
        if(arr[mid]==k){
            ans=mid;
            ei=mid-1;
        }else if(arr[mid]>k){
            ei=mid-1;
        }else{
            si=mid+1;
        }
        mid=si+(ei-si)/2;
    }
    return ans;
}
int lastOcc(int arr[],int si,int ei,int k){
    int mid=si+(ei-si)/2;
    int ans=-1;
    while(si<=ei){
        if(arr[mid]==k){
            ans=mid;
            si=mid+1;
        }else if(arr[mid]>k){
            ei=mid-1;
        }else{
            si=mid+1;
        }
        mid=si+(ei-si)/2;
    }
    return ans;}
vector<int> find(int arr[], int n , int x )
{
   vector<int>output;
   output.push_back(firstOcc(arr,0,n-1,x));
   output.push_back(lastOcc(arr,0,n-1,x));
   return output;
    
}