#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 1000

int wgrepFunction(char termino[], char *fileName);
int wgrepByInput(char termino[]);

int main(int argc, char *argv[])
{
    /*Casos para wgrep*/
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    if (argc == 2)
    {
        if (wgrepByInput(argv[1]) == 1)
        {
            return 1;
        }
    }
    if (argc > 2)
    {
        for (int i = 2; i < argc; i++)
        {
            if (wgrepFunction(argv[1], argv[i]) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}
int wgrepByInput(char termino[])
{
    /*Variable para guardar la entrada por teclado*/
    char str[n];
    /*Ciclo para la entrada por teclado. Se sale con ctrl+c*/
    while (fgets(str, n, stdin))
    {
        /*Evalua si el termino está en la linea */
        if (strstr(str, termino) != NULL)
        {
            printf("%s", str);
        }
    }
    return 0;
}

int wgrepFunction(char termino[], char *fileName)
{
    /*Variables para el manejo del archivo*/
    FILE *fp = fopen(fileName, "r");
    char *linea = NULL;
    size_t tamano = 0;
    int contador = 0;
    ssize_t contadorDeLinea;
    /*Evalua si el archivo no existe...*/
    if (fp == NULL)
    {
        printf("wgrep: cannot open file\n");
        return 1;
    }
    /*Obtiene el numero de linea*/
    contadorDeLinea = getline(&linea, &tamano, fp);
    /* Ciclo que recorre todo el archivo */
    while (contadorDeLinea >= 0)
    {
        /* Incrementa el contador */
        contador++;
        /*Evalua si el termino está en la linea */
        if (strstr(linea, termino) != NULL)
        {
            printf("%s", linea);
        }
        /* Siguiente linea del archivo */
        contadorDeLinea = getline(&linea, &tamano, fp);
    }
    /*Libera el buffer asignado y cierra el archivo*/
    free(linea);
    linea = NULL;
    fclose(fp);

    return 0;
}