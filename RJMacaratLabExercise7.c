#include <stdio.h>
#include <string.h>
// function declarations
void displayPseudoternary(int bits[], int size);
void displayManchester(int bits[], int size);
void displayDiffManchester(int bits[], int size);

// string values as globals
char top_left[] = "┌";
char top_right[] = "┐";
char bottom_right[] = "┘";
char bottom_left[] = "└";
char horizontal[] = "─";
char vertical[] = "│";
char space[] = " ";

int main()
{

    int size;
    // prompt user to input bit size
    printf("\nInput bit size: ");
    scanf("%d", &size);

    int bits[size];
    printf("\nInput bits(separate each with space):\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &bits[i]);

    // signal encoding Pseudoternary
    printf("\nNRZ-L encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayPseudoternary(bits, size);

    // signal encoding Manchester
    printf("\nNRZ-I encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayManchester(bits, size);

    // signal encoding Differential Manchester
    printf("\nBPMI encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayDiffManchester(bits, size);
    printf("\n");

    return 0;
}