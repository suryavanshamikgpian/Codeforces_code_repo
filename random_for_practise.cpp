#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "Hello World";
  cout << "Initially: " << str << endl;

  str.erase(0,2);
  cout << "After using erase(): " << str;
  return 0;
}