#define maxSize 100
#include<iostream>

using namespace std;

#pragma region 插入类排序
/*
直接插入排序：时间复杂度：最差情况 O(n^2)，最好的情况 O(n), 平均为 O(n^2)
每趟将一个待排序的关键字按照其值的大小插入到已经排好的部分有序序列的适当位置上
直到所有待排序关键字都被插入到有序序列中为止。
**插入类排序一趟排序后并不能确保使一个关键字到达其最终位置**
*/

void InsertSort(int R[], int n) {
    int i, j;
    int temp;

    for(i = 0; i < n ; ++i) {
        temp = R[i];
        j = i - 1;
    }

    while(j >= 0 && temp < R[j]) {
        R[j + 1] = R[j];
        --j;
    }

    R[j + 1] = temp;
}

/*
折半插入排序：
采用折半查找法来插入位置(需要序列事先有序)
时间复杂度：最好情况 O(nlog2n),最差 O(n^2),平均为 O(n^2)
*/

/*
希尔排序（缩小增量排序）
希尔排序的每趟排序都会使整个序列变得更加有序，等整个序列基本有序了，再来一趟
直接插入排序。
不稳定的
增量选取 向下取整函数 N/2，N/4, N/2^k....
时间复杂度：每次增量除以 2 并向下取整，O(n^2)
*/

#pragma endregion

#pragma region 交换类排序
/*
气泡排序（冒泡）首先第一个关键字和第二个关键字比较，
如果第一个大，则两者交换，否则不交换；
然后第二个关键字和第三个比较，如果第二个大，则两者交换，反复...
**起泡排序算法结束的条件是在一趟排序过程中没有发生关键字交换**
时间复杂度：最坏情况 O(n^2), 最好情况 O(n),平均 O(n^2)
*/
void BubbleSort(int R[], int n) {
    int i, j, flag;
    int temp;

    for(i = n - 1; i >= 1; --i) {
        flag = 0;

        for(j = 1; j <= i; ++j) {
            if(R[j - 1] > R[j]) {
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
                flag = 1;
            }
        }

        if(flag == 0)
            return;
    }
}

/*
快速排序
时间复杂度：最好情况下为 O(nlog2n)，最坏情况下为 O(n^2),平均为 O(nlog2n);
空间复杂度: O(log2n)
通过多次划分操作实行排序 ：每一趟选择当前所有子序列的一个关键字（通常是第一个）
作为枢轴，将子序列中比枢轴小的移到枢轴前边，比枢轴打的移到枢轴后面；当本趟所有子序列
都被枢轴以上述规则划分完毕后会得到一组更短的子序列，它们称为下一趟划分的初始序列集。
*/
void QuickSort(int R[], int low, int high) {
    //对从R[low] 到 R[high] 的关键字进行排序
    int temp;
    int i = low, j = high;

    if(low < high) {
        temp = R[low];

        //将数组中小于 temp 的关键字放在左边，大于 temp 的关键字 放在右边
        while(i < j) {
            while(j > i && R[j] >= temp)//从右往左遍历，找到比 temp 小的数
                --j;

            if(i < j) {
                R [i] = R[j]; //交换 i 和 j 的值
                ++i;
            }

            while(i < j && R[i] < temp)//从左往右遍历，找比 temp 大的数
                ++i;

            if(i < j) {
                R[j] = R[i];
                --j;
            }
        }

        R[i] = temp;//放置 temp 的最终位置
        QuickSort(R, low, i - 1);
        QuickSort(R, i + 1, high);
    }
}
#pragma endregion

#pragma region 选择类排序

/*
简单选择排序，从头到尾顺序扫描序列，找出最小的关键字，和第一个关键字交换，
接着从剩下的关键字中继续这种选择和交换，最终使序列有序。
时间复杂度：O(n^2)
*/
void SelectSort(int R[], int n) {
    int i, j, k;
    int temp;

    for(i = 0; i < n; ++i) {
        k = i;

        //找出最小的关键字的 下标
        for(j = i + 1; j < n; ++j) {
            if(R[k] > R[i])
                k = j;
        }

        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

/*
堆排序
思想：将一个无序队列调整为一个堆，就可以找出这个序列的最大或（最小）值，然后将找出
的这个值交换到序列的最后（或最前），对新的无序序列重复这样的操作，就实现了排序。

时间复杂度：O(nlog2n)，最坏情况下也为 O(nlog2n) ,适用于关键字很多的情况

//堆的定义：一颗完全二叉树，这颗完全二叉树满足：任何一个非叶结点的值都大于（或不小于）
//其左右孩子结点的值。若父亲大，孩子小，叫做大顶堆; 若父亲小，孩子大，叫做小顶堆
*/

//本函数完成数组 R[low] 到 R[high] 的范围内对在位置 low 上的结点进行调整
void Sift(int R[], int low, int high) {
    int i = low, j = 2 * i; //为什么 j = 2 * i?
    int temp = R [j];

    while(j <= high) {
        if(j < high && R[j] < R[j + 1]) // 若右孩子较大，则把 j 指向右孩子
            ++j; // j = 2 * i + 1;

        if(temp < R[j]) {
            R[i] = R[j];//将R[j] 调整到双亲结点的位置上
            i = j; //修改 i 和 j 的值，以便继续向下调整
            j = 2 * i;
        } else
            break;
    }

    R[i] = temp;
}

void headSort(int R[], int n) {
    int i;
    int temp;

    for(i = n / 2 ; i >= 1; --i) { // 建立初始堆
        Sift(R, i, n);
    }

    for(i = n ; i >= 2; --i) { //进行 n-1 次循环，完成堆排序
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;

        Sift(R, 1, i - 1);
    }
}

/*
二路归并排序：分而治之，先将整个序列分为两半，对每一半分别进行归并排序，将得到两个
有序序列，然后将这两个序列归并成一个序列即可。
时间复杂度和初始序列无关，平均条件下为 O(nlog2n),最坏情况下为 O(nlog2n)
空间复杂度为 O(n)
*/
void merge(int A[], int low, int mid, int high){

}

void mergeSort(int A[], int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1,high);

		merge(A, low, mid, high);
	}
}
#pragma endregion

#pragma region 基数排序
/*
"多关键字排序"，最高为优先，最低位优先
时间复杂度：平均和最坏都为 O(d(n + rd))
空间复杂度: O(rd)
n 为序列中的关键字数，d 为关键字的关键字位数

适合序列中地关键字数很多，但组成关键字的关键字取值范围较小。
*/


#pragma endregion

int main() {
    int R[] = {4621, 26, 357, 69, 5, 733, 9, 180, 55, 66, 77, 69, 7465};
    int n = 13;

    //InsertSort(R,n);
    QuickSort(R, 0, n - 1);

    cout << "Sort Output:\t" << endl;

    for(int j = 0; j < n; ++j)
        cout << R[j] << " ";

    return 0;
}
