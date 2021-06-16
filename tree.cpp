#include<iostream>

struct Tree
{
    int data;
    struct node* right_node;
    struct node* left_node;
};

bool check_binary_search_tree(struct Tree* node)
{
    if(node == nullptr)
    {
        return false;
    }
    while(node != nullptr)
    {
        if(node->left != nullptr)
    }
}

int main()
{
    return 0;
}