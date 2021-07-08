/*
 ============================================================================
 Name        : punterosDavila.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int initArray(int* pArray, int len, int valor);
int impArray(int* pArray, int len);
int resizeArray(int** pArray, int* limite, int len);

int main(void) {
	setbuf(stdout,NULL);
/*
	int* a;

	 * un solo espacio en memoria

	a=(int*) malloc (sizeof(int));
	if(a!=NULL)
	{
		*a=22;
	}
	printf("*a %d  ---a %d",*a,a);


	//mas espacio en memoria
	a=(int*) malloc(sizeof(int)*20);//20 o cualquier otro valos
	if(a!=NULL)
	{
		for(int i=0; i<20; i++)
		{
			a[i]=0;
			printf("a [%d]%d\n", i,a[i]);
		}
	}


	//int numeros[5];

	int* vec=(int*)malloc(sizeof(int)*5);

	for(int i=0; i<5;i++)
	{
		printf("Ingrese un num ");

		scanf("%d",&vec[i]);
		//scanf("%d",vec+i);
	}

	for(int i=0; i<5;i++)
	{
		printf("%d",vec[i]);
	//	printf("%d\n",*(vec+i));

	}

	free(vec);*/

	int* pArray=NULL;
	int tam=10;


	pArray= (int*) malloc (sizeof(int)*tam);

	if(pArray!=NULL)
	{
		if(initArray(pArray, tam, 0)==0)
		{
			printf("ok\n");
			impArray(pArray, tam);
		}

	}

	if(resizeArray(&pArray, &tam, 20)==0)
	{
		printf("%d ok", tam);
	}
	else
	{
		printf("%d ok", tam);
	}





free(pArray);

return EXIT_SUCCESS;
}


int initArray(int* pArray, int len, int valor)
{
	int error=-1;

	if(pArray!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			*(pArray+i)= valor;
		}
		error=0;
	}

	return error;
}

int impArray(int* pArray, int len)
{
	int error=-1;

	if(pArray!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			printf("%d\n",*(pArray+i));
		}
		error=0;
	}

	return error;
}

int resizeArray(int** pArray, int* limite, int len)
{
	int error=-1;
	int* aux=NULL;

	if(pArray!=NULL && limite!=NULL && len>0)
	{
		aux= (int*)realloc(*pArray, sizeof(int)*len);

		if(aux!=NULL)
		{
			*limite=len;
			*pArray= aux;
			aux=NULL;
		}
		error=0;
	}

	return error;
}
