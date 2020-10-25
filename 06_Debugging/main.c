#include <stdio.h>
#include <stdlib.h>

int main(){
    char* ptr = malloc(sizeof(char));
    *ptr = 'a';
    free(ptr);
    free(ptr);

    return 0;
}
