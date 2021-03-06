#include<iostream>
#include<ctime>
using namespace std;
int PERMUTATIONS;



void Exchange(int i, int j, int *x) {
	++PERMUTATIONS;
	int tmp;
	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void Quick_Sort(int left, int right, int *x) {
	int i, j, m, h;
	i = left;
	j = right;
	m = x[(i + j + 1) / 2];
	do {
		while (x[i] < m) i++;
		while (x[j] > m) j--;
		if (i <= j) {
			Exchange(i, j, x);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		Quick_Sort(left, j, x);
	if (i < right)
		Quick_Sort(i, right, x);
}



void Hoar_Sort(int *x, int k, int &number_mass) {

	unsigned int start_time = clock();
	PERMUTATIONS = 0;
	cout << "Original array: ";


	if (number_mass < 1 || number_mass>2)
	{
		for (int i = 0; i < k; i++) {
			x[i] = rand() % 1000;
		}

	}
	++number_mass;
	for (int i = 0; i < k; i++) {
		cout << x[i] << " ";
	}

	cout << endl;

	Quick_Sort(0, k - 1, x);

	cout << "Sorted array: ";
	for (int i = 0; i < k; i++) {
		cout << x[i] << " ";
	}
	unsigned int end_time = clock();
	cout << endl;
	cout << "Amount of permutation: " << PERMUTATIONS << endl;
	cout << "Sorting time: " << end_time - start_time << endl;
	system("pause");

}





int main()
{
	srand(time(NULL));
	int a = 10;
	int number_mass = 0;
	int random_array[10]; 
	int almost_sorted[10] = { 1,2,4,3,5,6,7,8,9,10 }; 
	int reverse_sorted[10] = { 9,8,7,6,5,4,3,2,1,0 }; 
	int ten_thousand_elements[10000]; 

	Hoar_Sort(random_array, a, number_mass);
	Hoar_Sort(almost_sorted, a, number_mass);
	Hoar_Sort(reverse_sorted, a, number_mass);
	a = 10000;
	Hoar_Sort(ten_thousand_elements, a, number_mass);

	cout << endl;
	system("pause");
	return 0;
}