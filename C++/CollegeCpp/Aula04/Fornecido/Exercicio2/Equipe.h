/*
 * Coloque a definicao da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 *
 *  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
 */
 #ifndef EQUIPE_H
 #define EQUIPE_H
 #include <string>
 #include <iostream>

 using namespace std;

class Equipe {
private:
    string nome;
    int numeroDeMembros = 0;
public:
    string getNome();
    int getNumeroDeMembros();
    void setNome(string nome);
    void setNumeroDeMembros(int membros);

    int getMaximoDeTorcedores();
    void imprimir();
};
#endif // EQUIPE_H
