#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GetArraySize(int *arraySize);

int* CreateArray(int arraySize);

bool IsEqualToPickedNumber(int* argArray, int pickedNumber, int midPoint);

bool IsHigherThanPickedNumber(int* argArray, int pickedNumber, int midPoint);

void IsLowerThanPickedNumber(int* argArray, int arraySize, int pickedNumber, int midPoint);

int BinarySearch(int pickedNumber, int* argArray, int arraySize);

int main() {

	int array_size;
	GetArraySize(&array_size);
	
	int* array = CreateArray(array_size);
	
	printf("Generated array:\n");
	for (int i = 0; i < array_size; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
	
	printf("Select number from array to get its index:\n");
	int picked_number;
	scanf("%d", &picked_number);

	picked_number = BinarySearch(picked_number, array, array_size); // here we overwrite value of picked number to store position of it in array
	printf("position in array: %d\n", picked_number);

	return 0;
}

void GetArraySize(int *arraySize) {
	*arraySize = 9;
}

int* CreateArray(int arraySize) {
	int* array = (int*)malloc(arraySize * sizeof(int));
	
	if (array != NULL) {
		for (int i = 0; i < arraySize; i++) {
			array[i] = (i-1)*2+5;
		}
	}

	return array;
}

bool IsEqualToPickedNumber(int* argArray, int pickedNumber, int midPoint) {
	return (argArray[midPoint] == pickedNumber);
}

bool IsHigherThanPickedNumber(int* argArray, int pickedNumber, int midPoint) {
	return (argArray[midPoint] > pickedNumber);
}

void IsLowerThanPickedNumber(int* argArray, int arraySize, int pickedNumber, int midPoint) {
	int* helper_array = (int*)malloc(arraySize * sizeof(int));
	
	if (helper_array != NULL) {
		for (int i = 0; i < arraySize; i++) {
			helper_array[i] = argArray[i];
		}
	}

	argArray = (int*)realloc(argArray, sizeof(int)*midPoint);

	if (argArray != NULL && helper_array != NULL) {
		for (int i = 0; i < midPoint; i++) {
			argArray[i] = helper_array[i + midPoint];
		}
	}
}

int BinarySearch(int pickedNumber, int* argArray, int arraySize) {

	int midPoint = floor(arraySize / 2);
	
	if (IsEqualToPickedNumber(argArray, pickedNumber, midPoint)) {
		int array_size;
		GetArraySize(&array_size);
		int* array = CreateArray(array_size);
		for (int i = 0; i < array_size; i++) {
			if (array[i] == argArray[midPoint]) {
				return i;
			}
		}
	}
	else if (midPoint == 0) {
		int array_size;
		GetArraySize(&array_size);
		int* array = CreateArray(array_size);
		for (int i = 0; i < array_size+1; i++) {
			if (array[i] == argArray[midPoint]) {
				return i+1;
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
