/*
 * tpInput.c
 *
 *  Created on: 12 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pasajeros.h"
#include "tpInput.h"

#define TAM 51

void rellenarCodigo(char* codigoDeVuelo, char* mensaje){

	printf(mensaje);
	fflush(stdin);
	gets(codigoDeVuelo);
}

int myGets(char *cadena, int longitud){

	int retorno = -1;

	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena){

		fflush(stdin);

		if (cadena[strlen(cadena) - 1] == '\n'){

			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int getInt(int *pResultado){

	int retorno = -1;
	char buffer[50];

	if (pResultado != NULL){

		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){

			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float *pResultado){

	int retorno = -1;
	char buffer[50];

	if(pResultado != NULL){

		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){

			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int esNumerica(char *cadena){

	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0){

		while(cadena[i] != '\0'){

			if (isalpha(cadena[i]) != 0){

				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int input_Int(int *pResultado, char *mensaje, char *mensajeError, int min, int max){

	int bufferInt;
	int retorno = -1;

	while(retorno != 0){

		printf("%s", mensaje);

		if (getInt(&bufferInt) == 0){

			if (bufferInt >= min && bufferInt <= max){

				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int input_Float(float *pResultado, char *mensaje, char *mensajeError, float min, float max){

	float bufferFloat;
	int retorno = -1;

	while(retorno != 0){

		printf("%s", mensaje);

		if (getFloat(&bufferFloat) == 0){

			if (bufferFloat >= min && bufferFloat <= max){

				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int input_Char(char* cadena, char* mensaje, char* mensajeError){

	int retorno = 1;

	while(retorno != 0){

		printf(mensaje);
		fflush(stdin);
		gets(cadena);

		for (int i = 0; i < strlen(cadena); i++){

			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ'){

				retorno = 1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}
	return retorno;
}
