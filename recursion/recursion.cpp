#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ARRAY_SIZE;
int* TEMP_ARRAY = NULL;

bool IsEqualToPickedNumber(int* argArray, int pickedNumber, int midPoint);

bool IsHigherThanPickedNumber(int* argArray, int pickedNumber, int midPoint);

void IsLowerThanPickedNumber(int* argArray, int arraySize, int pickedNumber, int midPoint);

int BinarySearch(int pickedNumber, int* argArray, int arraySize);

int main() {

	int array_size = 9;
	int* array = (int*)malloc(array_size * sizeof(int));
	int picked_number = 8;

	ARRAY_SIZE = array_size;
	TEMP_ARRAY = (int*)calloc(ARRAY_SIZE, sizeof(int));
	printf("Picked number: %d\n", picked_number);
	
	for (int i = 0; i < array_size; i++) {
		array[i] = i+2;
		TEMP_ARRAY[i] = array[i];
		printf("array[%d] = %d\n", i, array[i]);
	}

	picked_number = BinarySearch(picked_number, array, array_size);
	printf("position in array: %d", picked_number);

	free(array);
	return 0;
}

bool IsEqualToPickedNumber(int* argArray, int pickedNumber, int midPoint) {
	return (argArray[midPoint] == pickedNumber);
}

bool IsHigherThanPickedNumber(int* argArray, int pickedNumber, int midPoint) {
	return (argArray[midPoint] > pickedNumber);
}

void IsLowerThanPickedNumber(int* argArray, int arraySize, int pickedNumber, int midPoint) {
	int* helperArr = (int*)malloc(arraySize * sizeof(int));

	for (int i = 0; i < arraySize; i++) {
		helperArr[i] = argArray[i];
	}

	argArray = (int*)realloc(argArray, sizeof(int)*midPoint);
	for (int i = 0; i < midPoint; i++) {
		argArray[i] = helperArr[i + midPoint];
	}
}

int BinarySearch(int pickedNumber, int* argArray, int arraySize) {

	int midPoint = floor(arraySize / 2);
	
	if (IsEqualToPickedNumber(argArray, pickedNumber, midPoint)) {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			if (TEMP_ARRAY[i] == argArray[midPoint]) {
				return i;
			}
		}
	}
	else {
		if (IsHigherThanPickedNumber(argArray, pickedNumber, midPoint)) {
			argArray = (int*)realloc(argArray, sizeof(int) * midPoint);
			BinarySearch(pickedNumber, argArray, midPoint);
		}
		else {
			IsLowerThanPickedNumber(argArray, arraySize, pickedNumber, midPoint);
			BinarySearch(pickedNumber, argArray, midPoint);
		}
	}
}
