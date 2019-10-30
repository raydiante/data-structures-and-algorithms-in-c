#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int t=2;		
int max=2*t;		//numero maximo de chaves em um nó
int min=(2*t)-1;	//numero minimo de chavem em um nó

struct no_arvb {
	int num_chaves;	//numero de chaves no nó
	int vet[max];	//vetor com as chaves
	no_arvb *filhos[max];	//ponteiro para os filhos
}


void main (){
}

