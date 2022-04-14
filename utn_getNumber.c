#include <stdio.h>
#include <stdlib.h>


int utn_getNumber( int *pResultado, char *message, char *messageError, int minimo, int maximo, int reintentos){

    int exitCode = -1;
    int bufferInt;
    
    if(pResultado != NULL && message != NULL && messageError != NULL){
        printf("%s", message);
        scanf("%d", &bufferInt);
    }

    return exitCode;
}