/*
 * utn_Input.h
 *
 *  Created on: 16 jun. 2022
 *      Author: BETO
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_



#endif /* UTN_INPUT_H_ */

/**
 *  brief Ingresa un numero y verifica que sea numero y que no contenga letras llamando a
 *  otras funciones y valida que este dentro del rango con min max
 * @param pResultado int *
 * @param mensaje char*
 * @param mensajeError char*
 * @param min int
 * @param max int
 * @return [0]ok [-1]fail
 */
int input_Int(int *pResultado, char *mensaje, char *mensajeError, int min, int max);

/**
 *  brief Ingresa un numero y verifica que sea numero y que no contenga letras llamando a
 *  otras funciones y valida que este dentro del rango con min max
 * @param pResultado float*
 * @param mensaje char*
 * @param mensajeError char*
 * @param min float
 * @param max float
 * @return [0]ok [-1]fail
 */
int input_Float(float *pResultado, char *mensaje, char *mensajeError, float min, float max);

/**
 * brief Ingresa un texto y verifica que no contenga numeros recorriendolo con for
 * @param cadena char*
 * @param mensaje char*
 * @param mensajeError char*
 * @return [0]ok [-1]fail
 */
int input_Char(char* cadena, char* mensaje, char* mensajeError);

/**
 * brief Ingreso comun de texto solo para el codigo de vuelo
 * @param codigoDeVuelo char*
 * @param mensaje char*
 */
void rellenarCodigo(char* codigoDeVuelo, char* mensaje);

/**
 * brief Declara un dato tipo char en donde guardo el dato numerico
 * y valido que sea numerica con la funcion esNumerica en caso
 * de ser valido lo convierto con atoi y lo guardo en el puntero
 * @param pResultado int*
 * @return [0]ok [-1]fail
 */
int getInt(int *pResultado);

/**
 * brief Declara un dato tipo char en donde guardo el dato numerico
 * y valido que sea numerica con la funcion esNumerica en caso
 * de ser valido lo convierto con atof y lo guardo en el puntero
 * @param pResultado int*
 * @return [0]ok [-1]fail
 */
int getFloat(float *pResultado);

/**
 * brief Busca el final de la cadena recibida en getInt y getFloat
 * @param cadena char*
 * @param longitud int
 * @return [0]ok [-1]fail
 */
int myGets(char *cadena, int longitud);

/**
 * brief Verifica que el char recibida en getInt y getFloat NO
 * contenga ningun numero
 * @param cadena char*
 * @return [0]ok [1]fail
 */
int esNumerica(char *cadena);
