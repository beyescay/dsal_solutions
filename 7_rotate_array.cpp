// Rotate an array forward by k positions
#include <vector>
#include <iostream>

using std::vector;

void RotateArray(vector<int>& nums, int k) {

  if (nums.size() == 1 || k == 0 || k == nums.size()) {
      return;
  }

  for(int start = 0, moves = 0; moves < nums.size(); start++) {

    auto prev = nums[start];
    auto next = start;

    do{
        next = (next+k)%nums.size();
        auto temp = nums[next];
        nums[next] = prev;
        moves++;
        prev = temp;
    } while(start != next && moves < nums.size());

  }

}


template <typename T>
void PrintVector(vector<T> vec) {

  for(T e : vec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

}

int main() {
  vector<int> nums {1,2,3,4,5,6,7};
  int k = 3;
  PrintVector<int>(nums);
  RotateArray(nums, k);
  PrintVector<int>(nums);
}
