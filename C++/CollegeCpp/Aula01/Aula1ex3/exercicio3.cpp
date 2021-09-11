#include <iostream>
#include <string>
using namespace std;

bool nomesIguais(string nomes[], int quantidade) {
    bool m=false;
    for(int i=0;i<quantidade;i++){
        for(int j=i+1;j<quantidade;j++){
        if(nomes[i]==nomes[j]){
            m=true;
        }
    }
}
        return(m);
}
/*
int main()
{
  string nomes[] = {"Poli", "FEA", "ECA", "FFLCH", "EACH"};
  int quantidade=5;
    cout << nomesIguais(nomes,quantidade)<< endl;
    return 0;
}
*/
