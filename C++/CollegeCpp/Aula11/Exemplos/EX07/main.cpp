#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	list<int>* valores = new list<int>();

	for (int i = 0; i < 10; i++) {
		valores->push_back(i);
	}

	list <int>::iterator valor =
		find(valores->begin(), valores->end(), 8);

	if (valor!= valores->end() )
		cout << "Encontrou o " << *valor << endl;
	else cout << "Nao encontrou" << endl;

  return 0;
}
