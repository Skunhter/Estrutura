#include <iostream>
using namespace std;
#define MAXTAM 20

/*
    TADS LISTA EST�TICA
*/
struct Lista{
    char vetor[MAXTAM];
    int ultimo;
};

// lista => lista a ser inicializada
void inicializar(Lista &lista){
    lista.ultimo = -1;
}

// lista => lista a ser manipulada
// valor => valor a ser armazenado na lista
// ordem => ordem da inser��o: ''- sem ordem // 'C'-cresc // 'D'-descr
// Retorna true (inser��o OK) ou false (inser��o falhou)
bool inserir(Lista &lista, char valor, char ordem=' '){
    int pos;
    if( lista.ultimo == MAXTAM-1 ) return false;

    switch(ordem){
        case 'C':
            pos=0;
            while( pos <= lista.ultimo && valor > lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        case 'D':
            pos=0;
            while( pos <= lista.ultimo && valor < lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        default:
            lista.ultimo++;
            lista.vetor[lista.ultimo] = valor;
            break;
    }
    return true;
}

// lista => lista a ser usada na pesquisa
// valor => valor a ser procurado
// retorna a posi��o do valor ou -1 se n�o achou
int pesquisar(Lista lista, char valor, char ordem = ' '){
    switch (ordem) {
        case 'F':
            for (int i = lista.ultimo; i >= 0; i--) {
            if (lista.vetor[i] == valor) return i;
            }
            break;
        default:
            for (int i = 0; i <= lista.ultimo; i++) {
            if (lista.vetor[i] == valor) return i;
            }
    }
    return - 1;
}

// lista => lista a ser usada na retirada
// valor => valor a ser retirado
// retorna true (retirada ok) ou false (retirada falhou)
bool retirar(Lista &lista, char valor , char ordem = ' '){
    int pos;
    if (ordem == 'F') {
        pos = pesquisar(lista, valor, ordem);
    } else {
        pos = pesquisar(lista, valor);
    }
    
    if (pos == -1) {
        return false;
    } else {
        for(int i = pos; i <= lista.ultimo; i++) {
            lista.vetor[i] = lista.vetor[i + 1];
        }
    }
    lista.ultimo--;
    return true;
}

bool duplicar(Lista &novaLista, Lista lista) {
    for (int i = 0; i <= lista.ultimo; i++) {
        inserir(novaLista, lista.vetor[i]);
    } 
    return true;
}

void retirarRepetido(Lista &lista) { 

    for (int i = 0; i < lista.ultimo; i++) {
        while (pesquisar(lista, lista.vetor[i]) != pesquisar(lista, lista.vetor[i], 'F')) {
            retirar(lista, lista.vetor[i], 'F');
        }
    }
   
}



bool juntarListas(Lista &novaLista, Lista l1, Lista l2) {
    if (l1.ultimo + l2.ultimo > 20) {
        return false;
    } else {
        for (int i = 0; i <= l1.ultimo; i++) {
            inserir(novaLista, l1.vetor[i]);
    }   for (int i = 0; i <= l2.ultimo; i++) {
            inserir(novaLista, l2.vetor[i]);
    }
    }
    return true;
}


// Mostrar a lista na tela
void mostrar(Lista lista){
    for( int i=0; i<=lista.ultimo; i++ )
        cout << lista.vetor[i] << "\t";
}
/*
    FIM TADS
*/

int main(){
    Lista l1;
    Lista l2;
    Lista l3;

    inicializar(l1);
    inicializar(l2);
    inicializar(l3);
    inserir(l1, 'P', 'D');
    inserir(l1, 'E', 'D');
    inserir(l1, 'R', 'D');
    inserir(l1, 'N', 'D');
    inserir(l1, 'A', 'D');
    inserir(l1, 'M', 'D');
    inserir(l2, 'A', 'D');
    inserir(l2, 'R', 'D');
    inserir(l2, 'R', 'D');
    inserir(l2, 'R', 'D');
    inserir(l2, 'A', 'D');
    inserir(l2, 'M', 'D');
    int i = pesquisar(l1, 'M');
    cout << i << endl;
    retirar(l1, 'P');

    juntarListas(l3, l1, l2);
    

    cout << endl << "Lista 1: ";
    mostrar(l1);

    cout << endl << "Lista duplicada: ";
    mostrar(l2);

    cout << endl << "Lista juntada: ";
    mostrar(l3);

    retirarRepetido(l3);

    cout << endl << "Lista sem repetir: ";
    mostrar(l3);

}
