#include <iostream>
using namespace std;

int soma (int a) {
  return a;
}

int soma (int a, int b) {
  return a + b;
}

int soma (int a, int b, int c) {
  return a + b + c;
}

int main() {
  cout << "6 = " << soma (6) << endl;
  cout << "6 + 6 = " << soma (6, 6) << endl;
  cout << "6 + 6 + 6 = " << soma (6, 6, 6) << endl;
  return 0;
}
