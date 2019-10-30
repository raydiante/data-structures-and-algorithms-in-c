#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct no{
	int chave;
	struct no *prox;
};
typedef struct no No;

No* criaArvore(){
	No* raiz = (No *)malloc(sizeof(No));
	if(raiz){
		raiz->chave=-1;
		raiz->prox=NULL;	
		return raiz;
	}
	printf("Não é possivel");
	return NULL;
}

bool insereNo( No * raiz, int chave){
	if(!raiz){
		printf("arvore não criada");
		return false;
	}
	if(raiz->prox==NULL && raiz->chave==-1){
		raiz->chave=chave;
		return true;
	}
	No* novo = (No *)malloc(sizeof(No));
	if(!novo){
		printf("Não é possivel");
		return false;
	}
	novo->chave=chave;
	No * p = raiz;
	while(p->prox != NULL){
		p=p->prox;	
	}
	novo->prox=NULL;
	p->prox=novo;
	return true;
}

bool busca(No* raiz, int chave){
	No * p = raiz;
	while(p != NULL){
		if(p->chave == chave){
			printf("Chave encontrada\n");
			return true;
		}
		p=p->prox;	
	}
	printf("Chave nao encontrada\n");
	return false;
}

void printa(No* raiz){
	No * p = raiz;
	while(p != NULL){
		printf("%d -> ",p->chave);
		p=p->prox;	
	}
	printf("\n");
}


bool removeNo(No* raiz, int chave){

}




void main(){
	int i, e,b;
	No*raiz;
	
	do{
		
		printf("\n\t O que deseja?\n");
		printf("1-cria\n2-Insere\n3-Busca\n4-printa\n0-Sair\n");
		scanf("%d", &e);
		switch (e){
			case 0:
				exit(0);
		
			case 1:
				raiz=criaArvore();
				break;
			case 2:
			
				printf("Insira n\n");
				scanf("%d", &b);
				if (insereNo(raiz,b) == true){
					printf("Elemento inserido com sucesso!\n");
				}else{
					printf("Deu ruim\n");
				}
				break;
			case 3:
				printf("Insira n a ser buscada\n");
				scanf("%d", &b);
				if (busca(raiz, b) == true){
					printf("Elemento encontrado\n");
				}else{
					printf("Elemento nao encontrado\n");
				
				}
				break;
			case 4:
				printa(raiz);
				break;
		
		}
	}while (e!=0);



}
