#include <iostream>
#define DIGITS 100

using namespace std;

unsigned long long reverse(long long numero) {
	unsigned long long m = 0; 
	int digits[DIGITS];
	int pos = 0, power = 1;
	for (int i=0; i< DIGITS; i++)
		digits[i] = 0;
	while (numero > 0) {
		digits[pos++] = numero % 10;
		numero = numero / 10;
	}
	for (int i=pos-1; i>=0; i--) {
		m += power * digits[i];
		power *= 10;
	}	
	return m;
}

int main() {
	int nc; 
	int m; 
	unsigned long long n;
	cin >> nc;
	for (int i = 0; i < nc; i++) {
		cin >> n;
		m = 0;
		while (true) {
			if (reverse(n) == n) {
				break;
			} else {
				n += reverse(n);
				m++;
			}
		}
		cout << m << " " << n << endl;
	}
	return 0;
} 
