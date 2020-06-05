#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> TwoSumTarget(vector<int>& nums, int target) {

        unordered_map<int, int> num_to_idx;
        vector<int> res;

        for(int i = 0; i < nums.size(); ++i) {

            if (num_to_idx.find(target-nums[i]) == num_to_idx.end()) {
                num_to_idx[nums[i]] = i;
            }

            else {
                res.push_back(i);
                res.push_back(num_to_idx[target-nums[i]]);
                return res;
            }
        }
        return res;
}

int main() {

  vector<int> nums{2, 4, 5, 7, 4, 9};
  int target = 8;
  auto res = TwoSumTarget(nums, target);

  for(auto i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

}
