#include<stdio.h>
#include<conio.h>
#include<malloc.h>

static int capacity;

struct Node				// A Binary Tree Node has data, pointer to left child and a pointer to right child
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Stack				// Structure of a Stack Node. Linked List implementation is used for  
{							// Stack. A Stack Node contains a pointer to Tree Node and a pointer to next Stack Node 
	struct Node *s;
	struct Stack *link;
};

Stack* push(struct Stack *stackTop, struct Node *new_node)
{
	struct Stack *new_stack = (struct Stack *)malloc(sizeof(struct Stack));
	new_stack->s = new_node;
	new_stack->link = stackTop;
	stackTop = new_stack;
	return stackTop;
}

Stack *pop(struct Stack *stackTop)
{
	struct Stack *temp = stackTop;
	stackTop = stackTop->link;
	free(temp);
	return stackTop;
}

Node* createNode(int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;
	capacity++;
	return new_node;
}

void addToTree(char choice, struct Node *root, struct Node *new_node)
{
	if (choice == 'R')
		root->right = new_node;
	if (choice == 'L')
		root->left = new_node;
}

void NonRecursive_Traverse_Inorder(struct Node *root)
{
	struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack)), *st2;
	struct Node *temp = root;

		while (temp->left != NULL)
		{
			temp = temp->left;
			st = push(st, temp);
		}
		printf(" %d ", st->s->data);
		st2 = pop(st);
		printf(" %d ", st2->s->data);
		if (st2->s->right != NULL)
			printf(" %d ", st2->s->right->data);

}

void main()
{
	struct Node *root1, *node1, *node2, *node3, *node4, *node5, *node6;
	root1 = createNode(2);
	node1 = createNode(3);
	addToTree('L', root1, node1);
	node2 = createNode(4);
	addToTree('R', root1, node2);
	node3 = createNode(5);
	addToTree('L', node1, node3);
	node4 = createNode(6);
	addToTree('R', node1, node4);
	node5 = createNode(7);
	addToTree('L', node2, node5);
	node6 = createNode(8);
	addToTree('R', node2, node6);
	NonRecursive_Traverse_Inorder(root1);

	_getch();
}