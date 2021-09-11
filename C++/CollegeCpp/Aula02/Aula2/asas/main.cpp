    #include <iostream>
    using namespace std;

        int main() {
            int soma=0;
            int numeros[10];
            cout << "Digite 10 numeros" << endl;
                for (int i=0;i<10; i++){
                   cin >>numeros[i];
                    if(numeros[i]>0){
                        soma+=numeros[i];
                    }
                    }

            cout << "Valor: " << soma;
        return 0;


    }
