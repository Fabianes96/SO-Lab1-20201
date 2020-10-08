#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de función
int wunzipFunction(char *fileName);
int main(int argc, char *argv[])
{
    /*Casos para argc*/
    if (argc == 1){
        printf("wunzip: file1 [file2 ...]\n");        
        return 1;
    }
    if (argc > 1){
        for (size_t i = 1; i < argc; i++){
            /*Ejecuta la función*/
            wunzipFunction(argv[i]);
        }
    }    
    
}
int wunzipFunction(char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("wunzip: cannot open file\n");
        return 1;
    }
    /*Variables para el manejo del archivo*/
    char caracter;    
    int cantidad;
    /*Mientras no se el fin del archivo*/
    while (!feof(fp))
    {
        //fread lee los bytes correspondientes al entero en cada ciclo del while
        if(fread(&cantidad, sizeof(cantidad), 1, fp)!=1){
            break;
        }        
        //Se lee el byte correspondiente al char y se imprime el resultado en pantalla según la cantidad de veces que se repite
        fread(&caracter, sizeof(char), 1, fp);
        for (size_t i = 0; i < cantidad; i++)
        {
            printf("%c", caracter);
        }             
    }    
    //Cierra el archivo y retorna
    fclose(fp);
    return 0;
}