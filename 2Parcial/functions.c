#include "functions.h"



int database_load (FILE *database, char dbName[], ArrayList *pList)
{
    int returnAux = -1;

    eTasks *ptrAux = NULL;

    ArrayList *auxList = NULL;

    char auxDescription[30];
    char auxPriorityChar[2];
    int auxPriority;
    char auxHoursChar[6];
    int auxHours;


    if ((database = fopen (dbName, "r")) != NULL)
    {
        /* lectura del fichero y almacenamiento en lista temporal */

        if ((auxList = al_clone(pList)) != NULL)
        {

            while (!feof(database))
            {
                if (fscanf(database,"%[^,],%[^,],%[^\n]\n", auxDescription, auxPriorityChar, auxHoursChar) == 3)
                {
                    auxPriority = atoi(auxPriorityChar);
                    auxHours = atoi(auxHoursChar);

                    ptrAux = task_new();

                    if (task_initialize(ptrAux, auxHours, auxPriority, auxDescription) != -1)
                    {
                        pList->add(auxList, ptrAux);
                        returnAux = 1;
                    }

                }
                else
                {
                    if (returnAux == -1)
                    {
                        /* Si entra al else sin haber pasado por el if, marca que el fichero esta vacio */

                        returnAux = 0;
                    }
                    break;
                }
            }
        }

        if (returnAux != -1)
        {

            for (int i = 0; i < al_len(auxList); i++)
            {
                al_add(pList, al_get(auxList, i));
            }

            auxList->deleteArrayList(auxList);

            if (fclose(database) == -1)
            {
                printf("\nERROR: No se pudo cerrar el archivo.\n");
                system("pause");
                returnAux = -1;
            }
        }
    }

    return returnAux;
}


int database_partition (ArrayList *pList, ArrayList *pListHigh, ArrayList *pListLow)
{
    int returnAux = -1;

    eTasks *auxTask = NULL;

    for (int i = 0; i < pList->len(pList); i++)
    {
        auxTask = (eTasks*) pList->get(pList, i);

        if (auxTask->priority == 1)
        {
            pListHigh->add(pListHigh, auxTask);
            returnAux = 0;
        }
        else if (auxTask->priority == 0)
        {
            pListLow->add(pListLow, auxTask);
            returnAux = 0;
        }
    }

    if (returnAux == 0)
    {
        pList->clear(pList);
    }

    return returnAux;
}


void partition_order (ArrayList *pList1, ArrayList *pList2)
{
    eTasks *auxTask = NULL;

    pList1->sort(pList1, hours_compare, 0);
    pList2->sort(pList2, hours_compare, 0);

    if (pList1->isEmpty(pList1) == 0)
    {
        printf("PRIORIDAD ALTA\n");
        printf("|       TAREAS       | HS |\n");
        for (int i = 0; i < pList1->len(pList1); i++)
        {
            auxTask = (eTasks*) pList1->get(pList1, i);

            printf("|%20s|%4d|\n", auxTask->description, auxTask->iHours);
        }
    }

    if (pList2->isEmpty(pList2) == 0)
    {
        printf("PRIORIDAD BAJA\n");
        printf("|       TAREAS       | HS |\n");
        for (int i = 0; i < pList2->len(pList2); i++)
        {
            auxTask = (eTasks*) pList2->get(pList2, i);

            printf("|%20s|%4d|\n", auxTask->description, auxTask->iHours);
        }
    }

    if (pList1->isEmpty(pList1) == 1 && pList2->isEmpty(pList2) == 1)
    {
        printf("No hay mas tareas en el sistema.\n\n");
    }

}


int hours_compare (eTasks *task1, eTasks *task2)
{
    int returnAux;

    if (task1->iHours > task2->iHours)
    {
        returnAux = 1;
    }
    else if (task1->iHours < task2->iHours)
    {
        returnAux = -1;
    }
    else
    {
        returnAux = 0;
    }

    return returnAux;
}


void task_do (ArrayList *pList1, ArrayList *pList2)
{
    eTasks *auxTask = NULL;

    pList1->sort(pList1, hours_compare, 1);
    pList2->sort(pList2, hours_compare, 1);

    if (pList1->isEmpty(pList1) == 0)
    {
        printf("PROXIMA TAREA:\n\n");

        auxTask = (eTasks*) pList1->pop(pList1, 0);

        printf("Descripcion: %s\nTiempo en horas: %d\nPrioridad: Alta\n\n", auxTask->description, auxTask->iHours);
    }
    else if (pList2->isEmpty(pList2) == 0)
    {
        printf("PROXIMA TAREA:\n\n");

        auxTask = (eTasks*) pList2->pop(pList2, 0);

        printf("Descripcion: %s\nTiempo en horas: %d\nPrioridad: Baja\n\n", auxTask->description, auxTask->iHours);
    }
    else
    {
        printf("No quedan tareas pendientes.\n\n");
    }

}


eTasks* task_new()
{
    eTasks* returnAux = NULL;
    returnAux = (eTasks*) malloc (sizeof(eTasks));

    if (returnAux == NULL)
    {
        printf("\nERROR: No hay lugar en memoria.\n");
        system("pause");
    }
    return returnAux;
}

int task_initialize(eTasks* task, int auxHours, int auxPriority, char auxDescription[])
{
    int returnAux = -1;
    if (task != NULL)
    {
        task->iHours = auxHours;
        task->priority = auxPriority;
        strcpy(task->description, auxDescription);
        returnAux = 0;
    }

    return returnAux;
}
