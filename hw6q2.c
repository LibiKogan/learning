#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define SORTED_FROM_SMALL_TO_LARGE 1
#define SORTED_FROM_LARGE_TO_SMALL 2

void printIDontKnow()
{
	printf(DONT_KNOW);
	exit(0);
}

int q2(int arr[], int n, int x);
int binomial_search(int arr[], int n, int x, int rise);

int* ReadArray(int* n)
{
	if (scanf("%d", n) != 1)
		return NULL;

	int* arr = malloc(*n * sizeof(int));
	if (arr == NULL)
		return NULL;

	for (int i = 0; i < *n; ++i)
		if (scanf("%d", &arr[i]) != 1)
		{
			free(arr);
			return NULL;
		}


	return arr;
}


int main()
{
    // uncomment next line if you don't know the answer
	// printIDontKnow();
    printf("Hello Git!");
	int n, x;
	int* arr = ReadArray(&n);
	if (arr == NULL)
		return 1;
    if (scanf("%d", &x) != 1){
        free(arr);
        return 1;
    }
	printf("%d", q2(arr, n, x));
	free(arr);

	return 0;
}

int q2(int arr[], int n, int x)
{
    // check first even places with corted array then check odd places with
    // sorted array
    // SORTED_FROM_SMALL_TO_LARGE and SORTED_FROM_LARGE_TO_SMALL tells what
    // type of array binonial search got
    int result = binomial_search(arr, n, x, SORTED_FROM_SMALL_TO_LARGE);
    if (result != -1) return result;
    else result = binomial_search(arr, n, x, SORTED_FROM_LARGE_TO_SMALL);
    return result;
}

int binomial_search(int arr[], int n, int x, int rise)
{
    int mid;
    // depends on the rype of array we check only odd places from 1 to n-1
    // or even places from 0 to n-2
    int low = (rise == SORTED_FROM_SMALL_TO_LARGE) ? 0 : 1;
    int high = (rise == SORTED_FROM_SMALL_TO_LARGE) ? n-2 : n-1;
    while (low <= high)
    {
         mid = (low+high)/2;
         //check that we are on odd place if we check odd places and on the
         //even place if we check even places
         if (((mid%2 == 1)&&(rise == SORTED_FROM_SMALL_TO_LARGE))||
            ((mid%2 == 0)&&(rise == SORTED_FROM_LARGE_TO_SMALL))) mid--;
         if (arr[mid] == x) return mid;
         else if (arr[mid] < x)
            {
                //we want to checl only odd/even numbers so we need 2 here
                if (rise == SORTED_FROM_SMALL_TO_LARGE) {
                    low = mid + 2;
                }
                if (rise == SORTED_FROM_LARGE_TO_SMALL) {
                    high = mid - 2;
                }
            }
            else
            {
                if (rise == SORTED_FROM_SMALL_TO_LARGE) {
                    high = mid - 2;
                }
                if (rise == SORTED_FROM_LARGE_TO_SMALL) {
                    low = mid + 2;
                }
            }
    }
    return -1;
}

