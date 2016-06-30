#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
typedef struct
{
    char nombre[20];
    char apellido[20];
    int legajo;
}ePersona;

void initPersona(ePersona* pPersona, int length);

int buscarLibre(ePersona* pPersona, int length);

int buscarLegajo(ePersona* pPersona, int length, int indice);
void pedirDatos(ePersona* pPersona,int length, char* nombre, char* apellido, int* legajo, int PedirLegajo);
ePersona* nuevaPersona(char* nombre, char* apellido, int* legajo);
void agregarPersona(ePersona* pPersona, int length);

void printArrayAgenda(ePersona* pPersona, int length);

int main()
{
    ePersona personas[200];
    char opcion;
    int auxInt;
    initPersona(personas, 200);
    do
    {
        printf("1.ALTA\n2.MODIFICACION\n3.BAJA\n4.IMPRIMIR\n5.SALIR\n");
        scanf(" %c", &opcion);

        switch(opcion)
        {
            case '1':
                agregarPersona(personas, 200);
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                printArrayAgenda(personas, 200);
                break;
            case '5':
                break;
        }
    }while(opcion!='5');
    return 0;
}


void initPersona(ePersona* pPersona, int length)
{
    int i;
    if(pPersona !=NULL && length > 0)
    {
        for(i = 0; i<length; i++)
        {
            (pPersona+i)->legajo = -1;
        }
    }
}

int buscarLibre(ePersona* pPersona, int length)
{
    int i;
    int returnAux = -1;
    if(pPersona != NULL && length> 0)
    {
        for(i= 0; i<length; i++)
        {
            if( (pPersona+i)->legajo == -1)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

void pedirDatos(ePersona* pPersona,int length, char* nombre, char* apellido, int* legajo, int PedirLegajo)
{
    int auxInt;
    char auxNombre[30];
    char auxApellido[30];
    int auxLegajo;


    if(nombre != NULL && apellido != NULL && legajo != NULL && PedirLegajo > 0)
    {
        do
        {
            auxInt = getName(auxNombre,"Ingrese el nombre: ", "ERROR: Maximo 30 caracteres",0, 31);
        }while(auxInt != 0);
        strcpy(nombre, auxNombre);

        do
        {
            auxInt = getName(auxApellido,"Ingrese el Apellido: ", "ERROR: Maximo 30 caracteres", 0, 31);
        }while(auxInt != 0);
        strcpy(apellido, auxApellido);
        if(PedirLegajo == 1)
        {
            do
            {
                auxInt = getInt(&auxLegajo,"Ingrese el legajo: ", "ERROR: Maximo 30 caracteres",0, 200);
                if(auxInt == 0)
                {
                    auxInt = buscarLegajo(pPersona, length, auxLegajo);
                    if(auxInt == 1)
                    {
                        auxInt = -1;
                    }
                    else
                    {
                        auxInt = 0;
                    }
                }


            }while(auxInt != 0);
            *(legajo) = auxLegajo;
            /*
            printf("%s", nombre);
            printf("\n%s", apellido);
            printf("\n%d", *legajo);
            */
        }
    }
}

int buscarLegajo(ePersona* pPersona, int length, int indice)
{
    int i;
    int returnAux = -1;
    if(pPersona != NULL && length > 0)
    {
        returnAux = 0;
        for(i= 0; i<length; i++)
        {
            if((pPersona+i)->legajo == indice)
            {
                returnAux = 1;
            }
        }
    }
    return returnAux;
}

ePersona* nuevaPersona(char* nombre, char* apellido, int* legajo)
{
    ePersona* returnPersona = malloc(sizeof(ePersona));
    if(nombre != NULL && apellido != NULL && legajo != NULL)
    {
        strcpy(returnPersona->nombre, nombre);
        strcpy(returnPersona->apellido, apellido);
        returnPersona->legajo = *legajo;

        printf("%s %s %d", returnPersona->nombre, returnPersona->apellido, returnPersona->legajo);
    }
    return returnPersona;
}

void agregarPersona(ePersona* pPersona, int length)
{
    char nombre[30];
    char apellido[30];
    int legajo;
    int auxInt;
    int libre;
    ePersona* auxPersona = malloc(sizeof(ePersona));

    if(pPersona != NULL && length > 0)
    {
        pedirDatos(pPersona, length, nombre, apellido, &legajo, 1);
        libre = buscarLibre(pPersona, length);

        if(libre != -1)
        {
             auxPersona = nuevaPersona(nombre, apellido, &legajo);
             *(pPersona+libre) = *auxPersona;
             printf("  %s    %s    %d\n", pPersona->nombre, pPersona->apellido, pPersona->legajo);
        }
    }

}


void printArrayAgenda(ePersona* pPersona, int length)
{
    int i;
    if(pPersona != NULL && length> 0)
    {
        printf("legajo              Nombre            Apellido\n");
        for(i=0; i<10; i++)
        {
            if((pPersona+i)->legajo != -1)
            {
                printf("%6d%20s%20s\n", (pPersona+i)->legajo, (pPersona+i)->nombre, (pPersona+i)->apellido);
            }
        }
    }
}

//void guardarDatos()
