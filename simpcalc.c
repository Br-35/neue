#include <stdio.h>

int main () {
    float input1, input2, output;
    char op;

    printf("Input a number: ");
    scanf("%f", &input1);

    printf("Choose op (+ - * or /): ");
    scanf("%c", &op);
    scanf("%c", &op);

    switch (op) {
        case '+': op = 0; break;
        case '-': op = 1; break;
        case '*': op = 2; break;
        case '/': op = 3; break;
    }

    printf("Input 2nd number: ");
    scanf("%f", &input2);

    switch (op) {
        case 0: output = input1 + input2; break;
        case 1: output = input1 - input2; break;
        case 2: output = input1 * input2; break;
        case 3: output = input1 / input2; break;
    }

    printf("%.2f", output);
}