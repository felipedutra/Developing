#include <iostream>
using namespace std;

int calculaPontuacao(int posicao, bool participou) {
    int m;
    int pontos[]={7,5,4,3,1,0};

    if(posicao<6&&participou){
        m=pontos[posicao-1];
     }else {
     m=0;
     }
     return(m);
}

int calculaPontuacaoFinal(int posicoes[], bool participou[],int quantidade) {
    int pontos=0;
    for(int i=0;i<quantidade;i++){

    pontos+=calculaPontuacao(posicoes[i],participou[i]);
    }
    cout<<pontos;
    return(pontos);


}


bool nomesIguais(string nomes[], int quantidade) {




}



 COMENTE A MAIN PARA SUBMETER
int main() {
int posicoes[]={3,1,1};
bool participou[]={true,true,false};
 // cout<<calculaPontuacao(3,true);
// calculaPontuacaoFinal(posicoes,participou,3);
    return 0;
}
*/
