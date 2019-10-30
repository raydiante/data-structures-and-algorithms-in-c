#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct no{
	int num;
	struct no *prox;
};
typedef struct no * vertice;

vertice *crialista(vertice *l,int n){
	int i;
	for(i=0;i<n;i++){
		l[i]->prox=NULL;
	}
	return l;
	
}
void preenchelista(vertice *l){
	int v1,v2,v,a,pond;
	FILE *fp;
	vertice p;
	fp = fopen("G1.txt","r");	
	if( fp == NULL ){
		printf("não é posssivel abrie arquirvo \n");
	}
	fscanf(fp,"%d %d %d",&v, &a, &pond);
	
	
	while (fscanf(fp,"%d %d",&v1,&v2) != EOF){
		p=l[v1-1];
		if(p->prox ==NULL){
			p->prox=(vertice)malloc(sizeof(struct no));	//cria no
			p->prox->num=v2;
			p->prox->prox=NULL;
			
		}else{
			while( p->prox != NULL){	//vai para o final da lista
				p=p->prox;
			}
			p->prox=(vertice)malloc(sizeof(struct no));	//cria no
			p->prox->num=v2;
			p->prox->prox=NULL;
		}
		
		p=l[v2-1];
		if(p->prox ==NULL){
			p->prox=(vertice)malloc(sizeof(struct no));	//cria no
			p->prox->num=v1;
			p->prox->prox=NULL;
			
		}else{
			while( p->prox != NULL){	//vai para o final da lista
				p=p->prox;
			}
			p->prox=(vertice)malloc(sizeof(struct no));	//cria no
			p->prox->num=v1;
			p->prox->prox=NULL;
		}
	}
	fclose(fp);
}
void printalista(vertice *l, int n){
	vertice p;
	int i;
	
	for(i=0 ; i<n ; i++){
		if(l[i]){
			printf("[%d]", i+1);
			p=l[i]->prox;
			while (p != NULL){
				printf(" -> %d",p->num);
				p=p->prox;
			}
			printf("\n");
		}
	}


}

void main (){
	int v,a,i,p;
	FILE *fp;
	fp = fopen("G1.txt","r");	
	if( fp == NULL ){
		printf("não é posssivel abrie arquirvo \n");
	}
	fscanf(fp,"%d %d %d",&v, &a, &p);
	fclose(fp);
	vertice l[v];
	for(i=0 ; i<v ; i++){
		l[i]= (vertice)malloc(sizeof(struct no));
		l[i]->num=0;
		l[i]->prox=NULL;
	}
	//vertice *l2= crialista(l,v);
	preenchelista(l);
	printalista(l, v);
}
