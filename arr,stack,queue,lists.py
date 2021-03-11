#lists

# arr=[]
# n=10
# i=0
# for i in range(n):
#     e=int(input())
#     arr.append(e)

# print(arr)

# stack as array

# arr=[]
# top=-1
# cont='Y'
# choice='push'
# while cont == 'Y' or cont == 'y':
#     choice = input("Enter choice: ")
#     if choice == 'push':
#         top+=1
#         e=int(input("Enter element: "))
#         print("Pushing {}...".format(e))
#         arr.append(e)
#         print(arr)

#     elif choice == 'pop':
#         if top < 0:
#             print("Underflow!!")

#         else:
#             print("Popping {}".format(arr[top]))
#             arr.pop(top)
#             top-=1
#             print(arr)

#     cont = input("Continue? ")

# print(arr)

#queue as array

# arr=[]
# front=0;rear=-1
# cont='Y'
# choice = "add"
# while cont == 'Y' or cont == 'y':
#     choice = input("Enter choice: ")
#     if choice == "add":
#         e = int(input("Enter element: "))
#         print("Adding...")
#         arr.append(e)
#         rear+=1
#         print(arr)
#     elif choice == "del":
#         if rear <= front:
#             print("Underflow!!")
#         else:
#             print("Deleting")
#             arr.pop(0)
#         print(arr)
#     cont = input("Continue? ")

# print(arr)

#linked list

# class Node:
#     def __init__(self,data=None):
#         self.data = data
#         self.next = None

# first = Node(int(input("Enter first element: ")))
# second = Node(int(input("Enter second element: ")))
# third = Node(int(input("Enter third element: ")))

# first.next = second
# second.next = third
# third.next = None

# n = first
# while n is not None:
#     print(n.data,end=" ")
#     n = n.next

#stack as linked list

# class Node:
#     def __init__(self,data=None):
#         self.data = data
#         self.join = None

# class linkedlist:
#     def __init__(self): 
#         self.top = None #top element

#     def printlist(self):
#         temp = self.top
#         while temp is not None:
#             print(temp.data)
#             temp = temp.join

#     def push(self,data):
#         if self.top is None:
#             self.top = Node(data)
#         else:
#             temp = Node(data)
#             temp.join = self.top
#             self.top = temp
#         self.printlist()

#     def pop(self):
#         if self.top is None:
#             print("Underflow!!")
#         else:
#             self.top = self.top.join
#         self.printlist()

# A = linkedlist()
# cont = 'Y'; choice = "push"
# while(cont == 'Y' or cont == 'y'):
#     choice = input("Enter choice: ")
#     if choice == "push":
#         e=int(input("Enter element: "))
#         A.push(e)
#     elif choice == "pop":
#         A.pop()

#     cont = input("Continue? ")

# A.printlist()

#queue as linked list

# class Node:
#     def __init__(self,data=None):
#         self.data = data
#         self.join = None

# class linkedqueue:
#     def __init__(self):
#         self.front=None
#         self.rear=None
    
#     def printqueue(self):
#         temp = self.front
#         while temp is not None:
#             print(temp.data,end=" ")
#             temp = temp.join
#         print()

#     def add(self,data):
#         if self.front == None:
#             self.front = Node(data)
#             self.rear = self.front
#         else:
#             self.rear.join = Node(data)
#             self.rear = self.rear.join
#         self.printqueue()
    
#     def delete(self):
#         if self.front == None:
#             print("Underflow!!")
#         else:
#             self.front = self.front.join
#         self.printqueue()

# A = linkedqueue()
# cont = 'Y'; choice = "add"
# while(cont == 'Y' or cont == 'y'):
#     choice = input("Enter choice: ")
#     if choice == "add":
#         e=int(input("Enter element: ")); A.add(e)
#     elif choice == "del":
#         A.delete()

#     cont = input("Continue? ")

# A.printqueue()
