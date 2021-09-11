#include <iostream>
#include <string>

using namespace std;


string* encontrarOponente(string nomes[], int membros[], int quantidade, string nomeEquipe, int membrosEquipe) {
    int *j;
    j=NULL;
    int achou=0;

    for(int i=0;i<quantidade-1;i++){
                cout << "contra2" << endl;

        if(membrosEquipe==membros[i]){
            // Achou um oponente
            *j=i;
            achou=1;
        }

    }
    if(achou==1){
    cout << " puto" << endl;

   // return(nomes[*j]);
    }

}
/* COMENTE A MAIN PARA SUBMETER */
int main() {
    // FACA TESTES NA MAIN
    string nomes[] = {"Poli", "FEA", "ESALQ"};
     int membros[] = {10, 9, 10};
     int quantidade=3;
    string nomeEquipe={"Poli"};
    cout << nomeEquipe << " contra" << endl;

    cout << encontrarOponente(nomes,membros, quantidade,nomeEquipe, 10) << endl;
    return 0;
}
//*/
