/*
 * utn.h
 *
 *  Created on: 17 abr. 2021
 *      Author: ledes
 */

#ifndef UTN_H_
#define UTN_H_
/** \brief realiza una division
 *
 * \param a o b, numeros ingresados para resolver, Presultado el resultado
 * \return el resultado de la operacion.
 */

int dividir(int numeroA, int numeroB, float *pResultado);
/** \brief realiza una suma
 *
 * \param a o b, numeros ingresados para resolver, Presultado el resultado
 * \return el resultado de la operacion.
 */
int sumar(int numeroA, int numeroB, float *pResultado);
/** \brief realiza una resta
 *
 * \param a o b, numeros ingresados para resolver, Presultado el resultado
 * \return el resultado de la operacion.
 */
int restar(int numeroA, int numeroB, float *pResultado);
/** \brief realiza una multiplicacion
 *
 * \param a o b, numeros ingresados para resolver, Presultado el resultado
 * \return el resultado de la operacion.
 */
int multiplicar(int numeroA, int numeroB, float *pResultado);
/** \brief realiza una busqueda de factorial
 *
 * \param a , numeros ingresados para resolver, Presultado el resultado
 * \return el resultado de la operacion.
 */
int factorial(int numero);
/** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
float getFloat (char mensaje[]);
/** \brief Solicita un caracter al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el caracter ingresado por el usuario.
 */
char getChar(char mensaje[]);
/** \brief Solicita un texto al usuario.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return void.
 */
void getString(char mensaje[], char input[]);
/** \brief Verifica si el valor recibido es un numero entero.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es un numero entero // 0 si no es un numero entero.
 */
int esNumerico (char str[]);
/** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
int utn_getInt(int *pDatoIngresado, char *pTexto, char *pTextoError, int min,
		int max, int reintentos);
/** \brief arma un menu
 *
 * \param Presultado
 * \return Es el numero ingresado por el usuario.
 */
int getMenu(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int intentos);
/** \brief Solicita un numero de cuit  al usuario y devuelve el resultado
 *
 * \param captura el string, limite solicita con texto, mensaje de erroir y reintentos
 * \return Es el numero ingresado por el usuario.
 */
int utn_getCuit(char* pString,int limite,char* pTexto,char* pError, int reintentos);
/** \brief Solicita un numero de cuit  al usuario y devuelve el resultado
 *
 * \param captura el string, limite solicita con texto, mensaje de erroir y reintentos
 * \return Es el numero ingresado por el usuario.
 */
int getCuit(char* pString, int limite);
/** \brief valida el cuit que se usa en la funcion UTN_getCuit
 *
 * \param captura el string, limite solicita con texto, mensaje de erroir y reintentos
 * \return Es el numero ingresado por el usuario.
 */
int ValidateCuit(char* charArray);

#endif /* UTN_H_ */
