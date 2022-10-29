#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct node {
  void** data;
  struct node* next;
}Node;

typedef struct sll {
  Node* head;
  Node* cur;
}Sll;

Sll* criar(){
    Sll *l;
    l= (Sll *) malloc ( sizeof(Sll));
    if ( l != NULL ) {
        l->head = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int inserir(Sll* lista, void* info){
    Node *newnode;
    if (lista != NULL){
        newnode = (Node*)malloc(sizeof(Node));
        if ( newnode != NULL ) {
            newnode->data = info;
            newnode->next = lista->head;
            lista->head = newnode;
            return 1;
        }
    }
    return 0;
}

void DestruirList(Sll* lista){
  while(lista->head != NULL){
    Node* prox = lista->head;
    prox = prox->next;
    free(lista->head);
    lista->head = prox;
  }
  free(lista);
}

void* buscarElm(Sll* lista, void* key, int(*cmp)(void*,void*)){
  if(lista != NULL){
    if(lista->head != NULL){
      Node* current = lista->head;
      while(current->next != NULL && cmp(current->data,key) != 1){
        current = current->next;
      }
      if(cmp(current->data,key) == 1){
        return current->data;
      }
    }
  }
  return NULL;
}

void* removeElm(Sll* lista, void* key, int(*cmp)(void*,void*)){
  if(lista == NULL){
    return NULL;
  }
  Node* aux = lista->head;
  Node* prev = NULL;
  while(aux != NULL){
    if(cmp(aux->data, key)){
      if(prev == NULL){
        lista->head = aux->next;
      }else{
        prev->next = aux->next;
      }

      free(aux);
      return aux;
    }
    prev = aux;
    aux = aux->next;
  }
    return NULL;
}

void* List(Sll* lista, void(*printList)(void*)){
    if(lista == NULL){
      return NULL;
    }
    Node* aux = lista->head;
    while(aux != NULL){
      printList(aux->data);
      aux = aux->next;
    }
    return NULL;
}

void *sllGetFirst ( Sll *l){
    if ( l!= NULL ) {
        if (l->head != NULL) {
            l->cur = l->head;
            return l->cur->data;
        }
    }
    return NULL;
}


void *sllGetNext( Sll *l){
    if (l!= NULL) {
        if (l->cur != NULL) {
            l->cur = l->cur->next;
            return l->cur;
        }
    }
    return NULL;
}
