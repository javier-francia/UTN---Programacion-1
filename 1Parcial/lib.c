#include "lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PROG 50
#define PROY 1000
#define PROY_PROG 1000





/***************************************** HARDCODED ************************************************/
/****************************************************************************************************/



void initHardcodedProgrammers (eProgrammers programmer[])
{
    eProgrammers aux [] = {{123, "Julio", "Garcia", 1, 3, 1},{456, "Eduardo", "Mazza", 2, 3, 1},{789, "Alberto", "Alonso", 1, 2, 1},{147, "Gerardo", "Fernandez", 2, 1, 1},{258, "Carlos", "Ranni", 1, 1, 1},{369, "Fernando", "Craus", 3, 1, 1},{741, "Diego", "Fresno", 3, 0, 1},{852, "Luis", "Urtz", 3, 0, 1},{963, "Mariana", "Cortazar", 3, 0, 1},{951, "Alejandra", "Tanasi", 2, 0, 1} };
    for (int i = 0; i < 10; i++)
    {

        programmer[i].idProgrammer = aux[i].idProgrammer;
        strcpy(programmer[i].nameProg, aux[i].nameProg);
        strcpy(programmer[i].surnameProg, aux[i].surnameProg);
        programmer[i].idCategory = aux[i].idCategory;
        programmer[i].iProyectsOn = aux[i].iProyectsOn;
        programmer[i].flagState = aux[i].flagState;
    }
}


void initHardcodedProyects (eProyects proyect[])
{
    eProyects aux [] = {{1, "Arkansas", 3, 1},{2, "Danone", 2, 1},{3, "Sony", 2, 1},{4, "Curso Android", 2, 1},{5, "UTN", 2, 1}};
    //eProyects aux [] = {{0, "Arkansas", 0, 1},{1, "Danone", 0, 1},{2, "Sony", 0, 1},{3, "Curso Android", 0, 1},{4, "UTN", 0, 1}};
    for (int i = 0; i < 5; i++)
    {
        strcpy(proyect[i].proyectName, aux[i].proyectName);
        proyect[i].iEmployees = aux[i].iEmployees;
        proyect[i].flagState = aux[i].flagState;
    }
}


void initHardcodedProy_Prog (eProy_Prog proyect_programmer[])
{
    eProy_Prog aux [] = {{1, 123, 4, 1}, {2, 456, 3, 1}, {3, 789, 10, 1}, {4, 147, 2, 1}, {5, 258, 7, 1}, {1, 456, 2, 1}, {2, 369, 4, 1}, {3, 123, 8, 1}, {4, 123, 7, 1}, {5, 456, 5, 1}, {1, 789, 3, 1}};
    for (int i = 0; i < 11; i++)
    {
        proyect_programmer[i].idProyect = aux[i].idProyect;
        proyect_programmer[i].idProgrammer = aux[i].idProgrammer;
        proyect_programmer[i].workHours = aux[i].workHours;
        proyect_programmer[i].flagState = aux[i].flagState;

    }


}



/***************************************** LOAD FUNCTIONS *******************************************/
/****************************************************************************************************/



void initDatabase (eProgrammers programmer[],eProyects proyect[], eProy_Prog proyect_programmer[])
{
    initProgrammerFlag(programmer, PROG, 0);
    initProyectFlag(proyect, PROY, 0);

    initProyectId(proyect, PROY);

    initProgrammer_iProyects(programmer, PROG, 0);
    initProyect_iEmployees(proyect, PROY, 0);

    initProyectProgrammerFlag(proyect_programmer, PROY_PROG, 0);
}



/************************************* VALIDATION FUNCTIONS *****************************************/
/****************************************************************************************************/



int validateCategory (int variable)
{
    int output;

    if (variable < 1 || variable > 3)
    {
        output = 0;
    }
    else
    {
        output = 1;
    }

    return output;
}


int validateProyectName (eProyects proyect[], char input[])
{
    int output = 0;

    for (int i = 0; i < PROY; i++)
    {
        if ((stringCompare(input, proyect[i].proyectName) == 0) && (proyect[i].flagState == 1))
        {
            output = 1;
            return output;
        }
    }

    return output;
}



