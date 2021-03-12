#include <stdio.h>

int prime(int a)
{
    int ip = 0;
    int flag = 0;
    for (ip = 2; ip <= (a / 2); ip++)
    {
        //printf("ip=%d\n",ip);
        if (a % ip == 0)
        {
            //printf("%d",a%ip);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int number;
    int flag2 = 0;
    printf("Enter number: ");
    scanf("%d", &number);
    //printf("%d ",number);
    int result = 0;

    while (number > 0)
    {
        result = prime(number);
        //printf("Number is %d",result);
        number = number / 10;
        //printf("result=%d ",result);
        if (result == 0)
        {
            flag2 = 1;
        }
    }
    if (flag2 == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
