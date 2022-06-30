#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"


/**
 * brief Crea un nuevo pasajero(un nuevo nodo)
 * @return retorna el pasajero con sus parametros inicializados en NULL
 */
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

/**
 * brief Toma los valores del archivo data.csv y setea los datos en cada uno de los elementos de un nodo
 * @param id puntero a char
 * @param nombre puntero a char
 * @param apellido puntero a char
 * @param precio puntero a char
 * @param codigoVuelo puntero a char
 * @param tipoPasajero puntero a char
 * @param estadoVuelo puntero a char
 * @return
 */
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

/**
 * bried Destruye un nodo de tipo pasajero
 * @param this referencia
 */
void Passenger_delete(Passenger* this){//Destructor

	if(this != NULL){
		free(this);
	}

}

/**
 * brief Guarda el id recibido en el campo id de la estructura
 * @param this estructura
 * @param id int
 * @return [1]-ok  [0]-fail
 */
int Passenger_setId(Passenger* this,int id){

	int retorno;
	retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

/**
 * brief Envia el dato en el elemento id a un puntero
 * @param this estructura
 * @param id int
 * @return [1]-ok  [0]-fail
 */
int Passenger_getId(Passenger* this,int* id){

	int retorno;
	retorno = 0;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

/**
 * brief Guarda el nombre recibido en el campo nombre de la estructura
 * @param this estructura
 * @param nombre char*
 * @return [1]-ok  [0]-fail
 */
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

/**
 * brief Envia el dato en el elemento nombre a un puntero char
 * @param this estructura
 * @param nombre char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_getNombre(Passenger* this,char* nombre){

	int retorno = 0;

	if(this != NULL && nombre != NULL){

		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	 return retorno;
}

/**
 * brief Guarda el apellido recibido en el campo apellido de la estructura
 * @param this estructura
 * @param apellido char*
 * @return [1]-ok  [0]-fail
 */
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

/**
 * brief Envia el dato en el elemento apellido a un puntero char
 * @param this estructura
 * @param apellido char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno = 0;

	if(this != NULL && apellido != NULL){

		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

/**
 * brief Guarda el precio recibido en el campo precio de la estructura
 * @param this estructura
 * @param precio float
 * @return [1]-ok  [0]-fail
 */
int Passenger_setPrecio(Passenger* this,float precio){

	int retorno = 0;

	if(this != NULL && precio > 0){

		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Envia el dato en el elemento precio a un puntero
 * @param this estructura
 * @param precio float puntero
 * @return [1]-ok  [0]-fail
 */
int Passenger_getPrecio(Passenger* this,float* precio){

	int retorno = 0;

	if(this != NULL && precio != NULL){

		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Guarda el codigo de vuelo recibido en el campo codigovuelo de la estructura
 * @param this estructura
 * @param codigoVuelo char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) > 0 && strlen(codigoVuelo) < 8){

		strupr(codigoVuelo);
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Envia el dato en el elemento codigoVuelo a un puntero char
 * @param this estructura
 * @param codigoVuelo char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL){

		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Guarda el tipo de pasajero recibido en el campo tipoPasajero de la estructura
 * @param this estructura
 * @param tipoPasajero char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){

	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL){

		strcpy(this->tipoPasajero, tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Envia el dato en el elemento tipoPasajero a un puntero char
 * @param this estructura
 * @param tipoPasajero char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){

	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL){

		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Guarda el estado de vuelo recibido en el campo estadoVuelo de la estructura
 * @param this estructura
 * @param estadoVuelo char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo){

	int retorno = 0;

	if(this!= NULL && estadoVuelo != NULL){

		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Envia el dato en el elemento estadoVuelo a un puntero char
 * @param this estructura
 * @param estadoVuelo char*
 * @return [1]-ok  [0]-fail
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){

	int retorno = 0;

	if(this != NULL && estadoVuelo != NULL){

		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

/**
 * brief Recibe un int y dependiendo del numero copia un mensaje en un puntero char
 * @param typePassenger int
 * @param descripcion char *
 * @return [1]-ok  [0]-fail
 */
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

/**
 * brief Recibe un int y dependiendo del numero copia un mensaje en un puntero char
 * @param statusFlight int
 * @param descripcion char *
 * @return [1]-ok  [0]-fail
 */
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

/**
 * brief Imprime un pasajero
 * @param unPasajero
 */
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

/**
 * brief Busca el id recibiendo un idAux tipo int
 * @param pArrayListPassengers estructura
 * @param id int
 * @return retorna el id encontrado
 */
int Passenger_searchForId(LinkedList* pArrayListPassengers, int id){

	int retorno = -1;

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

/**
 * brief Busca el mayor id de la linkedlist
 * @param pArrayListPassengers estructura
 * @return retorna el mayor id
 */
int maximoId(LinkedList* pArrayListPassengers){

	int retorno = 0;

	//Passenger* pPassengerAux;

	for(int i=0; i<ll_len(pArrayListPassengers); i++){
		retorno = i;
	}

	return retorno;
}

/**
 * brief Recibe los id de los pasajero ingresados anteriormente de cargar el archivo, en caso de
 * cargar el archivo teniendo pasajeros ingresados, los id de estos se le suman el ultimo id
 * del archivo modificando sus id.
 * @param pArrayListPassenger estructura
 * @param idContador int contador de los id ingresados
 * @return modifica los id anteriores a la carga del archivo
 */
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

/**
 * brief Ordena la lista por Id
 * @param idPassengerOne estructura pasajero 1
 * @param idPassengerTwo estructura pasajero 2
 * @return retorna la comparacion
 */
int Passenger_sortById(void* idPassengerOne, void* idPassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(idPassengerOne != NULL && idPassengerTwo != NULL){

		pPassengerOne = (Passenger*) idPassengerOne;
		pPassengerTwo = (Passenger*) idPassengerTwo;

		if(pPassengerOne->id > pPassengerTwo->id){
			retorno = 1;
		} else {
			if(pPassengerOne->id == pPassengerTwo->id){
				retorno = 0;
			} else {
				retorno = -1;
			}
		}
	}

	return retorno;
}

/**
 * brief Ordena la lista por nombre
 * @param namePassengerOne estructura pasajero 1
 * @param namePassengerTwo estructura pasajero 2
 * @return retorna la comparacion
 */
int Passenger_sortByName(void* namePassengerOne, void* namePassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(namePassengerOne != NULL && namePassengerTwo != NULL){

		pPassengerOne = (Passenger*) namePassengerOne;
		pPassengerTwo = (Passenger*) namePassengerTwo;

		retorno = strcmp(pPassengerOne->nombre, pPassengerTwo->nombre);
	}

	return retorno;
}

/**
 * brief Ordena la lista por apellido
 * @param lastNamePassengerOne estructura pasajero 1
 * @param lastNamePassengerTwo estructura pasajero 2
 * @return retorna la comparacion
 */
int Passenger_sortByLastName(void* lastNamePassengerOne, void* lastNamePassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(lastNamePassengerOne!= NULL && lastNamePassengerTwo != NULL){

		pPassengerOne = (Passenger*) lastNamePassengerOne;
		pPassengerTwo = (Passenger*) lastNamePassengerTwo;

		retorno = strcmp(pPassengerOne->apellido, pPassengerTwo->apellido);
	}

	return retorno;
}

/**
 * brief Ordena la lista por precio
 * @param pricePassengerOne estructura pasajero 1
 * @param pricePassengerTwo estructura pasajero 2
 * @return retorna la comparacion
 */
int Passenger_sortByPrice(void* pricePassengerOne, void* pricePassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(pricePassengerOne != NULL && pricePassengerTwo != NULL){

		pPassengerOne = (Passenger*) pricePassengerOne;
		pPassengerTwo = (Passenger*) pricePassengerTwo;

		if(pPassengerOne->precio > pPassengerTwo->precio){
			retorno = 1;
		} else {
			if(pPassengerOne->precio == pPassengerTwo->precio){
				retorno = 0;
			} else {
				retorno = -1;
			}
		}
	}

	return retorno;
}

/**
 * brief Ordena la lista por codigo de vuelo
 * @param flyCodePassengerOne estructura pasajero 1
 * @param flyCodePassengerTwo estructura pasajero 2
 * @return retorna el ordenamiento
 */
int Passenger_sortByFlyCode(void* flyCodePassengerOne, void* flyCodePassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(flyCodePassengerOne != NULL && flyCodePassengerTwo != NULL){

		pPassengerOne = (Passenger*) flyCodePassengerOne;
		pPassengerTwo = (Passenger*) flyCodePassengerTwo;

		retorno = strcmp(pPassengerOne->codigoVuelo, pPassengerTwo->codigoVuelo);
	}

	return retorno;
}

/**
 * brief Ordena la lista por tipo de pasajero
 * @param typePassengerOne estructura pasajero 1
 * @param typePassengerTwo estructura pasajero 2
 * @return retorna el ordenamiento
 */
int Passenger_sortByTypePassenger(void* typePassengerOne, void* typePassengerTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(typePassengerOne != NULL && typePassengerTwo != NULL){

		pPassengerOne = (Passenger*) typePassengerOne;
		pPassengerTwo = (Passenger*) typePassengerTwo;

		retorno = strcmp(pPassengerOne->tipoPasajero, pPassengerTwo->tipoPasajero);
	}

	return retorno;
}

/**
 * brief Ordena la lista por estado de vuelo
 * @param statusFlightOne estructura pasajero 1
 * @param statusFlightTwo estructura pasajero 2
 * @return retorna el ordenamiento
 */
int Passenger_sortByStatusFlight(void* statusFlightOne, void* statusFlightTwo){

	int retorno = 0;

	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;

	if(statusFlightOne != NULL && statusFlightTwo != NULL){

		pPassengerOne = (Passenger*) statusFlightOne;
		pPassengerTwo = (Passenger*) statusFlightTwo;

		retorno = strcmp(pPassengerOne->estadoVuelo, pPassengerTwo->estadoVuelo);
	}
	return retorno;
}
