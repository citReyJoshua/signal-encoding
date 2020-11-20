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
    printf("\nPseudoternary encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayPseudoternary(bits, size);

    // signal encoding Manchester
    printf("\nManchester encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayManchester(bits, size);

    // signal encoding Differential Manchester
    printf("\nDifferential Manchester encoding\n");
    for (int i = 0; i < size; i++)
        printf("%d ", bits[i]);
    displayDiffManchester(bits, size);
    printf("\n");

    return 0;
}

void displayPseudoternary(int bits[], int size)
{
    char *to_print = space;
    int pos_state = 0;

    // first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? horizontal : space;
        }
        else
            to_print = space;

        printf("%s", to_print);

        if (i < size - 1)
        {
            if (to_print == horizontal)
                printf("%s", top_right);
            else
            {
                if (pos_state)
                    printf("%s", space);
                else
                    printf("%s", !bits[i + 1] ? top_left : space);
            }
        }
    }

    // second row
    pos_state = 0;
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!bits[i])
        {
            pos_state = !pos_state;
            to_print = space;
        }
        else
            to_print = horizontal;

        printf("%s", to_print);

        if (i < size - 1)
        {
            if (!bits[i])
            {
                if (bits[i + 1])
                    printf("%s", pos_state ? bottom_left : top_left);
                else
                    printf("%s", vertical);
            }
            else
            {
                if (!bits[i + 1])
                    printf("%s", pos_state ? top_right : bottom_right);
                else
                    printf("%s", horizontal);
            }
        }
    }

    // third row
    pos_state = 0;
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (!bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? space : horizontal;
        }
        else
            to_print = space;

        printf("%s", to_print);

        if (i < size - 1)
        {
            if (to_print == horizontal)
                printf("%s", bottom_right);
            else
            {
                if (pos_state)
                    printf("%s", !bits[i + 1] ? bottom_left : space);
                else
                    printf("%s", space);
            }
        }
    }
}

void displayManchester(int bits[], int size)
{
    // first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", bits[i] ? top_left : top_right);

        if (i < size - 1)
        {
            if (bits[i])
                printf("%s", bits[i + 1] ? top_right : horizontal);
            else
                printf("%s", bits[i + 1] ? space : top_left);
        }
    }

    // second row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", vertical);
        if (i < size - 1)
            printf("%s", bits[i] == bits[i + 1] ? vertical : space);
    }

    // third row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", bits[i] ? bottom_right : bottom_left);

        if (i < size - 1)
        {
            if (bits[i])
                printf("%s", bits[i + 1] ? bottom_left : space);
            else
                printf("%s", bits[i + 1] ? horizontal : bottom_right);
        }
    }
}

void displayDiffManchester(int bits[], int size)
{
    int pos_state = 1;
    char *to_print = bits[0] ? top_right : top_left;

    // first row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? top_right : top_left;
        }

        printf("%s", to_print);

        if (i < size - 1)
        {
            if (pos_state)
                printf("%s", bits[i + 1] ? space : top_left);
            else
                printf("%s", bits[i + 1] ? horizontal : top_right);
        }
    }

    // second row
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", vertical);

        if (i < size - 1)
        {
            printf("%s", !bits[i + 1] ? vertical : space);
        }
    }

    // third row
    pos_state = 1;
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (bits[i])
        {
            pos_state = !pos_state;
            to_print = pos_state ? bottom_left : bottom_right;
        }

        printf("%s", to_print);

        if (i < size - 1)
        {
            if (pos_state)
                printf("%s", bits[i + 1] ? horizontal : bottom_right);
            else
                printf("%s", bits[i + 1] ? space : bottom_left);
        }
    }
}