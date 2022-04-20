#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        // Add all elements to hash map

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int newTarget = target - nums[i];
            if (m.count(newTarget) > 0 && i != m[newTarget]) {
                return {i, m[newTarget]};
            }
        }
        return {-1, -1};

    }
};

int main() {
    vector<int> nums = {3, 3};

    auto *s = new Solution();

    vector<int> ans = s->twoSum(nums, 6);
    cout << ans[0] << " " << ans[1];
}
