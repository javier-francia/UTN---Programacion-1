#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED




typedef struct
{
    int idProgrammer;
    char nameProg [20];
    char surnameProg [20];
    int idCategory;
    int iProyectsOn;
    int flagState;
}eProgrammers;

typedef struct
{
    int idProyect;
    char proyectName [20];
    int iEmployees;
    int flagState;
}eProyects;

typedef struct
{
    int idCategory;
    char description [20];
    float salaryPerHour;
}eCategories;

typedef struct
{
    int idProyect;
    int idProgrammer;
    int workHours;
    int flagState;
}eProy_Prog;





/***************************************** HARDCODED ************************************************/
/****************************************************************************************************/



/** \brief Inicializa en el programa datos precargados para un vector estructura eProgrammers
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 *
 *
 *
 */
void initHardcodedProgrammers (eProgrammers programmer[]);


/** \brief Inicializa en el programa datos precargados para un vector estructura eProyects
 *
 * \param proyect                       Vector estructura eProyects elegido
 *
 *
 *
 */
void initHardcodedProyects (eProyects proyect[]);


/** \brief Inicializa en el programa datos precargados para un vector estructura eProg_Proy
 *
 * \param proyect_programmer            Vector estructura eProg_Proy elegido
 *
 *
 *
 */
void initHardcodedProy_Prog (eProy_Prog proyect_programmer[]);



/***************************************** LOAD FUNCTIONS *******************************************/
/****************************************************************************************************/



/** \brief Inicializa los campos necesarios para que el programa empiece a funcionar correctamente
 *
 * \param programmer                   Vector eProgrammers elegido
 * \param proyect                      Vector eProyects elegido
 * \param proyect_programmer           Vector eProy_Prog elegido
 *
 */
void initDatabase (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[]);



/************************************* VALIDATION FUNCTIONS *****************************************/
/****************************************************************************************************/



/** \brief Valida la variable elegida para ver si es un numero de categoria
 *
 * \param variable                      Variable Int elegida
 *
 * \return  Devuelve True/False
 *
 */
int validateCategory (int);


/** \brief Valida si el vector char elegido es igual al campo proyectName de un vector estructura eProyect
 *
 * \param proyect                       Vector estructura eProyects elegido
 * \param input                         Vector char elegido
 * \return Devuelve True/False
 *
 */
int validateProyectName (eProyects proyect[], char input[]);



/************************************ ePROGRAMMERS FUNCTIONS*****************************************/
/****************************************************************************************************/



/** \brief Busca en el campo flagState de un vector estructura eProgrammers el valor indicado
 *
 * \param eProgrammers programmer       Vector estructura eProgrammers elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor a buscar en el campo flagState
 * \return      Devuelve -1 si no encuentra el valor o un numero correspondiente al indice si lo encuentra
 *
 */
int searchProgrammerFlag (eProgrammers programmer[], int , int);


/** \brief Inicializa el campo flagState de un vector estructura eProgrammers con un valor indicado
 *
 * \param eProgrammers programmer       Vector estructura elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor indicado para inicializar en el campo flagState
 *
 */
void initProgrammerFlag (eProgrammers programmer[], int , int);


/** \brief Inicializa el campo flagState de un vector estructura eProgrammers con un valor indicado
 *
 * \param eProgrammers programmer       Vector estructura elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor indicado para inicializar el campo flagState
 *
 */
void initProgrammer_iProyects (eProgrammers programmer[], int , int);


/** \brief Devuelve el indice en donde se ubica un idProgramador de eProgrammers. Puede chequear el estado del campo flagState
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Variable que contiene el idProgramador
 * \param flagValue                   | -1: No analizar flagState | 0: Buscar flagState con valor 0 | 1: Buscar flagState con valor 1 |
 *
 * \return Devuelve -1 si no lo encuentra y de 0 en adelante para el numero de indice donde se encontro
 *
 */
int searchProgrammerId_flagCheck (eProgrammers programmer[], int , int , int );



/************************************* ePROYECTS FUNCTIONS ******************************************/
/****************************************************************************************************/



