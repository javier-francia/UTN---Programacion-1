#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>

#define PROG 50
#define PROY 1000
#define PROY_PROG 1000

int main()
{

    eProgrammers programmer [PROG];
    eProyects proyect [PROY];
    eProy_Prog proyect_programmer [PROY_PROG];
    eCategories category [] = {{1,"Junior",50},{2,"SemiSenior",75},{3,"Senior",100}};

    char auxProyectName[20];
    char auxProgrammerIdChar[10];
    int auxProgrammerIdInt;
    int auxProyectIndex;
    char optionNewProyect;


    initDatabase(programmer, proyect, proyect_programmer);


    initHardcodedProgrammers(programmer);
    initHardcodedProyects(proyect);
    initHardcodedProy_Prog(proyect_programmer);

    int option = 0;
    while (option != 10)
    {
        system("cls");
        printf("1. Alta de programador\n");
        printf("2. Modificar datos del programador\n");
        printf("3. Baja del programador\n");
        printf("4. Asignar programador a proyecto\n");
        printf("5. Listado de programadores\n");
        printf("6. Listado de todos los proyectos\n");
        printf("7. Listar proyectos de programador\n");
        printf("8. Proyecto demandante\n");
        printf("9. Costo del proyecto\n");
        printf("10. Salir\n");
        printf("Opcion: ");

        scanf("%d",&option);
        system("cls");


        switch(option)
        {
        case 1:
            printf("ALTA DE PROGRAMADOR\n\n");

            if (programmerAdd(programmer))
            {
                printf("\nAlta realizada con exito.\n\n");
                system("pause");
                break;
            }
            else
            {
                printf("\nNo se pudo realizar el alta.\n\n");
                system("pause");
                break;
            }


        case 2:
            printf("MODIFICAR DATOS DEL PROGRAMADOR\n\n");

            if (programmerModify(programmer, category))
                {
                    printf("\nModificacion realizada con exito.\n\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nNo se pudo realizar la modificacion.\n\n");
                    system("pause");
                    break;
                }

        case 3:
            printf("BAJA DEL PROGRAMADOR\n\n");

            if(programmerDelete(programmer, proyect, category, proyect_programmer))
            {
                printf("\nBaja realizada con exito.\n\n");
                system("pause");
                break;
            }
            else
            {
                printf("\nNo se pudo realizar la baja.\n\n");
                system("pause");
                break;
            }

        case 4:
            printf("ASIGNAR PROGRAMADOR A PROYECTO\n\n");

            programmerSimpleList(programmer, category);

            if (!(getStringOnlyNum("\nIngrese un numero de ID: ", auxProgrammerIdChar)))
            {
                printf("\nERROR: El id debe contener solo numeros.\n");
                system("pause");
                break;
            }

            auxProgrammerIdInt = atoi(auxProgrammerIdChar);


            if (searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1) == -1)
            {
                printf("\nERROR: El numero de ID ingresado no se encuentra en el sistema.\n\n");
                system("pause");
                break;
            }

            system("cls");

            if (searchProyectFlag(proyect, PROY, 1) != -1)
            {
                proyectSimpleList(proyect);
            }
            else
            {
                printf("\nNo existen proyectos cargados en el sistema.\n");
            }

            if (!(getStringOnlyChar("\nIngrese el nombre del proyecto: ", auxProyectName)))
            {
                printf("\nERROR: El nombre del proyecto solo puede contener letras.\n");
                system("pause");
                break;
            }


            if (validateProyectName(proyect, auxProyectName) == 0)
            {
                printf("\nEl nombre de proyecto ingresado no existe en el sistema. Desea crearlo? (s/n): ");
                fflush(stdin);
                scanf("%c",&optionNewProyect);

                if (optionNewProyect == 's' || optionNewProyect == 'S')
                {
                    auxProyectIndex = searchProyectFlag(proyect, PROY, 0);

                    if(!proyect_programmerAdd(proyect_programmer, programmer, proyect, auxProyectIndex, auxProyectName, auxProgrammerIdInt))
                    {
                        printf("\nNo se pudo asignar el programador al proyecto.\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        printf("\nSe asigno el programador al proyecto con exito.\n\n");
                        system("pause");
                        break;
                    }
                }
                else
                {
                    break;
                }


            }
            else
            {
                auxProyectIndex = searchProyectName_flagCheck(proyect, auxProyectName, 1);

                if(!proyect_programmerAdd(proyect_programmer, programmer, proyect, auxProyectIndex, auxProyectName, auxProgrammerIdInt))
                {
                    printf("\nNo se pudo asignar el programador al proyecto.\n\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nSe asigno el programador al proyecto con exito.\n\n");
                    system("pause");
                    break;
                }
            }


    case 5:
            printf("LISTADO DE PROGRAMADORES\n\n");

            programmerFullList(programmer, proyect, proyect_programmer, category);


            system("pause");
            break;


        case 6:
            printf("LISTADO DE TODOS LOS PROYECTOS\n\n");

            proyectFullList(programmer, proyect, proyect_programmer, category);

            system("pause");
            break;


        case 7:
            printf("LISTAR PROYECTOS DE PROGRAMADOR\n\n");

            sortProgrammerById(programmer);
            programmerSimpleList(programmer, category);

            if (!(getStringOnlyNum("\nIngrese un numero de ID: ", auxProgrammerIdChar)))
            {
                printf("\nERROR: El id debe contener solo numeros.\n");
                system("pause");
                break;
            }

            auxProgrammerIdInt = atoi(auxProgrammerIdChar);


            if (searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1) == -1)
            {
                printf("\nERROR: El numero de ID ingresado no se encuentra en el sistema.\n\n");
                system("pause");
                break;
            }


            if (proyectOfProgramerList(programmer, proyect, proyect_programmer, auxProgrammerIdInt) == 0)
            {


            printf("\nEste programador no tiene proyectos asignados.\n");
            system("pause");
            break;

            }
            else
            {
                system("pause");
                break;
            }





        case 8:
            printf("PROYECTO DEMANDANTE\n\n");

            demandingProyect(proyect);
            system("pause");
            break;


        case 9:
            printf("COSTO DEL PROYECTO\n\n");

            proyectCostList(programmer, proyect, proyect_programmer, category);

            system("pause");
            break;

        default:
            break;
        }
    }

    return 0;
}
