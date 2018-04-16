#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)
#define LARGO_NOMBRE_MENU 20
#define LARGO_NOMBRE_ALUMNO 100

#define TITULO_PROGRAMA DEFINIR_MACRO_STRING(SEGUIMIENTO DE LEGAJOS DE ALUMNOS)
#define NRO_OPCIONES_DISPONIBLES 4
#define CANTIDAD_INGRESOS 5

int main()
{
    const int codigoOpcionesDisponibles[NRO_OPCIONES_DISPONIBLES] = {1,2,3,9};
    const char nombreOpcionesDisponibles[NRO_OPCIONES_DISPONIBLES][LARGO_NOMBRE_MENU] = {"1. ALTA","2. BAJA","3. MODIFICACION","9. SALIR"};
    char salirDelPrograma = 'N';
    int opcionDeMenu;
    int legajoAlumnos[CANTIDAD_INGRESOS];
    char nombreAlumnos[CANTIDAD_INGRESOS][LARGO_NOMBRE_ALUMNO];
    int nota1Alumnos[CANTIDAD_INGRESOS];
    int nota2Alumnos[CANTIDAD_INGRESOS];
    float promedioAlumnos[CANTIDAD_INGRESOS];

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        printf("\n%s", TITULO_PROGRAMA);
        mostrarMenu(nombreOpcionesDisponibles, NRO_OPCIONES_DISPONIBLES);
        opcionDeMenu = pedirOpcion(nombreOpcionesDisponibles, codigoOpcionesDisponibles, NRO_OPCIONES_DISPONIBLES);
        salirDelPrograma = procesarOpcion(opcionDeMenu, CANTIDAD_INGRESOS, legajoAlumnos, nombreAlumnos, nota1Alumnos, nota2Alumnos, promedioAlumnos);
    }
    while(salirDelPrograma == 'N');



    return 0;
}