/************************************ ePROGRAMMERS FUNCTIONS*****************************************/
/****************************************************************************************************/



int searchProgrammerFlag(eProgrammers programmer[], int qty_elements, int value)
{

    for (int i = 0; i < qty_elements; i++)
    {
        if (programmer[i].flagState == value)
        {
            return i;
        }
    }

    return -1;
}


void initProgrammerFlag (eProgrammers programmer[], int qty_elements, int value)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        programmer[i].flagState = value;
    }
}


void initProgrammer_iProyects (eProgrammers programmer[], int qty_elements, int value)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        programmer[i].iProyectsOn = value;
    }
}


int searchProgrammerId_flagCheck (eProgrammers programmer[], int qty_elements, int value, int flagValue)
{

    if (flagValue != -1)
    {
        for (int i = 0; i < qty_elements; i++)
        {
            if ((programmer[i].idProgrammer == value) && (programmer[i].flagState == flagValue))
            {
                return i;
            }
        }
    }
    else
    {
        for (int i = 0; i < qty_elements; i++)
        {
            if (programmer[i].idProgrammer == value)
            {
                return i;
            }
        }
    }
    return -1;
}



/************************************* ePROYECTS FUNCTIONS ******************************************/
/****************************************************************************************************/



void initProyectId (eProyects proyect[], int qty_elements)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        proyect[i].idProyect = i+1;
    }
}


void initProyectFlag (eProyects proyect[], int qty_elements, int value)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        proyect[i].flagState = value;
    }
}


void initProyect_iEmployees (eProyects proyect[], int qty_elements, int value)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        proyect[i].iEmployees = value;
    }
}


int searchProyectFlag (eProyects proyect[], int qty_elements, int value)
{


    for (int i = 0; i < qty_elements; i++)
    {
        if (proyect[i].flagState == value)
        {
            return i;
        }
    }
    return -1;
}


int searchProyectName_flagCheck (eProyects proyect[], char input[], int flagValue)
{
    int index = -1;

    if (flagValue != -1)
    {
    for (int i = 0; i < PROY; i++)
    {
        if ((stringCompare(input, proyect[i].proyectName) == 0) && (proyect[i].flagState == 1))
        {
            index = i;
            return index;
        }
    }
    }
    else
    {
        for (int i = 0; i < PROG; i++)
        {
            if (stringCompare(input, proyect[i].proyectName) == 0)
            {
                index = i;
                return index;
            }
        }
    }
    return index;
}


int searchProyectIdByProyectName (eProyects proyect[], char auxProyectName[])
{
    int result = -1;

    for (int i = 0; i < PROY; i++)
    {
        if (stringCompare(proyect[i].proyectName, auxProyectName) == 0)
        {
            result = proyect[i].idProyect;
            return result;
        }
    }
    return result;
}


void proyectSimpleList (eProyects proyect[])
{
    printf("\n||Listado de proyectos||\n");
    printf("\n\n ID |       NOMBRE       |  CDAD EMPLEADOS  |\n");

    for (int i = 0; i < PROY; i++)
    {
        if (proyect[i].flagState == 1)
        {
            printf("%4d|%20s|       %4d       |\n",proyect[i].idProyect, proyect[i].proyectName, proyect[i].iEmployees);
        }
    }



}



/************************************ ePROY_PROG FUNCTIONS ******************************************/
/****************************************************************************************************/



void initProyectProgrammerFlag(eProy_Prog proyect_programmer[], int qty_elements, int value)
{
    for (int i = 0; i < qty_elements; i++ )
    {
        proyect_programmer[i].flagState = value;
    }
}


int searchProyectProgrammerFlag (eProy_Prog proyect_programmer[], int qty_elements, int value)
{


    for (int i = 0; i < qty_elements; i++)
    {
        if (proyect_programmer[i].flagState == value)
        {
            return i;
        }
    }
    return -1;
}


