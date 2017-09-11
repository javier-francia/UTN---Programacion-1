#include "funciones.h"




eMovie* database_load (FILE* database, eMovie* ptrMovie, int *iLoadedStructs, int *iSizeStructsMemory)
{
    eMovie* output = NULL;
    eMovie *ptrAux;
    int loaded_data;

    int auxLoadedStructs = *iLoadedStructs;
    int auxSizeMemory = *iSizeStructsMemory;
    int auxReading = 0;

    //  ASIGNA MEMORIA A *ptrMovie
    if ((ptrMovie = (eMovie*)malloc(sizeof(eMovie))) == NULL)
    {
        printf("\nERROR: No hay lugar en la memoria.\n\n");
        system("pause");
        return output;
    }
    auxSizeMemory++;

    // INTENTA ABRIR EL ARCHIVO. SI NO EXISTE, CAMBIA A MODO "wb" Y CREA UNO
    if (((database = fopen ("database.bin", "rb")) == NULL))
    {
        if ((database = fopen ("database.bin", "wb")) == NULL)
        {
            printf("\nERROR. No se puede abrir el archivo.\n");
            system("pause");
            return output;
        }
        else
        {
            if (fclose(database) == -1)
            {
                printf("\nERROR: No se pudo cerrar el archivo.\n");
                system("pause");
                return output;
            }
            output = ptrMovie;
            return output;
        }
    }

    while (1)
    {
        loaded_data = fread((ptrMovie + auxReading), sizeof(eMovie), 1, database);
        auxReading++;
        if (feof(database))
        {
            break;
        }

        if ((loaded_data) != 1)
        {
            printf("\nERROR: El archivo no se pudo leer correctamente o no contiene ningun dato.\n");
            system("pause");
            return output;
        }

        auxLoadedStructs++;
        auxSizeMemory++;

        if ((ptrAux = (eMovie*)realloc(ptrMovie, sizeof(eMovie) * auxSizeMemory)) != NULL)
        {
            ptrMovie = ptrAux;
        }
        else
        {
            printf("\nERROR: No hay lugar en la memoria.\n");
            system("pause");
            return output;
        }
    }



    if (fclose(database) == -1)
    {
        printf("\nERROR: No se pudo cerrar el archivo.\n");
        system("pause");
        return output;
    }


    *iLoadedStructs = auxLoadedStructs;
    *iSizeStructsMemory = auxSizeMemory;
    output = ptrMovie;
    return output;
}


int database_list (eMovie *ptrMovie, int iLoadedStructs)
{
    int result = 0;
    int id = 1;


    if (iLoadedStructs == 0)
    {
        printf("\nNo hay peliculas en el sistema.\n\n");
        return result;
    }

    printf(" ID |  TITULO");

    for (int i = 0; i < iLoadedStructs; i++)
    {


        printf("\n%4d| %s", id, ptrMovie->title);

        ptrMovie++;
        id++;
    }
    result = 1;

    return result;
}


int database_write (FILE* database, eMovie* ptrMovie, int *iLoadedStructs)
{
    int result = 0;
    int iWrittenStructs;
    int auxLoadedStructs = *iLoadedStructs;

    if ((database = fopen ("database.bin", "wb")) == NULL)
    {
        printf("\nERROR. No se puede abrir el archivo.\n");
        system("pause");
        return result;
    }


    iWrittenStructs = fwrite(ptrMovie, sizeof(eMovie), auxLoadedStructs, database);

    if (iWrittenStructs != auxLoadedStructs)
    {
        printf("\nERROR: El archivo no se pudo guardar correctamente.\n\n");
        system("pause");
        return result;
    }



    if (fclose(database) == -1)
    {
        printf("\nERROR: No se pudo cerrar el archivo.\n");
        system("pause");
        result = 0;
        return result;
    }

    result = 1;

    return result;
}


