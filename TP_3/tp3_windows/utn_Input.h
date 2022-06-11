/*
 * utn_Input.h
 *
 *  Created on: 21 may. 2022
 *      Author: BETO
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_


#endif /* UTN_INPUT_H_ */

/**
 * brief Ingreso de dato numerico de tipo int y valido
 * @param inputInt puntero int
 * @param inputChar texto de ingreso
 * @param inputError texto de error
 * @param min minimo valor para validacion
 * @param max maximo valor para validacion
 * @return retorna el numero ingresado
 */
int input_Int(int* inputInt, char inputChar[], char inputError[], int min, int max);

/**
 * brief Ingreso de dato numerico de tipo float y valido
 * @param inputFloat puntero float
 * @param inputChar texto de ingreso
 * @param inputError texto de error
 * @param min minimo valor para validacion
 * @param max maximo valor para validacion
 * @return retorna el numero ingresado
 */
float input_Float(float* inputFloat, char inputChar[], char inputError[], float min, float max);

/**
 * brief Ingreso el dato alfabetico de tipo char y valido
 * @param inputChar puntero char
 * @param outputChar texto de ingreso
 * @return 1 valido 0 invalido
 */
void input_Char(char arrayRecibido[], char textoAMostrar[]);

