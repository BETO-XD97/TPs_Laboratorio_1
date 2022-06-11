/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"

Passenger* Passenger_new(){

	Passenger* unPasajero;
	unPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(unPasajero != NULL){

		unPasajero->id = 0;
		strcpy(unPasajero->nombre, " ");
		strcpy(unPasajero->apellido, " ");
		unPasajero->precio = 0;
		strcpy(unPasajero->codigoVuelo, " ");
		strcpy(unPasajero->tipoPasajero, " ");
		strcpy(unPasajero->estadoVuelo, " ");

	}

	return unPasajero;
}

Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo){

	Passenger* unPasajero;

	unPasajero = Passenger_new();

	int idAux;
	float precioAux;
	idAux = atoi(id);
	precioAux = atof(precio);

	if(unPasajero != NULL && id != NULL && nombre != NULL && apellido != NULL && precio != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL){

		if(!(Passenger_setId(unPasajero, idAux) &&
			Passenger_setNombre(unPasajero, nombre) &&
			Passenger_setApellido(unPasajero, apellido) &&
			Passenger_setPrecio(unPasajero, precioAux) &&
			Passenger_setCodigoVuelo(unPasajero, codigoVuelo) &&
			Passenger_setTipoPasajero(unPasajero, tipoPasajero) &&
			Passenger_setEstadoVuelo(unPasajero, estadoVuelo))
			)
		{
			Passenger_delete(unPasajero);
		}
	}
	return unPasajero;
}

void Passenger_delete(Passenger* this){//Destructor

	if(this != NULL){
		free(this);
	}

}

int Passenger_setId(Passenger* this,int id){

	int retorno;
	retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id){

	int retorno;
	retorno = 0;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){

	int retorno = 0;

	if(this != NULL && nombre != NULL){

		strlwr(nombre);
		nombre[0] = toupper(nombre[0]);
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){

	int retorno = 0;

	if(this != NULL && nombre != NULL){

		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	 return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno = 0;

	if(this != NULL && apellido != NULL){

		strlwr(apellido);
		apellido[0] = toupper(apellido[0]);
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno = 0;

	if(this != NULL && apellido != NULL){

		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){

	int retorno = 0;

	if(this != NULL && precio > 0){

		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){

	int retorno = 0;

	if(this != NULL && precio != NULL){

		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) > 0 && strlen(codigoVuelo) < 8){

		strupr(codigoVuelo);
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL){

		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){

	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL){

		strcpy(this->tipoPasajero, tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){

	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL){

		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo){

	int retorno = 0;

	if(this!= NULL && estadoVuelo != NULL){

		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){

	int retorno = 0;

	if(this != NULL && estadoVuelo != NULL){

		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_typePassengerDescripcion(int typePassenger, char* descripcion){

	int retorno = 0;

	if(typePassenger != 0 && descripcion != NULL){

		switch(typePassenger){
			 case 1:
				 strcpy(descripcion, "EconomyClass");
				 break;

			 case 2:
				 strcpy(descripcion, "ExecutiveClass");
				 break;

			 case 3:
				 strcpy(descripcion, "FirstClass");
				 break;
		}
		retorno = 1;
	}
	return retorno;
}

int Passenger_statusFlightDescripcion(int statusFlight, char* descripcion){

	int retorno = 0;

		if(statusFlight != 0 && descripcion != NULL){

			switch(statusFlight){
				 case 1:
					 strcpy(descripcion, "Aterrizado");
					 break;

				 case 2:
					 strcpy(descripcion, "En Horario");
					 break;

				 case 3:
					 strcpy(descripcion, "En Vuelo");
					 break;

				 case 4:
					 strcpy(descripcion, "Demorado");
					 break;
			}
			retorno = 1;
		}
		return retorno;
}

void Passenger_printOne(Passenger* unPasajero){

	//Variables auxilires para imprimir
	int idAux;
	char nameAux[50];
	char lastNameAux[50];
	float priceAux;
	char flyCodeAux[10];
	char typePassengerAux[50];
	char statusFlightAux[50];

	if(unPasajero != NULL){

		Passenger_getId(unPasajero, &idAux);
		Passenger_getNombre(unPasajero, nameAux);
		Passenger_getApellido(unPasajero, lastNameAux);
		Passenger_getPrecio(unPasajero, &priceAux);
		Passenger_getCodigoVuelo(unPasajero, flyCodeAux);
		Passenger_getTipoPasajero(unPasajero, typePassengerAux);
		Passenger_getEstadoVuelo(unPasajero, statusFlightAux);

		printf("|%6d| |%-24s| |%-26s| |$%13.2f| |%14s| |%19s| |%18s|\n", idAux, nameAux, lastNameAux, priceAux, flyCodeAux, typePassengerAux, statusFlightAux);

	}
}

int Passenger_searchForId(LinkedList* pArrayListPassengers, int id){

	int retorno = 0;

	Passenger* pPassengerAux;

	if(pArrayListPassengers != NULL && id != 0){

		for(int i=0; i<ll_len(pArrayListPassengers); i++){

			pPassengerAux =  (Passenger*) ll_get(pArrayListPassengers, i);

			if(pPassengerAux->id == id){
				retorno = i;
			}
		}
	}
	return retorno;
}

int maximoId(LinkedList* pArrayListPassengers){

	int retorno = 0;

	//Passenger* pPassengerAux;

	for(int i=0; i<ll_len(pArrayListPassengers); i++){
		retorno = i;
	}

	return retorno;
}


int verificarId(LinkedList* pArrayListPassenger, int idContador){
	int retorno = 0;

	if(pArrayListPassenger != NULL && idContador > 0){

		int tamano;
		int idAux;

		Passenger* unPasajeroAux;

		tamano = ll_len(pArrayListPassenger);

		if(tamano >= 0){

			for(int i = 0; i < idContador; i++){

				unPasajeroAux = ll_get(pArrayListPassenger,i);

				if(unPasajeroAux != NULL){

					idAux = i + tamano + 1 - idContador;

					if(Passenger_setId(unPasajeroAux, idAux) == 0){

						if(ll_set(pArrayListPassenger, i, unPasajeroAux) == 0){
							retorno = 1;
						}
					}
				}
			}
		}
	}

	return retorno;
}