eMovie* getData_eMovie()
{
    eMovie* output = NULL;
    int flagError = 0;

    eMovie* auxMovie = NULL;


    if ((auxMovie = (eMovie*)malloc(sizeof(eMovie))) == NULL)
    {
        printf("\nERROR: No hay lugar en la memoria.\n");
        flagError++;
        goto label_end;
    }


    char auxLength[20];
    char auxScore[20];


    printf("Ingrese los datos de la pelicula\n\n");

    /*          TITULO          */
    printf("Titulo: ");
    fflush(stdin);
    if (fgets(auxMovie->title,201,stdin) == NULL)
    {
        printf("\nERROR: El titulo ingresado supera el maximo permitido de caracteres.\n");
        flagError++;
        goto label_end;
    }




    for (int i = 0; i < 201; i++)
    {
        if (auxMovie->title[i] == '\n')
        {
            auxMovie->title[i] = '\0';
            break;
        }
    }

    if (strlen(auxMovie->title) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }


    /*          GENERO          */
    printf("Genero: ");
    fflush(stdin);
    if (fgets(auxMovie->genre,31,stdin) == NULL)
    {
        printf("\nERROR: El genero ingresado supera el maximo permitido de caracteres.\n");
        flagError++;
        goto label_end;
    }
    for (int i = 0; i < 31; i++)
    {
        if (auxMovie->genre[i] == '\n')
        {
            auxMovie->genre[i] = '\0';
            break;
        }
    }

    if (strlen(auxMovie->genre) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }


    /*          DURACION            */
    if ((getStringOnlyNum("Duracion (minutos): ", auxLength)) == 0)
    {
        printf("\nERROR: La duracion de la pelicula contiene solo numeros.\n");
        flagError++;
        goto label_end;
    }
    if (strlen(auxLength) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }
    auxMovie->length = atoi(auxLength);

    if (auxMovie->length < 0)
    {
        printf("\nERROR: La duracion de una pelicula deberia ser mayor a 0.\n");
        flagError++;
        goto label_end;
    }
    else if (auxMovie->length > 318)
    {
        printf("\nERROR: La pelicula mas larga de la historia dura 318 minutos, no te creo que esta pelicula dure mas.\n");
        flagError++;
        goto label_end;
    }


    /*          DESCRIPCION         */
    printf("Descripcion: ");
    fflush(stdin);
    if (fgets(auxMovie->description,301,stdin) == NULL)
    {
        printf("\nERROR: La descripcion ingresada supera el maximo permitido de caracteres.\n");
        flagError++;
        goto label_end;
    }
    for (int i = 0; i < 301; i++)
    {
        if (auxMovie->description[i] == '\n')
        {
            auxMovie->description[i] = '\0';
            break;
        }
    }

    if (strlen(auxMovie->description) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }


    /*          PUNTAJE         */
    if ((getStringOnlyNum("Puntaje (0 a 100): ", auxScore)) == 0)
    {
        printf("\nERROR: El puntaje de la pelicula contiene solo numeros.\n");
        flagError++;
        goto label_end;
    }
    if (strlen(auxScore) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }
    auxMovie->score = atoi (auxScore);

    if (((auxMovie->score) < 0 ) || ((auxMovie->score) > 100))
    {
        printf("\nERROR: El puntaje de la pelicula debe ser un numero entre 0 y 100.\n");
        flagError++;
        goto label_end;
    }

    /*          LINK A IMAGEN           */
    printf("Link a imagen: ");
    fflush(stdin);
    if (fgets(auxMovie->imageLink,251,stdin) == NULL)
    {
        printf("\nERROR: El link a imagen ingresado supera el maximo permitido de caracteres.\n");
        flagError++;
        goto label_end;
    }
    for (int i = 0; i < 251; i++)
    {
        if (auxMovie->imageLink[i] == '\n')
        {
            auxMovie->imageLink[i] = '\0';
            break;
        }
    }

    if (strlen(auxMovie->imageLink) == 0)
    {
        printf("\nERROR: No se permiten campos vacios.\n");
        flagError++;
        goto label_end;
    }


    output = auxMovie;



label_end:
    if (flagError == 1)
    {
        output = NULL;
    }



    return output;
}


