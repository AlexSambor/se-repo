#include<iostream>
#include<ctime>
using namespace std;



void Selection(int *array, int length, int &number_mass)
{
	int permutations = 0;
	unsigned int start_time = clock();


	cout << "Original array: ";
	if (number_mass < 1 || number_mass>2)
	{
		for (int i = 0; i < length; i++) {
			array[i] = rand() % 1000; 
		}
	}
	++number_mass;
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;


	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{

		int smallestIndex = startIndex;


		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{

			if (array[currentIndex] < array[smallestIndex])

				smallestIndex = currentIndex;
		}

		++permutations;
		std::swap(array[startIndex], array[smallestIndex]);
	}


	cout << "Sorted array: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	unsigned int end_time = clock();

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

	Selection(random_array, a, number_mass);
	Selection(almost_sorted, a, number_mass);
	Selection(reverse_sorted, a, number_mass);
	a = 10000;
	Selection(ten_thousand_elements, a, number_mass);

	cout << endl;
	system("pause");
	return 0;
}