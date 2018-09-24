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

typedef struct BinomialMatrix {
    string element[maxSize];
    int length;
} BinomialMatrix;

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

void PrintBinoMatrix(BinomialMatrix matrix, int n) {
    int i;
    cout << "\n" << "The Result is :" << endl;

    int loopStart = matrix.length <= 2 ? 0 : 2;

    for(i = loopStart; i < matrix.length; ++i) {
        if(i == matrix.length - 1) {
            cout << matrix.element[i] << endl;
        } else {
            cout << matrix.element[i] << "+";
        }
    }
}

void CalculateExpression(Binomial binomial, BinomialMatrix &matrix,
                         BinomialMatrix &matrixTemp, int n) {
    int i, j, k = 0, t = 0, p = 0;

    if(n == 0) {
        matrix.element[n] = "1";
        matrix.length = 1;
        return;
    }

    matrix.element[k] = string(1, binomial.array[k]);
    matrix.element[k + 1] = string(1, binomial.array[k + 1]);
    matrix.length = 2;

    int loopLength = matrixTemp.length - matrix.length > 0 ? matrix.length : 0;

    if(matrixTemp.length < 10000) {
        for(i = 0; i < matrix.length; ++i) {
            for(j = loopLength; j < matrixTemp.length; ++j) {
                matrix.element[matrix.length + t] = matrix.element[i] + matrixTemp.element[j];
                ++t;
            }
        }

        matrix.length = matrix.length + t;
    }

    if(n >= 2) {
        CalculateExpression(binomial, matrixTemp, matrix, --n);
    }
}

int main() {
    int n;
    char a[] = "ab";

    Binomial bino;
    BinomialMatrix matrix;
    BinomialMatrix matrixTemp;

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

    CalculateExpression(bino, matrix, matrixTemp, n);

    if(matrix.length >= matrixTemp.length) {
        PrintBinoMatrix(matrix, n);
    } else {
        PrintBinoMatrix(matrixTemp, n);
    }
}
