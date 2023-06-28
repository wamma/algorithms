#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_word
{
	char			word[100];
	char			meaning[100];
	int				height;
	struct s_word	*left;
	struct s_word	*right;
}	t_word;

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

t_word	*insert_word(t_word *root, const char *word, const char *meaning)
{
	int	comparison;

	if (root == NULL)
	{
		root = (t_word *)malloc(sizeof(t_word));
		if (root == NULL)
			return (NULL);
		strcpy(root->word, word);
		strcpy(root->meaning, meaning);
		root->left = NULL;
		root->right = NULL;
		root->height = 1;
	}
	else
	{
		comparison = strcmp(root->word, word);
		if (0 < comparison)
			root->left = insert_word(root->left, word, meaning);
		else if (0 > comparison)
			root->right = insert_word(root->right, word, meaning);
		else
			return (root);
	}
	update_height(root);
	return (balance_tree(root, word));
}

void	search_word(t_word *root, const char *word)
{ 
	int	comparison;

	if (root == NULL)
	{
		printf("단어를 찾을 수 없습니다.\n");
		return ;
	}
	comparison = strcmp(root->word, word);
	if (0 < comparison)
		search_word(root->left, word);
	else if (0 > comparison)
		search_word(root->right, word);
	else
		printf("%s: %s\n\n", root->word, root->meaning);
}

void	print_all(t_word *root)
{
	if (root == NULL)
		return ;
	print_all(root->left);
	printf("%s: %s\n\n", root->word, root->meaning);
	print_all(root->right);
}

t_word	*delete_word(t_word *root, const char *word)
{
	int		comparison;
	t_word	*temp;

	if (root == NULL)
	{
		printf("단어를 찾을 수 없습니다.\n");
		return (NULL);
	}
	comparison = strcmp(root->word, word);
	if (comparison < 0)
		root->left = delete_word(root->left, word);
	else if (comparison > 0)
		root->right = delete_word(root->right, word);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			if (root->left != NULL)
				temp = root->left;
			else
				temp = root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			free(temp);
		}
		else
		{
			temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			strcpy(root->word, temp->word);
			strcpy(root->meaning, temp->meaning);
			root->right = delete_word(root->right, temp->word);
		}
	}
	return (root);
}

int	main(void)
{
	t_word		*root = NULL;
	int			menu;
	char		word[100];
	char		meaning[100];

	while (1)
	{
		printf("------단어장------\n");
		printf("1. 단어 추가\n");
		printf("2. 단어 검색\n");
		printf("3. 단어 삭제\n");
		printf("4. 모든 단어 출력\n");
		printf("5. 종료\n");
		printf("단어 선택: \n");
		scanf("%d", &menu);

		if (menu == 1)
		{
			printf("추가할 단어: ");
			scanf("%s", word);
			getchar(); // 버퍼 비우기
			printf("단어의 뜻: ");
			scanf("%s", meaning);
			getchar(); // 버퍼 비우기
			root = insert_word(root, word, meaning);
		}
		else if (menu == 2)
		{
			printf("검색할 단어: ");
			scanf("%s", word);
			getchar(); // 버퍼 비우기
			search_word(root, word);
		}
		else if (menu == 3)
		{
			printf("삭제할 단어: ");
			scanf("%s", word);
			getchar(); // 버퍼 비우기
			delete_word(root, word);
		}
		else if (menu == 4)
		{
			printf("모든 단어 출력\n");
			print_all(root);
		}
		else if (menu == 5)
		{
			printf("종료\n");
			break ;
		}
	}
	return (0);
}