/** \brief Inicializa el campo idProyect de un vector estructura eProyects con el valor del indice + 1
 *
 * \param eProyects proyect             Vector estructura eProyects elegido
 * \param qty_elements                  Tamaño del vector estructura
 *
 */
void initProyectId (eProyects proyect[], int);


/** \brief Inicializa el campo flagState de un vector estructura eProyects con el valor indicado
 *
 * \param eProyects proyect             Vector estructura eProyects elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor indicado para inicializar el campo flagState
 *
 */
void initProyectFlag (eProyects proyect[], int, int);


/** \brief Inicializa el campo iEmployees de un vector estructura eProyects con el valor indicado
 *
 * \param eProyect proyect              Vector estructura eProyects elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor indicado para inicializar el campo iEmployees
 *
 */
void initProyect_iEmployees (eProyects proyect[], int , int );


/** \brief Busca en el campo flagState de un vector estructura eProyects el valor indicado
 *
 * \param eProyects proyect             Vector estructura eProyects elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor a buscar en el campo flagState
 * \return      Devuelve -1 si no encuentra el valor o un numero correspondiente al indice si lo encuentra
 */
int searchProyectFlag (eProyects proyect[], int , int );


/** \brief Compara un vector char con el campo proyectName de un vector estructura Eproyects. Puede chequear el estado del campo flagState
 *
 * \param proyect                       Vector estructura eProyects elegido
 * \param input                         Vector char elegido
 * \param flagValue                     | -1: No analizar flagState | 0: Buscar flagState con valor 0 | 1: Buscar flagState con valor 1 |
 *
 * \return      Devuelve -1 si no encuentra el valor o un numero correspondiente al indice si lo encuentra
 *
 */
int searchProyectName_flagCheck (eProyects proyect[] , char input[] , int);


/** \brief Compara el vector char elegido con el campo proyectName de un vector estructura eProyects
 *
 * \param proyect                       Vector estructura eProyects elegido
 * \param auxProyectName                Vector char elegido
 *
 * \return
 *
 */
int searchProyectIdByProyectName (eProyects proyect[], char auxProyectName[]);


/** \brief Crea una lista con los elementos de un vector estructura eProyects. Muestra id, nombre de proyecto y cdad de empleados
 *
 * \param proyect                       Vector estructura eProyects elegido
 *
 *
 */
void proyectSimpleList (eProyects proyect[]);



/************************************ ePROY_PROG FUNCTIONS ******************************************/
/****************************************************************************************************/



/** \brief Inicializa el campo flagState de un vector estructura eProy_Prog con el valor indicado
 *
 * \param eProyects proyect             Vector estructura elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor indicado para inicializar en el campo flagState
 *
 */
void initProyectProgrammerFlag(eProy_Prog proyect_programmer[], int, int);


/** \brief Busca en el campo flagState de un vector estructura eProy_Prog el valor indicado
 *
 * \param eProyects proyect             Vector estructura eProyProg elegido
 * \param qty_elements                  Tamaño del vector estructura
 * \param value                         Valor a buscar en el campo flagState
 * \return      Devuelve -1 si no encuentra el valor o un numero correspondiente al indice si lo encuentra
 */
int searchProyectProgrammerFlag (eProy_Prog proyect_programmer[], int , int );


/** \brief Busca elementos en un vector estructura eProy_Prog que coincidan con los ingresados. Usa los campos: idProgrammer, proyectName y flagState
 *
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param proyect                       Vector estructura eProyect elegido
 * \param auxProyectName                Vector char que contiene el nombre del proyecto
 * \param idProgrammer                  Variable que contiene el numero de id del programador
 * \param flagValue                     | -1: No analizar flagState | 0: Buscar flagState con valor 0 | 1: Buscar flagState con valor 1 |
 * \return      Devuelve -1 si no encuentra el valor o un numero correspondiente al indice si lo encuentra
 *
 */
int searchProyectProgrammerIdProg_ProyName_flagCheck (eProy_Prog proyect_programmer[], eProyects proyect[], char auxProyectName[], int, int);



/************************************ PROCESSING FUNCTIONS ******************************************/
/****************************************************************************************************/



