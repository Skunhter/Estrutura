#include <iostream>
using namespace std;

struct No{
    char info;
    No *eloP, *eloA;
};

struct LDE{
    No *comeco;
    No *fim;
};

void inicializarLDE(LDE &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

void mostrarLDE(LDE lista, char ordem= ' '){

    if (ordem == ' ' || ordem == 'C') {
       No *aux = lista.comeco;
       while( aux != NULL ){
           cout << aux->info << " ";
           aux = aux->eloP;
       }
    } else if (ordem == 'D') {
       No *aux = lista.comeco;
       while( aux != NULL ){
           cout << aux->info << " ";
           aux = aux->eloA;
       }
    }
}

bool inserirLDE(LDE &lista, char valor){
    No *novo;
    No *aux = lista.comeco;

    // Criar o novo no
    novo = new No;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->eloP = NULL;
    novo->eloA = NULL;

    // Lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }



    // Inser��o no comeco
    if( valor <= lista.comeco->info ){
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
        return true;
    }

    // Inser��o no final
    if( valor >= lista.fim->info ){
       lista.fim->eloP = novo;
       novo->eloA = lista.fim;
       lista.fim = novo;
       return true;
    }


    // Inserir no meio

    while ( aux->info < valor && valor > aux->eloP->info ) {
        aux = aux->eloP;
    }
    novo->eloA = aux;
    novo->eloP = aux->eloP;
    aux->eloP = novo;
    aux->eloP->eloA = novo;
    return true;
}

 No * pesquisarLDE (LDE &lista, char valor) {
   No *aux = lista.comeco;

   while (aux != NULL) {
       if (aux->info == valor) return aux;
       aux = aux->eloP;
   }

   return NULL;
}

bool retirarLDE(LDE &lista, char valor) {
    No *aux = lista.comeco;

    while (aux != NULL && aux->info != valor) {
        aux = aux->eloP;
    }

    if (aux == NULL) return false;

    if (aux == lista.comeco) {
        lista.comeco = lista.comeco->eloP;
        lista.comeco->eloA = NULL;
        if (aux == lista.fim) lista.fim = NULL;
    } else {
        aux->eloA = aux->eloP;
        aux->eloP = aux->eloA;
        if (aux == lista.fim) lista.fim = aux->eloA;
    }
    delete aux;
    return true;
}



void liberarLDE(LDE &lista){
    No *aux = lista.comeco;
    No *aux2;

    while( aux != NULL ){
        aux2 = aux->eloP;
        delete aux;
        aux = aux2;
    }
}

int main(){
    LDE lista1;

    inicializarLDE(lista1);

    inserirLDE(lista1, 'C');
    inserirLDE(lista1, 'B');
    inserirLDE(lista1, 'A');
    inserirLDE(lista1, 'C');
    inserirLDE(lista1, 'D');
    inserirLDE(lista1, 'A');
    inserirLDE(lista1, 'B');
    inserirLDE(lista1, 'U');
    inserirLDE(lista1, 'C');
    inserirLDE(lista1, 'O');

    retirarLDE(lista1, 'A');
    retirarLDE(lista1, 'A');


    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);

    liberarLDE(lista1);

    cout << endl;
}
