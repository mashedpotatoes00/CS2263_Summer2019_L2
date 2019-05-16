/********************************
 *
 * ArraySort.c
 *
 * Created by Jean-Philippe Legault
 *
 * Your task is to implement in place sorting using the two available functions
 * swapAdjacent, and compareAdjacent.
 *
 * Some bug might have been introduced... you will have to find out if there are any!
 * if so, you will have to correct it
 *
 *Modified by Tully Masterson and Seth Wydysh
 *
 ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *array, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i != 0)
        {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}
/*
*swaps elements in array at index and index+1
*@input: an array and index
*/
void swapAdjacent(int *a, int index)
{
    int temp = *(a + index);
    *(a + index) = *(a + index + 1);
    *(a + index + 1) = temp;
}
/*
*compares elments in a array at index and index+1
*@input: array and a index location
*@return: a integer value of element at index - element at index+1
*/
int compareAdjacent(int *a, int index)
{
    return *(a + index) - *(a + (index + 1));
}

/**
 *uses Bubble sort to sort Array of integers, calls methods compareAdjacent() to
 *compare elements that are side by side in the array and calls swapAdjacent()
 *to swpa elements that are side by side
 *@intput: take in array and size of that array
 *@return: no more swaps need to take place, breaks the loop an exits method
 *         with sorted array
 */
void inPlaceSort(/* your input parameter */int size, int *a)
{
  int swap;
  for(int i=0; i<size-1;i++){
    swap = 0;
    for(int j=0; j<size-i-1; j++){
      if(compareAdjacent(a, j) > 0){
        swapAdjacent(a, j);
        swap = 1;
      }
    }
    if(swap == 0){
      return;
    }
  }
}

int main(void)
{

    int array_size = 0;
    printf("Enter the array size (>0) and the numbers to fill the array with: ");
    if(!scanf("%d", &array_size))
    {
        printf("ERROR. Must enter an integer.\n");
        return EXIT_FAILURE;
    }
    else if(array_size < 1)
    {
        printf("ERROR. array size must be at least 1.\n");
        return EXIT_FAILURE;
    }

    int a[array_size];

    /**********************
     * TODO finish parsing the user input to fill the array
     *
     * it should parse user input with scanf to fill the array with values
     **********************/
    for(int i=0; i<array_size; i++){
      if(!scanf("%d", &a[i])){
        printf("ERROR. Must enter an integer.\n");
        return EXIT_FAILURE;
      }
    }

    //printf("=== Array before Sorting = ");
    printArray(a, array_size);

    inPlaceSort(/* your input parameter */array_size, a);
    //printf("=== Array after Sorting = ");

    printArray(a, array_size);
    return EXIT_SUCCESS;
}
