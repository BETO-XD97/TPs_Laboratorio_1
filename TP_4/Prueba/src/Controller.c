#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn_Input.h"
#include "Parser.h"

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

	if(path != NULL && pArrayListPassenger != NULL){

		FILE* pFile = fopen(path, "rb");

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
	char flyCodeAux[10];
	int typePassengerAux;
	int statusFlightAux;
	int tamano;
	char descripcionTipo[50];
	char descripcionEstado[50];

	if(pArrayListPassenger != NULL){

		tamano = ll_len(pArrayListPassenger);
		idAux = tamano + 1 + idIngUlt;

		printf("\n----------Ingrese los datos---------------\n");

		input_Char(nameAux, "\nIngrese el nombre: ", "\nError!\n");
		input_Char(lastNameAux, "\nIngrese el apellido: ", "\nError!\n");
		input_Float(&priceAux, "\nIngrese el precio: ", "\nError!\n", 1, MAX);
		rellenarCodigo(flyCodeAux, "\nIngrese el codigo de vuelo: ");
		strupr(flyCodeAux);
		input_Int(&typePassengerAux, "\n1)Clase Economica\n2)Clase Ejecutiva\n3)Primera Clase\nIngrese el tipo de pasajero-->", "\nError!\n", 1, 3);
		input_Int(&statusFlightAux, "\n1)Aterrizado\n2)En Horario\n3)En Vuelo\n4)Demorado\nIngrese el estado de vuelo-->", "\nError!\n", 1, 4);

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
	char tipoPasajeroDesc[50];

	int idBuscar;
	int indice;
	int opcionMod;
	int tamano;

	Passenger* pPassengerAux;

	if(pArrayListPassenger != NULL){
		printf("\n----------Modificacion de Pasajero--------------\n");

		tamano = ll_len(pArrayListPassenger);

		input_Int(&idBuscar, "\nIngrese el ID del pasajero a modificar: ", "\nError!\n", 1, tamano);

		indice = Passenger_searchForId(pArrayListPassenger, idBuscar);

		if(indice >= 0){

			pPassengerAux = ll_get(pArrayListPassenger, indice);

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
								input_Char(nombreAux, "\nIngrese el nuevo nombre: ", "\nError!\n");
								if(Passenger_setNombre(pPassengerAux, nombreAux) == 1){
									retorno = 1;
									printf("\nEl nombre fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 2:
								input_Char(apellidoAux, "\nIngrese el nuevo apellido: ", "\nError!\n");
								if(Passenger_setApellido(pPassengerAux, apellidoAux) == 1){
									retorno = 1;
									printf("\nEl apellido fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 3:
								input_Float(&precioAux, "\nIngrese el nuevo precio: ", "\nError!\n", 1, MAX);
								if(Passenger_setPrecio(pPassengerAux, precioAux) == 1){
									retorno = 1;
									printf("\nEl precio fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 4:
								rellenarCodigo(codigoVueloAux, "\nIngrese el nuevo codigo de vuelo: ");

								if(Passenger_setCodigoVuelo(pPassengerAux, codigoVueloAux) == 1){
									retorno = 1;
									printf("\nEl nombre fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 5:
								input_Int(&tipoPasajeroAux, "\n1)Clase Economica\n2)Clase Ejecutiva\n3)Primera Clase\nIngrese el nuevo tipo de pasajero-->", "\nError!\n", 1, 3);
								Passenger_typePassengerDescripcion(tipoPasajeroAux, tipoPasajeroDesc);
								if(Passenger_setTipoPasajero(pPassengerAux, tipoPasajeroDesc) == 1){
									retorno = 1;
									printf("\nEl tipo de pasajero fue modificado exitosamente!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
							break;
						case 6:
								if(ll_set(pArrayListPassenger, indice, pPassengerAux) == 0){
									retorno = 1;
									printf("\nLas modificaciones fueron hechas con exito!");
								} else {
									printf("\nHubo un problema al modificar!");
								}
								printf("\n\nRegresando al menu principal...\n");
							break;
						default:
								printf("\nOpcion incorrecta!");
							break;
					}
				}while(opcionMod != 6);

			}
		} else {
			printf("\nEl id del usuario no ha sido encontrado!\n");
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
						input_Int(&eliminar, "\n\nSeguro que desea eliminar a este pasajero: 1-SI / 2-NO\n-------->", "\nError!\n", 1, 2);
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

			input_Int(&eliminarOtro, "\n\nDesea eliminar otro pasajero: 1-SI / 2-NO\n-------> ", "\nError!\n", 1, 2);

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
	int modoOrd;

	//Variables de verificacion
	int rtnSid, rtnSna, rtnSln, rtnSpr, rtnSfc, rtnStp, rtnSev;

	if(pArrayListPassenger != NULL){

		input_Int(&opcionOrd, "\n1)ID\n2)Nombre\n3)Apellido\n4)Precio\n5)Codigo Vuelo\n6)Tipo Pasajero\n7)Estado Vuelo\n8)Salir\nIngrese el tipo de orden por el cual se va a ordenar---> ", "\nError!\n", 1,8);

		if(opcionOrd >= 1 && opcionOrd <= 7){
			switch(opcionOrd){

				case 1:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSid = ll_sort(pArrayListPassenger,Passenger_sortById, modoOrd);
					if(rtnSid == 0){
						printf("\nEl ordenamiento por Id fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 2:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSna = ll_sort(pArrayListPassenger,Passenger_sortByName, modoOrd);
					if(rtnSna == 0){
						printf("\nEl ordenamiento por Nombre fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 3:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSln = ll_sort(pArrayListPassenger,Passenger_sortByLastName, modoOrd);
					if(rtnSln == 0){
						printf("\nEl ordenamiento por Apellido fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 4:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSpr = ll_sort(pArrayListPassenger,Passenger_sortByPrice, modoOrd);
					if(rtnSpr == 0){
						printf("\nEl ordenamiento por Precio fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 5:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSfc = ll_sort(pArrayListPassenger,Passenger_sortByFlyCode, modoOrd);
					if(rtnSfc == 0){
						printf("\nEl ordenamiento por Codigo Vuelo fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 6:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnStp = ll_sort(pArrayListPassenger,Passenger_sortByTypePassenger, modoOrd);
					if(rtnStp == 0){
						printf("\nEl ordenamiento por Tipo Pasajero fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				case 7:
					input_Int(&modoOrd, "\nIngrese el modo de ingreso: 1-Ascendente / 0-Descendente\n-------->", "\nError!\n", 0, 1);
					rtnSev = ll_sort(pArrayListPassenger,Passenger_sortByStatusFlight, modoOrd);
					if(rtnSev == 0){
						printf("\nEl ordenamiento por Estado Vuelo fue exitoso!\n");
					} else {
						printf("\nHubo un problema en el ordenamiento!\n");
					}
					break;

				default:
					printf("\nError! Opcion invalida. Reintente ----> ");
					break;
			}
			retorno = 1;
		} else {
			if(opcionOrd == 8){
				printf("\nVolviendo al menu principal...\n");
				retorno = 0;
			}
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
    int retorno = 0;

    FILE* pArchivoTexto;

    Passenger* pPassengerAux;

    //Variables auxiliares

    int id;
    char idAux[8000];
    char nombre[8000];
    char apellido[8000];
    float precio;
    char precioAux[8000];
    char codigoVuelo[8000];
    char tipoPasajero[8000];
    char estadoVuelo[8000];

    int tamano;

    if(pArrayListPassenger != NULL){

    	pArchivoTexto = fopen(path, "w");

    	if(pArchivoTexto != NULL){

    		tamano = ll_len(pArrayListPassenger);
    		ll_sort(pArrayListPassenger,Passenger_sortById, 1);

    		fprintf(pArchivoTexto, "Id,Name,LastName,Price,FlyCode,TypePassenger,StatusFlight\n");

    		for(int i=0; i<tamano; i++){

    			pPassengerAux = (Passenger*) ll_get(pArrayListPassenger, i);

    			if(pPassengerAux != NULL){

    				if(Passenger_getId(pPassengerAux, &id) &&
    						Passenger_getNombre(pPassengerAux, nombre) &&
							Passenger_getApellido(pPassengerAux, apellido) &&
							Passenger_getPrecio(pPassengerAux, &precio) &&
							Passenger_getCodigoVuelo(pPassengerAux, codigoVuelo) &&
							Passenger_getTipoPasajero(pPassengerAux, tipoPasajero) &&
							Passenger_getEstadoVuelo(pPassengerAux, estadoVuelo)){

    					itoa(id,idAux,10);
    					itoa(precio,precioAux,10);

    					fprintf(pArchivoTexto,"%s,%s,%s,%s,%s,%s,%s\n",idAux,nombre,apellido,precioAux,codigoVuelo,tipoPasajero,estadoVuelo);
    					retorno = 1;
    				}
    			}
    		}
    	}
    	fclose(pArchivoTexto);
    }
	return retorno;
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
	int retorno = 0;
	int tamano;

	FILE* pArchivoBin;

	Passenger* pPassengerAux;

	if(path != NULL && pArrayListPassenger != NULL){

		pArchivoBin = fopen(path, "wb");
		tamano = ll_len(pArrayListPassenger);
		ll_sort(pArrayListPassenger,Passenger_sortById, 1);

		for(int i=0; i<tamano; i++){

			pPassengerAux = (Passenger*) ll_get(pArrayListPassenger, i);

			if(pArchivoBin != NULL){

				fwrite(pPassengerAux, sizeof(Passenger), 1, pArchivoBin);
				retorno = 1;
			}
		}
		fclose(pArchivoBin);
	}
    return retorno;
}


int controller_Pop(LinkedList* this){

	int retorno = 0;
	int pushAux;
	int popAux;
	int pop;

	Passenger* pasajeroAux;

	if(this != NULL){

		input_Int(&pop, "\nIngrese el ID del pasajero que desea remover de la lista: ", "\nError!\n", 1, ll_len(this));
		input_Int(&pushAux, "\nIngrese el ID del pasajero a donde lo desea mover: ", "\nError!\n", 1, ll_len(this));

		popAux = Passenger_searchForId(this, pop);
		pushAux = Passenger_searchForId(this, pushAux);

		pasajeroAux = ll_pop(this, popAux);

		if(pasajeroAux != NULL){

			Passenger_printOne(pasajeroAux);
			ll_push(this, pushAux, pasajeroAux);
			retorno = 1;
		}
	}
	return retorno;
}
