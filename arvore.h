#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo{
    int chave;
    TipoApontador Esq, Dir;
}TipoNo;

void Inicializa(TipoApontador *No);
TipoApontador *Pesquisa(int x, TipoApontador *p);
void Insere(int x, TipoApontador *p);
void Antecessor(TipoApontador q, TipoApontador *r);
void Retira(int x, TipoApontador *p);
void InOrdem(TipoApontador p);
void PreOrdem(TipoApontador p);
void PosOrdem(TipoApontador p);
void DesenharArvore(TipoApontador p, int nivel);

#endif //ARVORE_ARVORE_H
