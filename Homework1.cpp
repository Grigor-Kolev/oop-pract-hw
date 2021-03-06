// Homework1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3D.h"

using namespace std;

int main() {
	char x;
	int n;
	Vector3D vectors[10000];

	x = cin.peek();
	
	if (x == '+' || x == '-') {
		cin.get();
		read(vectors, n);

		if (x == '+') {
			cout << evaluate(vectors, n, identityTransform) << endl;
		}
		if (x == '-') {
			cout << evaluate(vectors, n, negativeTransform) << endl;
		}
	}
	
	else {

		if (x == 'N') {
			cin >> x >> x >> x;
			read(vectors,n);

			transform(vectors, n, negativeTransform);
		}

		else {
			double multiplier;
			
			if (x == '*') {
				cin >> x >> multiplier;
			}
			else {
				cin >> multiplier >> x;
			}

			read(vectors, n);

			transform(vectors, n, multiplicativeTransform, multiplier);
			
		}

		print(vectors, n);
	}

	system("pause");
	return 0;
}