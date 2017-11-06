// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (start < end) {
            // if duplicates exist;
            
            while (nums[start] == nums[start+1]) start++;
            while (nums[end] == nums[end-1]) end--;

            mid = (start + end) / 2;
            if (nums[mid] > nums[end] ) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};

void print_vec2(vector<vector<int>> v){

    for (vector<int> u : v){
        for (int i : u) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{

    Solution* sol = new Solution();

    // vector<int> nums {0, 2, 1, -3};
    // vector<int> nums {-3,-2,-5,3,-4};

    // cout << sol->threeSumClosest(nums, 1) << endl;

    vector<int> nums {2, 1};

    cout << sol->findMin(nums) << endl;

}

