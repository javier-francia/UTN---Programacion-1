#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"


struct eTasks
{
    char description[30];
    int priority;
    int iHours;

}typedef eTasks;


/** \brief Lee un fichero y lo incorpora en una lista
 *
 * \param   *database                Puntero a FILE seleccionado
 * \param   dbName[]                 Nombre del fichero con extension
 * \param   *pList                   Lista donde se incorporan los datos leidos
 *
 * \return  -1 si hay error | 0 si lee bien pero no hay datos para cargar | 1 si lee bien y cargo por lo menos un elemento
 *
 */
int database_load (FILE *database, char dbName[], ArrayList *pList);



/** \brief Divide la lista original cargada del fichero en 2 listas, dependiendo de la prioridad de la tarea
 *
 * \param *pList                            Lista original cargada con datos leidos del fichero
 * \param *pListHigh                        Nueva lista con elementos de prioridad alta
 * \param *pListLow                         Nueva lista con elementos de prioridad baja
 * \return -1 si hay algun error | 0 si esta todo bien
 *
 */
int database_partition (ArrayList *pList, ArrayList *pListHigh, ArrayList *pListLow);


/** \brief Ordena las listas en funcion del tiempo de forma descendente y las imprime, siempre que haya elementos en ellas
 *
 * \param *pList1                       Lista seleccionada
 * \param *pList2                       Lista seleccionada
 *
 */
void partition_order (ArrayList *pList1, ArrayList *pList2);


/** \brief Funcion complementaria para usar al_sort, que compara el campo iHours de una estructura eTasks
 *
 * \param *task1                        Puntero a estructura eTasks
 * \param *task2                        Puntero a estructura eTasks
 *
 * \return      task1>task2 devuelve 1 | task1=task2 devuelve 0 | task1<task2 devuelve -1
 *
 */
int hours_compare (eTasks *task1, eTasks *task2);


/** \brief Ordena ambas listas de forma ascendente y le hace pop al elemento que sigue en la lista, con la prioridad pedida
 *
 * \param *pList1                       Lista seleccionada
 * \param *pList2                       Lista seleccionada
 *
 *
 */
void task_do (ArrayList *pList1, ArrayList *pList2);


/** \brief  Asigna espacio en el heap para tipo eTasks
 *
 * \return eTasks*  Puntero a eTasks
 *
 */
eTasks* task_new();

/** \brief  Inicializa un puntero eTasks
 *
 * \param task eTasks*          Puntero eTasks
 * \param auxHours int          Input horas
 * \param auxPriority int       Input prioridad
 * \param auxDescription int    Input descripcion
 * \return int      -1 Si hay error    //   0 si funciona bien
 *
 */
int task_initialize(eTasks* task, int auxHours, int auxPriority, char auxDescription[]);

#endif // FUNCTIONS_H_INCLUDED
