#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int **criamatriz (int n){
	int i, j;
	int **m=(int **)malloc(n*sizeof(int*));
	for(i=0 ; i<n ; i++){
		m[i]= (int*)malloc(n*sizeof(int));
	}
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			m[i][j]=0;
		}
	}
	return m;
}

int **lermatriz (int **m){
	FILE *fp;
	int v,a,p,v1,v2;
	fp = fopen("G1.txt","r");	
	if( fp == NULL ){
		printf("não é posssivel abrie arquirvo \n");
	}
	fscanf(fp,"%d %d %d",&v, &a, &p);
	while (fscanf(fp,"%d %d",&v1, &v2) != EOF){
		m[v1-1][v2-1]+=1;
		m[v2-1][v1-1]+=1;
	}
	fclose(fp);
	return m;
} 

void printamatriz(int **m, int n){
	int i,j;
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

void grau(int **m, int n){
	int i,j,g;
	for(i=0 ; i<n ; i++){
		g=0;
		for(j=0 ; j<n ; j++){
			if(m[i][j] == 1){
				g+=1;
			}
		}
		printf("v[%d]->%d\n", i+1, g);
	}
}


void main (){
	FILE *fp;
	int v,a,p;
	fp = fopen("G1.txt","r");	
	if( fp == NULL ){
		printf("não é posssivel abrie arquirvo \n");
	}
	fscanf(fp,"%d %d %d",&v, &a, &p);
	fclose(fp);
	int **m=criamatriz(v);
	m=lermatriz(m);
	printamatriz(m, v);
	grau(m, v);
}
