#include <iostream>
using namespace std;
#define SIZE 5
// Circular Queue class using fixed-size Array
class CircularQueue {
private:
   int arr[SIZE];
   int front;
   int rear;
public:
   CircularQueue() {
       front = -1;
       rear = -1;
   }
   // Check if the Circular Queue is full
   bool isFull() {
       if ((rear + 1) % SIZE == front) {
           return true;
       }
       return false;
   }
   // Check if the Circular Queue is empty
   bool isEmpty() {
       if (front == -1) {
           return true;
       }
       return false;
   }
   // a) Insertion (Enqueue) operation
   void enqueue(int val) {
       if (isFull()) {
           cout << "Queue Overflow! Cannot insert " << val << endl;
           return;
       }
       if (isEmpty()) {

           front = 0;
           rear = 0;
       }
       else {
           rear = (rear + 1) % SIZE;
       }
       arr[rear] = val;
       cout << "Enqueued: " << val << endl;
   }
   // b) Deletion (Dequeue) operation
   void dequeue() {
       if (isEmpty()) {
           cout << "Queue Underflow! Queue is Empty" << endl;
           return;
       }
       int deletedVal = arr[front];
       cout << "Dequeued: " << deletedVal << endl;
       if (front == rear) {
           // Queue has only one element, reset pointers
           front = -1;
           rear = -1;
       }
       else {
           front = (front + 1) % SIZE;
       }
   }
   // c) Display all elements in the Circular Queue
   void display() {
       if (isEmpty()) {
           cout << "Circular Queue is Empty" << endl;
           return;
       }
       cout << "Circular Queue Elements: ";
       int i = front;
       while (true) {
           cout << arr[i] << " ";
           if (i == rear) {
               break;

           }
           i = (i + 1) % SIZE;
       }
       cout << endl;
   }
};
int main() {
   CircularQueue cq;
   // Insert 5 elements to fill the queue
   cq.enqueue(10);
   cq.enqueue(20);
   cq.enqueue(30);
   cq.enqueue(40);
   cq.enqueue(50);
   cq.display();
   // Attempt insertion when queue is full
   cq.enqueue(60);
   // Delete 2 elements from the front
   cq.dequeue();
   cq.dequeue();
   cq.display();
   // Insert elements using circular wrap-around
   cq.enqueue(60);
   cq.enqueue(70);
   cq.display();
   return 0;
}
