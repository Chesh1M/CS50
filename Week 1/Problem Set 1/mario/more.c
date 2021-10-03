#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt for height of tower
    do {
        height = get_int("Height of pyramid?: ");
    } while (height < 1 || height > 8); // Keep repeating prompt if input is not an integer within 1 to 8


    int level = 1; // Variable to represent which level the loop is currently on (counting from the top)

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < height - level; y++) { // Print spaces (number of spaces needed is height - level)
            printf(" ");
        }
        for (int z = 0; z < level; z++) { // Print # (corresponds with level the loop is currently on)
            printf("#");
        }
        
        printf("  "); // Prints the required 2 spaces
        
        for (int z = 0; z < level; z++) { // Print # again (Since number of # required is the same as before, use the same loop again)
            printf("#");
        }
        level++; // Move on to the next level
        printf("\n");
    }
}