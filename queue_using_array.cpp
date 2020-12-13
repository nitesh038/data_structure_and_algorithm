#include<iostream>

struct queue
{
    int size;
    int *arr;
    int front;
    int rear;
};
bool isEmpty(queue* q)
{
    if(q->front == q->rear)
        return true;

    return false;
}

bool isFull(queue* q)
{
    if(q->rear > (q->size-1))
        return true;

    return false;
}

void enqueue(queue* q, int data)
{
    if(isFull(q))
    {
        std::cout<< "Queue overflow";
        return;
    }

    q->arr[++q->rear] = data;
}

int dequeue(queue* q)
{
    if(isEmpty(q))
    {
        std::cout<<"\nQueue underflow";
        return -1;
    }
    int popped_element = q->arr[++q->front];
    
    return popped_element;
}

void display(queue q)
{
    std::cout<< "Elements in the Queue are: \n";
    while(q.front != q.rear)
    {
        std::cout << q.arr[++q.front] << std::endl;
    }
}

int main()
{
    struct queue q;
    std::cout<< "Enter the size of Queue: ";
    std::cin >> q.size;
    q.arr = new int[q.size];
    q.front = -1; 
    q.rear = -1;
    int data{};
    int position{};
    char ch{};
    while(ch!='4')
    {
        std::cout << "Press 1 to Enqueue an element .. 2 to Deque an element .... 3 to display and 4 to exit\n";
        std::cin >> ch;
        switch (ch)
        {
        case '1':  std::cout<< "\nEnter the element to enqueue to Queue: \n";
                   std::cin >> data;    
                   enqueue(&q, data);
            /* code */
            break;
        case '2':  std::cout<< "Dequeued element is: " << dequeue(&q) << std::endl;
                   break;

        case '3': display(q);
                  break;  
        case '4': break;

        default:
                std::cout<< "Wrong Input provided\n";
            break;
        }
    }
        
    return 0;
}