#include <stdio.h>

#define MAX_SIZE 100

typedef struct TreeNode {
    int data;
} TreeNode;

int findIndex(TreeNode tree[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (tree[i].data == target) {
            return i;
        }
    }
    return -1;
}

int main()
{
	TreeNode tree[MAX_SIZE] = {0};

    for (int i = 0; i < 10; i++) {
        tree[i].data = i + 1;
    }
    
    int target = ;
    int index = findIndex(tree, MAX_SIZE, target);
    
    if (index != -1) {
        printf("%d의 인덱스는 %d입니다.\n", target, index);
    } else {
        printf("%d를 찾을 수 없습니다.\n", target);
    }
    
    return 0;
}
