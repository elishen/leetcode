// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;

        int max_area = 0; // Initalize max area
        int tp;  // To store top of stack
        int area_with_top; // To store area with top bar as the smallest bar

        // Run through all bars of given histogram
        int i = 0;
        while (i < heights.size())
        {
            // If this bar is higher than the bar on top stack, push it to stack
            if (s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);

            // If this bar is lower than top of stack, then calculate area of rectangle 
            // with stack top as the smallest (or minimum height) bar. 'i' is 
            // 'right index' for the top and element before top in stack is 'left index'
            else
            {
                tp = s.top();  // store the top index
                s.pop();  // pop the top

                // Calculate the area with hist[tp] stack as smallest bar
                area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);

                // update max area, if needed
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }

            // this following block is for tracing the execution of program;
            /*
            stack<int> tmps;

            cout << "Item: " << heights[i] << "  Max: " << max_area << endl; 
            while (!s.empty()){
                int val = s.top();
                s.pop();
                cout << heights[val] << " ";
                tmps.push(val);
            }
            cout << endl;

            while (!tmps.empty()){
                int val = tmps.top();
                tmps.pop();
                s.push(val);
            }
            */
        }

        // Now pop the remaining bars from stack and calculate area with every
        // popped bar as the smallest bar
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }        
};

void print_vec(vector<int> v){

    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}


int main()
{

    Solution* sol = new Solution();

    // vector<int> nums {0, 2, 1, -3};
    // vector<int> nums {-3,-2,-5,3,-4};

    // cout << sol->threeSumClosest(nums, 1) << endl;

    vector<int> nums {2, 1, 5, 6, 2, 3};

    cout << sol->largestRectangleArea(nums) << endl;

}

