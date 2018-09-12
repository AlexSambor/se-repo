#include<iostream>
#include<ctime>
using namespace std;



void  Merging_Sort(int  *arr, int  size, int &number_mass) {
	int  i, j, k, t, s, Fin1, Fin2;
	unsigned int start_time = clock();
	int permutations = 0;
	int*  tmp = new  int[size];

	cout << "Original array: ";
	if (number_mass < 1 || number_mass>2)
	{
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 1000; 
		}
	}
	++number_mass;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


	k = 1;
	while (k  <  size) {
		t = 0;
		s = 0;
		while (t + k  <  size) {
			Fin1 = t + k;
			Fin2 = (t + 2 * k  <  size ? t + 2 * k : size);
			i = t;
			j = Fin1;
			for (; i < Fin1 && j < Fin2; s++) {
				if (arr[i]  <  arr[j]) {
					tmp[s] = arr[i];
					i++;
				}
				else {
					tmp[s] = arr[j];
					j++;
				}
			}
			for (; i < Fin1; i++, s++)
				tmp[s] = arr[i];
			for (; j < Fin2; j++, s++)
				tmp[s] = arr[j];
			t = Fin2;
		}
		k *= 2;
		for (s = 0; s < t; s++)
		{
			++permutations;
			arr[s] = tmp[s];
		}
	}
	delete(tmp);



	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	unsigned int end_time = clock();

	cout << endl;
	cout << "Amount of permutations: " << permutations << endl;
	cout << "Sorting time: " << end_time - start_time << endl;
	system("pause");
}







int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int a = 10;
	int number_mass = 0;
	int random_array[10]; 
	int almost_sorted[10] = { 1,2,4,3,5,6,7,8,9,10 }; 
	int reverse_sorted[10] = { 9,8,7,6,5,4,3,2,1,0 }; 
	int ten_thousand_elements[10000]; 

	Merging_Sort(random_array, a, number_mass);
	Merging_Sort(almost_sorted, a, number_mass);
	Merging_Sort(reverse_sorted, a, number_mass);
	a = 10000;
	Merging_Sort(ten_thousand_elements, a, number_mass);

	cout << endl;
	system("pause");
	return 0;
}