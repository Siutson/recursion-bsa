#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arrSize;
int* arrStorage = NULL;

int roundUp(int number) {
	return ceil(number / 2);
}

int binarySearch(int pos, int* arr, int size, const int constSize) {

	int midPoint = floor(size / 2);
	
	if (arr[midPoint] == pos) {
		
		for (int i = 0; i < arrSize; i++) {
			if (arrStorage[i] == arr[midPoint]) {
				return i;
			}
		}
	}
	else {
		if (arr[midPoint] > pos) {
			arr = (int*)realloc(arr, sizeof(int)*midPoint);
			binarySearch(pos, arr, midPoint, constSize);
		}
		else {
			int* helperArr = (int*)malloc(size * sizeof(int));

			for (int i = 0; i < size; i++) {
				helperArr[i] = arr[i];
			}

			arr = (int*)realloc(arr, sizeof(int)*midPoint);
			for (int i = 0; i < midPoint; i++) {
				arr[i] = helperArr[i + midPoint];
			}
			binarySearch(pos, arr, midPoint, constSize);
		}
	}

}

int main() {

	int size = 9;
	const int constSize = size;
	int* array = (int*)malloc(size * sizeof(int));
	int position = 8;

	arrSize = size;
	arrStorage = (int*)calloc(arrSize, sizeof(int));
	printf("Picked position: %d\n", position);
	
	for (int i = 0; i < size; i++) {
		array[i] = i+2;
		arrStorage[i] = array[i];
		printf("array[%d] = %d\n", i, array[i]);
	}


	position = binarySearch(position, array, size,constSize);
	printf("position in array: %d", position);

	free(array);
	return 0;
}