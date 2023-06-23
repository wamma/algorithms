#include <stdio.h>
#include <stdlib.h>

// 레드블랙 트리 노드 구조체
typedef struct Node {
	int data;
	char color;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
} Node;

// 전역 변수
Node* root = NULL;

// 보조 함수들
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->color = 'R';
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void swapColors(Node* node1, Node* node2) {
	char temp;
	temp = node1->color;
	node1->color = node2->color;
	node2->color = temp;
}

void rotateLeft(Node* node) {
	Node* rightChild = node->right;
	node->right = rightChild->left;

	if (rightChild->left != NULL) {
		rightChild->left->parent = node;
	}

	rightChild->parent = node->parent;

	if (node->parent == NULL) {
		root = rightChild;
	} else if (node == node->parent->left) {
		node->parent->left = rightChild;
	} else {
		node->parent->right = rightChild;
	}

	rightChild->left = node;
	node->parent = rightChild;
}

void rotateRight(Node* node) {
	Node* leftChild = node->left;
	node->left = leftChild->right;

	if (leftChild->right != NULL) {
		leftChild->right->parent = node;
	}

	leftChild->parent = node->parent;

	if (node->parent == NULL) {
		root = leftChild;
	} else if (node == node->parent->right) {
		node->parent->right = leftChild;
	} else {
		node->parent->left = leftChild;
	}

	leftChild->right = node;
	node->parent = leftChild;
}

void fixViolation(Node* node) {
	Node* parent = NULL;
	Node* grandparent = NULL;

	while ((node != root) && (node->color != 'B') && (node->parent->color == 'R')) {
		parent = node->parent;
		grandparent = node->parent->parent;

		if (parent == grandparent->left) {
			Node* uncle = grandparent->right;

			if (uncle != NULL && uncle->color == 'R') {
				grandparent->color = 'R';
				parent->color = 'B';
				uncle->color = 'B';
				node = grandparent;
			} else {
				if (node == parent->right) {
					rotateLeft(parent);
					node = parent;
					parent = node->parent;
				}

				rotateRight(grandparent);
				swapColors(parent, grandparent);
				node = parent;
			}
		} else {
			Node* uncle = grandparent->left;

			if ((uncle != NULL) && (uncle->color == 'R')) {
				grandparent->color = 'R';
				parent->color = 'B';
				uncle->color = 'B';
				node = grandparent;
			} else {
				if (node == parent->left) {
					rotateRight(parent);
					node = parent;
					parent = node->parent;
				}

				rotateLeft(grandparent);
				swapColors(parent, grandparent);
				node = parent;
			}
		}
	}

	root->color = 'B';
}

// 주요 함수들
void insert(int data) {
	Node* newNode = createNode(data);
	if (root == NULL) {
		root = newNode;
		root->color = 'B';
		return;
	}

	Node* current = root;
	Node* parent = NULL;

	while (current != NULL) {
		parent = current;
		if (data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	newNode->parent = parent;

	if (data < parent->data) {
		parent->left = newNode;
	} else {
		parent->right = newNode;
	}

	fixViolation(newNode);
}

void inorderTraversal(Node* node) {
	if (node == NULL) {
		return;
	}

	inorderTraversal(node->left);
	printf("%d ", node->data);
	inorderTraversal(node->right);
}

int main() {
	insert(7);
	insert(3);
	insert(18);
	insert(10);
	insert(22);
	insert(8);
	insert(11);
	insert(26);
	insert(2);
	insert(6);
	insert(13);

	printf("레드블랙 트리의 중위 순회 결과: ");
	inorderTraversal(root);

	return 0;
}
