#include <iostream>
#include "string.h"
#include <iomanip>
#include <limits>
#include "tgmath.h"
#include <cmath>
#define maxSize 1000

using namespace std;

typedef struct Binomial {
    char array[maxSize];
    int length;
} Binomial;

void CreateBinomial(Binomial &binomial, char a[], int length) {
    int i;

    for(i = 0; i < length; ++i) {
        binomial.array[i] = a[i];
    }

    binomial.length = length;
}

void PrintBinomialValue(Binomial binomial) {
    for(int i = 0; i < binomial.length; ++i) {
        cout << binomial.array[i] << " ";
    }

    cout << "\n" << endl;
}

void PrintBinoMatrix(string matrix[], int length) {
    int i;
    cout << "\n" << "The Result is :" << endl;

    if(length == 0) {
        cout << matrix[0] << endl;
    } else {
        for(i = 0; i < length; ++i) {
            if(i == length - 1) {
                cout << matrix[i] << endl;
            } else {
                cout << matrix[i] << "+";
            }
        }
    }
}

void CalculateExpression(Binomial binomial, string matrix[], string matrixTemp[], int n) {
    int i, j, k = 0;
    int tempN = n;

	if( n == 0){
		matrix[n] = "1";
		return;
	}

    if(n == 1) {
        matrix[k] = string(1, binomial.array[k]);
        matrix[k + 1] = string(1, binomial.array[k + 1]);
    } else if(n == 2) {
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                matrix[k++] = string(1, binomial.array[i]) + string(1, binomial.array[j]);
            }
        }
    }
	for(i = 0; i < pow(2, n); ++i)
	{
		matrixTemp[i] = matrixTemp[i] + matrix[i];
	}
    CalculateExpression(binomial, matrix, matrixTemp, --n);
}

int main() {
    int n;
    char a[] = "ab";
    string matrix[maxSize];
	string matrixTemp[maxSize];

    Binomial bino;
    CreateBinomial(bino, a, 2);

    cout << "Please input the a and b to calculate the (a+b)^n expression!" << endl;
    cout << "Give me the value of n" << endl;

    while(!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nPlease type a number n:\t";
    }

    if(n < 0 || n > maxSize) {
        cout << "The number you input is invalid!" << endl;
        return 0;
    }

    CalculateExpression(bino, matrix,matrixTemp, n);

	PrintBinoMatrix(matrixTemp,pow(2,n));
}
