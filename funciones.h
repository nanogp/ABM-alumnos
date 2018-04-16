#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)
#define LARGO_NOMBRE_MENU 20
#define LARGO_NOMBRE_ALUMNO 100


/** \brief ejecuta en la consola del SO el texto recibido
 *
 * \param char[] const lineaDeComando: el texto a ejecutar
 * \return void
 *
 */
void ejecutarEnConsola(const char[]);


/** \brief buscar en un array de enteros
 *
 * \param int const valor: el valor a buscar entre los elementos
 * \param int[] const array: la posici�n en memoria del array
 * \param int const cantElementos: la cantidad de elementos del array
 * \return int: devuelve la posici�n del elemento buscado, o -1 si no lo encuentra
 *
 */
int buscarEnArrayInt(const int, const int[], const int);

/** \brief muestra un menu de opciones recorriendo un array
 *
 * \param char[][LARGO_NOMBRE_MENU] const menu: el array que contiene la descripci�n de las opciones del menu
 * \param int const cantElementosMenu: la cantidad de elementos del array
 * \return void
 *
 */
void mostrarMenu(const char[][LARGO_NOMBRE_MENU], const int);


/** \brief pide al usuario que elija una opci�n de men� v�lida
 *
 * \param char[][LARGO_NOMBRE_MENU] const menu: el array que contiene la descripci�n de las opciones del menu
 * \param int[] const opciones: el array que contiene las opciones de men�
 * \param int const cantElementosMenu: la cantidad de elementos del array
 * \return int: n�mero de opci�n elegida y validada
 *
 */
int pedirOpcion(const char[][LARGO_NOMBRE_MENU], const int[], const int);


/** \brief procesa seg�n la opci�n elegida por el usuario
 *
 * \param int const opcion: el n�mero de opci�n para switchear
 * \return char: 'S' o 'N' para saber si debe continuar ejecuci�n del programa
 *
 */
char procesarOpcion(const int, const int, int[], char[][LARGO_NOMBRE_ALUMNO], int[], int[], float[]);

void procesarAltas(const int, int[], char[][LARGO_NOMBRE_ALUMNO], int[], int[], float[]);
