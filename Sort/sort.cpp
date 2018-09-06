#define maxSize 100
#include<iostream>

using namespace std;

#pragma region 插入类排序
/*
直接插入排序：最差情况 O(n^2)，最好的情况 O(n):
每趟将一个待排序的关键字按照其值的大小插入到已经排好的部分有序序列的适当位置上
直到所有待排序关键字都被插入到有序序列中为止。
**插入类排序一趟排序后并不能确保使一个关键字到达其最终位置**
*/

void InsertSort(int R[], int n)
{
    int i,j;
    int temp;
    for(i = 0; i < n ; ++i)
    {
        temp = R[i];
	j = i - 1;
    }
    while(j >= 0 && temp < R[j]){
        R[j+1] = R[j];
	--j;
    }
    R[j+1] = temp;
}

/*
折半插入排序，采用折半查找法来插入位置(需要序列事先有序)
最好情况 O(nlog2n),最差 O(n^2)
*/

/*希尔排序（缩小增量排序）
希尔排序的每趟排序都会使整个序列变得更加有序，等整个序列基本有序了，再来一趟
直接插入排序。
不稳定的
增量选取 向下取整函数 N/2，N/4, N/2^k....
每次增量除以 2 并向下取整，O(n^2)
*/

#pragma endregion

#pragma region 交换类排序
/*气泡排序（冒泡）首先第一个关键字和第二个关键字比较，
如果第一个大，则两者交换，否则不交换；
然后第二个关键字和第三个比较，如果第二个大，则两者交换，反复...
**起泡排序算法结束的条件是在一趟排序过程中没有发生关键字交换**
最坏情况 O(n^2), 最好情况 O(n)
*/
void BubbleSort(int R[], int n){
	int i,j,flag;
	int temp;
	for(i = n-1; i >= 1; --i){
		flag = 0;
		for(j = 1; j <= i; ++j){
			if(R[j-1] > R[j]){
				temp = R[j];
				R[j] = R[j-1];
				R[j-1] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
			return;
	}
}

#pragma endregion

int main(){
	int R[] = {2,3,6,5,7,9,10,55,66,77,69,4621,7465};
	int n = 13;

	InsertSort(R,n);

	cout << "InsertSort:\t" << endl;
	for(int j = 0; j < n; ++j)
		cout << R[j] << " ";
}
