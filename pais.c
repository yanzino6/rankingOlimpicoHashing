#include "pais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pais
{
    int ouros;
    int pratas;
    int bronzes;
    int total;
    char *sigla;
    tPais *prox;
};


tPais *criaPais (int ouros, int pratas, int bronzes, char *sigla)
{
    tPais *criado = (tPais*)malloc(sizeof(tPais));
    criado->bronzes=bronzes;
    criado->pratas=pratas;
    criado->ouros=ouros;
    criado->total=ouros+pratas+bronzes;
    criado->sigla=strdup(sigla);
    criado->prox=NULL;
    return criado;
}

void adicionaPaisColisao(tPais *pais1, tPais *paisColisao)
{
    if (pais1->prox!=NULL)
    {
        adicionaPaisColisao(pais1->prox,paisColisao);
    }
    else
    {
        pais1->prox=paisColisao;
        paisColisao->prox;
    }
}

void liberaPais(tPais *pais)
{   
    if (pais!=NULL)
    {
        if (pais->prox!=NULL)
    {
        liberaPais(pais->prox);
    }
    if (pais!= NULL)
    {
        printf("Pais %s liberado\n",pais->sigla);
    free(pais->sigla);
    free(pais);
    }
    }
    
    
}

char *getSiglaPais(tPais *p)
{
    return p->sigla;
}

void atualizaMedalhas(tPais *p1, tPais *p2)
{
    p1->bronzes=p2->bronzes;
    p1->ouros=p2->ouros;
    p1->pratas=p2->pratas;
    p1->total=p2->total;
}

void imprimePais(tPais *pais)
{
    printf("PAIS: %s\nOUROS: %d\nPRATAS: %d\nBRONZES: %d\nTOTAL: %d\n\n",pais->sigla,pais->ouros,pais->pratas,pais->bronzes,pais->total);
    if (pais->prox!=NULL)
    {
        imprimePais(pais->prox);
    }
    
}