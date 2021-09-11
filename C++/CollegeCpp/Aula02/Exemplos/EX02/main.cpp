#include <iostream>

using namespace std;

int main() {
    int i = 5;
    int *p = &i; //Atribui a p o endereço de i

    cout << i << endl;
    cout << *p << endl;
    cout << p << endl;
    cout << &i << endl;


    *p = 10;
    cout << *p << endl;
    cout << i << endl;
    cout << p << endl;
    cout << &i << endl;

  return 0;
}
