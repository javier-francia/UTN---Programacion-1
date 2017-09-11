#include "functions.h"


int main()
{

    FILE* database = NULL;


    ArrayList *list_database = NULL;
    ArrayList *list_priority_high = NULL;
    ArrayList *list_priority_low = NULL;


    int option = 0;

    list_database = al_newArrayList();
    list_priority_high = al_newArrayList();
    list_priority_low = al_newArrayList();



    if (list_database == NULL || list_priority_high == NULL || list_priority_low == NULL)
    {
        printf("ERROR: Una o mas listas dinamicas no se crearon correctamente.\n\n");
        system("pause");
        exit(1);
    }

    /* LEO LA BASE DE DATOS */


    while(option != 5)
    {
        system("cls");

        printf("|| SISTEMA DE GESTION DE TAREAS ||\n\n");

        printf("1. Cargar lista de tareas.\n");
        printf("2. Particionar por prioridad.\n");
        printf("3. Ordenar.\n");
        printf("4. Resolver tareas.\n");
        printf("5. Salir.\n");

        printf("\nOpcion: ");
        scanf("%d", &option);

        system("cls");


        switch(option)
        {
        case 1:
            printf("|| SISTEMA DE GESTION DE TAREAS ||\n\n");
            printf("CARGAR LISTA DE TAREAS:\n\n");

            if ((database_load(database, "tar.csv", list_database)) == -1)
            {
                printf("ERROR EN LA CARGA DE LA BASE DE DATOS.\n\n");
            }
            else
            {
                printf("Carga realizada con exito.\n\n");
            }

            system("pause");
            break;

        case 2:
            printf("|| SISTEMA DE GESTION DE TAREAS ||\n\n");
            printf("PARTICIONAR POR PRIORIDAD:\n\n");

            if (database_partition(list_database, list_priority_high, list_priority_low) != -1)
            {
                printf("La lista general se particiono en dos listas correctamente.\n\n");
            }
            else
            {
                printf("ERROR: Primero debe cargar una lista de tareas.\n\n");
            }

            system("pause");
            break;

        case 3:
            printf("|| SISTEMA DE GESTION DE TAREAS ||\n\n");
            printf("ORDENAR:\n\n");



            partition_order(list_priority_high, list_priority_low);

            system("pause");
            break;



        case 4:
            printf("|| SISTEMA DE GESTION DE TAREAS ||\n\n");
            printf("RESOLVER TAREAS:\n\n");

            task_do(list_priority_high, list_priority_low);

            system("pause");
            break;
        default:
            break;


        }
    }

    return 0;
}
