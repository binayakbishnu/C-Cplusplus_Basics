#include <iostream>

using namespace std;

//arrays

// #define s 10
// int main()
// {
//     int arr[s];
//     int i;
//     for (i = 0; i < s; i++)
//     {
//         int e;
//         cin>>e;
//         arr[i]=e;
//     }
//     for (i = 0; i< s-1; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<arr[i];
//     return 0;
// }

//stack as array

// void printarray(int arr[],int t){cout<<"|";
//     for (int i = 0;i<t-1;i++){cout<<arr[i]<<",";}
//     cout<<arr[t-1]<<"|\n";}
// #define s 10
// int main(){
//     int arr[s];
//     int top = -1;
//     char cont = 'Y';
//     char choice = 'a';
//     while (cont == 'Y' || cont == 'y'){
//         cout<<"Enter choice:"; cin>>choice;
//         if (choice == 'a'){
//             if (top == s-1)
//                 cout<<"Overflow!!\n";
//             else{
//                 top++;
//                 int e=0;
//                 cout<<"Enter element: "; cin>>e;
//                 cout<<"Pushing "<<e<<"...\n";
//                 arr[top]=e;
//                 printarray(arr,top+1);
//             }
//         }
//         else if (choice == 'b'){
//             if (top < 0)
//                 cout<<"Underflow!!\n";
//             else{
//                 cout<<"Popping "<<arr[top]<<"...\n";
//                 top--;
//                 printarray(arr,top+1);
//             }
//         }
//         cout<<"Continue? "; cin>>cont;
//     }
//     printarray(arr,top+1);
//     return 0;
// }

//queue as array

// void printarray(int arr[],int t){
//     cout<<"|";
//     for (int i = 0;i<t-1;i++)
//          {cout<<arr[i]<<",";}
//     cout<<arr[t-1]<<"|\n";
// }
// #define s 10
// int main()
// {
//     int arr[s];
//     int front=0, rear=-1;
//     char cont='Y';
//     char choice = 'a';
//     while (cont=='Y' || cont == 'y'){
//         cout<<"Enter choice: "; cin>>choice;
//         if (choice == 'a'){ //add
//             if (rear == s-1)
//                 cout<<"Overflow!!\n";
//             else{
//                 int e;
//                 cout<<"Enter element: "; cin>>e;
//                 rear++;
//                 cout<<"Adding...\n"; arr[rear]=e; }
//             printarray(arr,rear+1);
//         }
//         else if (choice == 'b'){
//             if (rear <= front)
//                 cout<<"Underflow!!";
//             else{
//                 cout<<"Deleting...\n";
//                 for (int x = 0; x < rear; x++)
//                     arr[x] = arr[x+1];
//                 rear--; }
//             printarray(arr,rear+1);
//         }
//         cout<<"Continue? "; cin>>cont;
//     }
//     printarray(arr,rear+1);    
//     return 0;
// }

//linked list

// class Node
// {
//     public:
//         int info;
//         Node *next;
// };
// int main()
// {
//     Node *first = NULL;
//     Node *second = NULL;
//     Node *third = NULL;
//     first = new Node();
//     second = new Node();
//     third = new Node();
//     cout<<"Enter first element: "; cin>>first->info;
//     first->next= second;
//     cout<<"Enter second element: "; cin>>second->info;
//     second->next= third;
//     cout<<"Enter third element: "; cin>>third->info;
//     third->next=NULL;
//     Node *n=first;
//     while (n!=NULL)
//     {
//         cout<<n->info<<" ";
//         n=n->next;
//     }
//     return 0;
// }

//stack as linked list

// class Node{public: int data; Node *join; }; Node *top=NULL;
// void printlist(){
//     Node* temp; temp = top;
//     cout<<"Stack:";
//     while (temp!=NULL){
//         cout<<temp->data<<"\n";
//         temp = temp->join;
//     }cout<<"\n";
// }
// void push(int data){
//     Node* temp; 
//     temp = new Node();
//     if(!temp){
//         cout<<"Overflowed heap!!";
//         exit(1);}
//     temp->data = data;
//     temp->join = top;
//     top = temp;
//     printlist();
//     }
// void pop(){   
//     Node* temp; 
//     if (top == NULL){
//         cout<<"Underflow!!";
//         exit(1);}
//     temp = top;
//     top = top->join;
//     temp->join = NULL; //disconnection
//     free(temp);  //deletion from memory
//     printlist();
//     }
// int main()
// {
//     char cont = 'Y', choice ='a';
//     while(cont == 'y' || cont == 'Y'){
//         cout<<"Enter choice: "; cin>>choice;
//         if (choice == 'a'){
//             int e; cout<<"Enter element: "; cin>>e; push(e);}
//         else if (choice == 'b') pop();
//         cout<<"Continue? "; cin>>cont;
//     }
//     printlist();
//     return 0;
// }

//queue as linked list

// class Node{public: int data; Node *join;};
// class Queue{public: Node *front,*rear;
//     Queue(){front=rear=NULL;}
//     ~Queue();
//     void add(int data);
//     void del();
//     void printqueue();
// };
// void Queue::printqueue(){
//     if (front==NULL)
//     {cout<<"Underflow!!";
//     exit(1);}
//     Node *temp; temp = front;
// 	while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->join;
//     }cout<<"\n";
// }
// void Queue::add(int data){
//     Node *temp; temp = new Node();
//     if (temp==NULL)
//     {cout<<"Overflow heap!!!"; exit(1);}
//     cout<<"Adding...\n";
//     temp->data = data; temp->join=NULL; //extra since old points to new
//     if (front == NULL)
//     {front = rear = temp;}//1 element
//     else{
//     rear->join = temp; //older element points to new element
//     //rear older element above
//     rear = temp;} //rear assigned to newer element
//     printqueue();
// }
// void Queue::del(){
//     if (front == NULL){cout<<"Underflow!!!";exit(1);}
//     cout<<"Deleting...\n";
//     if (front == rear)
//     {front =rear =NULL;} //1 element
//     else
//     {front = front ->join;} //no need to disconnect
//     //since destructor used
//     printqueue();
// }
// Queue ::~Queue(){
//     while(front!=NULL){
//         Node *temp=front;
//         front=front->join;
//         delete temp;
//     }
//     rear=NULL;
// }

// int main()
// {
//     Queue A;
//     char cont = 'Y'; char choice = 'a';
//     while(cont == 'y' || cont == 'Y'){
//     	cout<<"Enter choice: "; cin>>choice;
//     	if (choice == 'a'){
//     		int e;
//     		cout<<"Enter element: "; cin>>e;
//     		A.add(e);
// 		}
// 		else if (choice == 'b'){
// 			A.del();
// 		}
// 		cout<<"Continue? "; cin>>cont;
// 	}
//     cout<<endl;
//     A.printqueue();
//     return 0;
// }
