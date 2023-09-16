#ifndef LUE_HPP
#define LUE_HPP

#endif // LUE_HPP

#include <iostream>
using namespace std;

/*5. Usando algum conjunto de chaves (por exemplo, nomes de cidades do estado de SC), faça o seguinte:
a) Escreva e teste um programa que carregue as chaves em uma tabela Hash com M=20 e colisão tratada por
encadeamento;
b) Escreva um programa para gerenciar inserções e remoções na tabela.
*/

#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No *elo;
};

template <typename T>
struct LUE{
    No <T> *comeco;
    No <T> *fim;
};

//
// Inicializa a lista dada por par�metro
//
template <typename T>
void inicializarLUE(LUE <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

//
// Mostra todo o conte�do da lista na tela
//
template <typename T>
void mostrarLUE(LUE <T> lista){
    No <T> *aux = lista.comeco;

    while( aux != NULL ){
        cout << aux->info << " ";
        aux = aux->elo;
    }
    if( lista.comeco == NULL ) cout << "<Vazio>";
}


template <typename T>
bool inserirLUE(LUE <T> &lista, T valor){
    No <T> *novo;

    // Criar o novo no
    novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elo = NULL;

    // Lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    lista.fim->elo = novo;
    lista.fim = novo;
    return true;
}

//
// Pesquisar se o valor est� na lista
// retornar o endere�o do valor ou nulo se n�o estiver
//
template <typename T>
No <T> * pesquisarLUE(LUE <T> lista, T valor){
    No <T> *aux = lista.comeco;

    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->elo;
    }
    return NULL;
}

//
// Retirar o valor da lista
// retornar verdadeiro ou false se n�o achar
//
template <typename T>
bool retirarLUE(LUE <T> &lista, T valor ){
    No <T> *aux = lista.comeco, *anterior=NULL;

    while( aux != NULL && aux->info != valor ){
        anterior = aux;
        aux = aux->elo;
    }
    if( aux == NULL ) return false;

    if( aux == lista.comeco ){ // Casos 1 e 2
        lista.comeco = lista.comeco->elo;
        if( aux == lista.fim ) lista.fim = NULL;
    } else { // Casos 3 e 4
        anterior->elo = aux->elo;
        if( aux == lista.fim ) lista.fim = anterior;
    }
    delete aux;
    return true;
}

//
// Libera toda a mem�ria alocada para a lista fornecida
//
template <typename T>
void liberarLUE(LUE <T> &lista){
    No <T> *aux = lista.comeco;
    No <T> *aux2;

    while( aux != NULL ){
        aux2 = aux->elo;
        delete aux;
        aux = aux2;
    }
}



