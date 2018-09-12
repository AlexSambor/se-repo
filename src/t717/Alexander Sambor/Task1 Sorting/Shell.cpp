#include<iostream>
#include<ctime>
using namespace std;


void  Exchange(int  i, int  j, int  *x) {
	int  tmp;
	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void  Shell_Sort(int  *mass, int  a, int &number_mass) {
	int  h, i, j;
	unsigned int start_time = clock();
	int permutations = 0;
	cout << "Original array: ";


	if (number_mass < 1 || number_mass>2)
	{
		for (int i = 0; i < a; i++) {
			mass[i] = rand() % 1000; 	
		}

	}
	++number_mass;

	for (int i = 0; i < a; i++) {
		cout << mass[i] << " ";
	}

	cout << endl;

	for (h = a / 2; h > 0; h = h / 2)
		for (i = 0; i < a - h; i++)
			for (j = i; j >= 0; j = j - h)
				if (mass[j] > mass[j + h])
				{
					++permutations;
					Exchange(j, j + h, mass);
				}
				else  j = 0;

				unsigned int end_time = clock();
				cout << "Sorted array: ";
				for (int i = 0; i < a; i++) {
					cout << mass[i] << " ";
				}
				cout << endl;
				cout << "Amount of permutation: " << permutations << endl;
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

	Shell_Sort(random_array, a, number_mass);
	Shell_Sort(almost_sorted, a, number_mass);
	Shell_Sort(reverse_sorted, a, number_mass);
	a = 10000;
	Shell_Sort(ten_thousand_elements, a, number_mass);

	cout << endl;
	system("pause");
	return 0;
}