int movieAdd (eMovie* ptrMovie, int *iLoadedStructs, int *iSizeStructsMemory)
{
    int result = 0;

    eMovie *ptrNew = NULL;//movie auxiliar para encontrar posicion en memoria y dsp asignar ahi el valor

    int auxLoadedStructs = *iLoadedStructs;
    int auxSizeMemory = *iSizeStructsMemory;

    for (int i = 0; i < auxSizeMemory; i++)
    {
        //se ajusta donde tiene que escribir el nuevo dato
        if (i < auxLoadedStructs)
        {
            ptrMovie++;
            continue;
        }


        ptrNew = getData_eMovie();

        if (ptrNew == NULL)
        {
            return result;
        }

        strcpy(ptrMovie->title, ptrNew->title);
        strcpy(ptrMovie->genre, ptrNew->genre);
        ptrMovie->length = ptrNew->length;
        strcpy(ptrMovie->description, ptrNew->description);
        ptrMovie->score = ptrNew->score;
        strcpy(ptrMovie->imageLink, ptrNew->imageLink);

    }

    auxLoadedStructs++;
    auxSizeMemory++;


    *iLoadedStructs = auxLoadedStructs;
    *iSizeStructsMemory = auxSizeMemory;

    result = 1;

    return result;
}


int movieModify (eMovie* ptrMovie, int *iLoadedStructs)
{
    int result = 0;

    char auxMovieIdChar[10];
    int auxMovieIdInt;

    eMovie *ptrNew = NULL;

    int auxLoadedStructs = *iLoadedStructs;


    if (auxLoadedStructs == 0)
    {
        printf("\nNo hay peliculas cargadas en el sistema.\n\n");
        return result;
    }

    database_list(ptrMovie, auxLoadedStructs);


    if ((getStringOnlyNum("\nIngrese el ID: ",auxMovieIdChar)) == -1)
    {
        printf("\nERROR: El ID puede contener solo numeros.\n\n");
        return result;
    }
    auxMovieIdInt = atoi (auxMovieIdChar);
    if (auxMovieIdInt > auxLoadedStructs || auxMovieIdInt == 0)
    {
        printf("\nERROR: El numero de id no existe en el sistema.\n\n");
        return result;
    }

    system("cls");

    for (int i = 1; i < (auxLoadedStructs + 1); i++)
    {
        //se ajusta donde tiene que escribir el nuevo dato
        if (i < auxMovieIdInt)
        {
            ptrMovie++;
            continue;
        }

        printf("Modificando la pelicula '%s'\n\n", ptrMovie->title);

        ptrNew = getData_eMovie();

        if (ptrNew == NULL)
        {
            return result;
        }

        strcpy(ptrMovie->title, ptrNew->title);
        strcpy(ptrMovie->genre, ptrNew->genre);
        ptrMovie->length = ptrNew->length;
        strcpy(ptrMovie->description, ptrNew->description);
        ptrMovie->score = ptrNew->score;
        strcpy(ptrMovie->imageLink, ptrNew->imageLink);
        break;

    }


    result = 1;

    return result;
}


int movieDelete (eMovie* ptrMovie, int *iLoadedStructs, int *iSizeStructsMemory)
{
    int result = 0;

    char auxMovieIdChar[10];
    int auxMovieIdInt;

    eMovie *ptrNew = NULL;

    int auxLoadedStructs = *iLoadedStructs;
    int auxSizeMemory = *iSizeStructsMemory;


    if (auxLoadedStructs == 0)
    {
        printf("\nNo hay peliculas cargadas en el sistema.\n\n");
        return result;
    }

    database_list(ptrMovie, auxLoadedStructs);


    if ((getStringOnlyNum("\nIngrese el ID: ",auxMovieIdChar)) == -1)
    {
        printf("\nERROR: El ID puede contener solo numeros.\n\n");
        return result;
    }
    auxMovieIdInt = atoi (auxMovieIdChar);
    if (auxMovieIdInt > auxLoadedStructs || auxMovieIdInt == 0)
    {
        printf("\nERROR: El numero de id no existe en el sistema.\n\n");
        return result;
    }

    system("cls");

    //       elimino 1          2           1
    for (int i = 1; i < (auxLoadedStructs + 1); i++)
    {
        //se ajusta donde tiene que escribir el nuevo dato
        if (i < auxMovieIdInt)
        {
            ptrMovie++;
            continue;
        }

        printf("Se va a eliminar la pelicula '%s'\n\n", ptrMovie->title);

        ptrNew = ptrMovie + (auxLoadedStructs-i);

        if (ptrNew == NULL)
        {
            return result;
        }

        strcpy(ptrMovie->title, ptrNew->title);
        strcpy(ptrMovie->genre, ptrNew->genre);
        ptrMovie->length = ptrNew->length;
        strcpy(ptrMovie->description, ptrNew->description);
        ptrMovie->score = ptrNew->score;
        strcpy(ptrMovie->imageLink, ptrNew->imageLink);
        break;

    }
    auxLoadedStructs--;
    auxSizeMemory--;

    *iLoadedStructs = auxLoadedStructs;
    *iSizeStructsMemory = auxSizeMemory;


    result = 1;

    return result;
}