int searchProyectProgrammerIdProg_ProyName_flagCheck (eProy_Prog proyect_programmer[], eProyects proyect[], char auxProyectName[], int idProgrammer, int flagValue)
{
    int index = -1;
    int auxProyectId;

    auxProyectId = searchProyectIdByProyectName (proyect, auxProyectName);


    if (flagValue != -1)
    {
        for (int i = 0; i < PROY_PROG; i++)
        {
            if ((proyect_programmer[i].idProgrammer == idProgrammer) && (proyect_programmer[i].flagState == flagValue) && (proyect_programmer[i].idProyect == auxProyectId))
            {

                index = i;
                return index;

            }
        }

    }
    else
    {
        for (int i = 0; i < PROY_PROG; i++)
        {
            if ((proyect_programmer[i].idProgrammer == idProgrammer) && (proyect_programmer[i].idProyect == auxProyectId))
            {
                for (int j = 0; j < PROY; j++)
                {
                    if (stringCompare(proyect[j].proyectName, auxProyectName) == 0)
                    {
                        index = i;
                        return index;

                    }
                }
            }
        }
    }

    return index;
}



/************************************ PROCESSING FUNCTIONS ******************************************/
/****************************************************************************************************/



int programmerAdd (eProgrammers programmer[])
{
    int result = 0;

    int auxProgrammerIndex;
    int auxProgrammerCategory;
    int auxProgrammerIdInt;
    char auxProgrammerIdChar[10];
    char auxProgrammerName[20];
    char auxProgrammerSurname[20];

    auxProgrammerIndex = searchProgrammerFlag(programmer,PROG, 0);

            if (auxProgrammerIndex == -1)
            {
                printf("\nERROR: No hay mas lugares para ingresar programadores.\n");
                return result;
            }

            if (!(getStringOnlyNum("Ingrese el numero de id: ", auxProgrammerIdChar)))
            {
                printf("\nERROR: El id debe contener solo numeros.\n");
                return result;
            }

                auxProgrammerIdInt = atoi(auxProgrammerIdChar);

            if ((auxProgrammerIdInt < 0) || (auxProgrammerIdInt > 32000))
            {
                printf("\nERROR: El id debe ser un numero entre 0 y 32000.\n");
                return result;
            }

            if ((searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1)) != -1)
            {
                    printf("\nERROR: El numero de ID ingresado ya figura en el sistema.\n\n");
                    return result;
            }


            if (!(getStringOnlyChar("Ingrese el nombre: ", auxProgrammerName)))
            {
                printf("\nERROR: El nombre solo puede contener letras.\n");
                return result;
            }


            if (!(getStringOnlyChar("Ingrese el apellido: ", auxProgrammerSurname)))
            {
                printf("\nERROR: El apellido solo puede contener letras.\n");
                return result;
            }


            auxProgrammerCategory = getInt("Ingrese su categoria (1:Junior 2:SemiSenior 3:Senior): ");

            if (!(validateCategory(auxProgrammerCategory)))
            {
                printf("\nERROR: Categoria incorrecta.\n");
                return result;

            }
            /*PASO DE DATOS A VARIABLE ESTRUCTURA*/

            programmer[auxProgrammerIndex].idProgrammer = auxProgrammerIdInt;
            strcpy(programmer[auxProgrammerIndex].nameProg,auxProgrammerName);
            strcpy(programmer[auxProgrammerIndex].surnameProg,auxProgrammerSurname);
            programmer[auxProgrammerIndex].idCategory = auxProgrammerCategory;
            programmer[auxProgrammerIndex].flagState = 1;

            result = 1;

            return result;
}


