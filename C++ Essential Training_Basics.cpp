#include <iostream>

using namespace std;
//expression returns value
//statement equivalent to line of code and part of execution context
//a statement can also be an expression--
int main()
{
    //int x;
    //printf('%d',x=42);
    
    int a = 10;
    int *p = &a;
    cout<<a<<endl;  //returns value of a
    cout<<&a<<endl; //returns memory location of a
    cout<<p<<endl;  //returns value of p == memory location of a
    cout<<&p<<endl; //returns memory location of p
    cout<<*p<<endl; //returns value of a pointed by p

    int &y = a;
    cout<<y<<endl; //*y not used, only y
    y = 42;
    cout<<y<<endl<<a<<endl; //changes a as well
    //pointers: point to variable, cannot change value of the pointed,
    //if value of pointer changed, pints to different location/variable
    //can be used to changes variable that is pointed without declaring new pointer
    //reference: point to variable, can change value of the pointed,
    //if value changed, still points to original, changes original too
    //cannot be reassigned
    //(helpful in functions)

    //primitive array type also, C-Array
    int arr[5];
    arr[0]=1; arr[1]=11; arr[2]=21;
    cout<<arr[0]<<endl;
    *arr = 2; //array equivalent to pointer
    cout<<arr[0]<<endl;
    
    int *pp = arr; // don't need & since arr is like
                    //a pointer pointing to an address
    *pp = 8; //changes value of variable pointed by it
                //== pointed by arr == first element
    cout<<arr[0]<<endl;
    pp++;
    cout<<*pp<<endl;
    *(++pp) = 23; //changed arr[2] to 23
    cout<<arr[2]<<endl;

    char ch[] = "Strings";
    for (int i = 0;ch[i]!=0;i++)
    {cout<<ch[i]<<endl;}
    for (char *j = ch;*j;j++)
    {cout<<*j<<endl;}

    //special type of for loop only in C++: Range based for loop
    cout<<3<<endl;
    cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<endl;
    for (int k : arr)
    {
        cout<<k<<endl;
    }
    //form C++11->
    for (int k : ch)
    {
        if (k==0) break; //or else last null character printed
        
        cout<<k<<endl;
    }

    //a union is used for overlapping data types;
    //looks similiar to struct but overlapping;
    //data type depends on initialisation

    int x = -'A';
    int y = 'B';
    cout<<x<<" "<<y;
    //char, uchar, short, ushort, int, uint, long, ulong, long long
    //are all integer types
    //'u' means only positive values
    //above type sizes may vary system to system
    //but relatively constants
    //long is either = or 2x range of integer
    //long long is either = or 2x range of long
    
    //for specific ranges independent of system
    //header file: cstdint
    //int8_t, int16_t, int32_t, int64_t

    return 0;
}