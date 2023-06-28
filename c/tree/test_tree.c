#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_word
{
	char word[100];
	char meaning[100];
	int height;
	struct s_word* left;
	struct s_word* right;
} t_word;

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_height(t_word *root)
{
	if (root == NULL)
		return (0);
	return (root->height);
}

void	update_height(t_word *root)
{
	root->height = 1 + max(get_height(root->left), get_height(root->right));
}

int	get_balance(t_word *root)
{
	if (root == NULL)
		return (0);
	return (get_height(root->left) - get_height(root->right));
}

t_word	*rotate_right(t_word *root)
{
	t_word	*left = root->left;
	t_word	*left_right = left->right;

	left->right = root;
	root->left = left_right;

	update_height(root);
	update_height(left);
	return (left);
}

t_word	*rotate_left(t_word *root)
{
	t_word	*right = root->right;
	t_word	*right_left = right->left;

	right->left = root;
	root->right = right_left;

	update_height(root);
	update_height(right);
	return (right);
}

t_word	*balance_tree(t_word *node, const char *word)
{
	int	balance = get_balance(node);

	if (balance > 1 && strcmp(word, node->left->word) < 0)
		return (rotate_right(node));
	else if (balance < -1 && strcmp(word, node->right->word) > 0)
		return (rotate_left(node));
	else if (balance > 1 && strcmp(word, node->left->word) > 0)
	{
		node->left = rotate_left(node->left);
		return (rotate_right(node));
	}
	else if (balance < -1 && strcmp(word, node->right->word) < 0)
	{
		node->right = rotate_right(node->right);
		return (rotate_left(node));
	}
	return (node);
}

t_word* create_node(const char* word, const char* meaning)
{
	t_word* newNode = (t_word*)malloc(sizeof(t_word));
	strcpy(newNode->word, word);
	strcpy(newNode->meaning, meaning);
	newNode->height = 1;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

t_word* add_word(t_word* root, const char* word, const char* meaning)
{
	if (root == NULL)
	{
		return create_node(word, meaning);
	}

	int comparison = strcmp(word, root->word);

	if (comparison < 0)
	{
		root->left = add_word(root->left, word, meaning);
	}
	else if (comparison > 0)
	{
		root->right = add_word(root->right, word, meaning);
	}
	else
	{
		return root;
	}

	update_height(root);
	return balance_tree(root, word);
}

void print_tree_inorder(t_word* root)
{
	if (root == NULL) return;

	print_tree_inorder(root->left);
	printf("단어: %s, 뜻: %s, 높이: %d\n", root->word, root->meaning, root->height);
	print_tree_inorder(root->right);
}

int main()
{
	t_word* root = NULL;

	root = add_word(root, "bye", "A yellow fruit");
	root = add_word(root, "banana", "A yellow fruit");
	root = add_word(root, "apple", "A fruit");
	// root = add_word(root, "orange", "A citrus fruit");
	// root = add_word(root, "grape", "A small, round fruit");
	// root = add_word(root, "kiwi", "A green fruit");

	printf("트리 출력 (중위 순회):\n");
	print_tree_inorder(root);

	return 0;
}
