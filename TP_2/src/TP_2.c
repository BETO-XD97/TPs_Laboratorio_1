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

#define TAM 2000
#define OCCUPED 1
#define TAMCHAR 51

int opcionMP; //Opcion de menu principal
int opcionMOr;
int idAux = 0;
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
char tipoPasajero[TAMCHAR];
char estadoVuelo[TAMCHAR];
int valor;
int idAuxA;
int inicioInt = 0;

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
				if(idAux < TAM){
					printf("\n\n-------------Ingreso de Datos----------------\n\n");
					idAux++;
					input_Char(nameAux, "\n-->Ingrese el nombre\n(Solo letras): ", "\nError!\n");
					input_Char(lastNameAux, "\n-->Ingrese el apellido\n(Solo letras): ", "\nError!\n");
					input_Float(&priceAux, "\n-->Ingrese el precio\n(Precio Maximo: $1.000.000): ", "\nError!\n", 1,1000000);
					rellenarCodigo(flyCodeAux, "\n-->Ingrese el codigo de vuelo\n(Ej:ABC174): ");
					strupr(flyCodeAux);
					input_Int(&typePassengerAux, "\nIngrese el tipo de pasajero: \n1-->Ejecutivo  \n2-->Turista \n3-->VIP\n--------> ", "\nError!\n", 1, 3);
					input_Int(&statusFlightAux, "\nIngrese el estado de vuelo: \n1-->Activo \n2-->Demorado \n3-->Cancelado \n-------> ", "\nError!\n", 1, 3);

					addPassenger(pasajero, TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux,statusFlightAux,isEmptyAux);

					inicioInt = 1;
				} else {
					printf("El sistema esta lleno!!!");
				}


				break;

			case 2:
				if(inicioInt == 1){
					modifyPassengerData(pasajero, TAM,idAux,nameAux,lastNameAux,priceAux,flyCodeAux,typePassengerAux,statusFlightAux,isEmptyAux);
				} else {
					printf("No ha ingresado ningun dato!!!");
				}
				break;

			case 3:
				if(inicioInt == 1){
					input_Int(&idRecibida, "\n-->Ingrese el ID del usuario a eliminar:", "\nError!\n", 1, 2000);

					idRemover = removePassenger(pasajero, TAM, idRecibida);
				} else {
					printf("No ha ingresado ningun dato!!!");
				}
				break;

			case 4:
				if(inicioInt == 1){
					do{
						printf("\n\n1-->Ordenar por Apellido y Tipo de Pasajero."
								"\n2-->Sacar el promedio."
								"\n3-->Ordenar por codigo de vuelo y Estado de vuelo."
								"\n4-->Salir."
								"\n---> Que opcion desea realizar: ");
						scanf("%d", &opcionMOr);
						fflush(stdin);

						switch(opcionMOr)
						{
								case 1:
									input_Int(&tipoOrden, "\nEn que orden queres acomodar: 1-Asc / 2-Desc--->", "\nError!\n", 1, 2);
									sortPassenger(pasajero, TAM, tipoOrden);
									printPassenger(pasajero, TAM, idAux);
									break;
								case 2:
									acumuladorPrecio = calculatePrice(pasajero, TAM);
									printf("\nEl total de los precios es: %.2f", acumuladorPrecio);
									promedioPrecio = calculatePromPrice(pasajero, TAM, acumuladorPrecio);
									printf("\nEl promedio de los precios es: %.2f", promedioPrecio);
									pasajerosMayorAProm = calculatePassengerProm(pasajero, TAM, promedioPrecio);
									printf("\nLa cantidad de pasajeros cuyos precios superan al promedio: %d", pasajerosMayorAProm);

									break;
								case 3:
									input_Int(&tipoOrden, "\n\nEn que orden queres acomodar: 1-Asc / 2-Desc---> ", "\nError!\n", 1,2);
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
				} else {
					printf("No ha ingresado ningun dato!!!");
				}

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
					statusFlightAux = 3;
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

					inicioInt = 1;

					break;

			case 6:
				printf("\nGracias por usar nuestros servicios!!!");
				break;

			default:
				printf("\nERROR! Opcion incorrecta.\n\n");
				break;
		}

	}while(opcionMP != 6);

	return 0;
}

