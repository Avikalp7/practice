#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
struct node
{
    T key;
    node* left;
    node* right;
    node(T key_val)
    {
        key = key_val;
        left = right = NULL;
    }
};

template <typename T>
int count_nodes(node<T>* root)
{
    if(root->left != NULL && root->right != NULL)
        return count_nodes(root->left) + count_nodes(root->right) + 1;
    if(root -> left != NULL)
        return count_nodes(root->left) + 1;
    else if(root -> right != NULL)
        return count_nodes(root->right) + 1;
    else
        return 1;
}

template<typename T>
bool is_complete(node<T>* cnode, int index, int node_count)
{
    if(cnode == NULL)
        return true;
    else if(index > node_count)
        return false;
    else
        return is_complete(cnode -> left, 2*index + 1, node_count) && is_complete(cnode -> right, 2*index + 2, node_count);
}

template <typename t>
bool is_min(node<t> *T)
{
    if(!T -> left && !T -> right)
        return true;
    else if(T -> right == NULL)
        return (T -> key <= T -> left -> key && is_min(T -> left));
    else
        return (T -> key <= T -> left -> key && is_min(T -> left) && T -> key <= T -> right -> key && is_min(T -> right));
}

template <typename T>
bool is_minHeap(node<T>* root)
{
    int node_count = count_nodes(root);
    node_count -=  1;
    return (is_complete(root, 0, node_count) && is_min(root));
}

int main()
{
    /*
    node<int> *n = new node<int>(2);
    n->key = 4;
    n->left = new node<int>(22);
    n->right = new node<int>(40);
    n -> left -> right = new node<int>(200);
    n -> left -> left = new node<int>(100);
    n -> right -> left = new node<int> (230);
    n -> right -> right = new node<int> (48);
    */
    node<char>* root = NULL;
    root = new node<char>('a');
    root->left = new node<char>('b');
    root->right = new node<char>('c');
    root->left->left = new node<char>('d');
    root->left->right = new node<char>('e');
    root->right->left = new node<char>('f');
    root->right->right = new node<char>('g');
    root->left->left->left = new node<char>('h');
    root->left->left->right = new node<char>('i');
    root->left->right->left = new node<char>('m');

    if (is_minHeap(root))
        printf("Given binary tree is a Heap\n");
    else
        printf("Given binary tree is not a Heap\n");
    int cnt = count_nodes(root);
    cout << "Count = " << cnt << endl;
    bool status = is_minHeap(root);
    cout << status;
    return 0;
}