int programmerModify (eProgrammers programmer[], eCategories category[])
{
    int result = 0;
    int auxProgrammerIndex;

    int auxProgrammerCategory;
    int auxProgrammerIdInt;
    char auxProgrammerIdChar[10];
    char auxProgrammerName[20];
    char auxProgrammerSurname[20];
    int auxNewProgrammerIdInt;
    char auxNewProgrammerIdChar [10];

    sortProgrammerById(programmer);
    programmerSimpleList(programmer, category);


    if (!getStringOnlyNum("Ingrese el numero de ID: ", auxProgrammerIdChar))
    {
        printf("\nERROR: El id debe contener solo numeros.\n");
        return result;
    }
    auxProgrammerIdInt = atoi(auxProgrammerIdChar);

    if ((searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1)) == -1)
    {
        printf("\nERROR: El numero de ID ingresado no figura en el sistema.\n\n");
        return result;
    }

    auxProgrammerIndex = searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1);
    if (auxProgrammerIndex != -1)
    {
        if (!getStringOnlyNum("\nNUEVOS DATOS:\nIngrese el numero de ID: ", auxNewProgrammerIdChar))
        {
            printf("\nERROR: El id debe contener solo numeros.\n");
            return result;
        }
        auxNewProgrammerIdInt = atoi(auxNewProgrammerIdChar);

        if (!(getStringOnlyChar("Ingrese el nombre: ", auxProgrammerName)))
        {
            printf("\nERROR: El nombre solo puede contener letras.\n");
            return result;
        }


        if (!(getStringOnlyChar("Ingrese el apellido: ", auxProgrammerSurname)))
        {
            printf("\nERROR: El apellido solo puede contener letras.\n");
            return result;
        }

        auxProgrammerCategory = getInt("Ingrese su categoria (1:Junior 2:SemiSenior 3:Senior): ");

        if (!(validateCategory(auxProgrammerCategory)))
        {
            printf("\nERROR: Categoria incorrecta.\n");
            return result;

        }

        programmer[auxProgrammerIndex].idProgrammer = auxNewProgrammerIdInt;
        strcpy(programmer[auxProgrammerIndex].nameProg,auxProgrammerName);
        strcpy(programmer[auxProgrammerIndex].surnameProg,auxProgrammerSurname);
        programmer[auxProgrammerIndex].idCategory = auxProgrammerCategory;

        result = 1;

        return result;

    }
    else
    {
        printf("\nERROR: El numero de ID ingresado no se encuentra en el sistema.\n");
        return result;
    }
}


int programmerDelete (eProgrammers programmer[], eProyects proyect[], eCategories category[], eProy_Prog proyect_programmer[])
{
    int result = 0;

    int auxProgrammerIndex;
    int auxProgrammerIdInt;
    char auxProgrammerIdChar[10];

    programmerSimpleList(programmer, category);

    if (!getStringOnlyNum("Ingrese el numero de ID: ", auxProgrammerIdChar))
    {
        printf("\nERROR: El id debe contener solo numeros.\n");
        return result;
    }
            auxProgrammerIdInt = atoi(auxProgrammerIdChar);

            auxProgrammerIndex = searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerIdInt, 1);
            if (auxProgrammerIndex == -1)
            {
                    printf("\nERROR: El numero de ID ingresado no figura en el sistema.\n\n");
                    return result;
            }
            else
           {
               for (int i = 0; i < PROY_PROG; i++)
               {
                   if (proyect_programmer[i].idProgrammer == auxProgrammerIdInt)
                   {
                       for (int j = 0; j < PROY; j++)
                       {
                           if (proyect_programmer[i].idProyect == proyect[j].idProyect)
                           {
                               proyect_programmer[i].flagState = 0;
                               proyect[j].iEmployees--;
                           }
                       }
                   }
               }
           }



           programmer[auxProgrammerIndex].flagState = 0;

           result = 1;

           return result;

}


void programmerSimpleList (eProgrammers programmer[], eCategories category[])
{
    printf("\n||Listado de programadores||\n");
    printf("\n\n ID |       NOMBRE       |      APELLIDO      | CATEGORIA |\n");


    for (int i = 0; i < PROG; i++)
    {
        if (programmer[i].flagState == 1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (programmer[i].idCategory == category[j].idCategory)
                {
                    printf("%4d|%20s|%20s|%11s|\n", programmer[i].idProgrammer, programmer[i].nameProg, programmer[i].surnameProg, category[j].description);
                }
            }
        }
    }
}


