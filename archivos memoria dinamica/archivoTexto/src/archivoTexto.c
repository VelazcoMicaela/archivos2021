/*
 ============================================================================
 Name        : archivoTexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x=20;
	int y;
	int cant;
	char auxCad[100];
	char car;

	int legajo;
	char nombre[20];
	float sueldo;
	char sexo;

	char buffer [4][20];

	/*FILE* f= fopen("variables.txt","w"); // crea un archivo

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}

	cant=fprintf(f, "%d", x);

	printf("cant %d \n",cant);//cantidad de datos escrito
	if(cant!=0)
	{
		printf("Guardado con exito\n");
	}
	else
	{
		printf("ERROR\n");
	}

	FILE* f= fopen("variables.txt","r");//lectura, no crea solo lee

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}

	//cant=fscanf(f, "%d",&y);//devuelve la cantidad de variables q lee

	cant=fscanf(f, "%s",auxCad);

	y=atoi(auxCad);

	if(cant==1)
	{
		printf("Se leyo el dato\n");
	}
	else
	{
		printf("ERROR\n");
	}
	printf("y %d\n",y);*/

/*	FILE* f= fopen("variables.txt","r");//lectura, no crea solo lee

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}

	while(!feof(f))
	{
		car=fgetc(f);
		printf("%c", car);
	}*/

	FILE* f= fopen("listaPersonas.csv","r");//lectura, no crea solo lee

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}
	printf("HOLA\n");

	cant=fscanf(f,"%d,%[^,],%c,%f",&legajo,nombre,&sexo,&sueldo);




	cant=fscanf(f,"%[^,],%[^,],%[^,],%s",buffer[0],buffer[1],buffer[2],buffer[3]);
	printf("cant %d\n",cant);
	//printf("Legajo %s\nNombre %s\nSexo %s\nSueldo %s\n",buffer[0],buffer[1],buffer[2],buffer[3]);

//	printf("Legajo %d\nNombre %s\nSexo %c\nSueldo %.2f\n",atoi(buffer[0]),buffer[1],buffer[2][0],atof(buffer[3]));



	fclose(f);

	return EXIT_SUCCESS;
}
