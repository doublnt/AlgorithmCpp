  // Project: Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "tgmath.h"
#include <cmath>


using namespace std;

unsigned long factorial(unsigned long);

int main()
{
	int r = 1;

	while (r == 1)
	{
		int n = 0;
		int a = 0;
		int b = 0;
		int k = 0;
		int y = 0;
		
		cout << "This is a program to solve (ax+b)^n given a,b,n \n" << endl;
		cout << "Give me a: \t";
		while (!(cin >> a))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease type a number a:\t";
		}
		
		cout << "Give me b: \t";
		while (!(cin >> b))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error \n \nPlease type a number b:\t";
		}
		
		cout << "Give me n: \t";
		while (!(cin >> n))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error \n \nPlease type a number:\t";
		}

	
		
		n = abs(n);

		cout << "(";
		cout << a;
		cout << "x";
		cout << " + ";
		cout << b;
		cout << ")^";
		cout << n;
		cout << endl << endl;



		while (n >= k)
		{
		   
			y = y + (factorial(n) / (factorial(k)*factorial(n - k)))*((a ^ (n - k))*pow(b,k));
			
			cout << (pow(a, (n - k)))*pow(b, k);

			if ((n - k) > 0)
			{
				
				cout << "x";
				cout << "^";
				cout << n - k;
				cout << " + ";
			}
			k = k + 1;
			}
		cout << "\n \nTo repeat press 1, to exit press any other number:\t";
		cin >> r;
		//system("CLS");
	}
	cout << endl << endl;
	return 0;
}

    
unsigned long factorial(unsigned long number)
{                             
	if (number <= 1)
		return 1;
	else
		return number * factorial(number - 1);
}       
