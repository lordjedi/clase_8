#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int resp;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);          // Se pone bandera por si nos olvidamos un return
        resp = scanf("%d", &auxInt);
        if(resp == 1)
        {
            if(auxInt > lowLimit && auxInt < hiLimit)
            {
                *input = auxInt;
                flag = 0;

            }
        }

        if(flag == -1)
        {
            printf("%s", eMessage);
        }


    }
    else
    {
        printf("No entro");
    }
    return flag;

}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char* message,char* eMessage, float lowLimit, float hiLimit)
{
    float auxFloat;
    int resp;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);
        resp = scanf("%f", &auxFloat);
        if(resp == 1)
        {
            if(auxFloat > lowLimit && auxFloat < hiLimit)
            {
                *input = auxFloat;
                return 0;

            }
            /*else
            {
                printf("%s", eMessage);
                return -1;
            }*/
        }
        printf("%s", eMessage);

    }
    else
    {
        printf("No entro");
    }
    return -1;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char auxChar[5];
    int resp;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);
        resp = scanf("%s", auxChar);
        if(resp == 1 && (auxChar[1] == '\0'))
        {
            if(auxChar[0] >= lowLimit && auxChar[0] <= hiLimit)
            {
                *input = auxChar[0];
                return 0;

            }
            else
            {
                printf("%s", eMessage);
            }
        }
    }



    return -1;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);
        resp = scanf("%s", auxChar);
        if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
        {

                strcpy(input, auxChar);
                return 0;


        }
        printf("%s", eMessage);
    }

    return -1;
}

/**
* \brief Solicita una cadena de caracteres de solo letras y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getName(char* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int flagName = 1;
    int i;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);
        resp = scanf("%s", auxChar);
        if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
        {
            for(i= 0; i< strlen(auxChar); i ++)
            {
                auxChar[i] = tolower(auxChar[i]);
                if(auxChar[i] < 'a' || auxChar[i] >'z')
                {
                    flagName = 0;
                    break;
                }
            }
        }
        else
        {
            flagName = 0;
        }
        if(flagName)
        {
            auxChar[0] = toupper(auxChar[0]);
            strcpy(input, auxChar);
            return 0;
        }
        printf("%s", eMessage);
    }
    return -1;
}


/**
* \brief Solicita email y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getEmail(char* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int i;
    if(message != NULL && eMessage != NULL && strlen(message) > 0 && strlen(eMessage) > 0 && input> 0)
    {
        printf("%s", message);
        fflush(stdin);
        resp = scanf("%s", auxChar);
        if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
        {
            for(i = 0; i<strlen(auxChar); i++)
            {
                if(auxChar[i] == '@')
                {
                    strcpy(input, auxChar);
                    return 0;
                }
            }
        }
        printf("%s", eMessage);
    }
    return -1;
}


/**
* \brief Solicita una cadena de caracteres que admite espacio (hasta 50 caracteres) al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getStringSpace(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    printf("%s", message);
    fflush(stdin);
    scanf("%50[^\n]",auxChar);
    if(strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit )
    {
        toupper(auxChar[0]);
        strcpy(input, auxChar);
        return 0;
    }
    printf("%s", eMessage);
    return -1;
}
