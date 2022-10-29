#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct funcinario{
  char nome[30];
  float salario;
  int cpf;
}Funcionario;

void printList(void* printList){
    Funcionario* aux = (Funcionario*) printList;

    printf("\nNome do Funcionario: %s.\n", aux->nome);
    printf("CPF : %i\n", aux->cpf);
    printf("Salario: R$ %.2f\n\n", aux->salario);
}

int cmp(void* elm, void* key){ // RECEBE DOIS VOID E RETORNA UM INT COMO CHAVE.
    Funcionario* pElm = (Funcionario*) elm;
    int *pKey = ( int*) key;
    if ( pElm->cpf == (*pKey)) {
        return 1;
    }else {
        return 0;
    }
}

int main(void) {
    int aux;
    int menu;

    Sll* funcionarioC  = criar();
    Funcionario* j;

    do{
        printf("---------------------------------");
        printf("\n1-Inserir funcionarios.\n2-Remover funcinario.\n3-Buscar funcinario.\n4-Lista de funcionarios.\n5-Destruir lista.\n6-Sair.\n");
        printf("\nopcao-> ");
        scanf("%i",&menu);
        printf("---------------------------------\n");
        getchar();

        switch (menu){
        case 1:
                j = (Funcionario*)malloc(sizeof(Funcionario));

                printf("Nome do Funcionario :\n");
                scanf("%30[^\n]",j->nome);

                printf("CPF:\n");
                scanf("%i",&j->cpf);
                getchar();

                printf("Renda Funcionario:\n");
                scanf("%f",&j->salario);
                getchar();

                inserir(funcionarioC,j);
           break;
        case 2:
            printf("Informe o CPF do funcinario:\n");
            scanf("%i",&aux);
            getchar();
            if (removeElm(funcionarioC,&aux,cmp)!=NULL){
                printf("Removido com sucesso!!\n");
            }else{
                printf("Funcionario nao encontrado.\n");
            }
        break;
        case 3:
            printf("Informe o CPF do funcinario:\n");
            scanf("%i",&aux);
            getchar();
            printList(buscarElm(funcionarioC,&aux,cmp));

        break;
        case 4:
            List(funcionarioC, printList);
        break;
        case 5:
            DestruirList(funcionarioC);
            printf("\n!LISTA DESTRUIDA!\n\n");
            printf("Voce deseja sair ou criar outra lista para sua aplicacao?\n1-Criar nova lista.\n0-Sair.");
            scanf("%i", &aux);
            if (aux==1){
              criar();
            }else{
              printf("Voce saiu do programa.");
              menu = 6;
            }
        break;
        case 6:
            DestruirList(funcionarioC);
            printf("Voce saiu do programa. Sua lista foi destruida.");
        break;
        default:
            printf("Esta opcao nao existe.\n");
        }
    }while(menu!=6);
}
