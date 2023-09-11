#include "BinaryTree.h"
#include "Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BinaryTreeNode *BinaryTreeCreate(BTDataType *a, int *pi) {
    if (a[*pi] == '#') {
        (*pi)++;
        return NULL;
    }

    BinaryTreeNode *root = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    if (root == NULL) {
        perror("malloc fail");
        exit(-1);
    }
    root->data = a[(*pi)++];

    root->left = BinaryTreeCreate(a, pi);
    root->right = BinaryTreeCreate(a, pi);
    return root;
}

// 申请树节点
BinaryTreeNode *BuyBinaryTreeNode(BTDataType x) {
    BinaryTreeNode *newnode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    if (newnode == NULL) {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// 前序遍历
void BinaryTreePrevOrder(BinaryTreeNode *root) {
    // 前序遍历 根、左子树、右子树
    // 如果root为空，递归结束
    if (root == NULL) {
        printf("NULL ");
        return;
    }

    printf("%d ", root->data);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}

// 中序遍历
void BinaryTreeInOrder(BinaryTreeNode *root) {
    // 中序遍历 - 左子树、根、右子树
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%d ", root->data);
    BinaryTreeInOrder(root->right);
}

// 后序遍历
void BinaryPostOrder(BinaryTreeNode *root) {
    // 后序遍历 - 左子树、右子树、根
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    BinaryPostOrder(root->left);
    BinaryPostOrder(root->right);
    printf("%d ", root->data);
}

// 求二叉树节点个数
int BinaryTreeSize(BinaryTreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// 求二叉树的叶子节点个数
int BinaryTreeLeafSize(BinaryTreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 求二叉树的高度
int BinaryTreeHeight(BinaryTreeNode *root) {
    // 求左子树的高度，右子树的高度
    // 取最大的
    if (root == NULL) {
        return 0;
    }
    int leftHeight = BinaryTreeHeight(root->left);
    int rightHeight = BinaryTreeHeight(root->right);

    //如果左右子树两边相等就取左边的高度,所以大于等于
    return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 求第k层的节点个数 k>=1
int BinaryTreeLevelSize(BinaryTreeNode *root, int k) {
    if (root == NULL) {
        return 0;
    }

    if (k == 1) {
        return 1;
    }

    return BinaryTreeLevelSize(root->left, k - 1) + BinaryTreeLevelSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BinaryTreeNode *BinaryTreeFind(BinaryTreeNode *root, BTDataType x) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == x) {
        return root;
    }

    // 左子树递归的节点保存到leftTree中,如果leftTree不为NULL，则return leftTree
    BinaryTreeNode *leftTree = BinaryTreeFind(root->left, x);
    if (leftTree) {
        return leftTree;
    }

    // 右子树递归的节点保存到rightTree中,如果rightTree不为NULL，则return rightTree
    BinaryTreeNode *rightTree = BinaryTreeFind(root->right, x);
    if (rightTree) {
        return rightTree;
    }

    // 找不到，返回NULL
    return NULL;
}

// 二叉树销毁
void BinaryTreeDestory(BinaryTreeNode **root) {
    if (*root == NULL) {
        return;
    }
    // 后序遍历销毁，根要最后释放
    BinaryTreeDestory(&(*root)->left);
    BinaryTreeDestory(&(*root)->right);
    free(*root);
    *root = NULL;
}

// 层序遍历 - 利用队列
void BinaryTreeLevelOrder(BinaryTreeNode *root) {
    // 创建一个队列，队列中入数据，取队头，然后带左右子树，出一个数，带一个树的所有子树
    Queue q;
    QueueInit(&q);
    if (root) {
        // root不为NULL，就入队列
        QueuePush(&q, root);
    }

    while (!QueueEmpty(&q)) {
        // 取队头，打印
        BinaryTreeNode *front = QueueFront(&q);
        printf("%d ", front->data);

        // 取完POP
        QueuePop(&q);
        // 取队头，带下一层,
        if (front->left) {
            QueuePush(&q, front->left);
        }

        if (front->right) {
            QueuePush(&q, front->right);
        }
    }
    printf("\n");
    QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BinaryTreeNode *root) {
    // 层序走，走到第一个为空的时候，就跳出去，如果是满二叉树，后面的节点都应该为空
    Queue q;
    QueueInit(&q);
    if (root) {
        QueuePush(&q, root);
    }

    while (!QueueEmpty(&q)) {
        BinaryTreeNode *front = QueueFront(&q);
        QueuePop(&q);

        if (front == NULL) {
            break;
        } else {
            QueuePush(&q, front->left);
            QueuePush(&q, front->right);
        }
    }
    // 出到空以后，如果后面全是空，则是完全二叉树
    while (!QueueEmpty(&q)) {
        BinaryTreeNode *front = QueueFront(&q);
        QueuePop(&q);
        if (front != NULL) {
            QueueDestroy(&q);
            return false;
        }
    }
    QueueDestroy(&q);
    return true;
}

//求单值二叉树
bool isUnivalTree(BinaryTreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    if (root->left && root->data != root->left->data) {
        return false;
    }

    if (root->right && root->data != root->right->data) {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//求对称二叉树
bool _isSymmetric(BinaryTreeNode *left, BinaryTreeNode *right) {
    // 两个都为NULL，对称
    if (left == NULL && right == NULL)
        return true;

    // 两个其中一个为NULL，一个不为NULL，不对称
    if (left == NULL || right == NULL)
        return false;

    // left的左孩子的值和right的值不相等，不对称
    if (left->data != right->data)
        return false;

    // 左子树的左孩子，和右子树的右孩子对比，然后左子树的右孩子和右子树的左孩子在对比
    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    return _isSymmetric(root->left, root->right);
}

//翻转二叉树
BinaryTreeNode *invertTree(BinaryTreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    BinaryTreeNode *leftTree = invertTree(root->left);
    BinaryTreeNode *rightTree = invertTree(root->right);

    root->left = rightTree;
    root->right = leftTree;

    return root;
}