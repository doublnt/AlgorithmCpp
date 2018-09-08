#include<iostream>
#include<stdlib.h>
#define maxSize 1000
using namespace std;

#pragma region 折半查找法
/*
 * 要求线性表是有序的：设 R[low, .... high]，首先确定该区间的中间位置 mid = (low + high) /2
 * 然后将待查的 k 值与 R[mid] 比较，若相等，则返回该位置
 * 否则，根据 R[mid] > k 则在左边 R[low.... mid-1] 里查找
 * 若 R[mid] < k 则在右边 R[mid+1 .... high]
 */
int BSearch(int R[], int low, int high, int k) {
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(R[mid] == k)
            return mid;
        else if(R[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return 0;
}
#pragma endregion

#pragma region 分块查找
/*也称顺序索引查找：把索引表分成若干块，每一块中的元素存储顺序是任意的，但是块与块之间
必须按照关键字的大小有序排列，即前一块的最大元素要小于后一块的最小关键字。

第一步采用二分查找，第二步采用顺序查找。
*/
typedef struct {
    int key;
    int low, high;
} indexElem;

indexElem index[maxSize];
#pragma end region

#pragma region 二叉排序树 BST
/*
二叉排序树的性质：（如果按中序遍历，则输出的是递增有序的）
1）若它的左子树不空，则左子树上的所有关键字的值均小于根关键字的值。
2）若它的右子树不空，则右子树上的所有关键字的值均大于根关键字的值。
3）左右还是一颗二叉排序树

思想：先和根节点中的关键字比较，
如果相等，则比较成功。
如果大于，则到右子树中查找，无需考虑左子树中的关键字。
如果小于，则到左子树中查找，无需考虑右子树。
重复上述过程，如果来到了节点的空指针域，则说明查找失败。
*/
typedef struct BTNode {
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

BTNode *BSTSearch(BTNode *bt, int key) {
    if(bt == NULL)
        return NULL;
    else {
        if(bt -> key == key)
            return bt;
        else if(key < bt -> key)
            return BSTSearch(bt -> lchild, key);
        else
            return BSTSearch(bt -> rchild, key);
    }
}

int BSTInsert(BTNode *&bt, int key) {
    if(bt == NULL) { //当前为空指针时，说明找到位置，创建新节点，插入。
        bt = (BTNode *)malloc(sizeof(BTNode));
        bt -> lchild = bt -> rchild = NULL;
        bt -> key = key;
        return 1;
    } else {
        if(key == bt -> key) {
            return 0;
        } else if(key < bt -> key) {
            return BSTInsert(bt -> lchild, key);
        } else
            return BSTInsert(bt -> rchild, key);
    }
}

void CreateBST(BTNode *&bt, int key[], int n) {
    int i;
    bt = NULL;

    for(i = 0; i < n; ++i) {
        BSTInsert(bt, key[i]);
    }
}

#pragma endregion

#pragma region 平衡二叉树
/*
AVL 树，其左右子树都是平衡二叉树，且左右子树高度之差的绝对值不超过 1 。
平衡二叉树 也是 二叉排序树
平衡因子： 一个结点的平衡因子为其左子树高度减去右子树高度的差，树中所有结点的平衡因子
只能取 -1,0,1
LL RR LR RL
*/
#pargma endregion





