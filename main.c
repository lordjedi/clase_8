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
int borrarPersona(ePersona* pPersona, int length);
int buscarIndiceLegajo(ePersona* pPersona, int length, int legajo);
void pedirDatos(ePersona* pPersona,int length, char* nombre, char* apellido, int* legajo, int PedirLegajo);
int modificarPersona(ePersona* pPersona, int length);
ePersona* nuevaPersona(char* nombre, char* apellido, int* legajo);
void agregarPersona(ePersona* pPersona, int length);
void guardarDatos(ePersona *pPersona, int length);
void cargarDatos(ePersona* pPersona, int length);
void printArrayAgenda(ePersona* pPersona, int length);

int main()
{
    ePersona personas[200];
    char opcion;
    initPersona(personas, 200);
    cargarDatos(personas, 200);
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
                modificarPersona(personas, 200);
                break;
            case '3':
                borrarPersona(personas, 200);
                break;
            case '4':
                printArrayAgenda(personas, 200);
                break;
            case '5':
                guardarDatos(personas, 200);
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


    if(nombre != NULL && apellido != NULL && legajo != NULL)
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
                    auxInt = buscarIndiceLegajo(pPersona, length, auxLegajo);
                    if(auxInt != -1)
                    {
                        printf("Ese legajo ya existe!");
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

int buscarIndiceLegajo(ePersona* pPersona, int length, int legajo)
{
    int i;
    int returnAux = -1;
    if(pPersona != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if((pPersona+i)->legajo == legajo)
            {
                returnAux = i;
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

    }
    return returnPersona;
}

void agregarPersona(ePersona* pPersona, int length)
{
    char nombre[30];
    char apellido[30];
    int legajo;
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

void guardarDatos(ePersona *pPersona, int length)
{
    int i;
    int cantidad = 0;
    FILE* pArch;
    int longitud;

    if(pPersona != NULL && length> 0)
    {
        for(i = 0; i<length; i++)
        {
            if((pPersona+i)->legajo != -1)
            {
               cantidad++;
            }
        }

        pArch = fopen("agenda.dat", "wb");
        if(pArch != NULL)
        {
            longitud = fwrite(pPersona,sizeof(ePersona), cantidad, pArch);
            if(longitud< cantidad)
            {
                printf("ERROR");
            }
        }
        fclose(pArch);
    }
}

void cargarDatos(ePersona* pPersona, int length)
{
    FILE* pArch;
    int longitud;

    if(pPersona != NULL && length > 0)
    {
        pArch = fopen("agenda.dat","rb");
        if(pArch != NULL)
        {
            fseek(pArch, 0L, SEEK_END);
            longitud = ftell(pArch);
            rewind(pArch);
            while(!feof(pArch))
            {
               fread(pPersona, sizeof(ePersona), longitud, pArch);
               if(feof(pArch))
               {
                   break;
               }
            }

        }
    }
}

int borrarPersona(ePersona* pPersona, int length)
{
    int returnAux = -1;
    int auxLegajo;
    int auxInt;
    int indice;
    if(pPersona != NULL && length> 0)
    {
        returnAux = 0;
        do
        {
            auxInt = getInt(&auxLegajo, "Ingrese el legajo de la persona a borrar: ", "error: legajo no valido", 0, 200);
        }while(auxInt != 0);

        indice = buscarIndiceLegajo(pPersona, length, auxLegajo);
        if(indice != -1)
        {
            pPersona[indice].legajo = -1;
            printf("persona borrada!\n");
        }


    }
    return returnAux;
}

int modificarPersona(ePersona *pPersona, int length)
{
    int legajo, indice;
    int auxInt;
    char nombre[20];
    char apellido[20];
    int returnAux = -1;
    ePersona* auxPersona;
    if(pPersona != NULL && length > 0)
    {
        returnAux = 0;
        do
        {
            auxInt = getInt(&legajo, "Ingrese el legajo de la persona a modificar", "ERROR: legajo no valido", 0, 200);
        }while(auxInt != 0);

        indice = buscarIndiceLegajo(pPersona, length, legajo);
        if( indice != -1)
        {
            pedirDatos(pPersona,length,nombre,apellido, &legajo,0);
            auxPersona = nuevaPersona(nombre,apellido,&legajo);
            *(pPersona+indice) = *auxPersona;
            printf("Persona modificada");
        }
    }
    return returnAux;
}
