#include <stdio.h>
#include <stdlib.h>
#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)
#define LARGO_NOMBRE_MENU 20
#define LARGO_NOMBRE_ALUMNO 100

void ejecutarEnConsola(const char lineaDeComando[])
{
    system(lineaDeComando);
}

int buscarEnArrayInt(const int valor, const int array[], const int cantElementos)
{
    int retorno = -1;
    int i;

    for(i=0 ; i<cantElementos ; i++)
    {
        if(array[i]==valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void mostrarMenu(const char menu[][LARGO_NOMBRE_MENU], const int cantElementosMenu)
{
    int i;
    for(i=0 ; i<cantElementosMenu; i++)
    {
        printf("\n%s", menu[i]);
    }
}

int pedirOpcion(const char menu[][LARGO_NOMBRE_MENU], const int opciones[], const int cantElementosMenu)
{
    int retorno;
    int i;

    printf("\nElija un n£mero de opci¢n del men£: ");
    scanf("%d", &retorno);

    while(buscarEnArrayInt(retorno, opciones, cantElementosMenu) == -1)
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        mostrarMenu(menu, cantElementosMenu);
        //armo lista de opciones en el renglón por si el usuario se equivoca muchas veces
        //y el menú queda fuera de vista
        for(i = 0 ; i < cantElementosMenu ; i++)
        {
            if(i == 0)
            {
                printf("\nOpci¢n %d no v lida.\nElija una opci¢n de men£ de la lista\n(%d", retorno, opciones[i]);
            }
            else
            {
                if(i < cantElementosMenu-1)
                {
                    printf("-%d", opciones[i]);
                }
                else
                {
                    printf("-%d): ", opciones[i]);
                }
            }
        }//for
        fflush(stdin);
        scanf("%d", &retorno);
    }

    return retorno;
}

char procesarOpcion(const int opcion,
                    const int cantElementos,
                    int legajoAlumnos[],
                    char nombreAlumnos[][LARGO_NOMBRE_ALUMNO],
                    int nota1Alumnos[],
                    int nota2Alumnos[],
                    float promedioAlumnos[])
{
    char salirDelPrograma = 'N';
    switch(opcion)
    {
        case 1:
            printf("ALTA");
            ejecutarEnConsola(HACER_PAUSA);
            break;
        case 2:
            printf("BAJA");
            ejecutarEnConsola(HACER_PAUSA);
            break;
        case 3:
            printf("MODIFICACION");
            ejecutarEnConsola(HACER_PAUSA);
            break;
        case 9:
            ejecutarEnConsola(LIMPIAR_PANTALLA);
            printf("\n\nFin del programa.\n\n");
            ejecutarEnConsola(HACER_PAUSA);
            salirDelPrograma = 'S';
            break;
    }
    return salirDelPrograma;
}
/*
void procesarAltas(const int cantElementos,
                   int legajoAlumnos[],
                   char nombreAlumnos[][LARGO_NOMBRE_ALUMNO],
                   int nota1Alumnos[],
                   int nota2Alumnos[],
                   float promedioAlumnos[])
{
    const char aux[LARGO_NOMBRE_ALUMNO*2];
}
*/
