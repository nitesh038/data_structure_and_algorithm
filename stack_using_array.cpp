#include<iostream>
#include<vector>


struct Stack
{
    int top;
    int size;
    int *arr;
};


bool isEmpty(Stack* s)
{
    if(s->top == -1)
        return true;
    
    return false;
}

bool isFull(Stack* s)
{
    if(s->top == s->size-1)
        return true;
    
    return false;
}

int peek(Stack s , int pos)
{
    if(s.top-pos+1 < 0)
    {
        std::cout<<"Invalid Position\n";
        return -1;
    }
    //top-pos+1
    return (s.arr[s.top-pos+1]);
}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        std::cout<< "Stack Underflow\n";
        return -1;
    }

    return s->arr[s->top--];
}

void push(Stack *s, int data)
{
    if(isFull(s))
    {
        std::cout<<"Stack Overflow\n";
        return;
    }
    s->top++;
    s->arr[s->top] = data;
    std::cout<< s->arr[s->top] << " is Pushed\n";
}

int main()
{
    Stack st;;
    std::cout<< "Enter the size of Stack: ";
    std::cin >> st.size;
    st.top = -1; //Empty Stack
    int data{};
    int position{};
    st.arr = new int[st.size];
    char ch{};
    while(1)
    {
        std::cout << "Press 1 to Push an element .. 2 to Pop an element .... 3 to Peek and 4 to exit\n";
        std::cin >> ch;
        switch (ch)
        {
        case '1':  std::cout<< "\nEnter the element to push to stack: \n";
                   std::cin >> data;    
                   push(&st, data);
            /* code */
            break;
        case '2':  //int popped_element = pop(st);
                   std::cout<< "Popped element is: " << pop(&st) << std::endl;
                   break;

        case '3': std::cout<< "\nEnter the Position to Peek: \n";
                  std::cin >> position;
                  std::cout<< "Peeked Element is: " << peek(st, position) << std::endl;
                  break;  

        case '4': exit(0);
                  break;  
        default:
                std::cout<< "Wrong Input provided\n";
            break;
        }
    }
    

    return 0;
}
