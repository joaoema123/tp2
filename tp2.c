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

  for (i = 0; i < tam-1; i++){
    
    pos_menor = i;

    for (j = i + 1; j < tam; j++) 
      if (compara_r (vet [j], vet [pos_menor]) == -1)
        pos_menor = j;

    aux = vet[i];
   
    vet[pos_menor] = vet[i];
    
    vet[i] = aux;
    
  }
}

struct racional calcula_soma (struct racional vet[], int n)
{
  struct racional r;
  long soma_numerador, soma_denominador;
  int i;

  for (i = 0, soma_numerador = 0; i < n; i++)
    soma_numerador = soma_numerador + vet[i].num;
  for (i = 0, soma_denominador = 0; i < n; i++)
    soma_denominador = soma_denominador + vet[i].den;
  r = cria_r (soma_numerador, soma_denominador);
  
  return simplifica_r (r);


}


/* programa principal */
int main ()
{
  struct racional vet [99];
  struct racional soma;
  int n, i;
  long den, num;
  scanf ("%d", &n);

  for (i = 0; i < n; i++) {
    scanf ("%ld %ld", &num, &den);
    vet[i] = cria_r (num, den);
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

  soma = calcula_soma (vet, n);
  
  printf ("SOMA = ");

  imprime_r (soma);

  printf ("\n");

 

  return (0) ;
}