/*
 ============================================================================
 Name        : parcial1.c
 Author      : aledesma
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANO 100
#include "clientes.h"
#include "ventas.h"
#include "utn.h"
#include "informes.h"

int main()
{
	setbuf(stdout, NULL);
    int comprobarInicializacion;
    int comprobarInicializacion1;
    int auxCantidadVentas=0;

    clientes lista[TAMANO];
    ventas listaVentas[TAMANO];
    comprobarInicializacion = clientes_inicializar(lista, TAMANO);
    comprobarInicializacion1 = ventas_inicializar(listaVentas, TAMANO);

    if (comprobarInicializacion == 0 && comprobarInicializacion1==0)
    {
        printf("Todos los estados se han inicializado.\n\n");
    }
    else
    {
        printf("Ha ocurrido un error al inicializar estados.\n\n\n");
    }


    clientes_inicializarConDatos(lista, TAMANO);
    ventas_inicializarConDatos(listaVentas, TAMANO);


    system("cls");


    char opcion;

    do
    {
        printf("(1) ALTA CLIENTE\n");
        printf("(2) BAJA CLIENTE\n");
        printf("(3) MODIFICACION CLIENTE\n");
        printf("(4) MOSTRAR CLIENTES Y COMPRAS\n");
        printf("(5) REALIZAR COMPRA\n");
        printf("(6) PAGAR COMPRAS\n");
        printf("(7) CANCELAR COMPRAS\n");
        printf("Debe elegir una opcion a realizar: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6')
        {
            printf("Error. Ha ingresado una opcion erronea!\n\n");
            printf("Debe elegir una opcion a realizar: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch (opcion)
        {
        case '1':
        	clientes_alta(lista, TAMANO);
            break;

        case '2':
        	clientes_baja(lista, TAMANO);
            break;

        case '3':
        	clientes_modificacion(lista, TAMANO);
            break;

        case '4':
            clientes_mostrarDatos(lista, TAMANO);
            break;

        case '5':
        	ventas_alta(listaVentas, TAMANO,&auxCantidadVentas);
            break;

        case '6':
        	ventas_mostrarDatos(listaVentas, TAMANO);
            break;

        default:
            printf("Error. Ha ingresado una opcion erronea.\n\n");
        }

        system("pause");
        system("cls");
    }
    while (opcion!= '6');

    return 0;
}
