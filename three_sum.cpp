// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int res = 9999999;
        
        if (nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
                    
        int a, b, c, total;
        for (int i = 0; i < nums.size()-2; i++){
            // this line skips repeated a;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int start = i+1;
            int end = nums.size()-1;

            a = nums[i];
            while (start < end) {
                b = nums[start];
                c = nums[end];

                total = a + b + c;
                cout << a << " " << b << " " << c << endl;

                if (total == target) return total; 
                
                if (abs(total - target) < abs(res - target)) {
                    res = total;
                    cout << res << endl;
                }
                // start++;
                // end--;
                // // this 2 lines skip repeated b and c values;
                // while (start < end && nums[start] == nums[start-1]) start++;
                // while (start < end && nums[end] == nums[end+1]) end--;
                    
                if (total > target ){
                    end--;
                } else {
                    start++;
                }
            }
        }
        return res;        
    }
};


int main()
{

    Solution* sol = new Solution();

    // vector<int> nums {0, 2, 1, -3};
    vector<int> nums {-3,-2,-5,3,-4};

    cout << sol->threeSumClosest(nums, 1) << endl;
}

