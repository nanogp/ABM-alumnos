#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones_generales.h"

#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)
#define LARGO_ITEM_MENU 50
#define LARGO_NOMBRE_ALUMNO 100

#define TITULO_PROGRAMA DEFINIR_MACRO_STRING(SEGUIMIENTO DE LEGAJOS DE ALUMNOS)
#define NRO_OPCIONES_MENU_PRINCIPAL 5
#define CANTIDAD_INGRESOS 5

int main()
{
    const int codigosMenuPrincipal[NRO_OPCIONES_MENU_PRINCIPAL] = {1,2,3,4,9};
    const char itemsMenuPrincipal[NRO_OPCIONES_MENU_PRINCIPAL][LARGO_ITEM_MENU] = {"1. ALTA",
                                                                                   "2. BAJA",
                                                                                   "3. MODIFICACION",
                                                                                   "4. LISTAR",
                                                                                   "9. SALIR"};
    char salirDelPrograma = 'N';
    int opcionDeMenu;
    int legajoAlumnos[CANTIDAD_INGRESOS]={};
    char nombreAlumnos[CANTIDAD_INGRESOS][LARGO_NOMBRE_ALUMNO];
    int nota1Alumnos[CANTIDAD_INGRESOS];
    int nota2Alumnos[CANTIDAD_INGRESOS];
    float promedioAlumnos[CANTIDAD_INGRESOS];

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        printf("\n%s", TITULO_PROGRAMA);
        mostrarMenu(itemsMenuPrincipal, NRO_OPCIONES_MENU_PRINCIPAL);
        opcionDeMenu = pedirOpcion(itemsMenuPrincipal, codigosMenuPrincipal, NRO_OPCIONES_MENU_PRINCIPAL);
        salirDelPrograma = procesarOpcion(opcionDeMenu, CANTIDAD_INGRESOS, legajoAlumnos, nombreAlumnos, nota1Alumnos, nota2Alumnos, promedioAlumnos);
    }
    while(salirDelPrograma == 'N');



    return 0;
}
