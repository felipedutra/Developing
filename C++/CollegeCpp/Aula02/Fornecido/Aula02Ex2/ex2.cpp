#include <iostream>
using namespace std;

int calcularEstatisticas (int membros[], int quantidade, int* minimo, int& maximo) {
    int soma=0;
    if(quantidade){
        *minimo=membros[0];
            maximo=membros[0];
            for(int i=0;i<quantidade;i++){
                soma+=membros[i];
                if(*minimo>membros[i]){
                    *minimo=membros[i];
                 }
                 if(maximo<membros[i]){
                    maximo=membros[i];
                 }
            }
    }else{
    *minimo=0;
    maximo=0;
    }
    return(soma);
}

//COMENTE A MAIN PARA SUBMETER
int main() {
    int i;
    int minimo=0;
    int maximo=0;
    int membros[] = {10, 9, 10};
    int quantidade=3;



   i=calcularEstatisticas (membros,quantidade,& minimo, maximo);
   cout << i << minimo << maximo << endl;
    return 0;
}

