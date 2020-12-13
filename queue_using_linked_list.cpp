#include<iostream>

struct Node
{
    int data;
    struct Node* next;
};

bool isEmpty(struct Node* front)
{
    if(front==NULL)
        return true;

    return false;
}

bool isFull(struct Node* rear)
{
    if(rear == NULL)
        return true;

    return false;
}

void enqueue(struct Node** rear, struct Node** front, int data)
{
    struct Node* p = new Node;
    if(isFull(p))
    {
        std::cout<<"Stack Overflow\n";
        return;
    }
    
    p->data = data;
    p->next = NULL;

    if(*front==NULL) // first NODE though it could have been rear == NULL also
    {
        *front = *rear = p;
    }
    else
    {
        (*rear)->next = p;
        *rear = p;
    }
}
int dequeue(struct Node** front)
{
    if(isEmpty(*front))
    {
        std::cout<< "Stack Underflow\n";
        return -1;
    }
    int dequeued_element = (*front)->data;
    *front = (*front)->next;
    return dequeued_element;
}
void display(struct Node* front)
{
    std::cout<<"Elements in the queue are: \n";
    while(front!=NULL)
    {
        std::cout<<front->data << std::endl;
        front = front->next;
    }
}

int main()
{
    struct Node* q = NULL;
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int data{};
    char ch{};
    while(ch!='4')
    {
        std::cout << "Press 1 to Enqueue an element .. 2 to Deque an element .... 3 to display and 4 to exit\n";
        std::cin >> ch;
        switch (ch)
        {
        case '1':  std::cout<< "\nEnter the element to enqueue to Queue: \n";
                   std::cin >> data;    
                   enqueue(&rear, &front, data);
            /* code */
            break;
        case '2':  std::cout<< "Dequeued element is: " << dequeue(&front) << std::endl;
                   break;

        case '3': display(front);
                  break;  
        case '4': break;

        default:
                std::cout<< "Wrong Input provided\n";
            break;
        }
    }
    return 0;
}
