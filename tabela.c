#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabela
{
    int tamTabela;
    int qtdItens;
    tPais **paises;
};

tHash *criaHash(int tamTabela)
{
    tHash *criada = (tHash *)malloc(sizeof(tHash));
    criada->tamTabela = tamTabela;
    criada->paises = (tPais **)malloc(tamTabela * sizeof(tPais *));
    for (int i = 0; i < criada->tamTabela; i++)
    {
        criada->paises[i] = NULL;
    }
    return criada;
}

int funcHash(char *sigla, tHash *tab)
{
    int val, dimSigla;
    val = 0;
    dimSigla = strlen(sigla);
    for (int i = 0; i < dimSigla; i++)
    {
        val += sigla[i];
    }
    int pos = val % tab->tamTabela;
    return pos;
}

tHash *insereElemHash(tPais *pais, tHash *tabela)
{
    int indice = funcHash(getSiglaPais(pais), tabela);

    if (tabela->qtdItens > 0.75*tabela->tamTabela)
    {
        redimensionaTabela(tabela);
    }
    

    if (verificaElemExiste(tabela, pais) == 0)
    {
        
        tabela->paises[indice] = pais;
        tabela->qtdItens++;
        return tabela;
    }
    else if (strcmp(getSiglaPais(tabela->paises[indice]), getSiglaPais(pais)) == 0)
    {
        atualizaMedalhas(tabela->paises[indice], pais);
        liberaPais(pais);
        return tabela;
    }
    else
    {
        adicionaPaisColisao(tabela->paises[indice], pais);
        return tabela;
    }
}

int verificaElemExiste(tHash *tabela, tPais *elem)
{
    int indice = funcHash(getSiglaPais(elem), tabela);
    if (tabela->paises[indice] != NULL)
    {
        return 1;
    }
    else if (verificaPaisNaLista(tabela->paises[indice],elem)==1)
    {
        return 1;
    }
    
    return 0;
}

void liberaHash(tHash *tabela)
{
    for (int i = 0; i < tabela->tamTabela; i++)
    {
        liberaPais(tabela->paises[i]);
    }
    free(tabela->paises);
    free(tabela);
}

tPais *getElemTabela(tHash *tabela, char *sigla)
{
    return tabela->paises[funcHash(sigla, tabela)];
}

void redimensionaTabela(tHash *tabela)
{

    int tamAntigo = tabela->tamTabela;
    tPais **paises = tabela->paises;
    tabela->tamTabela *= 1.947;
    tabela->qtdItens=0;
    tabela->paises = (tPais **)malloc(tabela->tamTabela * sizeof(tPais *));
    for (int i = 0; i < tabela->tamTabela; i++)
    {
        tabela->paises[i] = NULL;
    }
    for (int i = 0; i < tamAntigo; i++)
    {
        if (paises[i])
        {
            insereElemHash(paises[i],tabela);
        }
    }
    free(paises);
}