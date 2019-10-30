#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int **criam(int l, int c){
	int i,j;
	int **m=(int**)malloc(l*sizeof(int*));
	for (i=0 ; i<l ; i++){
		m[i]=(int*)malloc(c*sizeof(int));
	}
	for (i=0 ; i<l ; i++){
		for (j=0 ; j<c ; j++){
			m[i][j]=0;
		}
	}
	return m;	
}

int **lermatriz (int **m){
	FILE *fp;
	int v,a,p,v1,v2,k=0;
	fp = fopen("G1.txt","r");	
	if( fp == NULL ){
		printf("não é posssivel abrie arquirvo \n");
	}
	fscanf(fp,"%d %d %d",&v, &a, &p);
	while (fscanf(fp,"%d %d",&v1, &v2) != EOF){
		m[v1-1][k]=1;
		m[v2-1][k]=1;
		k++;
	}
	fclose(fp);
	return m;
}
void printamatriz(int **m, int l,int c){
	int i,j;
	for(i=0 ; i<l ; i++){
		for(j=0 ; j<c ; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

void grau(int **m, int l, int c){
	int i,j,g;
	for(i=0 ; i<l ; i++){
		g=0;
		for(j=0 ; j<c ; j++){
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
	
	int **m=criam(v, a);
	m=lermatriz(m);
	printamatriz(m, v,a);
	grau(m,v,a);

}
