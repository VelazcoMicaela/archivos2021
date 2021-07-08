/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Dividir(int a, int b, float* resultado);
int main(void) {
	setbuf(stdout,NULL);

	int a=27;
	int b=2;
	float resultado;
	int error;

	error=Dividir(a,b,&resultado);

	if(error==0)
	{
		printf("no se puede dividir");
	}
	else
	{
		printf("resultado es %.2f",resultado);
	}

	return EXIT_SUCCESS;
}
int Dividir(int a, int b, float* resultado)
{
	float total;
	int error;

	if(b!=0)
	{
		total=(float)a/b;
		error=1;
		(*resultado)=total;
	}
	else
	{
		error=0;
	}

	return error;
}
