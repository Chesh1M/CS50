#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt for height of tower
    do {
        height = get_int("Height of pyramid?: ");
    } while (height < 1 || height > 8);

    int level = 1;

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < height - level; y++) {
            printf(" ");
        }
        for (int z = 0; z < level; z++) {
            printf("#");
        }
        level++;
        printf("\n");
    }
}