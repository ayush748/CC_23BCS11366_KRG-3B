#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};

int main() {
    Solution obj;
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for (auto subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