int proyect_programmerAdd (eProy_Prog proyect_programmer[], eProgrammers programmer[], eProyects proyect[], int auxProyectIndex, char auxProyectName[], int auxProgrammerId)
{
    int result = 0;

    char auxProyectHoursChar[5];
    int auxProgrammerIndex = searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerId,-1);
    int auxProyectProgrammerIndex;
    int auxProyectHoursInt;


    if (searchProyectProgrammerIdProg_ProyName_flagCheck(proyect_programmer, proyect, auxProyectName, auxProgrammerId, 1) != -1)
    {
        printf("\nERROR: El programador ya esta asignado a ese proyecto.\n");
        return result;

    }

    if (!(getStringOnlyNum("Ingrese la cantidad de horas a trabajar: ",auxProyectHoursChar)))
    {
        printf("\nERROR: Solo se pueden ingresar numeros.\n");
        return result;
    }

    auxProyectHoursInt = atoi(auxProyectHoursChar);

    if (auxProyectHoursInt < 1)
    {
        printf("\nERROR: La cantidad de horas asignadas no puede ser menor a 1.\n");
        return result;
    }

    auxProyectProgrammerIndex = searchProyectProgrammerFlag(proyect_programmer, PROY_PROG, 0);

    programmer[auxProgrammerIndex].iProyectsOn++;

    strcpy(proyect[auxProyectIndex].proyectName, auxProyectName);
    proyect[auxProyectIndex].flagState = 1;
    proyect[auxProyectIndex].iEmployees++;

    proyect_programmer[auxProyectProgrammerIndex].flagState = 1;
    proyect_programmer[auxProyectProgrammerIndex].idProgrammer = auxProgrammerId;
    proyect_programmer[auxProyectProgrammerIndex].idProyect = proyect[auxProyectIndex].idProyect;
    proyect_programmer[auxProyectProgrammerIndex].workHours = auxProyectHoursInt;

    result = 1;

    return result;

}


void programmerFullList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[])
{
    int auxEmployeeProyects;
    float employeeCategorySalary;
    float employeeSalary;


    printf("\n||Listado de programadores||\n");
    printf("\n\n ID |       NOMBRE       |      APELLIDO      | CATEGORIA |      PROYECTOS     |  SUELDO  \n");
    printf("----|--------------------|--------------------|-----------|--------------------|----------\n");

    sortProgrammerById(programmer);



    for (int i = 0; i < PROG; i++)
    {
        if ((programmer[i].flagState == 1))
        {
            auxEmployeeProyects = 0;

            for (int j = 0; j < 3; j++)
            {

                if (programmer[i].idCategory == category[j].idCategory)
                {
                    printf("%4d|%20s|%20s|%11s|", programmer[i].idProgrammer, programmer[i].nameProg, programmer[i].surnameProg, category[j].description);
                    employeeCategorySalary = category[j].salaryPerHour;
                }
            }


            if (programmer[i].iProyectsOn == 0)
            {
                printf("                    |          \n");
                printf("----|--------------------|--------------------|-----------|--------------------|----------\n");
                continue;

            }
            else
            {


                for (int k = 0; k < PROY_PROG; k++)
                {


                    if (programmer[i].idProgrammer == proyect_programmer[k].idProgrammer)
                    {
                        for (int l = 0; l < PROY; l++)
                        {
                            if (auxEmployeeProyects == programmer[i].iProyectsOn)
                            {
                                printf("----|--------------------|--------------------|-----------|--------------------|----------\n");
                                break;
                            }

                            if (proyect_programmer[k].idProyect == proyect[l].idProyect)
                            {
                                employeeSalary = (float) employeeCategorySalary * proyect_programmer[k].workHours;

                                if (auxEmployeeProyects == 0)
                                {
                                    printf("%20s|  %4.2f$ \n",proyect[l].proyectName, employeeSalary);
                                    auxEmployeeProyects++;
                                }
                                else
                                {
                                    printf("    |                    |                    |           |%20s|  %4.2f$ \n",proyect[l].proyectName, employeeSalary);
                                    auxEmployeeProyects++;
                                }


                            }

                        }
                    }

                }
            }
        }
    }
}


