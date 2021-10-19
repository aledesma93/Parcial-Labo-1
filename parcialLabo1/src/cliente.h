/*
 * cliente.h
 *
*  Created on: 14 oct. 2021
 *      Author: ALEDESMA
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define LIBRE 0
#define OCUPADO 1


typedef struct
{
  int id;
  char NombreEmpresa[50];
  int cuit;
  char direccion[50];
  char localidad [50];
  int contadorPedidos;
  int isEmpty;

}eCliente;

int InicializarListaProductos(eCliente listaClientes[],int tam);
int AltaCliente(eCliente listaClientes[],int tam,int*);
void MostrarUnCliente(eCliente unCliente);
int MostrarListadoClientes(eCliente listaClientes[], int tam);
int ModificarCliente(eCliente listaClientes[],int tam);
int BuscarCliente(eCliente listaClientes[],int tam);
int BajaCliente(eCliente listaClientes[],int tam);



#endif /* CLIENTE_H_ */
