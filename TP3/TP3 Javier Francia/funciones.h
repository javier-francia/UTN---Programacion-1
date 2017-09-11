#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
    char title[200];
    char genre[30];
    int length;
    char description[300];
    int score;
    char imageLink[250];


}eMovie;










/** \brief Carga en memoria los datos extraidos del fichero especificado
 *
 * \param database                      Fichero seleccionado
 * \param *ptrMovie                     Apunta a la memoria dinamica, donde guardara los datos
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \param *iSizeStructsMemory           Puntero a la cantidad de espacio de eMovie reservado en memoria
 * \return Devuelve NULL si hay algun error | Si carga bien devuelve una direccion de memoria
 *
 */
eMovie* database_load (FILE *database, eMovie* , int* , int* );


/** \brief  Imprime un listado de peliculas y les asigna un ID temporal
 *
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int database_list (eMovie *ptrMovie, int iLoadedStructs);


/** \brief Escribe las peliculas cargadas en un fichero
 *
 * \param database                      Fichero seleccionado
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int database_write (FILE* database, eMovie*, int*);


/** \brief Toma y valida los datos a ingresar en una estructura eMovie
 *
 * \return Devuelve NULL si hay algun error | Si carga bien devuelve una direccion de memoria
 *
 */
eMovie* getData_eMovie();


/** \brief Agrega una pelicula a la base de datos del heap
 *
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \param *iSizeStructsMemory           Puntero a la cantidad de espacio de eMovie reservado en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int movieAdd (eMovie* ptrMovie, int*, int*);


/** \brief  Modifica una pelicula de la base de datos del heap
 *
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int movieModify (eMovie* ptrMovie, int *iLoadedStructs);


/** \brief  Elimina una pelicula de la base de datos del heap
 *
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \param *iSizeStructsMemory           Puntero a la cantidad de espacio de eMovie reservado en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int movieDelete (eMovie* ptrMovie, int *iLoadedStructs, int *iSizeStructsMemory);




/** \brief  Genera el archivo html requerido en el punto 4
 *
 * \param *ptrMovie                     Puntero estructura que apunta a la base de datos en el heap
 * \param *iLoadedStructs               Puntero a la cantidad de peliculas cargadas en memoria
 * \return Devuelve 0 si hay errores, 1 si sale todo bien
 *
 */
int printIndex(eMovie* ptrMovie, int *iLoadedStructs);






/********************************** COMPLEMENTARY FUNCTIONS *****************************************/
/****************************************************************************************************/



/** \brief Toma un valor de tipo int
 *
 * \param message                       Texto a ser mostrado
 * \param output                        Variable int donde se guarda el valor tomado
 * \return  Devuelve el entero ingresado
 *
 */
void getInt (char [], int);


/** \brief Toma un valor de tipo float
 *
 * \param message                       Texto a ser mostrado
 *
 * \return  Devuelve el numero de punto flotante ingresado
 *
 */
float getFloat (char []);


/** \brief Analiza si el string proporcionado contiene solo numeros
 *
 * \param str                           String a ser analizado
 *
 * \return Devuelve 1 si es numerico y 0 si no lo es
 *
 */
int isStrNumeric (char []);


/** \brief Analiza si el string proporcionado contiene solo caracteres
 *
 * \param str                           String a ser analizado
 *
 * \return Devuelve 1 si es numerico y 0 si no lo es
 *
 */
int isStrChar (char []);


/** \brief Toma una cadena de caracteres
 *
 * \param message                       Texto a ser mostrado
 * \param output                        Array donde se guardara la cadena ingresada
 *
 */
void getString (char [], char []);


/** \brief Toma un string que contenga solo letras y espacios
 *
 * \param message                       Texto a ser mostrado
 * \param output                        Array donde se guardara la cadena ingresada
 * \return Devuelve 1 si contiene solo letras y espacios, y devuelve 0 si contiene otra cosa
 *
 */
int getStringOnlyChar (char [], char []);


/** \brief Toma un string que contenga solo numeros
 *
 * \param message                       Texto a ser mostrado
 * \param output                        Array donde se guardara la cadena ingresada
 * \return Devuelve 1 si contiene solo numeros y 0 si contiene otra cosa
 *
 */
int getStringOnlyNum (char [], char []);


/** \brief Compara dos strings alfabeticamente sin importar mayuscula o minuscula
 *
 * \param str1                          Primer string a comparar
 * \param str2                          Segundo string a comparar
 * \return      Devuelve 1 si el primer string es mayor al segundo, -1 si el segundo es mayor al primero y 0 si son iguales
 *
 */
int stringCompare (char [], char []);




#endif // FUNCIONES_H_INCLUDED
