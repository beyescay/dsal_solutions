// Move all zeros to the end preserving the order of non-zero elements

#include <vector>
#include <iostream>

using std::vector;

void MoveZeroesToEnd(vector<int>& nums) {

  for(int z = 0, cur = 0; cur < nums.size(); cur++) {

      if (nums[cur] != 0) {
          std::swap(nums[cur], nums[z++]);
      }

  }

}

int main() {

  vector<vector<int>> nums{ {0,1,0,3,12}, {0,0,0,0,12}, {2,1,3,3,12}, {1,0,3, 0,12}};

  for(auto num : nums) {
    MoveZeroesToEnd(num);
    for(auto n : num) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
  }
}
