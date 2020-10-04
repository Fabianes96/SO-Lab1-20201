#include <stdio.h>

/*Definición de funciones*/
int wzipFunction(char *fileName);
int ultimo(int cont, char comparador);
int comparadorGlobal;
int main(int argc, char *argv[])
{   
    //Caso de solo un argumento
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }    
    int contador = 0;
    if (argc > 1)
    {
        //For para el caso de varios archivos
        for (int i = 1; i < argc; i++)
        {
            //A contador se va llevando la cantidad de veces que se repite la última letra de un archivo
            contador = contador + wzipFunction(argv[i]);
        }
        //Llamada a "ultimo" que escribe el resultado final
        ultimo(contador, comparadorGlobal);
    }
}
//Función del wzip
int wzipFunction(char *fileName)
{
    /*Variables para el manejo del archivo*/
    FILE *fp = fopen(fileName, "r");
    char c;
    char comparador;
    int cont = 1;
    /*Evalua si el archivo no existe...*/
    if (fp == NULL)
    {
        printf("wzip: cannot open file\n");
        return 1;
    }
    //Apuntador a las letras del archivo
    c = fgetc(fp);
    //do-while para recorrer el archivo
    do
    {
        //Primer letra del archivo    
        comparador = c;
        //Siguiente letra del archivo
        c = fgetc(fp);
        //Condición para el fin del ciclo
        if (c == EOF)
        {
            break;
        }
        //Si las letras son iguales suma el contador
        if (c == comparador)
        {
            cont++;
        }
        else
        {
            //Si no son iguales, se escribe con fwrite la secuencia que se lleva en el momento 
            fwrite(&cont, 1, sizeof(cont), stdout);
            printf("%c", comparador);
            //Contador a 1 
            cont = 1;
        }
    } while (1);
    //Lleva el ultimo char del archivo a comparadorGlobal
    comparadorGlobal = comparador;
    //Cierra el archivo y retorna la cantidad de veces que se repitió la ultima letra
    fclose(fp);
    return cont;
}

//Función que recibe la última letra leida y el número de veces que se repitió luego de leer uno o varios archivos
int ultimo(int cont, char comparador)
{
    //Se escribe el resultado final de la compresión
    fwrite(&cont, 1, sizeof(cont), stdout);
    printf("%c", comparador);
    return 0;
}