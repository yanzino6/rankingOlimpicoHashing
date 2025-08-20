#ifndef PAIS_H_
#define PAIS_H_

typedef struct pais tPais;

tPais *criaPais (int ouros, int pratas, int bronzes, char *sigla);

void adicionaPaisColisao(tPais *pais1, tPais *paisColisao);

void liberaPais(tPais *pais);

char *getSiglaPais(tPais *p);

void atualizaMedalhas(tPais *p1, tPais *p2);

void imprimePais(tPais *pais);

#endif