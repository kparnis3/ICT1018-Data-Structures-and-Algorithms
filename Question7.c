#include <stdio.h>
#include <malloc.h>
#define AMOUNT 5 //default space amount

struct BST
{
    int node;
    struct BST* left, *right;
};

void display(struct BST *root, int space);
struct BST* addchild(struct BST *root, int val);
struct BST* resize(int val);

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Enter integers one by one, enter 0 to finish: \n");
    int value;
    struct BST *root;
    int flag=0;

    do{
        scanf("%d", &value);
        if(flag==0 && value!=0) {
            root = resize(value);
            flag=1;
        }
        else if(value!=0) {
            addchild(root, value);
        }

    }while (value != 0);

    printf("Binary Search Tree: \n");
    display(root, 0);

    return 0;
}

void display(struct BST *root, int space)
{
    if (root == NULL) { //Base case
        return;
    }

    space += AMOUNT;
    display(root->right, space);
    printf("\n");

    for (int i = AMOUNT; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->node);

    display(root->left, space);
}

struct BST* addchild(struct BST *root, int val)
{
    if(root==NULL) {
        return resize(val);
    }
    else if(val>root->node){
        root->right = addchild(root->right, val);
    }
    else {
        root->left = addchild(root->left, val);
    }
    return root;
}

struct BST* resize(int val)
{
    struct BST *node = malloc(sizeof(struct BST));
    node->node = val;
    node->left = node->right = NULL;

    return node;
}
