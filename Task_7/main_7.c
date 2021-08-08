#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    return 0;
}