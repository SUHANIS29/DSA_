#include <stdio.h>
#define max 5

int a[max];
int top = -1;
int i;
int val;

void push();
void pop();
void display();
void peek();
int op;

int main()
{
  printf("Select operation:\n");
  printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");

  while (1)
  {
    scanf("%d", &op);
    if (op == 5)
      break; // Exit if the user selects 5

    switch (op)
    {
    case 1:
      printf("Enter val to add: ");
      scanf("%d", &val);
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    default:
      printf("Invalid option. Please try again.\n");
    }
    printf("Select operation:\n");
    printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
  }

  return 0;
}

void push()
{
  if (top == max - 1)
  {
    printf("Stack is full\n");
  }
  else
  {
    top++;
    a[top] = val;
    printf("%d pushed to stack\n", val);
  }
}

void pop()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Deleted value is %d\n", a[top]);
    top--;
  }
}

void display()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Stack elements:\n");
    for (i = top; i >= 0; i--)
    {
      printf("%d\n", a[i]);
    }
  }
}

void peek()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Top element is %d\n", a[top]);
  }
}
