// Find max sum of sub array

#include <vector>
#include <iostream>

using std::vector;

int MaxSubArraySum(vector<int>& nums) {

  int max_sum = nums[0];

  for(int i = 0, curr_sum = 0; i < nums.size(); ++i) {

      curr_sum += nums[i];

      curr_sum = curr_sum > nums[i] ? curr_sum : nums[i];
      max_sum = curr_sum > max_sum ? curr_sum : max_sum;

  }

  return max_sum;

}

int main() {

  vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

  std::cout << MaxSubArraySum(nums) << std::endl;
}
