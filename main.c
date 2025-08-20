#include "tabela.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *leEntrada = fopen("teste.txt","r");
    char nomepais[4];
    int ouros,pratas,bronzes,total;
    tPais *pais;
    tHash *tabela =criaHash(75);

    while (fscanf(leEntrada,"%s %d %d %d %d\n",nomepais,&ouros,&pratas,&bronzes,&total)==5)
    {
        pais=criaPais(ouros,pratas,bronzes,nomepais);
        imprimePais(pais);
        tabela=insereElemHash(pais,tabela);
    }
    liberaHash(tabela);
    fclose(leEntrada);
    
    /* tHash *tabela =criaHash(31);
    int indice =funcHash("EUA",tabela);
    printf("%d\n",indice);
    indice =funcHash("AUS",tabela);
    printf("%d\n",indice); */

    
    return 0;
}