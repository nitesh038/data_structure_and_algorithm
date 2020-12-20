#include<iostream>

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* lchild;
    struct BinaryTreeNode* rchild;
};

struct Node
{
    struct BinaryTreeNode* bt;
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

void enqueue(struct Node** rear, struct Node** front, struct BinaryTreeNode* data)
{
    struct Node* p = new Node;
    if(isFull(p))
    {
        std::cout<<"Queue Overflow\n";
        return;
    }
    p->bt = data;
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
void dequeue(struct Node** front, struct BinaryTreeNode** dequeued_element)
{
    if(isEmpty(*front))
    {
        std::cout<< "Queue Underflow\n";
        return ;
    }
    *dequeued_element = (*front)->bt;
    *front = (*front)->next;
}

void preorder(struct BinaryTreeNode* root)
{
    if(root)
    {
        std::cout<< root->data;
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct BinaryTreeNode* root)
{
    if(root)
    {
        inorder(root->lchild);
        std::cout<< root->data;
        inorder(root->rchild);
    }
}

void postorder(struct BinaryTreeNode* root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        std::cout<< root->data;
    }
}
void levelorder(struct BinaryTreeNode* root)
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    
    std::cout<< root->data;
    enqueue(&rear, &front, root);
    
    while(!isEmpty(front))
    {   
        dequeue(&front, &root);
        if(root->lchild)
        {
            std::cout<< root->lchild->data;
            enqueue(&rear, &front, root->lchild);
        }
        if(root->rchild)
        {
            std::cout<< root->rchild->data;
            enqueue(&rear, &front, root->rchild);
        }
    }

 }

void createBinaryTree()
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    struct BinaryTreeNode* root = new BinaryTreeNode;
    std::cout << "Please enter root node data: \n";
    std::cin >> root->data;
    root->lchild = NULL;
    root->rchild = NULL;
  
    enqueue(&rear, &front, root);
    struct BinaryTreeNode* p = new BinaryTreeNode;
    struct BinaryTreeNode* temp = NULL;
    int data{};
    while(!isEmpty(front))
    {   
        dequeue(&front, &p);
        std::cout<< "Enter the data of the left child(-1 if no node) of: "<< p->data << std::endl;
        std::cin>>data;
        if(data != -1)
        {
            temp = new BinaryTreeNode;
            temp->data = data;
            temp->lchild = NULL;
            temp->rchild = NULL;
            p->lchild = temp;
            enqueue(&rear, &front, p->lchild);
        }
        std::cout<< "Enter the data of the right child(-1 if no node) of: "<< p->data << std::endl;
        std::cin>>data;
        if(data!=-1)
        {
            temp = new BinaryTreeNode;
            temp->data = data;
            temp->lchild = NULL;
            temp->rchild = NULL;
            p->rchild = temp;
            enqueue(&rear, &front, p->rchild);
        }
    }

    std::cout<< "Preorder Traversal of Tree is: \n";
    preorder(root);

    std::cout<< "\nInorder Traversal of Tree is: \n";
    inorder(root);

    std::cout<< "\nPostorder Traversal of Tree is: \n";
    postorder(root);

    std::cout<< "Level order Traversal of Tree is: \n";
    levelorder(root);

}
        


int main()
{
    createBinaryTree();
    return 0;
}
