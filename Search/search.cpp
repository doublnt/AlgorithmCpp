#include<iostream>
#include<stdlib.h>
#define maxSize 1000
using namespace std;

#pragma region �۰���ҷ�
/*
 * Ҫ�����Ա�������ģ��� R[low, .... high]������ȷ����������м�λ�� mid = (low + high) /2
 * Ȼ�󽫴���� k ֵ�� R[mid] �Ƚϣ�����ȣ��򷵻ظ�λ��
 * ���򣬸��� R[mid] > k ������� R[low.... mid-1] �����
 * �� R[mid] < k �����ұ� R[mid+1 .... high]
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

#pragma region �ֿ����
/*Ҳ��˳���������ң���������ֳ����ɿ飬ÿһ���е�Ԫ�ش洢˳��������ģ����ǿ����֮��
���밴�չؼ��ֵĴ�С�������У���ǰһ������Ԫ��ҪС�ں�һ�����С�ؼ��֡�

��һ�����ö��ֲ��ң��ڶ�������˳����ҡ�
*/
typedef struct {
    int key;
    int low, high;
} indexElem;

indexElem index[maxSize];
#pragma end region

#pragma region ���������� BST
/*
���������������ʣ�������������������������ǵ�������ģ�
1�����������������գ����������ϵ����йؼ��ֵ�ֵ��С�ڸ��ؼ��ֵ�ֵ��
2�����������������գ����������ϵ����йؼ��ֵ�ֵ�����ڸ��ؼ��ֵ�ֵ��
3�����һ���һ�Ŷ���������

˼�룺�Ⱥ͸��ڵ��еĹؼ��ֱȽϣ�
�����ȣ���Ƚϳɹ���
������ڣ����������в��ң����迼���������еĹؼ��֡�
���С�ڣ����������в��ң����迼����������
�ظ��������̣���������˽ڵ�Ŀ�ָ������˵������ʧ�ܡ�
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
    if(bt == NULL) { //��ǰΪ��ָ��ʱ��˵���ҵ�λ�ã������½ڵ㣬���롣
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

#pragma region ƽ�������
/*
AVL ������������������ƽ��������������������߶�֮��ľ���ֵ������ 1 ��
ƽ������� Ҳ�� ����������
ƽ�����ӣ� һ������ƽ������Ϊ���������߶ȼ�ȥ�������߶ȵĲ�������н���ƽ������
ֻ��ȡ -1,0,1
LL RR LR RL
*/
#pargma endregion

#pragma region B- ��
/*
B- �������н�㺢�ӽ����������ֵ��Ϊ B- ���Ľף�ͨ�� m >= 3,
B- ���� ƽ�� m �������
���� n ���ؼ��ֵĽ�㺬�� n+1 ����֧
*/

#pragme endregion

#pragma region B+ ��
/*
���� n ���ؼ��ֵĽ�㺬�� n ����֧
*/
#pragma endregion

#pragma region ɢ�б�
/*
���ݸ����ؼ���������ؼ����ڱ��еĵ�ַ���ؼ��� �� ��ַ����һһ��Ӧ��ϵ��

*/

#pragma endregion


#pragma region �жϸ����Ķ������Ƿ��Ƕ���������
/*
˼�룺�Զ�����������˵���������������Ϊ�����������С���ˣ�
�Ը����Ķ����������������������ܱ�֤ǰһ��ֵ���Ⱥ�һ��ֵ��
��˵���ö�������һ�Ŷ���������

*/
int predt = INF;
int judBST(BTNode *bt){
	int b1,b2;
	if(bt == NULL)
		return 1;
	else{
		b1 = judBST(bt -> lchild);
		if(b1 == 0 || predt > bt -> data)//���������Ƕ�������������
			return 0;                   //predt ���ڵ�ǰ���ڵ�ֵ�����
		predt = bt -> data;             //�����Ƕ���������
		b2 = judBST(bt -> rchild);
		return b2;
	}
}

#pragma endregion




