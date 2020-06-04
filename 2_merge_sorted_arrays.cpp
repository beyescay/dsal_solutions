#include <iostream>

void mergeSortedArrays(int a[], int size_a, int b[], int size_b, int c[]) {

	int idx_a = 0;
	int idx_b = 0;
	int idx_c = 0;

	while(idx_a < size_a && idx_b < size_b) {

		if (a[idx_a] > b[idx_b]) {
			c[idx_c++] = b[idx_b++];
		}

		else {
			c[idx_c++] = a[idx_a++];
		}

	}

	while (idx_a < size_a){
		c[idx_c++] = a[idx_a++];
	}

	while (idx_b < size_b){
		c[idx_c++] = b[idx_b++];
	}

}

int main() {

	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8};

	auto size_a = sizeof(a)/sizeof(a[0]);
	auto size_b = sizeof(b)/sizeof(b[0]);

	int c[size_a+size_b];

	mergeSortedArrays(a, size_a, b, size_b, c);

	for(int i = 0; i < size_a+size_b; ++i) {
		std::cout << c[i] << " ";
	}

	std::cout << std::endl;

}
