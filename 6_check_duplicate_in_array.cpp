// Check if an array has duplicate elements

#include <vector>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::unordered_set;

bool ContainsDuplicateInArray(vector<int>& nums) {

  unordered_set<int> num_set;

  for(auto num : nums) {

      if (num_set.find(num) != num_set.end()) {
          return true;
      }

      num_set.insert(num);

  }

  return false;

}

int main() {

  vector<int> a{1,2,3,4};
  vector<int> b{1,2,3,1};

  std::cout << "Has duplicate? " << ContainsDuplicateInArray(a) << std::endl;
  std::cout << "Has duplicate? " << ContainsDuplicateInArray(b) << std::endl;

}
