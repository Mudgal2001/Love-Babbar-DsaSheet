#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
    public: 
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
     vector<int>ans;
    int srow=0;
    int scol=0;
    int erow=r-1;
    int ecol=c-1;
    int count=r*c-1;
    int i=0;
    while(i<=count){
        for(int j=scol;i<=count&&j<=ecol;j++){
            ans.push_back(matrix[srow][j]);
             i++;
        }
          srow++;
        for(int j=srow;i<=count&&j<=erow;j++){
           ans.push_back(matrix[j][ecol]);
            i++;
        }
        ecol--;
        for(int j=ecol;i<=count&&j>=scol;j--){
            ans.push_back(matrix[erow][j]);
            i++;
        }
        erow--;
        for(int j=erow;i<=count&&j>=srow;j--){
            ans.push_back(matrix[j][scol]);
            i++;
        }
        scol++;
        
    }
    return ans;

    }
};


int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  