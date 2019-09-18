#pragma warning(disable:4996)//this is important as it disables a visual studio specific warning regarding the copy function.
//I have verified that my implementation works and have disabled the warning to allow the code to build -Roberto
#include<iostream>  //including nessecary libraries
#include<ctime>
#include<chrono>
#include<fstream>
#include"sortingalgos.h"  //includes header file with sorting algorithms
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream outfile;
	outfile.open("C:/Users/Public/Documents/problem1.csv"); //specifies what file/directory to output data to, will create file if not already present.
	int Narry[9] = { 100,200,300,400,500,1000,2000,4000,10000 }; //Array to store the various values of n
	int* arry1 = NULL;   //3 Main arrays
	int* arry2 = NULL;
	int* arry3 = NULL;
	int* bubbleArry = NULL;  //Sorting algorithm specific arrays
	int* insertionArry = NULL;
	int* selectionArry = NULL;
	int* MergeArry = NULL;
	int* quickArry = NULL;
	int MAX, outervariable = 0;  //MAX is used to store the array capacity, outervariable is used to cycle through the various values of n. 
	int execute = 1; // Determines which array gets copied to the sorting algorithm specific arrays
	while (outervariable < 9)
	{
		MAX = Narry[outervariable]; //Setting the max value for all new arrays
		cout << "Sorting numbers from 1 to " << MAX << "." << endl;
		outfile << "Sorting numbers from 1 to " << MAX << "." << "," << "CPU Runtime (ms): " << "," << "Steps to complete sorting: " << "," << endl;
		arry1 = new int[MAX];           // The 3 main arrays are created with a capacity of 'n'
		arry2 = new int[MAX];
		arry3 = new int[MAX];
		for (int i = 0; i < MAX; i++)   // main arrays are then loaded with values 
		{
			arry1[i] = i + 1;  //arry1 gets 1 to n
			arry2[i] = MAX - (i);  //arry2 gets n to 1
			arry3[i] = i + 1;   //arry3 gets 1 to n ..
		}
		randomize(arry3, MAX); //..but is then randomized.
		for (int option = 0; option < 3; option++)  //option cycles through the 3 values needed for execute, which determines which array is getting worked with.
		{
			if (execute == 1)
			{
				outfile << "Array 1 (1 to n) being sorted." << endl;
			}
			if (execute == 2)
			{
				outfile << "Array 2 (n to 1) being sorted." << endl;
			}
			if (execute == 3)
			{
				outfile << "Array 3 (randomly sorted numbers from 1 to n) being sorted." << endl;
			}
			for (int option2 = 0; option2 < 6; option2++) //option2 determines which sorting algorithm is being used. 1=bubblesort, 5=quicksort.
			{
				if (option2 == 1)
				{
					int bubblecount = 0;  //stepcounter is declared and set equal to 0. This is important for subsequent runs.
					if (execute == 1)
					{
						bubbleArry = new int[MAX]; //declaring a new array for values to be copied to and passed to the functions
						copy(arry1, arry1 + MAX, bubbleArry); //copies main array's data into algorithm specific array
					}
					if (execute == 2)
					{
						bubbleArry = new int[MAX];
						copy(arry2, arry2 + MAX, bubbleArry);
					}
					if (execute == 3)
					{

						bubbleArry = new int[MAX];
						copy(arry3, arry3 + MAX, bubbleArry);
					}
					auto start = chrono::high_resolution_clock::now();   //starts measuring runtime right before sorting algorithm function is called
					bubblecount = BubbleSort(bubbleArry, MAX, bubblecount); //sorting algorithm function is value returning, and will return steps taken for the stepcounter variable
					auto finish = chrono::high_resolution_clock::now();//ends the runtime counter
					chrono::duration<double, milli> elapsed = finish - start; // calculates the elasped time by subtracting the ending time from the starting time and puts the time calculated into milliseconds
					double bubbleduration = elapsed.count(); //variable to hold the time
					outfile << "Bubble Sort: " << "," << bubbleduration << "," << bubblecount; // data being sent to the Excel table
					outfile << endl;
					delete[]bubbleArry; //deleting the array to free memory/it for future use
				}

				if (option2 == 2)
				{
					int insertioncount = 0;
					if (execute == 1)
					{
						insertionArry = new int[MAX];//declaring a new array for values to be copied to and passed to the functions
						copy(arry1, arry1 + MAX, insertionArry);//copies main array's data into algorithm specific array
					}
					if (execute == 2)
					{
						insertionArry = new int[MAX];
						copy(arry2, arry2 + MAX, insertionArry);
					}
					if (execute == 3)
					{

						insertionArry = new int[MAX];
						copy(arry3, arry3 + MAX, insertionArry);
					}
					auto start2 = chrono::high_resolution_clock::now();//starts measuring runtime right before sorting algorithm function is called
					insertioncount = InsertionSort(insertionArry, MAX, insertioncount); //sorting algorithm function is value returning, and will return steps taken for the stepcounter variable
					auto finish2 = chrono::high_resolution_clock::now();//ends the runtime counter
					chrono::duration<double, milli> elapsed2 = finish2 - start2;// puts the time calculated into milliseconds
					double insertduration = elapsed2.count();//variable to hold the time
					outfile << "Insertion Sort: " << "," << insertduration << "," << insertioncount;// data being sent to the Excel table
					outfile << endl;
					delete[]insertionArry;//deleting the array to free memory/it for future use
				}
				if (option2 == 3)
				{
					int selectioncount = 0;
					if (execute == 1)
					{
						selectionArry = new int[MAX];//declaring a new array for values to be copied to and passed to the functions
						copy(arry1, arry1 + MAX, selectionArry);//copies main array's data into algorithm specific array
					}
					if (execute == 2)
					{
						selectionArry = new int[MAX];
						copy(arry2, arry2 + MAX, selectionArry);
					}
					if (execute == 3)
					{

						selectionArry = new int[MAX];
						copy(arry3, arry3 + MAX, selectionArry);
					}
					auto start3 = chrono::high_resolution_clock::now();//starts measuring runtime right before sorting algorithm function is called
					selectioncount = SelectionSort(selectionArry, MAX, selectioncount); //sorting algorithm function is value returning, and will return steps taken for the stepcounter variable
					auto finish3 = chrono::high_resolution_clock::now();//ends the runtime counter
					chrono::duration<double, milli> elapsed3 = finish3 - start3;// puts the time calculated into milliseconds
					double selectionduration = elapsed3.count();//variable to hold the time
					outfile << "Selection Sort: " << "," << selectionduration << "," << selectioncount;// data being sent to the Excel table
					outfile << endl;
					delete[]selectionArry;//deleting the array to free memory/it for future use
				}
				if (option2 == 4)
				{
					int mergecount = 0;
					if (execute == 1)
					{
						MergeArry = new int[MAX];//declaring a new array for values to be copied to and passed to the functions
						copy(arry1, arry1 + MAX, MergeArry);//copies main array's data into algorithm specific array
					}
					if (execute == 2)
					{
						MergeArry = new int[MAX];
						copy(arry2, arry2 + MAX, MergeArry);
					}
					if (execute == 3)
					{
						MergeArry = new int[MAX];
						copy(arry3, arry3 + MAX, MergeArry);
					}
					auto start4 = chrono::high_resolution_clock::now();//starts measuring runtime right before sorting algorithm function is called
					mergecount = MergeSort(MergeArry, 0, MAX - 1, mergecount); //sorting algorithm function is value returning, and will return steps taken for the stepcounter variable
					auto finish4 = chrono::high_resolution_clock::now();//ends the runtime counter
					chrono::duration<double, milli> elapsed4 = finish4 - start4;// puts the time calculated into milliseconds
					double mergeduration = elapsed4.count();//variable to hold the time
					outfile << "Merge Sort: " << "," << mergeduration << "," << mergecount; // data being sent to the Excel table
					outfile << endl;
					delete[]MergeArry;//deleting the array to free memory/it for future use
				}
				if (option2 == 5)
				{
					int quickcount = 0;
					if (execute == 1)
					{
						quickArry = new int[MAX];//declaring a new array for values to be copied to and passed to the functions
						copy(arry1, arry1 + MAX, quickArry);//copies main array's data into algorithm specific array
					}
					if (execute == 2)
					{
						quickArry = new int[MAX];
						copy(arry2, arry2 + MAX, quickArry);
					}
					if (execute == 3)
					{
						quickArry = new int[MAX];
						copy(arry3, arry3 + MAX, quickArry);
					}

					auto start5 = chrono::high_resolution_clock::now();//starts measuring runtime right before sorting algorithm function is called
					quickcount = QuickSort(quickArry, 0, MAX - 1, quickcount); //sorting algorithm function is value returning, and will return steps taken for the stepcounter variable
					auto finish5 = chrono::high_resolution_clock::now();//ends the runtime counter
					chrono::duration<double, milli> elapsed5 = finish5 - start5;// puts the time calculated into milliseconds
					double quickduration = elapsed5.count();//variable to hold the time
					outfile << "Quick Sort: " << "," << quickduration << "," << quickcount;// data being sent to the Excel table
					outfile << endl;
					delete[] quickArry;//deleting the array to free memory/it for future use
				}
			}
			execute++;//increments execute so that arry2 and arry3 can be sorted next.

		}
		delete[]arry1; //Freeing up memory at the end of the loop taken up by declaring new arrays
		delete[]arry2; //also allows us to reuse the arrays everytime we go through the whole program
		delete[]arry3;
		execute = 1;//resets execute so that for the next n value arry1 is the first one sorted again
		outervariable++; //incrementing outervariable allows MAX to be the next n value 
	}
	cout << "Final sorting solution provided in a file named 'problem1.csv' in your Public Documents folder." << endl; //notifies the user via the console where the output file is stored.
	outfile.close(); //closing file
	return 0;
}
