/*
 * clientes.h
 *
 *  Created on: 2 may. 2021
 *      Author: ledes
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[14];
    int flag;
    int cantidadVentas;
} clientes;



/** \brief limpia el buffer o deja todo en limpio para luego cargar datos
 *
 * \param recibe arrays de clientes y su tamano
 * \return una variable de estad0=flag.
 */
int clientes_inicializar(clientes* list, int tamano);
/** \brief carga datos hard
 *
 * \param recibe arrays de clientes y su tamano
 * \return void.
 */
void clientes_inicializarConDatos (clientes* list, int tamano);

/** \brief se usa para que el usuario cargue datos de clientes
 *
 * \param recibe arrays de clientes y su tamano y la cantidad de ventas
 * \return retorno si esta todo ok, de lo contrario -1.
 */
int clientes_alta(clientes* list,int tamano);
/** \brief se usa para incrementar IDs en +1 cuadno se realiza una accion
 *
 * \param recibe arrays de clientes y su tamano
 * \return retorno +1.
 */
int clientes_idAutoIncremental(clientes* list, int tamano);
/** \brief busca espacios o indices vacios en donde alojar los nuevos datos ingresafdos
 *
 * \param recibe arrays de clientes y su tamano
 * \return inmdice.
 */

int clientes_buscarEspacio (clientes* list, int tamano);
/** \brief realiza baja logica de un cliente
 *
 * \param recibe arrays de clientes y su tamano
 * \return variable de estado=flag.
 */
int clientes_baja(clientes* list,int tamano);
/** \brief imprime un solo dato de un ID
 *
 * \param recibe arrays de clientes y su tamano
 * \return void.
 */
void clientes_mostrarUno (clientes list);
/** \brief mustra todos los datos solicitados
 *
 * \param recibe arrays de clientes y su tamano
 * \return retorno 0.
 */
void clientes_mostrarDatos(clientes* list, int tamano);
/** \brief busca espacios o indices vacios en donde alojar los nuevos datos ingresafdos
 *
 * \param recibe arrays de clientes y su tamano
 * \return inmdice.
 */
int clientes_encontrarPorId(clientes* list, int tamano, int id);
/** \brief modifica los clientes
 *
 * \param recibe arrays de ventas y su tamano
 * \return inmdice.
 */
int clientes_modificacion(clientes* list,int tamano);



#endif /* CLIENTES_H_ */
