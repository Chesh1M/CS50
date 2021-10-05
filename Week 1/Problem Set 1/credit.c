#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long cc_number;

    // Prompt for credit card number
    do {
        cc_number = get_long_long("Enter your credit card number here: ");
    } while (cc_number < 1);

    // Find card length
    long long card_length = floor(log10(llabs(cc_number))) + 1;

    // Initiate array with size of previously found card length
    long long card_digits[card_length];

    // Fill array with digits of the card number starting from the last array index, as credit card number digits will be found from last to first
    for (int x = card_length - 1; x >= 0; x--) {
        card_digits[x] = cc_number % 10;
        cc_number /= 10;
    }

    // Variables to store the sum of odd/even digits of the credit card number
    long long sum_odd = 0, sum_even = 0;

    // Variable to find the sum of 2 digits of a number if it is 2 digits long
    long long sum_both_digits;

    // Variable to store the sum of odd and even digits after applying Luhn's Algorithm
    long long total_odd_even;

    // Get the sum of odd index values starting from last index of array
    for (int x = card_length - 1; x >= 0; x-=2) {
        sum_odd += card_digits[x];
    }

    // Get the sum of even index values starting from second last index of array
    for (int x = card_length - 2; x >= 0; x-=2) {
        // If digit multiplied by 2 is more than 9, split the number into 2 separate digits and add them to sum_even
        if (2 * card_digits[x] > 9) {
            sum_both_digits = ((2 * card_digits[x]) % 10) + ((2 * card_digits[x]) / 10);
            sum_even += sum_both_digits;
        }
        // If not, digit can be added to sum_even straight away
        else {
            sum_even += 2 * card_digits[x];
        }
    }

    // Sum of all the digits of the credit card using Luhn's Algorithm
    total_odd_even = sum_odd + sum_even;

    // Check if last digit of sum is 0
    if (total_odd_even % 10 == 0) {
        switch(card_digits[0]) {
            // Check AMEX (start with 34/37 and card length of 15)
            case 3:
                if ((card_digits[1] == 4 || card_digits[1] == 7) && (card_length == 15))
                    printf("AMEX\n");
                else
                    printf("INVALID\n");
                break;

            // Check MASTERCARD (start with 51/52/53/54/55 and card length of 16)
            case 5:
                if ((card_digits[1] == 1 || card_digits[1] == 2 || card_digits[1] == 3 || card_digits[1] == 4 || card_digits[1] == 5) && (card_length == 16))
                    printf("MASTERCARD\n");
                else
                    printf("INVALID\n");
                break;

            // Check VISA (start with 4 and card length of 13/16)
            case 4:
                if (card_length == 13 || card_length == 16)
                    printf("VISA\n");
                else
                    printf("INVALID\n");
                break;

            // If last digits is 0 but starting digit is not 3/5/4, print INVALID message
            default:
                printf("INVALID\n");
        }
    }
    // If last digit not 0, print INVALID message
    else {
        printf("INVALID\n");
    }
}