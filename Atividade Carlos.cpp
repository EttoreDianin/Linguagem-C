#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar novo nó na Memória\n");
        return NULL;
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

No* inserirNovoNo(No* topo, int valor) {
    No* novoNo = criarNo(valor);
    if (novoNo == NULL) return topo;
    novoNo->prox = topo;
    return novoNo;
}

No* removerTopo(No* topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return NULL;
    }
    No* temp = topo;
    topo = topo->prox;
    printf("Desempilhando valor: %d\n", temp->valor);
    free(temp);
    return topo;
}

void mostrarPilha(No* topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elementos na pilha: ");
    No* atual = topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    No* topo = NULL;
    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1 - Empilhar valor\n");
        printf("2 - Desempilhar valor do topo\n");
        printf("3 - Mostrar pilha\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para empilhar: ");
                scanf("%d", &valor);
                topo = inserirNovoNo(topo, valor);
                break;

            case 2:
                topo = removerTopo(topo);
                break;

            case 3:
                mostrarPilha(topo);
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}

