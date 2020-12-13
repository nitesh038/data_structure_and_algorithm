//Important Link - https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/

#include<iostream>

struct Node
{
    int data;
    struct Node* next;
};

bool isEmpty(struct Node* top)
{
    if(top==NULL)
        return true;

    return false;
}

bool isFull(struct Node* t)
{
    if(t==NULL)
        return true;

    return false;
}

void push(struct Node** top, int data)
{
    struct Node *t = new Node;
    if(isFull(t))    
    {
        std::cout<<"Stack Overflow\n";
        delete t;
        t=nullptr;
        return ;
    }

    t->data = data;
    t->next = *top;
    *top=t;
}

int pop(struct Node** top)
{
    struct Node *t = new Node;
    if(isEmpty(*top))
    {
        std::cout<<"Stack Underflow\n";
        return -1;
    }
    t = *top;
    *top = (*top)->next;
    int popped_element = t->data;
    delete t;
    t = nullptr;
    return popped_element;
}
void display(struct Node* top)
{
    struct Node* p = top;
    std::cout<< "Elements in the stack are: \n";
    while(p!=NULL)
    {
        std::cout<<p->data<<std::endl;
        p=p->next;
    }

}

int peek(Node* top, int pos)
{
    Node* t = top;
    for(int counter=0; counter < pos-1 && t != NULL; counter++ )
        t = t->next;

    if(t!=NULL)
        return t->data;
    else
        return -1;
}

int main()
{
    struct Node* top = NULL;
    char ch{};
    int data{};
    int position{};
    while(ch!='5')
    {
        std::cout << "Press 1 to Push an element .. 2 to Pop an element .... 3 to Peek and 4 to display  and 5 to exit\n";
        std::cin >> ch;
        switch (ch)
        {
        case '1':  std::cout<< "\nEnter the element to push to stack: \n";
                   std::cin >> data;    
                   push(&top, data);
                   break;
        
        case '2':  std::cout<< "Popped element is: " << pop(&top) << std::endl;
                   break;

        case '3':  std::cout<< "\nEnter the Position to Peek: \n";
                   std::cin >> position;
                   std::cout<< "Peeked Element is: " << peek(top, position) << std::endl;
                   break;  

        
        case '4':  display(top);
                   break;  
        
        case '5':  break;  
        
        default:
                std::cout<< "Wrong Input provided\n";
            break;
        }
    }
    return 0;
}