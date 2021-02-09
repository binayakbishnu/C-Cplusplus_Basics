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
    *p = 42; //changes value of a as well
    cout<<*p<<" "<<a<<endl;

    int &y = a;
    cout<<y<<endl; //*y not used, only y
    y = 42;
    cout<<y<<endl<<a<<endl; //changes value a as well
    //reference: point to variable, can change value of the pointed,
    //if value changed, still points to original, changes original too
    //cannot be reassigned
    //cannot be null or uninitialised
    //cannot make array of references but array of pointers possible
    //pointer to refernece or reference of reference not possible
    //(helpful in functions)
    //reference equivalent to alias of variable and used like the variable
    //memory also shared
    //no de-reference required (pointers need de-reference: cout<<*p)


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

    //float types also vary system to system
    //float: 32bits (not always)
    //double float: 2x of float
    //long double float: 2x of double float
        //(==128 but 80bits memory used due to IEEE standards)
    
    //character array take length + 1 space due to terminating 0

    char ch1[] = "String1";
    //char *ch2 = "String2"; //gives error
    const char *ch2 = "String2";
    //Note: pointer to const char not a const pointer itself
    cout<<ch1<<endl<<ch2<<endl;
    ch2 = "String3";
    cout<<ch2<<endl;
    //therefore proved pointer is not constant,
    //can be changed to point something else
    //However...
    const char *const ch3 = "String3"; //pointer also constant
    //ch3 = "String4"; //gives error
    
    //contatenating while initialisation
    const char* ch = "String" "is" "fun";
    cout<<ch<<endl;

    //char escape sequences
    //cout<<"Hello World""; //error since 2nd quote completes literal
    cout<<"Hello World \""; //second quote printed as part literal
    //third quote completes literal
    // '\' is the escape sequence
    cout<<"Hello\nWorld"; //here it PREVENTS n from being part of literal
    //for newline

    //qualifiers
    //1. CV: 
    //const - immutable/read-only
    //volatile - maybe changed by another process (used for threaded code)
    //mutable - can be changed
    //2. Storage duration: (lifetime of variable)
    //static - these variable live for whole program not just the block
    //even if declared in class, stored globally
    //by default variable declared outside all blocks are static 
    //register - stored in process register, faster and easy to access
    //extern - defined separately and linked to code by linker step
    
    //without static ->
    //declare a function which initialises a variable, increments by 1 then returns it
    //run multiple times
    //each time value same 
    //with static ->
    //all same exceot declare variable as static integer
    //now each time value different
    //ignores initialisation after first one

    //now if same thing done in class function
    //all objects of class share same static variable
    //static member is =0
    //if 1st obj declared, value of static member increased
    //second obj declared, value of static member increased
    //third obj declared, value of static member printed
    //value shown =2 not 0
    
    //very helpful to count number of objects of a class declared
    //since value of static member not reset
    return 0;
}