/*
 * utn.c
 *
 *  Created on: 17 abr. 2021
 *      Author: ledes
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * \brief realiza una division de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. 0  si se puede.
 */
int dividir(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;

		if (numeroB != 0 && pResultado != NULL)
		{
			*pResultado = numeroA / numeroB;
			retorno = 0;
		}

		return retorno;
}
/*
 * \brief realiza una suma de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno  si se puede.
 */
int sumar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = numeroA+numeroB;
			retorno = 0;
		}

		return retorno;

}
/*
 * \brief realiza una resta de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno si se puede.
 */
int restar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = numeroA-numeroB;
			retorno = 0;

		}
		return retorno;
}
/*
 * \brief realiza una multiplicacion de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno  si se puede.
 */
int multiplicar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(numeroA != 0 && numeroB != 0 && pResultado != NULL)
		{
			*pResultado = numeroA*numeroB;
			retorno = 0;
		}

		return retorno;

}
/*
 * \brief realiza una factorizacion .
 * \param numero con el preimer numero.
 * \return resultado si s epuede realizar , retorna 1 si no es correcto.
 */
int factorial(int numero) {
	int resultado;

	if (numero >= 1) {
		resultado = (numero * factorial(numero - 1));
		return resultado;
	} else {
		return 1;
	}
}
/*
 * \brief comprueba datos ingresados.
 * \param pDatoIngresado con el dato.
 * \param pTexto con el texto que imprime al usuario.
 * \param min con la menor cantidad de opciones.
 * \param max  con la mayor cantidad de opciones.
 * \param reintentos asigna reintentos del usuario.
 * \return retorno si se puede realizar , retorna -1 si no es correcto.
 */
int utn_getInt(int *pDatoIngresado, char *pTexto, char *pTextoError, int min,
		int max, int reintentos) {
	int retorno = -1;

	for (int i = 0; reintentos >= i; reintentos--) {
		printf("%s\n", pTexto);
		fflush(stdin);
		if (scanf("%d", pDatoIngresado) == 1) {
			if (min <= max && (*pDatoIngresado) >= min
					&& (*pDatoIngresado) <= max) {
				retorno = 0;
				break;
			} else {
				printf("%s\n", pTextoError);
			}
		} else {
			printf("%s\n", pTextoError);
		}
	}
	return retorno;
}
float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}
char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(input);
}
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if (str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if (contadorGuiones==1)
        return 1;
        return 0;
}



int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
} utn_getCuit(char* pString,int limite,char* pTexto,char* pError, int reintentos){

    int retorno;
    char bChar[limite];

    if(pString!=NULL && pTexto!=NULL && pError!=NULL && reintentos>=0){
        for(int i=0; i<reintentos;i++){
            printf("%s",pTexto);
            fflush(stdin);
            if(getCuit(bChar,limite)==0){
                    strncpy(pString,bChar,limite);
                    retorno= 0;
                    reintentos=0;
            }else{
                printf("%s\n",pError);
                retorno=-1;
            }
        }
    }else{
        retorno=-1;
    }
    return retorno;
}
int getCuit(char* pString, int limite){

    int retorno=-1;
    char buffer[limite];

    if(pString!=NULL){
        fgets(buffer,limite,stdin);
        if(ValidateCuit(buffer)){
            strncpy(pString,buffer,limite);
            retorno=0;
        }
    }else{
        retorno=-1;
    }
    return retorno;
}
int ValidateCuit(char* charArray){
    int i=0;
    int retorno=-1;
    if(charArray !=NULL && strlen(charArray)>0){
        while(charArray[i] != '\0'){
            if( (charArray[i]>='0' && charArray[i]<='9')||
                (charArray[0]=='2' && charArray[0]=='3')||
                (charArray[2]=='-' && charArray[11]=='-'))
            {
                retorno=1;
            }else{
                retorno= 0;
                break;
            }
        i++;
        }
    }
    return retorno;
}
int esNumerico (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}

