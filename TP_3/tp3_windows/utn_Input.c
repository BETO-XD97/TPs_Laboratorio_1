/*
 * utn_Input.c
 *
 *  Created on: 21 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int input_Int(int* inputInt, char inputChar[], char inputError[], int min, int max){
	*inputInt = 0;
	int input = 0;
	int retorno;
	printf(inputChar);
	scanf("%d", inputInt);
	fflush(stdin);
	if(*inputInt < min || *inputInt > max){
		do{
			printf(inputError);
			scanf("%d", inputInt);
			fflush(stdin);
			if(*inputInt >= min && *inputInt <= max){
				input = 1;
			}
		}while(input != 1);
		retorno = *inputInt;
	} else {
		retorno = *inputInt;
	}

	while(*inputInt == 0){
		printf(inputError);
		scanf("%d", inputInt);
		fflush(stdin);
	}

	return retorno;
}

float input_Float(float* inputFloat, char inputChar[], char inputError[], float min, float max){
	*inputFloat = 0;
		int input = 0;
		int retorno;
		printf(inputChar);
		scanf("%f", inputFloat);
		fflush(stdin);
		if(*inputFloat < min || *inputFloat > max){
			do{
				printf(inputError);
				scanf("%f", inputFloat);
				fflush(stdin);
				if(*inputFloat >= min && *inputFloat <= max){
					input = 1;
				}
			}while(input != 1);
			retorno = *inputFloat;
		} else {
			retorno = *inputFloat;
		}

		while(*inputFloat == 0){
			printf(inputError);
			scanf("%f", inputFloat);
			fflush(stdin);
		}

		return retorno;

}

void input_Char(char arrayRecibido[], char textoAMostrar[]){
	printf(textoAMostrar);
	fflush(stdin);
	gets(arrayRecibido);

}