void sortProgrammerById (eProgrammers programmer[])
{
    int auxIdProgrammer;
    char auxName[20];
    char auxSurname[20];
    int auxIdCategory;
    int auxIProyectsOn;
    int auxFlagState;

    for (int i = 0; i < PROG -1; i++)
    {
        if (programmer[i].flagState != 1)
        {
            continue;
        }
        else
        {
            for (int j = i+1; j < PROG; j++)
            {
                if (programmer[j].flagState != 1)
                {
                    continue;
                }
                else
                {



                    if (programmer[i].idProgrammer > programmer[j].idProgrammer)
                    {
                        auxIdProgrammer = programmer[i].idProgrammer;
                        programmer[i].idProgrammer = programmer[j].idProgrammer;
                        programmer[j].idProgrammer = auxIdProgrammer;

                        strcpy(auxName, programmer[i].nameProg);
                        strcpy(programmer[i].nameProg, programmer[j].nameProg);
                        strcpy(programmer[j].nameProg, auxName);

                        strcpy(auxSurname, programmer[i].surnameProg);
                        strcpy(programmer[i].surnameProg, programmer[j].surnameProg);
                        strcpy(programmer[j].surnameProg, auxSurname);

                        auxIdCategory = programmer[i].idCategory;
                        programmer[i].idCategory = programmer[j].idCategory;
                        programmer[j].idCategory = auxIdCategory;

                        auxIProyectsOn = programmer[i].iProyectsOn;
                        programmer[i].iProyectsOn = programmer[j].iProyectsOn;
                        programmer[j].iProyectsOn = auxIProyectsOn;

                        auxFlagState = programmer[i].flagState;
                        programmer[i].flagState = programmer[j].flagState;
                        programmer[j].flagState = auxFlagState;

                    }


                }
            }
        }

    }

}


void proyectFullList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[])
{



    printf("\n||Listado de proyectos||\n\n");
    printf("                         |       CANTIDAD DE EMPLEADOS     |\n");
    printf(" ID |       NOMBRE       |  JUNIOR  | SEMI-SENIOR | SENIOR |\n");

    for (int i = 0; i < PROY; i++)
    {
        int iEmployeesPerCategory[] = {0, 0, 0};

        if (proyect[i].flagState == 1)
        {
            printf("%4d|%20s|",proyect[i].idProyect, proyect[i].proyectName);

            for (int j = 0; j < PROY_PROG; j++)
            {
                if ((proyect[i].idProyect == proyect_programmer[j].idProyect) && (proyect_programmer[j].flagState == 1))
                {
                    for (int k = 0; k < PROG; k++)
                    {
                        if (proyect_programmer[j].idProgrammer == programmer[k].idProgrammer)
                        {
                            for (int l = 0; l < 3; l++)
                            {

                            if (programmer[k].idCategory == category[l].idCategory)
                            {
                                iEmployeesPerCategory[l]++;
                            }



                            }

                        }

                    }


                }



            }
            printf("      %4d|         %4d|    %4d|\n", iEmployeesPerCategory[0], iEmployeesPerCategory[1], iEmployeesPerCategory[2]);
        }
    }
}


void proyectCostList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[])
{
    float auxJuniorCost; //50
    float auxSemiSeniorCost; //75
    float auxSeniorCost; //100
    float auxProyectCost;


    printf("\n||Listado de proyectos||\n\n");
    printf(" ID |       NOMBRE       | COSTO TOTAL \n");

    for (int i = 0; i < PROY; i++)
    {
        int iHoursPerCategory[] = {0, 0, 0};

        auxJuniorCost = 0;
        auxSemiSeniorCost = 0;
        auxSeniorCost = 0;
        auxProyectCost = 0;


        if (proyect[i].flagState == 1)
        {
            printf("%4d|%20s|",proyect[i].idProyect, proyect[i].proyectName);

            for (int j = 0; j < PROY_PROG; j++)
            {
                if ((proyect[i].idProyect == proyect_programmer[j].idProyect) && (proyect_programmer[j].flagState == 1))
                {


                    for (int k = 0; k < PROG; k++)
                    {
                        if (proyect_programmer[j].idProgrammer == programmer[k].idProgrammer)
                        {
                            for (int l = 0; l < 3; l++)
                            {

                            if (programmer[k].idCategory == category[l].idCategory)
                            {
                                iHoursPerCategory[l] += proyect_programmer[j].workHours;
                            }



                            }

                        }

                    }


                }



            }
            auxJuniorCost = (float) iHoursPerCategory[0] * category[0].salaryPerHour;
            auxSemiSeniorCost = (float) iHoursPerCategory[1] * category[1].salaryPerHour;
            auxSeniorCost = (float) iHoursPerCategory[2] * category[2].salaryPerHour;
            auxProyectCost = auxJuniorCost + auxSemiSeniorCost + auxSeniorCost;

            printf("   %4.2f    \n", auxProyectCost);
        }
    }
}



