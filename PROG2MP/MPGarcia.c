#include <stdio.h>
//display WIP Options
void displayOptions () {
	typedef char Str64 [65];
	
	Str64 options [12] = {
		"Show Pokemon Types",
		"Add New Pokemon Entry",
		"Display Complete Pokedex Chart",
		"Display Complete Pokedex Table",
		"Sort and Display Pokedex Table Based on Stats",
		"Search Pokemon", 
		"Edit Pokemon",
		"Delete Pokemon",
		"Simulate Level Up",
		"Simulate Battle",
		"Display Battle Details",
		"Exit"
	};
	
	printf("Welcome to the Pokedex!\n");
	printf("****\n");
	for (int i = 0; i < 12; i++) {
		printf("%d. %s", i + 1, options[i]);
		printf("\n");
	}
	printf("Enter no. of choice: ");
}

int main () {
	displayOptions();
}