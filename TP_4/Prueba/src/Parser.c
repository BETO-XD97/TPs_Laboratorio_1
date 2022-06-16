#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Passenger.h"


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

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int readBin;

	Passenger* pPassengerAux;

	if(pFile != NULL){

		while(!feof(pFile)){

			pPassengerAux = Passenger_new();

			readBin = fread(pPassengerAux, sizeof(Passenger), 1, pFile);

			if(readBin != 0){

				ll_add(pArrayListPassenger, pPassengerAux);
			}
		}
		retorno = 1;
	}
    return retorno;
}
