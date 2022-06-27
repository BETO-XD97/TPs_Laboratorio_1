/*
 * pasajeros.c
 *
 *  Created on: 10 may. 2022
 *      Author: BETO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pasajeros.h"
#include "tpInput.h"

#define OCCUPED 1

int findPassengerById(ePassenger list[], int len,int id)
{
	int i;
	for(i=0; i<len; i++){
		if(list[i].id == 0 && list[i].isEmpty != OCCUPED){
			break;
		} else {
			list[i].id = i;
		}
	}
	return i;
}

int initPassenger(ePassenger list[], int len){
	int retorno = 0;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].id = 0;
			list[i].isEmpty = 0;
		}
	} else {
		retorno = 1;
	}
	return retorno;
}

void addPassenger(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight, int isEmpty){

	for(int i=0; i<len; i++){
		if(list[i].isEmpty != OCCUPED){
		list[i].id = id;
		fflush(stdin);
		strcpy(list[i].name, name);
		strcpy(list[i].lastName, lastName);
		strcpy(list[i].flyCode, flyCode);
		list[i].price = price;
		list[i].typePassenger = typePassenger;
		list[i].statusFlight = statusFlight;
		list[i].isEmpty = OCCUPED;
		break;
		}
	}
}

void printPassenger(ePassenger list[], int len,int id){

	char typeAux[15];
	char statusAux[15];

	printf("\n\n [-ID-] [-------NOMBRE------] [------APELLIDO------] [---PRECIO---] [--CODIGO VUELO--] [---TIPO PASAJERO---] [---ESTADO VUELO---]");

	for(int i=0; i<len; i++){

		if(list[i].isEmpty == OCCUPED){
			if(list[i].typePassenger == 1){
				itoa(list[i].typePassenger, typeAux, 2);
				strcpy(typeAux, "EJECUTIVO");
			} else {
				if(list[i].typePassenger == 2){
					itoa(list[i].typePassenger, typeAux, 2);
					strcpy(typeAux, "TURISTA");
				} else {
					if(list[i].typePassenger == 3){
						itoa(list[i].typePassenger, typeAux, 2);
						strcpy(typeAux, "VIP");
					}
				}
			}
			if(list[i].statusFlight == 1){
				itoa(list[i].statusFlight, statusAux, 2);
				strcpy(statusAux, "ACTIVO");
			} else {
				if(list[i].statusFlight == 2){
					itoa(list[i].statusFlight, statusAux, 2);
					strcpy(statusAux, "DEMORADO");
				} else {
					if(list[i].statusFlight == 3){
						itoa(list[i].statusFlight, statusAux, 2);
						strcpy(statusAux, "CANCELADO");
					}
				}
			}

			printf("\n------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n [%4d] [%-19s] [%-20s] [%12.2f] [%-16s] [%-19s] [%18s] ",
					list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flyCode, typeAux, statusAux);
		}
	}
}


void modifyPassengerData(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight, int isEmpty){

	int opcion, posicion;
	printf("\n-->Ingrese el ID del pasajero: ");
	scanf("%d", &posicion);
	for(int i=0; i<len; i++){
		if(list[i].id == posicion && list[i].isEmpty == 1){
			do
			{
				printf("\n1-->Nombre"
						"\n2-->Apellido"
						"\n3-->Precio"
						"\n4-->Tipo de Pasajero"
						"\n5-->Codigo de Vuelo"
						"\n6-->Salir"
						"\n-->Ingrese su opcion: ");
				scanf("%d", &opcion);
				fflush(stdin);
				switch(opcion)
				{
					case 1:
						printf("\nEl nombre a modificar es: %s", list[i].name);
						input_Char(list[i].name, "\n-->Ingrese el nuevo nombre: ", "\nError!\n");
						break;
					case 2:
						printf("\nEl apellido a modificar es: %s", list[i].lastName);
						input_Char(list[i].lastName, "\n-->Ingrese el nuevo apellido: ", "\nError!\n");
						break;
					case 3:
						printf("\nEl precio a modificar es: %.2f", list[i].price);
						input_Float(&list[i].price, "\n-->Ingrese el nuevo precio: ", "\nError! Reingrese: ", 1, 1000000);
						break;
					case 4:
						printf("\nEl tipo de pasajero a modificar es: %d", list[i].typePassenger);
						input_Int(&list[i].typePassenger, "\n-->Ingrese el nuevo tipo de pasajero: ", "\nError! Reingrese: ", 1, 3);
						break;
					case 5:
						printf("\nEl codigo de vuelo a modificar es: %d", list[i].statusFlight);
						input_Int(&list[i].statusFlight, "\n-->Ingrese el nuevo codigo de vuelo: ", "\nError! Reingrese: ", 1, 3);
						break;
					case 6:
						printf("\nLa modificacion se ha realizado con exito!\n");
						break;
					default:
						printf("\nLa opcion elegida no es valida!\n");
						break;
				}
			}while(opcion != 6);
		} else {
			printf("\nNo se ha encontrado el ID del pasajero!\n");
			break;
		}
	}
}

int removePassenger(ePassenger list[], int len, int id){
	int retorno = 1;
	if(list != NULL){
		for(int i=0; i<len;i++){
			if(list[i].id == id && list[i].isEmpty == OCCUPED){
				list[i].isEmpty = 0;
				retorno = 0;
			}
		}
	}
	if(retorno == 0){
		printf("\nEl usuario ha sido eliminado con exito!\n");
	} else {
		printf("\nUsuario no encontrado!\n");
	}
	return retorno;
}


int sortPassenger(ePassenger list[], int len, int order){
	int i;
	int j;

	ePassenger listAux;

	if(order==1){
		for (i = 0; i < len-1; i++) {
			for (j = i + 1; j < len; j++) {
				if(list[i].isEmpty == OCCUPED && list[j].isEmpty == OCCUPED){
					if((strcmp(list[i].lastName, list[j].lastName)>0) && (list[i].typePassenger > list[j].typePassenger)){
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
				}
			}
		}
	}
	if(order==2){
		for (i = 0; i < len-1; i++) {
			for (j = i + 1; j < len; j++) {
				if(list[i].isEmpty == OCCUPED && list[j].isEmpty == OCCUPED){
					if((strcmp(list[i].lastName, list[j].lastName)<0) && (list[i].typePassenger < list[j].typePassenger)){
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
				}
			}
		}
	}
	return 0;
}



int sortPassengerByCode(ePassenger list[], int len, int order){
	int i;
	int j;
	ePassenger listAux;

	if(order==1){
		for (i = 0; i < len-1; i++) {
			for (j = i + 1; j < len; j++) {
				if(list[i].isEmpty == OCCUPED && list[j].isEmpty == OCCUPED){
					if((strcmp(list[i].flyCode,list[j].flyCode))>0){
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
				}
			}
		}
	}
	if(order==2){
		for (i = 0; i < len-1; i++) {
			for (j = i + 1; j < len; j++) {
				if(list[i].isEmpty == OCCUPED && list[j].isEmpty == OCCUPED){
					if((strcmp(list[i].flyCode,list[j].flyCode))<0){
						listAux = list[i];
						list[i]=list[j];
						list[j]=listAux;
					}
				}
			}
		}
	}
	return 0;
}



float calculatePrice(ePassenger list[],int len){
	float acumPrecio = 0;
	for(int i=0; i<len; i++){
		if(list[i].id && list[i].isEmpty == OCCUPED){
			acumPrecio += list[i].price;
		}
	}
	return acumPrecio;
}

float calculatePromPrice(ePassenger list[],int len, float acumPrecio){
	float promedioPrecio;
	int contPasajero = 0;
	for(int i=0; i<len; i++){
		if(list[i].id > 0){
			 contPasajero++;
		}
	}
	promedioPrecio = acumPrecio / contPasajero;

	return promedioPrecio;
}

int calculatePassengerProm(ePassenger list[], int len, float promedioPrecio){
	int pasajerosMayorPrecio = 0;
	for(int i=0; i<len; i++){
		if(list[i].price > promedioPrecio && list[i].isEmpty == 1){
			pasajerosMayorPrecio++;
		}
	}
	return pasajerosMayorPrecio;
}



