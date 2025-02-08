#include <stdio.h>

/* 
	Maximum function gets the array index 
	containing the largest int value in an array
	@param A[] array
	@param n array size
	@param i increment
	@param max index of greatest val
	@param indexVal val inside index
	@return max 
*/
int Maximum (int A[], int n) {
	int i, max, indexVal;
	max = 0;
	indexVal = A[0];
	
	for (i = 0; i < n; i++) {
		if (A[i] > indexVal) {
			max = i;
		}
		indexVal = A[i];
	}
		
	return max;
}

int main () {
	int A[5] = {2, 3, 5, 6, 1};
	int n = sizeof(A)/sizeof(A[0]);
	
	printf("%d", n);
	printf("%d", Maximum (A, n));
}