int printIndex(eMovie* ptrMovie, int *iLoadedStructs)
{
    int result = 0;

    FILE* html;

    int auxLoadedStructs = *iLoadedStructs;


    if ((html = fopen("index.html", "w")) == NULL)
    {
        return result;
    }

    //      PRIMERA PARTE DEL DOCUMENTO HTML

    fprintf(html, "<!DOCTYPE html>\n");
    fprintf(html, "<html lang='en'>\n");
    fprintf(html, "<head>\n");
    fprintf(html, "<meta charset='utf-8'>\n");
    fprintf(html, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
    fprintf(html, "<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
    fprintf(html, "<title>Lista peliculas</title>\n");
    fprintf(html, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
    fprintf(html, "<link href='css/custom.css' rel='stylesheet'>\n");
    fprintf(html, "</head>\n");
    fprintf(html, "<body>\n");
    fprintf(html, "<div class='container'>\n");
    fprintf(html, "<div class='row'>\n");


    //      ESCRIBIENDO LOS ARTICLES DE CADA PELICULA
    for (int i = 0; i < auxLoadedStructs; i++)
    {
        fprintf(html, "<article class='col-md-4 article-intro'>\n");
        fprintf(html, "<a href='#'>\n");
        fprintf(html, "<img class='img-responsive img-rounded' src='");
        fprintf(html, "%s", ptrMovie->imageLink);
        fprintf(html, "'alt='Cover of %s'>\n", ptrMovie->title);
        fprintf(html, "</a>\n");
        fprintf(html, "<h3>\n");
        fprintf(html, "<a href='#'>");
        fprintf(html, "%s", ptrMovie->title);
        fprintf(html, "</a>\n");
        fprintf(html, "</h3>\n");
        fprintf(html, "<ul>\n");
        fprintf(html, "<li>Genre: ");
        fprintf(html, "%s", ptrMovie->genre);
        fprintf(html, "</li>\n");
        fprintf(html, "<li>Rate: ");
        fprintf(html, "%d", ptrMovie->score);
        fprintf(html, "/100</li>\n");
        fprintf(html, "<li>Length: ");
        fprintf(html, "%d", ptrMovie->length);
        fprintf(html, " min</li>\n");
        fprintf(html, "</ul>\n");
        fprintf(html, "<p>");
        fprintf(html, "%s", ptrMovie->description);
        fprintf(html, "</p>\n");
        fprintf(html, "</article>\n");

        ptrMovie++;

    }


    //          ULTIMA PARTE

    fprintf(html, "</div>\n");
    fprintf(html, "</div>\n");
    fprintf(html, "<script src='js/jquery-1.11.3.min.js'></script>\n");
    fprintf(html, "<script src='js/bootstrap.min.js'></script>\n");
    fprintf(html, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
    fprintf(html, "<script src='js/holder.min.js'></script>\n");
    fprintf(html, "</body>\n");
    fprintf(html, "</html>");


    if (fclose(html) == -1)
    {
        printf("\nERROR: No se pudo cerrar el archivo.\n");
        return result;
    }
    result = 1;

    return result;

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


void getInt (char message[], int output)
{
    printf(message);
    scanf("%d",&output);
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
