class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mymap; 
        
        for (int i = 0; i < nums.size(); i++){
            int val = nums[i];
            if (mymap.find(target - val) == mymap.end()){
                mymap[val] = i;
            } else{
                return vector<int> {mymap[target - val], i};
            }
            
        }
        
        return vector<int> {};
    }
};
