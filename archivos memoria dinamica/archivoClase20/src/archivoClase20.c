/*
 ============================================================================
 Name        : archivoClase20.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5



int main(void) {
	setbuf(stdout,NULL);

	int numero=45;
	int numeros[]={34,21,56,43,88};
	int vec[TAM];
	int x;

	/*FILE* f= fopen("datos.bin", "wb");

	if(f==NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}

	if(fwrite(numeros, sizeof(int), TAM, f )==5)//devuelve la cantidad de elementos q quise escribir, en este caso1
	{
		printf("Se guardo con exito\n");
	}
	else
	{
		printf("Hubo un problema al guardar\n");
	}

	fclose(f);*/

	FILE* f= fopen("datos.bin","rb");
	if(f==NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}

	int cont=0;

	while(!feof(f))
	{
		if(fread(&vec[cont], sizeof(int),1,f)<1)
		{
			break;
		}
		cont++;
	}

	/*if(fread(vec, sizeof(int),TAM,f)==TAM)
	{
		printf("Se leyo con exito\n");
	}
	else
	{
		printf("Hubo un problema al leer\n");
	}
*/
	fclose(f);

	for(int i=0; i<TAM; i++)
	{
		printf("numeros:%d\n",vec[i]);
	}




	return EXIT_SUCCESS;
}
