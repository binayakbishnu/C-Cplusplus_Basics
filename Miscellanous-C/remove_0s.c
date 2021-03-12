#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int newnumber = 0; //to store number after removal
    int i = 0;         //power of 10
    while (number > 0)
    {
        int r = number % 10; //extract last digit
        if (r != 0)
        {
            newnumber += r * (pow(10, i++));
        }
        number = number / 10;
    }

    printf("%d", newnumber);

    return 0;
}