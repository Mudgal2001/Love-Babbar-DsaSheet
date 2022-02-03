class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int n=nums.size();
       int tortoise=0;
        int hare=0;
        while(true){
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
            if(tortoise==hare){
                break;
            }
        }
        tortoise=0;
        while(tortoise!=hare){
            hare=nums[hare];
           tortoise=nums[tortoise];
        }
        return hare;
    }    
};