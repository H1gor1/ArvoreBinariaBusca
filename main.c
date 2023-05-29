#include <stdio.h>
#include "arvore.h"

int main() {
    TipoApontador Arvore;
    Inicializa(&Arvore);
    int opcao, opcaoImprime;
    int chave;

    do {
        printf("\nArvore de busca binaria\n");
        printf("1- Insere na arvore\n"
               "2- Retira da arvore\n"
               "3- Imprime arvore\n"
               "4- Pesquisa na arvore\n"
               "5- Desenhar Arvore\n"
               "0- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nDigite o valor que deseja adicionar: ");
                scanf("%d", &chave);
                Insere(chave, &Arvore);
                break;
            case 2:
                printf("Digite o elemento que deseja retirar: ");
                scanf("%d", &chave);
                Retira(chave, &Arvore);
                break;
            case 3:
                printf("\n\nEscolha o percurso que deseja imprimir: "
                                   "\n1. Pre-Ordem"
                                   "\n2. In-Ordem"
                                   "\n3. Pos-Ordem\n");
                scanf("%d", &opcaoImprime);
                switch (opcaoImprime) {
                    case 1:
                        PreOrdem(Arvore);
                        break;
                    case 2:
                        //InOrdem(Arvore);
                        InOrdem(Arvore);
                        break;
                    case 3:
                        PosOrdem(Arvore);
                        break;
                }
                break;
            case 4:
                printf("Digite o elemento que deseja pequisar: ");
                scanf("%d", &chave);
                TipoApontador *x = Pesquisa(chave, &Arvore);
                printf("Elemento pesquisado: \n"
                       "Chave: %d", (*x)->chave);
                break;
            case 5:
                DesenharArvore(Arvore, 0);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
