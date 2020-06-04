#include <string>
#include <iostream>

using std::string;

void reverse(string& s){

  if (s.size() < 2){
    return;
  }

	for(int i = 0; i < s.size()/2; i++){
		auto temp = s[i];
		s[i] = s[s.size()-1-i];
		s[s.size()-1-i] = temp;
	}

}

int main(){
	string s = "Hi my name is sarath";
	reverse(s);
  std::cout << s << std::endl;
}
