#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_generales.h"
#include "funciones_arrays.h"

#define LARGO_ITEM_MENU 50
#define NRO_OPCIONES_ALTA 6

void procesarAltas(const int cantElementos,
                   int legajoAlumnos[],
                   char nombreAlumnos[][LARGO_NOMBRE_ALUMNO],
                   int nota1Alumnos[],
                   int nota2Alumnos[],
                   float promedioAlumnos[])
{
    const char menuAlta[NRO_OPCIONES_ALTA][LARGO_ITEM_MENU] = {"1. Ingresar legajo",
                                                               "2. Ingresar nombre alumno",
                                                               "3. Ingresar primer nota",
                                                               "4. Ingresar segunda nota",
                                                               "8. Confirmar ingreso",
                                                               "9. Cancelar ingreso"};

    const int codigosAlta[NRO_OPCIONES_ALTA] = {1,2,3,4,8,9};
    char continuarIngreso = 'S';
    int opcion;

    printf("buscar lugar en array\n");
    while(continuarIngreso == 'S')
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        mostrarMenu(menuAlta, NRO_OPCIONES_ALTA);
        opcion = pedirOpcion(menuAlta, codigosAlta, NRO_OPCIONES_ALTA);

        switch(opcion)
        {
            case 1:
                printf("pedir legajo entero mayor que 0\n");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 2:
                printf("pedir nombre alumno\n");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 3:
                printf("pedir nota1 entre 1 y 10\n");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 4:
                printf("pedir nota2 entre 1 y 10\n");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 8:
                printf("\nSe van a guardar los datos ingresados.");
                if(pedirConfirmacion("Est  seguro?") == 'S')
                {
                    ejecutarEnConsola(HACER_PAUSA);
                    continuarIngreso = 'N';
                }
                break;
            case 9:
                continuarIngreso = 'N';
                break;
        }//switch
        continuarIngreso = pedirConfirmacion("Desea continuar dando altas?");
    }//while
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
            procesarAltas(cantElementos, legajoAlumnos, nombreAlumnos, nota1Alumnos, nota2Alumnos, promedioAlumnos);
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

void ordenarPorPromedio(float array[], const int cant, const char orden[])
{
    float aux;
    int i;
    int j;
    for(i=0 ; i<cant-1 ; i++)
    {
        for(j=i+1 ; j<cant ; j++)
        {
            if(strcmp(orden, "mayor")==0)
            {
                if(array[i] < array[j])
                {
                    aux = array[i];
                    array[i] = array[j];
                    array[j] = aux;
                }
            }
            else
            {
                if(strcmp(orden, "menor")==0)
                {
                    if(array[i] > array[j])
                    {
                        aux = array[i];
                        array[i] = array[j];
                        array[j] = aux;
                    }
                }
            }
        }//for j
    }// for i
}

void ordenarPorNombre(char array[][LARGO_NOMBRE_ALUMNO], const int cant, const char orden[])
{
    char aux[LARGO_NOMBRE_ALUMNO];
    int i;
    int j;
    for(i=0 ; i<cant-1 ; i++)
    {
        for(j=i+1 ; j<cant ; j++)
        {
            if(strcmp(orden, "mayor")==0)
            {
                if(stricmp(array[i],array[j]) < 0)
                {
                    strcpy(aux,array[i]);
                    strcpy(array[i],array[j]);
                    strcpy(array[j], aux);
                }
            }
            else
            {
                if(strcmp(orden, "menor")==0)
                {
                    if(stricmp(array[i],array[j]) > 0)
                    {
                        strcpy(aux,array[i]);
                        strcpy(array[i],array[j]);
                        strcpy(array[j], aux);
                    }
                }
            }
        }//for j
    }// for i
}
