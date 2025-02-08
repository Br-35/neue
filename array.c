#include <stdio.h>

int main () {
	int a[5] = {10, 20, 30, 40, 50};
	printf("%s %12s\n", "Address", "Value");
	
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%p %d\n", &a[i], a[i]);
	
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%p %d\n", (a + i), *(a + i));
}