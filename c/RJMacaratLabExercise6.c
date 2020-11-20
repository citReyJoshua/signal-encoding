#include <stdio.h>
#include <string.h>
// function declarations
void displayNRZL(int bits[], int size);
void displayNRZI(int bits[], int size);
void displayBPMI(int bits[], int size);

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

    // signal encoding NRZL
    printf("\nNRZ-L encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayNRZL(bits, size);

    // signal encoding NRZI
    printf("\nNRZ-I encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayNRZI(bits, size);

    // signal encoding BPMI
    printf("\nBPMI encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayBPMI(bits, size);
    printf("\n");

    return 0;
}

void displayNRZL(int bits[], int size)
{
    // initial values
    int state_changed = 0; // boolean

    // first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!(i == size - 1))
            state_changed = bits[i] != bits[i + 1];
        else
            state_changed = 0;

        if (bits[i])
            printf("%s", horizontal);
        else
            printf(" ");

        if (state_changed)
        {
            if (bits[i])
                printf("%s", top_right);
            else
                printf("%s", top_left);
        }
        else if (bits[i])
            printf("%s", horizontal);
        else
            printf(" ");
    }

    // second row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!(i == size - 1))
            state_changed = bits[i] != bits[i + 1];
        else
            state_changed = 0;

        printf(" ");

        if (state_changed)
            printf("%s", vertical);
        else
            printf(" ");
    }

    // third row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!(i == size - 1))
            state_changed = bits[i] != bits[i + 1];
        else
            state_changed = 0;

        if (!bits[i])
            printf("%s", horizontal);
        else
            printf(" ");

        if (state_changed)
        {
            if (bits[i])
                printf("%s", bottom_left);
            else
                printf("%s", bottom_right);
        }
        else
        {
            if (!bits[i])
                printf("%s", horizontal);
            else
                printf(" ");
        }
    }
    printf("\n");
}

void displayNRZI(int bits[], int size)
{
    // initial values
    char *to_print = space;
    int state_changed = 0;
    if (bits[0])
        to_print = horizontal;

    // first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", to_print);
        if (i != size - 1)
            state_changed = bits[i + 1] == 1;
        else
            state_changed = 0;

        if (state_changed)
        {
            if (strcmp(to_print, " ") == 0)
            {
                printf("%s", top_left);
                to_print = horizontal;
            }
            else
            {
                printf("%s", top_right);
                to_print = space;
            }
        }
        else
            printf("%s", to_print);
    }

    // second row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", space);
        if (i != size - 1)
            state_changed = bits[i + 1] == 1;
        else
            state_changed = 0;

        if (state_changed)
            printf("%s", vertical);
        else
            printf("%s", space);
    }

    // initializer condition for last row
    to_print = bits[0] ? space : horizontal;

    // last row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", to_print);
        if (i != size - 1)
            state_changed = bits[i + 1] == 1;
        else
            state_changed = 0;

        if (state_changed)
        {
            if (to_print == space)
            {
                printf("%s", bottom_left);
                to_print = horizontal;
            }
            else
            {
                printf("%s", bottom_right);
                to_print = space;
            }
        }
        else
            printf("%s", to_print);
    }

    printf("\n");
}

void displayBPMI(int bits[], int size)
{
    char *to_print = space;
    int pos_state = 0; // 1 means high signal, 0 means low signal

    //first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? horizontal : space;
        }
        else
            to_print = space;

        printf("%s", to_print);

        if (i != size - 1)
        {
            if (to_print == horizontal)
                printf("%s", top_right);
            else
            {
                if (pos_state)
                    printf("%s", space);
                else
                {
                    if (bits[i + 1])
                        printf("%s", top_left);
                    else
                        printf("%s", space);
                }
            }
        }
    }

    // second row
    printf("\n");
    pos_state = 0;
    for (int i = 0; i < size; i++)
    {
        if (bits[i])
        {
            pos_state = !pos_state;
            to_print = space;
        }
        else
            to_print = horizontal;

        printf("%s", to_print);

        if (i != size - 1)
        {
            if (bits[i])
            {
                if (bits[i + 1] == 0)
                    printf("%s", pos_state ? bottom_left : top_left);
                else
                    printf("%s", vertical);
            }
            else
            {
                if (bits[i + 1])
                    printf("%s", pos_state ? top_right : bottom_right);
                else
                    printf("%s", horizontal);
            }
        }
    }

    // third row
    printf("\n");
    pos_state = 0;
    for (int i = 0; i < size; i++)
    {
        if (bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? space : horizontal;
        }
        else
            to_print = space;

        printf("%s", to_print);

        if (i != size - 1)
        {
            if (to_print == horizontal)
                printf("%s", bottom_right);
            else
            {
                if (pos_state)
                    printf("%s", bits[i + 1] ? bottom_left : space);
                else
                    printf("%s", space);
            }
        }
    }
    printf("\n");
}