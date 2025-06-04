#include <stdio.h>
#define MAX 5 // Maximum size of deque

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is full
int isFull()
{
  return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Check if deque is empty
int isEmpty()
{
  return front == -1;
}

// Insert at the front
void insertFront(int x)
{
  if (isFull())
  {
    printf("Deque is full\n");
    return;
  }
  if (front == -1)
  { // First element insertion
    front = rear = 0;
  }
  else if (front == 0)
  {
    front = MAX - 1; // Wrap around
  }
  else
  {
    front--;
  }
  deque[front] = x;
  printf("Inserted %d at front\n", x);
}

// Insert at the rear
void insertRear(int x)
{
  if (isFull())
  {
    printf("Deque is full\n");
    return;
  }
  if (front == -1)
  { // First element insertion
    front = rear = 0;
  }
  else if (rear == MAX - 1)
  {
    rear = 0; // Wrap around
  }
  else
  {
    rear++;
  }
  deque[rear] = x;
  printf("Inserted %d at rear\n", x);
}

// Delete from the front
void deleteFront()
{
  if (isEmpty())
  {
    printf("Deque is empty\n");
    return;
  }
  printf("Deleted %d from front\n", deque[front]);
  if (front == rear)
  { // Deque becomes empty
    front = rear = -1;
  }
  else if (front == MAX - 1)
  {
    front = 0; // Wrap around
  }
  else
  {
    front++;
  }
}

// Delete from the rear
void deleteRear()
{
  if (isEmpty())
  {
    printf("Deque is empty\n");
    return;
  }
  printf("Deleted %d from rear\n", deque[rear]);
  if (front == rear)
  { // Deque becomes empty
    front = rear = -1;
  }
  else if (rear == 0)
  {
    rear = MAX - 1; // Wrap around
  }
  else
  {
    rear--;
  }
}

// Display the deque
void display()
{
  if (isEmpty())
  {
    printf("Deque is empty\n");
    return;
  }
  printf("Deque elements: ");
  int i = front;
  while (1)
  {
    printf("%d ", deque[i]);
    if (i == rear)
      break;
    i = (i + 1) % MAX; // Circular increment
  }
  printf("\n");
}

// Main function to test the deque operations
int main()
{
  insertRear(5);
  insertRear(10);
  display();

  insertFront(15);
  display();

  deleteRear();
  display();

  insertFront(20);
  display();

  deleteFront();
  display();

  return 0;
}
