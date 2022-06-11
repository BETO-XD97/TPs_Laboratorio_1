#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	char id[8000];
	char name[8000];
	char lastName[8000];
	char price[8000];
	char flyCode[8000];
	char typePassenger[8000];
	char statusFlight[8000];
	int cant;

	Passenger* unPasajero;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,name,lastName,price,flyCode,typePassenger,statusFlight);

	while(!feof(pFile))
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,name,lastName,price,flyCode,typePassenger,statusFlight);

		if(cant == 7){
			unPasajero = Passenger_newParametros(id,name,lastName,price,flyCode,typePassenger,statusFlight);
		}
		if(unPasajero != NULL){
			ll_add(pArrayListPassenger, unPasajero);
			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	Passenger* pPassengerAux;

	if(pFile != NULL){

		do{

			pPassengerAux = Passenger_new();

			if(fread(pPassengerAux, sizeof(Passenger), 1, pFile) != 0){
				ll_add(pArrayListPassenger, pPassengerAux);
			}
		}while(!feof(pFile));
		retorno = 1;
	}
    return retorno;
}
