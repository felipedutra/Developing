#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream input;
  input.open ("dados.txt");

  int x;
  input >> x;
  string y;
  input >> y;

  input.close();

  cout << "x: " << x << " y: " << y << endl;

  ofstream output;
  output.open ("dados.txt");

  output << 10 << " " << "Teste";

  output.close();
}
