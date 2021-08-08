#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 10

static void swap_elements(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for(int j=low; j<=high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_elements(&arr[i], &arr[j]);
        }
    }
    swap_elements(&arr[i+1], &arr[high]);
    return (i+1);
}

static void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int x = partition(arr,low,high);

        quick_sort(arr,low,x-1);
        quick_sort(arr,x+1,high);
    }
}

void sorting(char *file_input, char *file_output) {

    int i = 0;
    int max_index = BLOCK_SIZE;
    int *data_arr = (int*)malloc(sizeof(int)*BLOCK_SIZE);
    FILE *file_input_pointer = fopen(file_input, "r");

    const unsigned MAX_LENGHT = 6;
    char buffer[MAX_LENGHT];

    while(fgets(buffer,MAX_LENGHT,file_input_pointer) != NULL) {
        if (i >= max_index) {
            data_arr = (int*)realloc(data_arr, sizeof(int)*(max_index + BLOCK_SIZE));
            if (data_arr == NULL) {
                printf("Error: Insufficient memory!");
                exit(0);
            }
            // printf("\nReallocated\n");
            max_index = max_index + BLOCK_SIZE;
        }
        data_arr[i++] = strtol(buffer, NULL, 10);
    }


    quick_sort(data_arr, 0, i-1);
    fclose(file_input_pointer);


    FILE *file_output_pointer = fopen(file_output, "w");

    for(int j=0; j<i; j++) {
        fprintf(file_output_pointer, "%d\n", *(data_arr + j));
    }

    free(data_arr);
    fclose(file_output_pointer);
}
