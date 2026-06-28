#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(vector<string> arr, string s) {
  if (arr.size() == 0) {
    return "";
  }
  if (arr.size() == 1) {
    return arr[0];
  }

  string result = "";

  for (int i = 0; i < arr.size(); i++) {
    result += arr[i];
    if (i < arr.size() - 1) {
      result += s;
    }
  }

  return result;
}

int main() {
  // Example1
  vector<string> arr1 = {"join", "by", "space"};
  string s1 = " ";
  cout << join(arr1, s1) << endl;

  // Example2
  vector<string> arr2 = {"b", "", "k", "", "p", "r n", "", "d", "d!!"};
  string s2 = "ee";
  cout << join(arr2, s2) << endl;

  return 0;
}
