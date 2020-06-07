// Return first recurring character of an array

#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::unordered_set;
using std::vector;
using std::string;
using std::stringstream;

template<typename T>
T FirstRecurringCharacter(const vector<T>& vec) {

  unordered_set<T> char_set;

  for(auto c : vec) {

    if (char_set.find(c) == char_set.end()) {
      char_set.insert(c);
    }
    else {
      return c;
    }

  }

  T t;
  return t;

}


int main() {

  string text;
  std::getline(std::cin, text);
  stringstream ss(text);

  vector<string> word;

  while(ss){
    string c;
    ss >> c;
    word.push_back(c);
  }

  std::cout << FirstRecurringCharacter<string>(word) << std::endl;
  
}
