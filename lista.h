#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

    typedef struct node Node;
    typedef struct sll Sll;

    Sll* criar(); // criando colecao com numero maximo de itens
    int inserir(Sll* lista, void *elemento); //inserindo um item na cole�o.
    void* removeElm(Sll* lista, void *key, int(*cmp)(void* , void*)); //remover um item, buscando atr�ves de uma key
    void* buscarElm(Sll* lista , void * key, int(*cmp)(void* , void*)); //buscando-o
    void* List(Sll* lista, void (*printList)(void*));
    void* sllGetFirst ( Sll *lista);
    void* sllGetNext( Sll *lista);
    void DestruirList(Sll* lista);

#endif // LISTA_H_INCLUDED
