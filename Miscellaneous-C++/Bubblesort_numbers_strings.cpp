#include <iostream>
#include <string.h>

using namespace std;

int s=5;
void bsort_num(int array[],int size=s)
{
    int i1=0,j1=0;
    for (i1=0;i1<s;i1++)
    {
        for (j1=0;j1<s-i1-1;j1++)
        {
            if (array[j1]>array[j1+1])
            {
                array[j1]=array[j1]+array[j1+1];
                array[j1+1]=array[j1]-array[j1+1];
                array[j1]=array[j1]-array[j1+1];
            }
        }
    }
    for (i1 =0;i1<s;i1++)
    {
        cout<<array[i1]<<" ";
    }
}

void bsort_str(char array[][10],int size=s)
{
    int i1=0,j1=0;
    char temp[10];
    for (i1=0;i1<size;i1++)
    {
        for (j1=0;j1<s-i1-1;j1++)
        {
            if (strcmp(array[j1],array[j1+1])>0)
            {
                strcpy(temp,array[j1]);
                strcpy(array[j1],array[j1+1]);
                strcpy(array[j1+1],temp);
            }
        }
    }
    for (i1 =0;i1<size;i1++)
    {
        cout<<array[i1]<<" ";
    }
}


int main()
{
    cout<<"Numbers:\n";
    int arr[s];
    int i=0;
    for (i =0;i<s;i++)
    {
        cin>>arr[i];
    }
    bsort_num(arr);
    
    cout<<"\n\nStrings:\n";
    char arr2[s][10];
    for (i =0;i<s;i++)
    {
        gets(arr2[i]);
    }
    int len = sizeof(arr2)/sizeof(arr2[0]);
    bsort_str(arr2,len);
    
    return 0;
}