int proyectOfProgramerList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], int auxProgrammerId)
{
    int result = 0;
    int auxProgrammerIndex;

    auxProgrammerIndex = searchProgrammerId_flagCheck(programmer, PROG, auxProgrammerId, 1);

    if (programmer[auxProgrammerIndex].iProyectsOn == 0)
    {
        return result;
    }

    printf("\nProyectos en los que trabaja el programador %s %s:\n\n",programmer[auxProgrammerIndex].nameProg, programmer[auxProgrammerIndex].surnameProg);



    printf(" ID |       NOMBRE       |\n");

    for (int i = 0; i < PROY_PROG; i++)
    {
        if (proyect_programmer[i].idProgrammer == auxProgrammerId)
        {
            for (int j = 0; j < PROY; j++)
            {
                if (proyect_programmer[i].idProyect == proyect[j].idProyect)
                {
                    printf("%4d|%20s|\n",proyect[j].idProyect ,proyect[j].proyectName);
                    result = 1;
                }
            }
        }
    }
    return result;
}


void demandingProyect (eProyects proyect[])
{
    int auxMaxEmployees;



    for (int i = 0; i < PROY; i++)
    {
        if (i == 0)
        {
            auxMaxEmployees = proyect[i].iEmployees;
        }
        else
        {
            if (proyect[i].iEmployees > auxMaxEmployees)
            {
                auxMaxEmployees = proyect[i].iEmployees;
            }
        }
    }


    printf("\nEl/los proyecto/s mas demandante/s (con %d empleados):\n", auxMaxEmployees);
    for (int i = 0; i < PROY; i++)
    {
        if (proyect[i].iEmployees == auxMaxEmployees)
        {
            printf("- %s\n", proyect[i].proyectName);
        }
    }
}



/********************************** COMPLEMENTARY FUNCTIONS *****************************************/
/****************************************************************************************************/



int isStrChar (char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int isStrNumeric (char str[])
{

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int getInt (char message[])
{
    int output;
    printf(message);
    scanf("%d",&output);
    return output;
}


void getString (char message[], char output[])
{
    printf(message);
    fflush(stdin);
    gets(output);
}


int getStringOnlyChar (char message[], char output[])
{
    char aux [256];
    getString(message,aux);
    if (isStrChar(aux))
    {
        strcpy(output,aux);
        return 1;
    }

    return 0;


}


int getStringOnlyNum (char message[], char output[])
{
    char aux[256];
    getString(message,aux);
    if (isStrNumeric(aux))
    {
        strcpy(output,aux);
        return 1;
    }
    return 0;
}


int stringCompare (char str1[], char str2[])
{
    int output = 0;
    char aux1;
    char aux2;

    for (int i = 0; i < 1; i++)
    {

            if (str1[i] == '\0' && str2[i] != '\0')
            {
                output = -1;
                return output;
            }
            else if (str1[i] != '\0' && str2[i] == '\0')
            {
                output = 1;
                return output;
            }
            else if (str1[i] == '\0' && str2[i] == '\0')
            {
                output = 0;
                return output;
            }

    }


    for (int i = 0; str1[i] != '\0'; i++)
    {



        aux1 = tolower(str1[i]);
        aux2 = tolower(str2[i]);

        if (aux1 == aux2)
        {
            continue;
        }
        else if (aux1>aux2)
        {
            output = 1;
            break;
        }
        else
        {
            output = -1;
            break;
        }

    }

    return output;

}

