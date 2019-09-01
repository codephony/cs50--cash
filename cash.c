#include <cs50.h>
#include <math.h>
#include <stdio.h>

float askPositiveFloat(void)
{
    // Ask user for double
    float positiveFloat;
    // negative until proven positive, basically a switch we turn on and off
    bool negative = true;
    //Loops the question until you give me a good answer
    while (negative)
    {
        // Get_float will automatically filter out non decimal numbers but doesn't filter out negatives
        positiveFloat = get_float("Change owed: ");
        
        // Check for negative
        if (positiveFloat > 0)
        {
            // Set to false if our number is positive
            negative = false;
        }
    }
    // As promised, we return the float positiveFloat
    return positiveFloat;
}

// This function will perform the tracking of coins we've counted and return it as an integer
int coinNum()
{
    // Gets user input and turns it into number of total cents, we're told to round with a function from math.h
    int totalCents = round(askPositiveFloat() * 100);
    // Declare variable to store coin count.
    int numOfCoins = 0;
    // Declare variable for remainder storage.
    int remainder;
    //Declare variable for temporary number for division.
    int tempNum;
    // Declare variables to store coin values.
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // we'll just cascade down a list of coins from biggest to smallest, all with basically the same formula
    
    // if totalCents is greater than OR EQUAL TO the value of a quarter
    if (totalCents >= quarter)
    {
        // We use modular math to see how many quarters fit into our totalCents, this will store the leftovers into our remainder variable aka remainder is 16 = 41 % 25
        remainder = totalCents % quarter;
        // Here we make a temporary variable that stores the cent value of the quarters we end up using to cover the totalCents without going over the totalCents amount
        tempNum = totalCents - remainder;
        // Then we divide the tempNum by our quarter value to get the number of coins aka 0 + 75 / 25 = 3 coins, and then we add it to our numofCoins tracking number
        numOfCoins = numOfCoins + (tempNum / quarter);
        // Here we can set our totalCents as equal to our remainder since we are finished with this step
        totalCents = remainder;
    }
    // For the next coins we can safely check for them and use the same formula in sequence until the end of the function
    if (totalCents >= dime)
    {
        remainder = totalCents % dime;
        tempNum = totalCents - remainder;
        numOfCoins = numOfCoins + (tempNum / dime);
        totalCents = remainder;
    }
    if (totalCents >= nickel)
    {
        remainder = totalCents % nickel;
        tempNum = totalCents - remainder;
        numOfCoins = numOfCoins + (tempNum / nickel);
        totalCents = remainder;
    }
    if (totalCents >= penny)
    {
        remainder = totalCents % penny;
        tempNum = totalCents - remainder;
        numOfCoins = numOfCoins + (tempNum / penny);
        totalCents = remainder;
    }
    // as promised we return an integer of numOfCoins
    return numOfCoins;
    
}

int main(void)
{
    // we can use the printf function and call coinNum() within the function itself
    printf("%i\n", coinNum());
}