/** \brief Añade un elemento a un vector estructura eProgrammers
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \return          True/False indicando si el programa logro su objetivo
 *
 */
int programmerAdd (eProgrammers programmer[]);


/** \brief Modifica un elemento en un vector estructura eProgrammers
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \return          True/False indicando si el programa logro su objetivo
 *
 */
int programmerModify (eProgrammers programmer[], eCategories category[]);


/** \brief Elimina un elemento de un eProgrammers y sus posibles relaciones con un eProyects y un eProy_Prog
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param proyect                       Vector estructura eProgroyects elegido
 * \param category                      Vector estructura eCategories elegido
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param
 * \return          True/False indicando si el programa logro su objetivo
 *
 */
int programmerDelete (eProgrammers programmer[], eProyects proyect[], eCategories category[], eProy_Prog proyect_programmer[]);


/** \brief Lista elementos de un eProgrammers indicando id, nombre, apellido y categoria
 *
 * \param programmer                    Variable estructura eProgrammers elegida
 * \param category                      Variable estructura eCategories elegida
 *
 *
 */
void programmerSimpleList (eProgrammers programmer[], eCategories category[]);


/** \brief Agrega un elemento a un eProy_Prog y modifica su relacion con un eProgrammers y un eProyects
 *
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param proyect                       Vector estructura eProyects elegido
 * \param auxProyectIndex               Variable con el indice del proyecto elegido
 * \param auxProyectName                Vector char con el nombre del proyecto elegido
 * \param auxProgrammerId               Variable con el id del programador elegido
 * \return          True/False indicando si el programa logro su objetivo
 *
 */
int proyect_programmerAdd (eProy_Prog proyect_programmer[], eProgrammers programmer[], eProyects proyect[], int , char [], int );


/** \brief Lista elementos de un eProgrammers indicando id, nombre, apellido, categoria, proyectos donde trabaja y sueldo por cada proyecto
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param proyect                       Vector estructura eProyects elegido
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param category                      Vector estructura eCategories elegido
 *
 *
 */
void programmerFullList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[]);


/** \brief Lista todos elementos cargados en un vector estructura eProyects junto con el calculo de su costo total
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param proyect                       Vector estructura eProyects elegido
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param category                      Vector estructura eCategories elegido
 *
 */
void proyectCostList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[]);


/** \brief Ordena los elementos de un vector estructura eProgrammers de menor a mayor por idProgrammer
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 *
 *
 */
void sortProgrammerById (eProgrammers programmer[]);


/** \brief Lista elementos de un eProyects indicando id, nombre, apellido, categoria, proyectos donde trabaja y sueldo por cada proyecto
 *
 * \param programmer                    Vector estructura eProgrammers elegido
 * \param proyect                       Vector estructura eProyects elegido
 * \param proyect_programmer            Vector estructura eProy_Prog elegido
 * \param category                      Vector estructura eCategories elegido
 *
 *
 */
void proyectFullList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], eCategories category[]);


/** \brief Lista todos los proyectos relacionados a un elemento de un vector eProgrammer
 *
 * \param programmer                    Vector estructura eProgrammer elegido
 * \param proyect                       Vector estructura eProyects elegido
 * \param proyect_programmer            Vector estructura proyect_programmer elegido
 * \param auxProgrammerId               Variable que contiene el idProgrammer elegido
 * \return
 *
 */
int proyectOfProgramerList (eProgrammers programmer[], eProyects proyect[], eProy_Prog proyect_programmer[], int);


/** \brief Indica el/los proyecto/s con mas empleados asignados y cuantos son
 *
 * \param proyect                       Vector estructura eProyects elegido
 *
 *
 */
void demandingProyect (eProyects proyect[]);



/********************************** COMPLEMENTARY FUNCTIONS *****************************************/
/****************************************************************************************************/



/** \brief Toma un valor de tipo int
 *
 * \param message                       Texto a ser mostrado
 *
 * \return  Devuelve el entero ingresado
 *
 */
int getInt (char []);


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




#endif // LIB_H_INCLUDED
