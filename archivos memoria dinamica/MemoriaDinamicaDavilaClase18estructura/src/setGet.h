/*
 * setGet.h
 *
 *  Created on: 11 jun. 2021
 *      Author: Asus
 */

#ifndef SETGET_H_
#define SETGET_H_

int empleado_setLegajo(eEmpleado* this, char* legajo);
int esDigito(char* cadena, int* numero);
int empleado_setNombre(eEmpleado* this, char*  nombre);


int empleado_getNombre(eEmpleado* this, char*  pNombre);
int empleado_getLegajo(eEmpleado* this, int* pLegajo);

int esLetra(char* cadena);
#endif /* SETGET_H_ */
