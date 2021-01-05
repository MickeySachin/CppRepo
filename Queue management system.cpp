// 3rd January 2021
// Queue Management System ( FIFO )

#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
     protected:
          int size, *queue;
     public:
          Queue()
          {
               size = 0;
               queue = new int[100];
          }

          void remove()  // Removing an element from front end of queue
          {
               if(size == 0)
                    cout << "Queue is empty!" << endl;
                    
               for(int i = 0; i < size; i++)
               {
                    queue[i] = queue[i+1];
               }
               size--;
               // cout << "\tRemoved successfully";
          }

          virtual void putData()  // Displaying elements of queue
          {
               if(size == 0)
                    cout << "\tQueue is empty!" << endl;

               cout << "\n\t";
               for(int i = 0; i < size; i++)
               {
                    cout << queue[i];
                    if(i < size-1)
                         cout << " <- ";
               }
               cout << endl;
          }

          void add(int x)  // Adding an element to rear end of queue
          {
               queue[size] = x;  // i.e. queue[0] = x;
               size++;
               // cout << "\n\tAdded successfully";
          }

          friend Queue operator+(Queue &, Queue &);  // Operator overloading using friend func ( Operator func ) 
};

Queue operator+(Queue & a, Queue & b)  // Operator func definition
{
     Queue temp;
     for (int i = 0; i < a.size; i++)
     {
          temp.queue[i] = a.queue[i];
          temp.size++;
     }
     for (int i = 0; i < b.size; i++)
     {
          temp.queue[temp.size] = b.queue[i];
          temp.size++;
     }
     return temp;
}

class Queue2 : public Queue
{
     public:
          void putData()
          {
               if (size == 0)
                    cout << "Queue is empty!" << endl;
               for (int i = 0; i < size; i++)
               {
                    cout << "\n\t" << queue[i];
               }
          }
};

int main()
{
     Queue q1;  // Queue object
     q1.add(1);
     q1.add(2);
     q1.add(3);
     q1.add(4);
     cout << "\n\tq1 elements := ";
     q1.putData();

     q1.remove();
     cout << "\n\tAfter removing front element, q1 elements := ";
     q1.putData();

     Queue q2;
     q2.add(5);
     q2.add(6);
     q2.add(7);
     q2.add(8);
     cout << "\n\tq2 elements := ";
     q2.putData();

     Queue q3;
     q3 = q1 + q2;  // Invoking overloaded + operator 
     cout << "\n\tConcatenated queue q3 := ";
     q3.putData();

     Queue2 q;
     q.add(9);
     q.add(10);
     q.add(11);
     q.add(12);
     cout << "\n\tq3 elements in new-line format :=";
     q.putData();    

     return 0;
}