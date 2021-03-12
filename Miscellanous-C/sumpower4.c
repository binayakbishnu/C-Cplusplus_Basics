#include <stdio.h>
#include <math.h>

int check(int a)
{
    int s=0;
    int temp=a;
    while(temp>0)
    {
        int digit = temp%10;
        s+=pow(digit,4);
        temp=temp/10;
    }
    if (s==a)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int l=0,u=0;
    printf("Lower limit: ");
    scanf("%d",&l);
    printf("Upper limit: ");
    scanf("%d",&u);
    
    int arr[u-l+1];
    int x=0,result=0;
    
    int i=0;
    for (i=l;i<u;i++)
    {   
        result = check(i);
        if (result==1)
        {
            arr[x++]=i;
        }
    }
    for (i=0;i<x-1;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("%d",arr[x-1]);
    
    return 0;
}
