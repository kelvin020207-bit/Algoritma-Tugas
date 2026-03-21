#include <stdio.h>
#include <stdlib.h>

void binary_search(int array[], int first, int last, int n)
{
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (array[middle] < n)
            first = middle + 1;
        else if (array[middle] == n) {
            printf("%d found at location %d.\n", n, middle + 1);
            return;
        }
        else
            last = middle - 1;
    }

    printf("Not found! %d is not present in the list.\n", n);
}

void search(int arr[], int size, int data)
{
    int p = (size - 1) / 2;
    int low, high;
    int a1 = 0, a2 = 1;

    low = p + a1;
    high = p + a2;

    while (1)
    {
        if (high >= size)
            high = size - 1;

        if (data >= arr[low] && data <= arr[high])
        {
            binary_search(arr, low, high, data);
            break;
        }
        else if (data < arr[low])
        {
            binary_search(arr, 0, low, data);
            break;
        }
        else
        {
            a2 = a2 * 2;
            low = high;
            high = p + a2;

            if (low >= size)
            {
                printf("Not found! %d is not present in the list.\n", data);
                break;
            }
        }
    }
}

int main()
{
    int a[200], i, n, size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d integers in ascending order:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    printf("Enter value to find: ");
    scanf("%d", &n);

    search(a, size, n);

    return 0;
}