#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.c"

// function declaration.
void sorting(char *file_input, char *file_output);

int main(void) {
    int num;
    FILE *fptr;

    fptr = fopen("data.txt","w");

    printf("Enter num of randomization:");
    scanf("%d", &num);

    srand(time(0));

    for (int i=0; i<num; i++) {
        fprintf(fptr,"%d\n", rand()%1000);
    }

    fclose(fptr);
    sorting("data.txt", "data_sorted.txt");
    return 0;
}