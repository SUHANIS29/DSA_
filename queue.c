\ //implemet queue
#include <stdio.h>
#define max 5
    int a[max];
int val, op, i, front = -1, rear = -1;
void enqueue();
void dequeue();
void display();
int main()
{
  while (1)
  {
    printf("Select operation\n");
    printf("1.Insert\n2.delete\n3.dispaly\n4.exit\n");
    scanf("%d", &op);
    if (op == 4)
      break;
    switch (op)
    {
    case 1:

      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    }
  }
}
void enqueue()
{
  if (rear == max - 1)
  {
    printf("Q full");
  }
  else
  {
    printf("enter a val:\n");
    scanf("%d", &val);
    front = 0;
    rear++;
    a[rear] = val;
  }
}

void dequeue()
{

  if (front == -1 || rear < front)
  {
    printf("empty");
  }
  else
  {
    printf("del %d", a[front]);
    front++;
  }
}
void display()
{

  for (i = front; i <= rear; i++)
  {
    printf("%d\n", a[i]);
  }
}