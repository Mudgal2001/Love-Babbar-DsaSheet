// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int ci=i;
        while(ci>0){
            int pi=(ci-1)/2;
            if(arr[pi]>arr[ci]){
                swap(arr[pi],arr[ci]);
                  ci=pi;
            }else{
                return ;
            }
        }
        return ;
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    int size=n;
       while(size){
           swap(arr[0],arr[size-1]);
           size--;
           int pi=0;
           int ci=1;
           int ci1=1;
           int ci2=2;
           while(ci1<size){
               int m=arr[pi];
               if(m>arr[ci1]){
                   m=arr[ci1];
                   ci=ci1;
               }
               if(m>arr[ci2] && ci2<size){
                   m=arr[ci2];
                   ci=ci2;
               }
               if(m==arr[pi]){
                   break;
               }
               swap(arr[pi],arr[ci]);
               pi=ci;
               ci1=pi*2+1;
               ci2=pi*2+2;
           }
       }
       reverse(arr,arr+n);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
       for(int i=0;i<n;i++){
           heapify(arr,n,i);
           
       }
       buildHeap(arr,n);
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends