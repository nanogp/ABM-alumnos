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
 * \param int[] const array: la posición en memoria del array
 * \param int const cantElementos: la cantidad de elementos del array
 * \return int: devuelve la posición del elemento buscado, o -1 si no lo encuentra
 *
 */
int buscarEnArrayInt(const int, const int[], const int);

/** \brief muestra un menu de opciones recorriendo un array
 *
 * \param char[][LARGO_NOMBRE_MENU] const menu: el array que contiene la descripción de las opciones del menu
 * \param int const cantElementosMenu: la cantidad de elementos del array
 * \return void
 *
 */
void mostrarMenu(const char[][LARGO_NOMBRE_MENU], const int);


/** \brief pide al usuario que elija una opción de menú válida
 *
 * \param char[][LARGO_NOMBRE_MENU] const menu: el array que contiene la descripción de las opciones del menu
 * \param int[] const opciones: el array que contiene las opciones de menú
 * \param int const cantElementosMenu: la cantidad de elementos del array
 * \return int: número de opción elegida y validada
 *
 */
int pedirOpcion(const char[][LARGO_NOMBRE_MENU], const int[], const int);


/** \brief procesa según la opción elegida por el usuario
 *
 * \param int const opcion: el número de opción para switchear
 * \return char: 'S' o 'N' para saber si debe continuar ejecución del programa
 *
 */
char procesarOpcion(const int, const int, int[], char[][LARGO_NOMBRE_ALUMNO], int[], int[], float[]);

void procesarAltas(const int, int[], char[][LARGO_NOMBRE_ALUMNO], int[], int[], float[]);
