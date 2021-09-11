// FACA OS INCLUDES NECESSARIOS
#include<iostream>
#include<string>

using namespace std;

string* encontrarOponente(string nomes[], int membros[], int quantidade, string nomeEquipe, int membrosEquipe) {
        int j;
        bool truth =false;
        for(int i=0;i<quantidade;i++){
            if(membrosEquipe==membros[i]){
                    int compare = nomeEquipe.compare(nomes[i]);
                    if(compare!=0){
                    j=i;
                    truth=true;
                    }

            }
        }
        if(truth){

        return(&nomes[j]);
        }else{
        return(NULL);
        }


}

/* COMENTE A MAIN PARA SUBMETER
int main() {
    // FACA TESTES NA MAIN
   string nomes[] = {"Poli", "FEA", "ESALQ"};
   int membros[] = {10, 11, 9};
   int quantidade=3;
   string nomeEquipe={"Poli"};
   int membrosEquipe=10;

   cout << *encontrarOponente(nomes,membros,quantidade,nomeEquipe,membrosEquipe)<<endl;
  if(encontrarOponente(nomes,membros,quantidade,nomeEquipe,membrosEquipe)== NULL)
   cout << "Null"<<endl;

    return 0;
}
*/
