/*
 ============================================================================
 Name        : TP_2.c
 Author      : Roberto Rocabado
 Division: D
 DNI: 40731247
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pasajeros.h"
#include "tpInput.h"

#define TAM 10
#define OCCUPED 1
#define TAMCHAR 51

int opcionMP; //Opcion de menu principal
int opcionMOr;
int idAux;
char nameAux[TAMCHAR];
char lastNameAux[TAMCHAR];
float priceAux;
char flyCodeAux[TAMCHAR];
int typePassengerAux;
int statusFlightAux;
int isEmptyAux=1;

float acumuladorPrecio = 0;
float promedioPrecio = 0;
int pasajerosMayorAProm = 0;
int idRecibida;
int idRemover;
int tipoOrden;

int main(void) {
	setbuf(stdout, NULL);

	ePassenger pasajero[TAM];
	//ePassenger pasajeroIngresado;

	//Inicializar la estructura
	initPassenger(pasajero, TAM);

	//MENU
	do{
		printf("\n----------------Bienvenido al Sistema----------------\n\n"
				"1)ALTA.\n"
				"2)MODIFICAR.\n"
				"3)BAJA.\n"
				"4)INFORMAR.\n"
				"5)CARGA FORZADA.\n"
				"6)SALIR.\n\n"
				"Ingrese la opcion que desea realizar: ");
		fflush(stdin);
		scanf("%d", &opcionMP);

		switch(opcionMP){

			case 1:
				if(idAux < 2000){
					printf("\n\n-------------Ingreso de Datos----------------\n\n");
					idAux++;
					rellenarChar(nameAux, "\n-->Ingrese el nombre:");
					rellenarChar(lastNameAux, "\n-->Ingrese el apellido: ");
					rellenarFloat(&priceAux, "\n-->Ingrese el precio: ", "\nError! Reingrese: ");
					rellenarChar(flyCodeAux, "\n-->Ingrese el codigo de vuelo:");
					strupr(flyCodeAux);
					rellenarInt(&typePassengerAux, "\nIngrese el tipo de pasajero: \n1-->Ejecutivo  \n2-->Turista \n3-->VIP\n-------->", "\nError! Reingrese: ");
					rellenarInt(&statusFlightAux, "\nIngrese el estado de vuelo: \n1-->Normal \n2-->En Demora \n3-->Cancelado \n------->", "\nError! Reingrese: ");
					addPassenger(pasajero, TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux,statusFlightAux,isEmptyAux);
				} else {
					printf("El sistema esta lleno!!!");
				}

				break;

			case 2:
				modifyPassengerData(pasajero, TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux,statusFlightAux,isEmptyAux);
				break;

			case 3:

				rellenarInt(&idRecibida, "\n-->Ingrese el ID del usuario a eliminar:", "\nError! Reingrese: ");
				idRemover = removePassenger(pasajero, TAM, idRecibida);

				//printf("%d", idRemover);

				break;

			case 4:
				do{
					printf("\n1-->Ordenar por Apellido y Tipo de Pasajero."
							"\n2-->Sacar el promedio."
							"\n3-->Ordenar por codigo de vuelo y Estado de vuelo."
							"\n4-->Salir."
							"\n---> Que opcion desea realizar: ");
					scanf("%d", &opcionMOr);
					fflush(stdin);

					switch(opcionMOr)
					{
							case 1:
								rellenarInt(&tipoOrden, "\nEn que orden queres acomodar: 1-Asc / 2-Desc--->", "\nError! Reingrese: ");
								sortPassenger(pasajero, TAM, tipoOrden);
								printPassenger(pasajero, TAM, idAux);
								break;
							case 2:
								acumuladorPrecio = calculatePrice(pasajero, TAM);
								printf("\n\nEl total de los precios es: %.2f", acumuladorPrecio);
								promedioPrecio = calculatePromPrice(pasajero, TAM, acumuladorPrecio);
								printf("\nEl promedio de los precios es: %.2f", promedioPrecio);
								pasajerosMayorAProm = calculatePassengerProm(pasajero, TAM, promedioPrecio);
								printf("\nLa cantidad de pasajeros cuyos precios superan al promedio: %d\n\n", pasajerosMayorAProm);

								break;
							case 3:
								rellenarInt(&tipoOrden, "\nEn que orden queres acomodar: 1-Asc / 2-Desc--->", "\nError! Reingrese: ");
								sortPassengerByCode(pasajero, TAM, tipoOrden);
								printPassenger(pasajero, TAM, idAux);
								break;
							case 4:
								printf("\nVolviendo al menu principal...\n");
								break;
							default:
								printf("La opcion elegida es la incorrecta!!!");
								break;
					}
				}while(opcionMOr != 4);

				break;

			case 5:

					idAux++;
					strcpy(nameAux, "Roberto");
					strcpy(lastNameAux, "Rocabado");
					priceAux = 2516.2;
					strcpy(flyCodeAux, "ACD117");
					typePassengerAux = 2;
					statusFlightAux = 2;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Jeimy");
					strcpy(lastNameAux, "Baldoceda");
					priceAux = 5015.2;
					strcpy(flyCodeAux, "ZCD097");
					typePassengerAux = 3;
					statusFlightAux = 1;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Pedro");
					strcpy(lastNameAux, "Pascal");
					priceAux = 3650.4;
					strcpy(flyCodeAux, "ACD117");
					typePassengerAux = 1;
					statusFlightAux = 2;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Juan");
					strcpy(lastNameAux, "Rodriguez");
					priceAux = 4512.7;
					strcpy(flyCodeAux, "ZCD097");
					typePassengerAux = 2;
					statusFlightAux = 1;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Micaela");
					strcpy(lastNameAux, "Perez");
					priceAux = 4127.0;
					strcpy(flyCodeAux, "UWN101");
					typePassengerAux = 1;
					statusFlightAux = 1;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Romina");
					strcpy(lastNameAux, "Gonzalez");
					priceAux = 4710.0;
					strcpy(flyCodeAux, "UWM101");
					typePassengerAux = 1;
					statusFlightAux = 1;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					idAux++;
					strcpy(nameAux, "Armando");
					strcpy(lastNameAux, "Barreda");
					priceAux = 3810.4;
					strcpy(flyCodeAux, "WEC056");
					typePassengerAux = 3;
					statusFlightAux = 1;
					isEmptyAux = 1;
					addPassenger(pasajero,TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux, statusFlightAux, isEmptyAux);

					break;

			case 6:
				printf("Gracias por usar nuestros servicio!!!");
				break;

			default:
				printf("\nERROR! Opcion incorrecta.\n\n");
				break;
		}

	}while(opcionMP != 6);

	return 0;
}

