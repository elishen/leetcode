// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<char>& heights) {
        stack<int> s;

        int max_area = 0; 
        int tp;  
        int area_with_top; 

        int i = 0;
        while (i < heights.size() || ! s.empty())
        {
            if (s.empty() || (i < heights.size() && heights[s.top()] <= heights[i]))
                s.push(i++);
            else
            {
                tp = s.top();  
                s.pop();  
                area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < area_with_top) max_area = area_with_top;
            }

        }

        return max_area;
    }        

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int max_area = 0;
        int tmp_area = 0;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == '0') matrix[i][j] = 0;
                else 
                    matrix[i][j] = i==0 ? 1 : matrix[i-1][j] + 1;
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            tmp_area = largestRectangleArea(matrix[i]);
            if (tmp_area > max_area) max_area = tmp_area;
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

    vector<vector<char>> nums;

    nums.push_back({'1', '0', '1', '0', '0'});
    nums.push_back({'1', '0', '1', '1', '1'});
    nums.push_back({'1', '1', '1', '1', '1'});
    nums.push_back({'1', '0', '0', '1', '0'});

    cout << sol->maximalRectangle(nums) << endl;

}

