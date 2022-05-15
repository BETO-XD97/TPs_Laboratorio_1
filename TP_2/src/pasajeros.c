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

		printf("\n\n|| ID ||     NOMBRE    ||      APELLIDO      ||      PRECIO      ||   CODIGO VUELO     ||    TIPO PASAJERO   ||  ESTADO VUELO   ");
		for(int i=0; i<len; i++){
			if(list[i].isEmpty == OCCUPED){
				printf("\n------------------------------------------------------------------------------------------------------------------------------------------");
				printf("\n   %d          %s            %s  	     %.2f            %s                 ",
				list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flyCode);
				if(list[i].typePassenger == 1){
					printf("EJECUTIVO          ");
				} else {
					if(list[i].typePassenger == 2){
						printf("TURISTA            ");
					} else {
						if(list[i].typePassenger == 3){
							printf("VIP                ");
						} else {
							printf("NO VALIDO            ");
						}
					}
				}
				if(list[i].statusFlight == 1){
					printf("ACTIVO");
				} else {
					if(list[i].statusFlight == 2){
						printf("DEMORADO");
					} else {
						if(list[i].statusFlight == 3){
							printf("CANCELADO");
						} else {
							printf("NO VALIDO");
						}
					}
				}
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
						rellenarChar(list[i].name, "\n-->Ingrese el nuevo nombre: ");
						break;
					case 2:
						printf("\nEl apellido a modificar es: %s", list[i].lastName);
						rellenarChar(list[i].lastName, "\n-->Ingrese el nuevo apellido: ");
						break;
					case 3:
						printf("\nEl precio a modificar es: %.2f", list[i].price);
						rellenarFloat(&list[i].price, "\n-->Ingrese el nuevo precio: ", "\nError! Reingrese: ");
						break;
					case 4:
						printf("\nEl tipo de pasajero a modificar es: %d", list[i].typePassenger);
						rellenarInt(&list[i].typePassenger, "\n-->Ingrese el nuevo tipo de pasajero: ", "\nError! Reingrese: ");
						break;
					case 5:
						printf("\nEl codigo de vuelo a modificar es: %d", list[i].statusFlight);
						rellenarInt(&list[i].statusFlight, "\n-->Ingrese el nuevo codigo de vuelo: ", "\nError! Reingrese: ");
						break;
					case 6:
						printf("\nLa modificacion se ha realizado con exito!\n");
						break;
					default:
						printf("\nLa opcion elegida no es valida!");
						break;
				}
			}while(opcion != 6);
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
		printf("\nEl usuario ha sido eliminado con exito!");
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



