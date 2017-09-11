#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
    FILE* database = NULL;
    eMovie* ptrMovie = NULL;
    eMovie *ptrAux = NULL;

    int iLoadedStructs = 0;
    int iSizeStructsMemory = 0;
    int option = 0;

    /*          CARGA LA BASE DE DATOS GUARDADA EN EL FICHERO       */
    ptrMovie = database_load(database, ptrMovie, &iLoadedStructs, &iSizeStructsMemory);
    if(ptrMovie == NULL)
    {
        printf("\nERROR: No se pudo cargar la base de datos correctamente.\n\n");
        system("pause");
        exit(0);
    }


    while(option != 5)
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir y guardar\n");
        printf("Opcion: ");

        scanf("%d", &option);
        system("cls");

        switch(option)
        {
        case 1:
            printf("AGREGAR PELICULA\n\n");

            if ((movieAdd(ptrMovie, &iLoadedStructs, &iSizeStructsMemory)) != 1)
            {
                printf("\nLa carga de peliculas no se pudo realizar.\n\n");
                system("pause");
                break;
            }

            if ((ptrAux = (eMovie*)realloc(ptrMovie, sizeof(eMovie) * iSizeStructsMemory)) != NULL)
            {
                ptrMovie = ptrAux;
            }
            else
            {
                iSizeStructsMemory--;

                printf("\nERROR: No hay lugar en la memoria.\n");
                system("pause");
                break;
            }

            if (ptrMovie == NULL)
            {
                printf("\nLa carga de peliculas no se pudo realizar.\n\n");
                system("pause");
                break;
            }

            printf("\nSe cargo la pelicula correctamente.\n\n");
            system("pause");
            break;
        case 2:
            printf("BORRAR PELICULA\n\n");

            if ((movieDelete(ptrMovie, &iLoadedStructs, &iSizeStructsMemory)) != 1)
            {
                printf("\nNo se pudo eliminar la pelicula.\n\n");
                system("pause");
                break;
            }

            if ((ptrAux = (eMovie*)realloc(ptrMovie, sizeof(eMovie) * iSizeStructsMemory)) != NULL)
            {
                ptrMovie = ptrAux;
            }
            else
            {
                iSizeStructsMemory++;

                printf("\nERROR: No hay lugar en la memoria.\n");
                system("pause");
                break;
            }

            if (ptrMovie == NULL)
            {
                printf("\nLa carga de peliculas no se pudo realizar.\n\n");
                system("pause");
                break;
            }

            printf("\nSe elimino la pelicula correctamente.\n\n");
            system("pause");
            break;


            break;
        case 3:
            printf("MODIFICAR PELICULA\n\n");

            if ((movieModify(ptrMovie, &iLoadedStructs)) != 1)
            {
                printf("\nLa modificacion de peliculas no se pudo realizar.\n\n");
                system("pause");
                break;
            }

            printf("\nSe modifico la pelicula correctamente\n\n");
            system("pause");

            break;
        case 4:
            /*      GENERAR HTML        */
            if (( printIndex(ptrMovie, &iLoadedStructs)) == 0)
            {
                printf("No se pudo generar el archivo html.\n\n");
            }
            else
            {
                printf("Se genero el archivo html.\n\n");
            }
            system("pause");

            break;
        case 5:
            /*      SALIR Y GUARDAR     */

            if ((database_write(database, ptrMovie, &iLoadedStructs)) == 0)
            {
                printf("\nNo se pudieron guardar las peliculas en la base de datos.\n\n");
                system("pause");
            }
            //free(ptrMovie);
            break;
        default:
            break;
        }
    }

    return 0;
}
