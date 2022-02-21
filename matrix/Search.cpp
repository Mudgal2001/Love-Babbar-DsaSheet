class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        
        int nrow=matrix.size();
        int ncol=matrix[0].size();
        int j=ncol-1;
        while(i<nrow){
            if(target<matrix[i][j]){
                int si=0;
                int ei=j;
                int mid=si+(ei-si)/2;
                while(si<=ei){
                    if(matrix[i][mid]==target){
                        return true;
                    }else if(matrix[i][mid]>target){
                        ei=mid-1;
                    }else{
                        si=mid+1;
                    }
                    mid=si+(ei-si)/2;
                }
                return false;
            }else{
                i++;
            }
        }
        return false;
    }
};