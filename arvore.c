#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

void Inicializa(TipoApontador *No){
    *No = NULL;
}

TipoApontador *Pesquisa(int x, TipoApontador *p){
    if(*p == NULL) {
        printf("Erro: Registro nao esta presente na arvore\n");
        return NULL;
    }
    if(x < (*p)->chave){
        return Pesquisa(x, &(*p)->Esq);
    }
    if(x > (*p)->chave){
        return Pesquisa(x, &(*p)->Dir);
    }
    else {
        return p;
    }
}

void Insere(int x, TipoApontador *p){
    if (*p == NULL){
        *p = (TipoApontador) malloc(sizeof(TipoNo));
        (*p)->chave = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if(x < (*p)->chave){
        Insere(x, &(*p)->Esq);
        return;
    }
    if(x > (*p)->chave){
        Insere(x, &(*p)->Dir);
    }
    else{
        printf("Erro: Registro ja existe na arvore\n");
        return;
    }
}

void Antecessor(TipoApontador q, TipoApontador *r){
    if((*r)->Dir != NULL){
        Antecessor(q, &(*r)->Dir);
        return;
    }

    q->chave = (*r)->chave;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

void Retira(int x, TipoApontador *p){
    TipoApontador aux;
    if(*p == NULL){
        printf("Erro: Registro nao esta na arvore!\n");
        return;
    }

    if(x < (*p)->chave){
        Retira(x, &(*p)->Esq);
        return;
    }
    if(x > (*p)->chave){
        Retira(x, &(*p)->Dir);
        return;
    }

    if((*p)->Dir == NULL){
        aux = *p;
        *p = (*p)->Esq;
        free(aux);
        return;
    }

    if((*p)->Esq != NULL){
        Antecessor(*p, &(*p)->Esq);
        return;
    }
    aux = *p;
    *p = (*p)->Dir;
    free(aux);
}

void InOrdem(TipoApontador p){
    if (p == NULL){
        return;
    }
    InOrdem(p->Esq);
    printf("%d ", p->chave);
    InOrdem(p->Dir);
}

void PreOrdem(TipoApontador p){
    if (p == NULL){
        return;
    }
    printf("%d ", p->chave);
    PreOrdem(p->Esq);
    PreOrdem(p->Dir);
}

void PosOrdem(TipoApontador p){
    if (p == NULL){
        return;
    }
    PosOrdem(p->Esq);
    PosOrdem(p->Dir);
    printf("%d ", p->chave);
}

void DesenharArvore(TipoApontador p, int nivel)
{
    if (p == NULL)
        return;

    const int espaco = 4; // Espaçamento horizontal entre os nós
    DesenharArvore(p->Dir, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        for (int j = 0; j < espaco; j++) {
            printf(" ");
        }
    }

    printf("%ld\n", p->chave);

    DesenharArvore(p->Esq, nivel + 1);
}






