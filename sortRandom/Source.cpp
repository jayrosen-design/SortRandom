//Jay Rosen
//This program reads random.txt into integer arrays which are then processed by sorting and searching
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// RandomlyOrganized class declaration
class RandomlyOrganized
{
private:
	int array0, array1, array2;						//Store the numbers of input file into two arays				
	void selectionSort(int[], int);					//Function to selection sort the original random numbers
	void bubbleSort(int[], int);					//Function to bubble sort the original random numbers
	void linearSearch(int[], int, int);				//Function to linear search the original random numbers
	void linearSearch2(int[], int, int);			//Function to linear search the sorted numbers
	void binarySearch(int[], int, int);				//Function to binary search the sorted numbers

public:
	void displayReport();							//Function to open txt file, read data into array, call and display the results of all other RandomlyOrganized members		
	ifstream txt;								    //Store random.txt file

}; // End RandomlyOrganized class declaration


   // Program that uses the RandomlyOrganized class

   /**************************************************************
   *               RandomlyOrganized::displayReport              *
   * This function reads the data of random.txt                  *
   * and initalizes arrays with the file's contents, passing its *
   * data to member functions.                                   *
   **************************************************************/
void RandomlyOrganized::displayReport()
{
	const int RANDOM = 200;
	int array0[RANDOM];		// input text file will be read into this array
	int array1[RANDOM];     // contents of array0 will be copied into array1 and array2
	int array2[RANDOM];

	int count = 0;

	//open and check if the random.txt file is accessible to program
	ifstream txt;
	txt.open("random.txt");
	if (!txt)
		cout << "Error opening data file\n";

	//initalize the three arrays with the 200 random integers from the random.txt file
	else
	{
		while (count < RANDOM && txt >> array0[count])
			count++;
		txt.close();

		//Display contents of the text file
		cout << "\n********************************************************************************";
		cout << "\n******************************[ RANDOM NUMBERS ]********************************";
		cout << "\n********************************************************************************\n";
		for (count = 0; count < RANDOM; count++)
		{
			cout << setw(5) << array0[count] << " \t ";
		}
		//Display the correct amount of line items (200)
		cout << "\n********************************************************************************";
		cout << "\n****************************[ " << count << " NUMBERS FOUND ]*******************************";
		cout << "\n********************************************************************************\n\n";
	}

	//Copy the contents of original array into two more, of which will be modified by sorting
	for (int count = 0; count < RANDOM; count++)
	{
		array1[count] = array0[count];
		array2[count] = array0[count];
	}
	//Call bubble sort function
	cout << "\a\n\n\t Press ENTER to Bubble Sort the Random numbers . . .";
	cin.get();
	bubbleSort(array1, RANDOM);

	//Call seletion sort function
	cout << "\a\n\n\t Press ENTER to Selection Sort the Random numbers . . .";
	cin.get();
	selectionSort(array2, RANDOM);

	//Call linear search function (searches the original, unsorted array)
	cout << "\a\n\n\t Press ENTER to Linear Search the Random numbers for '869' . . .";
	cin.get();
	linearSearch(array0, RANDOM, 869);

	//Call linear search2 function (searches the sorted array)
	cout << "\a\n\n\t Press ENTER to Linear Search the Sorted numbers for '869' . . .";
	cin.get();
	linearSearch2(array2, RANDOM, 869);

	//call the binary search function
	cout << "\a\n\n\t Press ENTER to Binary Search the Sorted numbers for '869' . . .";
	cin.get();
	binarySearch(array1, RANDOM, 869);

}

/**************************************************************
*               RandomlyOrganized::bubbleSort                     *
* This function performs an ascending-order bubble sort           *
* on the array.  The parameter array holds the elements.          *
* The parameter size holds the number of elements in the array.   *
**************************************************************/
void RandomlyOrganized::bubbleSort(int array[], int size)
{
	int temp;
	bool swap;
	int pass = 0;
	int k;

	//Bubble Sort
	do
	{
		swap = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = true;
				pass++; //used a counter for number of exchanges made during sort
			}
		}

	} while (swap);

	//Display the bubble sorted array
	cout << "\n********************************************************************************";
	cout << "\n******************************[ BUBBLE SORT ]***********************************";
	cout << "\n********************************************************************************\n";
	for (k = 0; k < size; k++)
	{
		cout << setw(5) << array[k] << " \t ";
	}
	cout << "\n********************************************************************************";
	cout << "\n************************[ NUMBER OF EXCHANGES: " << pass << " ]**************************";
	cout << "\n********************************************************************************\n\n\t";
}

