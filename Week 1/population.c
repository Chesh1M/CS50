#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int starting_population;
    int ending_population;
    int new_llamas;
    int dead_llamas;
    int years = 0;

    //Ask for the initial size for the population

    do
    {
        starting_population = get_int("Please enter a starting population size: ");
    } while (starting_population < 9);

    //Ask for the end size for the population

    do
    {
        ending_population = get_int("Please enter an ending population size:");
    } while (ending_population < starting_population);

    // Calculate number of years until we reach threshold
    int new_population = starting_population;

    while (new_population < ending_population)
    {
        new_llamas = new_population / 3;
        dead_llamas = new_population / 4;
        new_population = new_population + new_llamas - dead_llamas;
        years++;
    }

    // Print number of years
    printf("Years: %d\n", years);
}