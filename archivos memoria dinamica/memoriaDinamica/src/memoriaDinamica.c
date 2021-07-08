/*
 ============================================================================
 Name        : memoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mostrarEnteros(int* vector, int tam);

int main(void) {
	setbuf(stdout,NULL);
	int tam=5;
	int* aux=NULL;

	int* vec=(int*)malloc(tam*sizeof(int));

	if(vec==NULL)
	{
		printf("No se pudo conseguir espacio en memoria");
		exit(1);
	}

	for(int i=0; i<tam; i++)
	{
		printf("Ingrese un num ");

		//scanf("%d",&vec[i]);
		scanf("%d",vec+i);
	}

	mostrarEnteros(vec, tam);

	///agrando vector
	aux=(int*) realloc(vec, sizeof(int)*10);

	if(aux==NULL)
	{
		printf("No se pudo conseguir espacio en memoria");
		exit(1);
	}
	vec=aux;
	aux=NULL;
	tam+=5;

	printf("Vector agrandado con exito\n");

	for(int i=5; i<tam; i++)
	{
		printf("Ingrese un num ");

		//scanf("%d",&vec[i]);
		scanf("%d",vec+i);
	}

	mostrarEnteros(vec, tam);

	///ACHICAR VECTOR

	aux=(int*)realloc(vec, sizeof(int)*7);
	if(aux==NULL)
	{
		printf("No se pudo conseguir espacio en memoria");
		exit(1);
	}
	vec=aux;
	aux=NULL;
	tam-=3;

	printf("Vector achicado con exito\n");

	mostrarEnteros(vec, tam);

	free(vec);
	return EXIT_SUCCESS;
}

int mostrarEnteros(int* vector, int tam)
{
	int error=-1;

	if(vector!=NULL&& tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			printf("%d\n",*(vector+i));
		}
		error=0;
	}

	return error;
}
