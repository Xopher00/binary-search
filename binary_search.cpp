// This program demonstrates a Binary Search

//Kris Price

#include<iostream>
using namespace std;

int binarySearch(int [], int, int);  // function prototype

const int SIZE = 16;

int main()
{
	int found, value;
    int array[SIZE] ={0,2,2,3,5,9,11,12,12,12,13,17,18,19,19,34};

	cout << "Enter an integer to search for:" << endl;
	cin >> value;

	found = binarySearch(array, SIZE, value); //function call to perform the binary search
	                                          //on array looking for an occurrence of value
	if (found == -1)
		cout << "The value " << value << " is not in the list" << endl;
	else
	{
		cout << "The value " << value << " is in position number "
		     << found + 1 << " of the list" << endl;
	}
	return 0;
}


//*******************************************************************
//                     binarySearch
//
// task:		  This searches an array for a particular value
// data in:       List of values in an orderd array, the number of
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************
int binarySearch(int array[],int numElems,int value) //function heading
{
	int first = 0;				    // First element of list
	int last = numElems - 1;	    // last element of the list
	int middle;					    // variable containing the current
	                                // middle value of the list
int position = -1 ;  //position of search value
bool found = false ; //flag
while (!found && first <= last){
    middle = (first + last) / 2; //calculate mid point
    if (array[middle] == value) //if value is found at mid
    {
        found = true;
        position = middle;
    }
    else if (array[middle] > value) // if value is in lower half
        last = middle - 1;
    else
        first = middle + 1; //if value is in upper hal
}
    return position;
    }/*
	while (first <= last)
	{ //middle = first + (last - first) / 2      //search array in descending order

	if (array[middle] == value)
		return middle;		       // if value is in the middle, we are done

	else if (array[middle]<value)
		last = middle - 1;		   // toss out the second remaining half of
								   // the array and search the first
	else
		first = middle + 1;		   // toss out the first remaining half of
								   // the array and search the second
	}

	return -1;					   // indicates that value is not in the array
}

/*
Exercise 1
The right side of the statement middle=first+(last-first)/2 is not an integer, but is defined by the values' 
positions within the computer memory; ie. 13eeFF28 + (14eeFF32 - 17eeFF36) / 2. This affects the computer's logic in that 
it doesn't use a specific value when calculating the middle variable, but instead takes in values from predetermined positions

Exercise 2
Input 19
This is the first occurrence of 19 in the array
position = 2
Input 12
Position = 8
This is the second occurrence of 12 in the array
The difference is due to how the binary search splits the array in half continuously while searching for the value.
For 19, the sequence of splits led to the second 19 value being found, and for 12 this sequence led to the eighth value being found

Exercise 3
Input 34
position = 16
Input 12
position = 8
Input 19
position = 14
*/
