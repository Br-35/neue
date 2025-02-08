#include <stdio.h>   // Include standard input-output library
#include <stdlib.h>  // Include standard library for functions like rand() and system()
#include <time.h>    // Include time library for seeding the random number generator
#include <string.h>  // Include string library for functions like strcpy() and strcmp()

typedef char String[10];  // Define a new type 'String' as an array of 10 characters

void printSpinResults(String matrix[3][3]);
void assignRandomValues(String names[], int namesSize, String matrix[3][3]);
int checkForMatchesAndCalculateMultiplier(String matrix[3][3]);
void calculateAndPrintResult(int bet, int multiplier, int *totalMoney);

int main() {
	int i;
	int j;
	int bet = 1;
    int totalMoney = 100; // Declare and initialize total money
    
    String names[4] = { // Create a 1D array of type String with size 6 indicating the possible faces of the slots machine
        "jack",
		"queen",
		"king",
        "ace"
    };
    String matrix[3][3]; // Create a 2D array of type String with size [3][3] without initialization

    // Initialize the 2D array with empty strings
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            strcpy(matrix[i][j], "");  // Set each element to an empty string
        }
    }
    srand(time(NULL)); // Seed the random number generator

//	printf("********************\n");
//    printf("* Total Money: %-3d *\n", totalMoney);
//    printf("********************\n");
//    printf("Enter your bet: ");
//    scanf("%d", &bet);  // Read bet amount
    
    while (totalMoney > 0) { // Loop as long as total money is greater than 0
        system("cls");  // Clear screen for Windows

        printf("********************\n");
        printf("* Total Money: %-3d *\n", totalMoney);
        printf("********************\n");
        
        assignRandomValues(names, 4, matrix); // Assign random values from names to matrix

        do {
            printf("Enter your bet: ");
            scanf("%d", &bet);  // Read bet amount
            if (bet <= 0 || bet > totalMoney) {
                printf("Invalid bet. Please enter a positive amount up to your total money.\n");  // Validate bet amount
            }
        } while (bet <= 0 || bet > totalMoney);

        // Check for matches and calculate multiplier
        printf("\nChecking for matches:\n");
        int multiplier = checkForMatchesAndCalculateMultiplier(matrix);

        // Print the 2D array with assigned values
        printSpinResults(matrix);

        // Calculate and print the result
        calculateAndPrintResult(bet, multiplier, &totalMoney);

        // Check if the player has run out of money
        if (totalMoney <= 0) {
            printf("You have run out of money. Game over!\n");
        }
        system("pause");  // Pause the game
    }

    return 0;
}

// Function to print the spin results
void printSpinResults(String matrix[3][3]) {
    printf("\nSpin Results:\n");
    printf("+----------+----------+----------+\n");
    for (int i = 0; i < 3; i++) {  // Loop through rows
        for (int j = 0; j < 3; j++) {  // Loop through columns
            printf("| %-8s ", matrix[i][j]);  // Print each element in the matrix
        }
        printf("|\n");
        printf("+----------+----------+----------+\n");
    }
}

// Function to randomly assign values from names to matrix
void assignRandomValues(String names[], int namesSize, String matrix[3][3]) {
    //TODO - Assign random values to the matrix
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
			strcpy(matrix[i][j], names[rand() % namesSize]);
		} 
    }
}


// Function to check for matches in each row and calculate multiplier
int checkForMatchesAndCalculateMultiplier(String matrix[3][3]) {
    int matchCount = 0;  // Initialize match count
    int multiplier = 0; // Initialize multiplier

	//TODO - Determine if the rows have matches
	for (int i = 0; i < 3; i++) {
		if (strcmp(matrix[i][0], matrix[i][1]) + strcmp(matrix[i][0], matrix[i][1]) + strcmp(matrix[i][0], matrix[i][2]) == 0) {
			matchCount += 1;
			printf("Match at row %d, card: %s\n", i + 1, matrix[i][0]);
		}
	}	
	
    //TODO - Determine the multiplier
	switch (matchCount) {
		case 1: multiplier = 5; break;
		case 2: multiplier = 10; break;
		case 3: multiplier = 20; break;
		case 0: multiplier = 0; break;
	}

    return multiplier;  // Return the calculated multiplier
}

// Function to calculate and print the result
void calculateAndPrintResult(int bet, int multiplier, int *totalMoney) {
    int result = bet * multiplier;  // Calculate the result based on bet and multiplier
    if (multiplier > 0) {
    	printf("******************************\n");
        printf("* You win! Your winnings: %-2d *\n", result);  // Print winnings if there is a match
        printf("******************************\n");
        *totalMoney += result;  // Add winnings to total money
    } else {
        printf("No match. Your winnings: 0\n");  // Print no winnings if there is no match
        *totalMoney -= bet;  // Subtract bet from total money
    }
}