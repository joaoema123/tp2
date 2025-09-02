/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

void remove_invalido (struct racional vet[], int *tam, int pos) //passa o tamanho por "referencia" para diminuí-lo depois de remover o elemento
{
  int i;
  for (i = pos; i < *tam; i++)
    vet [i] = vet [i + 1];
  *tam = *tam - 1;
    
}

void ordena_vetor (struct racional vet [], int tam) 
{
  struct racional aux;
  int i, j, pos_menor;

  for (i = 0; i < tam-2; i++){
    
    pos_menor = i;

    for (j = i + 1; j <= tam; j++) 
      if (compara_r (vet [j], vet [pos_menor]) == -1)
        pos_menor = j;

    aux.num = vet [pos_menor].num;
    aux.den = vet [pos_menor].den;

    vet [pos_menor].num = vet [i].num;
    vet [pos_menor].den = vet [i].den;
    
    vet[i].num = aux.num;
    vet [i].den = aux.den;
    
  }
}


/* programa principal */
int main ()
{
  struct racional vet [99];
  int n, i;
  scanf ("%d", &n);

  for (i = 0; i < n; i++) {
    scanf ("%ld %ld", &vet[i].num, &vet[i].den);
    cria_r (vet[i].num, vet[i].den);
  }


  printf ("VETOR = ");

  for (i = 0; i < n; i++) {
    imprime_r (vet[i]); 
    printf (" ");
    
  }

  printf ("\n");

  for (i = 0; i < n; i++){
    if (valido_r (vet[i]) == 0) 
      remove_invalido (vet, &n, i); //função que remove elementos invalidos
  }

   printf ("VETOR = ");

  for (i = 0; i < n; i++) {
    imprime_r (vet[i]);
    printf (" ");
    
  }

  ordena_vetor (vet, n);

  printf ("\n");

  printf ("VETOR = ");

  for (i = 0; i < n; i++) {
    imprime_r (vet[i]);
    printf (" ");
    
  }

  printf ("\n");

  return (0) ;
}
