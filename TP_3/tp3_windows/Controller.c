#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#include "utn_Input.h"
#include "parser.h"
#define MAX 1000000
#define TAMC 50
#define TAMF 8


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL){

		parser_PassengerFromText(pFile, pArrayListPassenger);

		fclose(pFile);

		retorno = 1;
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL){

		parser_PassengerFromBinary(pFile, pArrayListPassenger);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int idIngUlt)
{
	int retorno = 0;

	Passenger* pPassengerAux;

	pPassengerAux = Passenger_new();

	//Variables auxiliares
	int idAux = 0;
	char nameAux[50];
	char lastNameAux[50];
	float priceAux;
	char flyCodeAux[8];
	int typePassengerAux;
	int statusFlightAux;
	int tamano = 0;
	char descripcionTipo[50];
	char descripcionEstado[50];

	if(pArrayListPassenger != NULL){

		tamano = ll_len(pArrayListPassenger);
		idAux = tamano + 1 + idIngUlt;

		printf("\n----------Ingrese los datos---------------\n");

		input_Char(nameAux, "\nIngrese el nombre: ");
		input_Char(lastNameAux, "\nIngrese el apellido: ");
		input_Float(&priceAux, "\nIngrese el precio: ", "\nError! Reingrese el precio: ", 0, MAX);
		input_Char(flyCodeAux, "\nIngrese el codigo de vuelo: ");
		input_Int(&typePassengerAux, "\n1)Clase Economica\n2)Clase Ejecutiva\n3)Primera Clase\nIngrese el tipo de pasajero-->", "Error! Reingrese--> ", 1, 3);
		input_Int(&statusFlightAux, "\n1)Aterrizado\n2)En Horario\n3)En Vuelo\n4)Demorado\nIngrese el estado de vuelo-->", "Error! Reingrese--> ", 1, 4);

		if(pPassengerAux != NULL){

			Passenger_setId(pPassengerAux, idAux);
			Passenger_setNombre(pPassengerAux, nameAux);
			Passenger_setApellido(pPassengerAux, lastNameAux);
			Passenger_setPrecio(pPassengerAux, priceAux);
			Passenger_setCodigoVuelo(pPassengerAux, flyCodeAux);
			Passenger_typePassengerDescripcion(typePassengerAux, descripcionTipo);
			Passenger_statusFlightDescripcion(statusFlightAux, descripcionEstado);

			Passenger_setTipoPasajero(pPassengerAux, descripcionTipo);
			Passenger_setEstadoVuelo(pPassengerAux, descripcionEstado);

			ll_add(pArrayListPassenger, pPassengerAux);

			retorno = 1;
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	//Variables auxiliares

	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	char codigoVueloAux[9];
	int tipoPasajeroAux;
	//int estadoVueloAux;
	char tipoPasajeroDesc[50];
	//char estadoVueloDesc[50];

	int idBuscar;
	int index = 0;
	int opcionMod;
	//int modExitosa;

	Passenger* pPassengerAux;

	if(pArrayListPassenger != NULL){
		printf("\n----------Modificacion de Pasajero--------------\n");

		input_Int(&idBuscar, "\nIngrese el ID del pasajero a modificar: ", "\nError! ID no encontrado. Reintente--->", 1, maximoId(pArrayListPassenger));

		index = Passenger_searchForId(pArrayListPassenger, idBuscar);

		if(index >= 0){
			pPassengerAux = ll_get(pArrayListPassenger, index);
			if(pPassengerAux != NULL){

				printf("\n[--ID--] [---------NOMBRE---------] [---------APELLIDO---------] [----PRECIO----] [-CODIGO VUELO-] [---TIPO PASAJERO---] [---ESTADO VUELO---]\n");
				Passenger_printOne(pPassengerAux);

				do{
					printf("\n1)Nombre"
							"\n2)Apellido"
							"\n3)Precio de Vuelo"
							"\n4)Codigo de Vuelo"
							"\n5)Tipo de Pasajero"
							"\n6)Salir"
							"\nIngrese la opcion a realizar---> ");
					fflush(stdin);
					scanf("%d", &opcionMod);
					switch(opcionMod){
						case 1:
								input_Char(nombreAux, "\nIngrese el nuevo nombre: ");
								if(Passenger_setNombre(pPassengerAux, nombreAux) == 1){
									printf("\nEl nombre fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 2:
								input_Char(apellidoAux, "\nIngrese el nuevo apellido: ");
								if(Passenger_setApellido(pPassengerAux, apellidoAux) == 1){
									printf("\nEl apellido fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 3:
								input_Float(&precioAux, "\nIngrese el nuevo precio: ", "\nError! Reingrese el precio: ", 0, MAX);
								if(Passenger_setPrecio(pPassengerAux, precioAux) == 1){
									printf("\nEl precio fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 4:
								input_Char(codigoVueloAux, "\nIngrese el nuevo codigo de vuelo: ");
								if(Passenger_setCodigoVuelo(pPassengerAux, codigoVueloAux) == 1){
									printf("\nEl nombre fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 5:
								input_Int(&tipoPasajeroAux, "\n1)Clase Economica\n2)Clase Ejecutiva\n3)Primera Clase\nIngrese el nuevo tipo de pasajero-->", "Error! Reingrese--> ", 1, 3);
								Passenger_typePassengerDescripcion(tipoPasajeroAux, tipoPasajeroDesc);
								if(Passenger_setTipoPasajero(pPassengerAux, tipoPasajeroDesc) == 1){
									printf("\nEl tipo de pasajero fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 6:
								//modExitosa = ll_set(pArrayListPassenger, index, pPassengerAux);
								if(ll_set(pArrayListPassenger, index, pPassengerAux) == 0){
									printf("\nLas modificaciones fueron hechas con exito!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
								printf("\n\nRegresando al menu principal...");
							break;
						default:
								printf("\nOpcion incorrecta!");
							break;
					}
				}while(opcionMod != 6);
			}
		}
	}


    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int idAux;
	int idAbuscar;
	int eliminar;
	int eliminarOtro;

	if(pArrayListPassenger != NULL){

		Passenger* pPassengerAux;

		do{

			printf("\nIngrese el ID del pasajero a eliminar: \n----->");
			fflush(stdin);
			scanf("%d", &idAux);

			if(idAux >= 1){

				idAbuscar = Passenger_searchForId(pArrayListPassenger, idAux);
				pPassengerAux = ll_get(pArrayListPassenger, idAbuscar);

				if(pPassengerAux != NULL){

					if(idAbuscar >= 0){

						printf("\n[--ID--] [---------NOMBRE---------] [---------APELLIDO---------] [----PRECIO----] [-CODIGO VUELO-] [---TIPO PASAJERO---] [---ESTADO VUELO---]\n");
						Passenger_printOne(pPassengerAux);
						input_Int(&eliminar, "\n\nSeguro que desea eliminar a este pasajero: 1-SI / 2-NO\n-------->", "\nError! Ingrese una opcion valida: \n-------->", 1, 2);
						switch(eliminar){
						case 1:
							if(ll_remove(pArrayListPassenger, idAbuscar) == 0){
								printf("\nEl pasajero fue eliminado con exito!");
								retorno = 1;
							}
							break;
						case 2:
							printf("\nUsted ha cancelado la operacion eliminar!");
							break;
						}
					} else {
						printf("\nHubo un problema al eliminar!");
					}
				} else {
					printf("\nEl ID del pasajero no fue encontrado!");
				}
			}

			input_Int(&eliminarOtro, "\n\nDesea eliminar otro pasajero: 1-SI / 2-NO\n-------> ", "\nError! Ingrese una opcion valida: \n-------> ", 1, 2);

		}while(eliminarOtro != 2);
	} else {
		retorno = 0;
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidad;

	Passenger* pPassengerAux;

	if(pArrayListPassenger != NULL){

		cantidad = ll_len(pArrayListPassenger);

		printf("\n\n[-----------------------------------------------------------LISTA DE PASAJEROS--------------------------------------------------------------]\n\n");
		printf("[--ID--] [---------NOMBRE---------] [---------APELLIDO---------] [----PRECIO----] [-CODIGO VUELO-] [---TIPO PASAJERO---] [---ESTADO VUELO---]\n");

		for(int i=0;i<cantidad; i++){

			pPassengerAux = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(pPassengerAux);
		}
		retorno = 1;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int opcionOrd;

	if(pArrayListPassenger != NULL){

		input_Int(&opcionOrd, "\n1)ID\n2)Nombre\n3)Apellido\n4)Precio\n5)Codigo Vuelo\n6)Tipo Pasajero\n7)Estado Vuelo\n8)Salir\n\nIngrese el tipo de orden por el cual se va a ordenar---> ", "\nError! Ingrese una opcion valida---> ", 1,8);

		switch(opcionOrd){

		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

