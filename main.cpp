#include <iostream>
#include <lue.hpp>
#include <stdio.h>

using namespace std;


int encontrarHash(string valor) {
    int soma = 0, posicao;
    for (int i = 0; i < valor.length(); i++) {
      soma = valor[i] + soma;
    }
    posicao = soma%20;
    return posicao;
}

int main()
{
    string cidade;
    int opcao;
    LUE <string> cidades[20];
    for (int i = 0; i < 20; i++) {
        inicializarLUE(cidades[i]);
    }
    do{
            cout << "Voce deseja inserir ou retirar: " << endl;
            cout << "1: Inserir" << "\n2: Retirar" << endl;
            cout << "Resposta: ";
            cin >> opcao;
            if (opcao == 1) {
                cout << "Digite uma cidade para inserir (fim-terminar): ";
                while(getline(cin, cidade))
                   if(cidade != ""){
                          break;
                    }
                if( cidade != "fim" && cidade != " " && cidade.length() > 0){
                    int pos = encontrarHash(cidade);
                    inserirLUE(cidades[pos], cidade);
                    for (int i = 0; i < 20; i++) {
                        cout << i << ": ";
                        mostrarLUE(cidades[i]);
                        cout << endl;
                    }
                 }
            } else if (opcao == 2) {
                for (int i = 0; i < 20; i++) {
                    cout << i << ": ";
                    mostrarLUE(cidades[i]);
                    cout << endl;
                }
                cout << "Digite uma cidade para retirar (fim-terminar): ";
                while(getline(cin, cidade))
                   if(cidade != ""){
                          break;
                    }
                if( cidade != "fim" && cidade != " " && cidade.length() > 0){
                    int pos = encontrarHash(cidade);
                    if (!retirarLUE(cidades[pos], cidade)) {
                          cout << "Cidade nao listada." << endl;
                    } else {
                        system("cls");
                        for (int i = 0; i < 20; i++) {
                            cout << i << ": ";
                            mostrarLUE(cidades[i]);
                            cout << endl;
                        }
                    }
                 }
            }
            system("pause");
            system("cls");
        }while( cidade != "fim" );

    return 0;
}
