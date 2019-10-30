#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int *f = NULL,*r = NULL; // Fila global

typedef struct Lista{
	int valor;
	struct Lista *prox;
}lista;

void InicializaArestas(int arestas,int vertices,lista vet[100]){

	int i=0,j=0,a1=0,a2=0;
	lista *aux=NULL,*aux2=NULL,*l;

	for(i=0;i<arestas;i++){
		//printf("Mas hein\n");
		scanf("%d %d",&a1,&a2);
		//printf("Aresta %d-%d\n",a1,a2);
		a1--;
		a2--;
		aux = vet[a1].prox; // Trata o primeiro parametro da aresta
									//printf("Que isso\n");
		if(aux != NULL){ // Poe no final da lista
			while(aux->prox != NULL){
				aux = aux->prox;
				//printf("Aux = %d\n",aux->valor);
			}
		}
		if(aux == NULL){ // Aloca mais uma posicao,e poe o valor
			l = malloc(sizeof(lista));
			//printf("vet[a1].prox = l com vet[a1] = %d\n",vet[a1].valor);
			vet[a1].prox = l;
			l->valor = a2+1;
			l->prox = NULL;
			//printf("l = %d\n",l->valor);
		}else{			
			l = malloc(sizeof(lista));

			l->valor = a2+1;
			l->prox = NULL;
			aux->prox = l;
			//printf("aux.prox = l com aux = %d e aux.prox = %d\n",aux->valor,aux->prox->valor);

						//printf("l = %d\n",l->valor);

					//printf("Que isso esp\n");
		}
		//printf("%p\n",aux2);
		
		aux2 = vet[a2].prox;
		if(aux2 != NULL){
			while(aux2->prox != NULL){
			aux2 = aux2->prox;
			}
		}
							//printf("Que isso\n");

		if(aux2 == NULL){
					//	printf("vet[a2].prox = l com vet[a2] = %d\n",vet[a1].valor);

			l = malloc(sizeof(lista));
			vet[a2].prox = l;
			l->valor = a1+1;
			l->prox = NULL;
		}else{
			l = malloc(sizeof(lista));
									//printf("vet[a2].prox = l com vet[a2] = %d\n",vet[a1].valor);

			aux2->prox = l;
			l->valor = a1+1;
			l->prox = NULL;


		}

	}
}
void printLista(int vertices,lista vet[100]){

	int i=0,j=0;
	lista *aux = NULL;

	for(i=0;i<vertices;i++){
		printf("V[%d] -> ",vet[i].valor);
		if(vet[i].prox == NULL){
			printf("NULL\n");
		}else{
			aux = &vet[i];
			aux = aux->prox;
			while(aux->prox != NULL){
				printf("%d -> ",aux->valor);
				aux = aux->prox;
						}
			printf("%d ->",aux->valor);
			printf("NULL\n");
		}


	}
}

void InicializaVetores(int vertices,int fila[vertices+1], int d[vertices],int pi[vertices],int cor[vertices]){
	
	int i;
	for(i=0;i<vertices;i++){
		d[i] = 0;
	}
	for(i=0;i<vertices;i++){
		pi[i] = 0;
	}
	for(i=0;i<vertices;i++){
		cor[i] = 0;
	}
	for(i=0;i<vertices+1;i++){
		fila[i] = 0;
	}


}

void PercursoBEL(int vertices,lista vet[vertices],int fila[vertices],int cor [vertices],int pi[vertices], int d[vertices]){
	int i=0,v = 0,j = 1,tamfila = 1;
	lista *aux = NULL;
	//Ja chega-se na funcao com o 1 na Fila
	while(*f != 0){
		printf("*f = %d?\n",*f);
		aux = &vet[i];
		while(aux->prox != NULL){
			aux = aux->prox;
			v = aux->valor;
			printf("v = %d\n",v-1);
			printf("Cor[%d] = %d\n",v-1,cor[v-1]);
			if(cor[v-1] == 0){
				 // V contem a aresta que faz vizinhanca
				d[v-1] = d[i]+1;
				pi[v-1] = vet[i].valor;
				fila[tamfila] = v;
				cor[v-1] = 1;
				printf("fila[%d] =  %d\n",tamfila,v);
				tamfila++;

			}

		}
		if(cor[v-1] == 0){
			v = aux->valor; // V contem a aresta que faz vizinhanca
			cor[v-1] = 1;
			d[v-1] = d[i]+1;
			pi[v-1] = vet[i].valor;
			fila[tamfila] = v;
			tamfila++;
		}
		f = &fila[j];
		j++;
		i++;	
		sleep(1);
	}

}


void main(){
	
	int i=0,j=0,arestas=0,vertices=0;
	lista vet[100],*aux= NULL;
	scanf("%d %d",&vertices,&arestas);
	int fila[vertices],d[vertices],pi[vertices],cor[vertices]; //Cores : 0 branco, 1 cinza, 2 preto

	for(i=0;i<vertices;i++){
		vet[i].valor = i+1;
		vet[i].prox = NULL;
	}
	//MUITA ATENCAO NA REPRESENTACAO NO VETOR, A POSICAO [0] GUARDA O NO [1]
	InicializaVetores(vertices,fila,d,pi,cor);
	InicializaArestas(arestas,vertices,vet);
	fila[0] = vet[0].valor;
	f = &fila[0]; // Sempre comeca o percurso pelo vertice 1
	cor[0] = 1;
	printLista(vertices	,vet);
	PercursoBEL(vertices,vet,fila,cor,pi,d);

}