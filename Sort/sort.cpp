#define maxSize 100
#include<iostream>

using namespace std;

#pragma region ����������
/*
ֱ�Ӳ������������� O(n^2)����õ���� O(n):
ÿ�˽�һ��������Ĺؼ��ְ�����ֵ�Ĵ�С���뵽�Ѿ��źõĲ����������е��ʵ�λ����
ֱ�����д�����ؼ��ֶ������뵽����������Ϊֹ��
**����������һ������󲢲���ȷ��ʹһ���ؼ��ֵ���������λ��**
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
�۰�������򣬲����۰���ҷ�������λ��(��Ҫ������������)
������ O(nlog2n),��� O(n^2)
*/

/*ϣ��������С��������
ϣ�������ÿ�����򶼻�ʹ�������б�ø������򣬵��������л��������ˣ�����һ��
ֱ�Ӳ�������
���ȶ���
����ѡȡ ����ȡ������ N/2��N/4, N/2^k....
ÿ���������� 2 ������ȡ����O(n^2)
*/

#pragma endregion

#pragma region ����������
/*��������ð�ݣ����ȵ�һ���ؼ��ֺ͵ڶ����ؼ��ֱȽϣ�
�����һ���������߽��������򲻽�����
Ȼ��ڶ����ؼ��ֺ͵������Ƚϣ�����ڶ����������߽���������...
**���������㷨��������������һ�����������û�з����ؼ��ֽ���**
���� O(n^2), ������ O(n)
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