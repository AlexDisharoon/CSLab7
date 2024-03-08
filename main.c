/*
Alexander Disharoon
Lab Assignment 7
3/7/2024
*/

#include <stdio.h>

void numSwapsBubble(int arr[], int size);
void numSwapsSelection(int arr[], int size);

int main() 
{
    int arr[] = {97,16,45,63,13,22,7,58,72};
    int arr2[] = {97,16,45,63,13,22,7,58,72};
    int arr3[] = {90,80,70,60,50,40,30,20,10};
    int arr4[] = {90,80,70,60,50,40,30,20,10};

    numSwapsBubble(arr, sizeof(arr)/sizeof(arr[0]));

    numSwapsSelection(arr2, sizeof(arr2)/sizeof(arr2[0]));

    numSwapsBubble(arr3, sizeof(arr3)/sizeof(arr3[0]));

    numSwapsSelection(arr4, sizeof(arr4)/sizeof(arr4[0]));

    return 0;
}

void numSwapsBubble(int arr[], int size) 
{
    int swaps = 0;

    int elementSwaps[9] = {0};

    for(int i = 0; i < size - 1; ++i) 
    {
        for(int h = 0; h < size - i - 1; ++h) 
        {
            if(arr[h] > arr[h + 1]) 
            {
                int temp = arr[h];
                arr[h] = arr[h+1];
                arr[h+1] = temp;
                swaps++;

                temp = elementSwaps[h];
                elementSwaps[h] = elementSwaps[h+1];
                elementSwaps[h+1] = temp;

                elementSwaps[h]++;
                elementSwaps[h+1]++;
            }
        }
    }

    for(int i = 0; i < size; ++i) 
    {
        printf("%d is swapped %d times\n", arr[i], elementSwaps[i]);
    }
    printf("Bubble sort swaps: %d\n\n", swaps);
}

void numSwapsSelection(int arr[], int size) 
{
    int swaps = 0;

    int elementSwaps[9] = {0};

    for(int i = 0; i < size - 1; ++i) 
    {
        int index = i;

        for(int h = i + 1; h < size; ++h) 
        {
            if(arr[h] < arr[index]) 
            {
                index = h;
            }
        }

        if(index != i) 
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            swaps++;

            temp = elementSwaps[i];
            elementSwaps[i] = elementSwaps[index];
            elementSwaps[index] = temp;

            elementSwaps[i]++;
            elementSwaps[index]++;
        }
    }

    for(int i = 0; i < size; ++i) 
    {
        printf("%d is swapped %d times\n", arr[i], elementSwaps[i]);
    }
    printf("Selection sort swaps: %d\n\n", swaps);
}