/**************************************************************
*               RandomlyOrganized::selectionSort                  *
* This function performs an ascending-order bubble sort           *
* on the array.  The parameter array holds the elements.          *
* The parameter size holds the number of elements in the array.   *
**************************************************************/
void RandomlyOrganized::selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;
	int k;
	int pass = 0;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
				pass++;                //used a counter for number of exchanges made during sort
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}

	//Display the selected sorted array
	cout << "\n********************************************************************************";
	cout << "\n******************************[ SELECTION SORT ]********************************";
	cout << "\n********************************************************************************\n";
	for (k = 0; k < size; k++)
	{
		cout << setw(5) << array[k] << " \t ";
	}
	cout << "\n********************************************************************************";
	cout << "\n*************************[ NUMBER OF EXCHANGES: " << pass << " ]***************************";
	cout << "\n********************************************************************************\n\n\t";
}


/**************************************************************
*             RandomlyOrganized::linearSearch                  *
* This function performs a  linear search on the random array. *
* The parameter array holds the elements.                      *
* The parameter size holds the number of elements in the array.*
**************************************************************/
void RandomlyOrganized::linearSearch(int array[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	int pass = 0;

	//Display the linear search results

	cout << "\n********************************************************************************";
	cout << "\n***************************[ LINEAR SEARCH (RANDOM) ]***************************";
	cout << "\n********************************************************************************\n";

	while (index < size && !found)
	{
		if (array[index] == value)
		{
			found = true;
			position = index;
		}
		cout << setw(5) << array[index] << " \t ";
		pass++;                                     //used a counter for number of comparisons made during search
		index++;
	}
	cout << "\n\n\t Value 869 is located as the " << (position + 1) << " position of the 200 random numbers\n\n";
	cout << "\n********************************************************************************";
	cout << "\n***********************[ NUMBER OF COMPARISONS: " << pass << " ]****************************";
	cout << "\n********************************************************************************\n\n\t";
}

/**************************************************************
*             RandomlyOrganized::linearSearch2                 *
* This function performs a  linear search on the sorted array. *
* The parameter array holds the elements.                      *
* The parameter size holds the number of elements in the array.*
**************************************************************/
void RandomlyOrganized::linearSearch2(int array[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	int pass = 0;

	//Display the linear search results

	cout << "\n********************************************************************************";
	cout << "\n**************************[ LINEAR SEARCH (SORTED) ]****************************";
	cout << "\n********************************************************************************\n";

	while (index < size && !found)
	{
		if (array[index] == value)
		{
			found = true;
			position = index;

		}
		cout << setw(5) << array[index] << " \t ";
		pass++;
		index++;
	}

	cout << "\n\n\t Value 869 is located as the " << (position + 1) << " position of the 200 sorted numbers\n\n";
	cout << "\n********************************************************************************";
	cout << "\n***********************[ NUMBER OF COMPARISONS: " << pass << " ]***************************";
	cout << "\n********************************************************************************\n\n\t";
}

/**************************************************************
*             RandomlyOrganized::binarySearch                  *
* This function performs a  binary search on the array.        *
* The parameter array holds the elements.                      *
* The parameter size holds the number of elements in the array.*
**************************************************************/

void RandomlyOrganized::binarySearch(int array[], int size, int value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;
	int pass = 0;

	//Display the binary search results
	cout << "\n********************************************************************************";
	cout << "\n*******************************[  BINARY SEARCH ]*******************************";
	cout << "\n********************************************************************************\n";


	cout << setw(5) << "\tPASS \t | \t FIRST \t | \t MIDDLE  | \t LAST  \t " << endl;
	cout << "\t-------------------------------------------------------------\n";


	while (!found && first <= last)
	{
		middle = (first + last) / 2;

		//display the first, middle, and last locations that the program steps through during each comparison of binary search
		cout << "\t " << (pass + 1) << "\t | ";
		cout << setw(5) << "\t [" << (first + 1) << "] \t | ";
		cout << setw(5) << " [" << (middle + 1) << "] \t | ";
		cout << setw(5) << " [" << (last + 1) << "] \t " << endl;

		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
		pass++;                   //used a counter for number of comparisons made during search
	}
	cout << "\n\n\t Value 869 is located as the " << (position + 1) << " position of the sorted numbers\n\n";
	cout << "\n********************************************************************************";
	cout << "\n***********************[ NUMBER OF COMPARISONS: " << pass << " ]*****************************";
	cout << "\n********************************************************************************\n\n\t";
}

//Driver Program
int main()
{
	RandomlyOrganized Search_Sort;		//Create Search_Sort object of the RandomlyOrganized class

	cout << "\n\n\t This program searchs and sorts through 200 random numbers.";
	cout << "\n\t Make sure 'random.txt' is located in the current directory.";
	cout << "\n\n\t Press ENTER to continue . . .";
	cin.get();

	Search_Sort.displayReport();	//Call displayReport member of RandomlyOrganized class

	cout << "\a\n\n\t\t";
	system("pause");

	return 0;
}



