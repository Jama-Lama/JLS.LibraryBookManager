//#include and namespace statements
#include <iostream>
#include <conio.h>
using namespace std;

//struct definition for a book, capitalized variable names because they're public
struct Book {
	string Title;
	string Author;
	int YearPublished;
	int NumPages;
};

int main() {
	//Initialize the Array of 4 Books
	// "Unknown" and -1 are used for 'unknown' data 
	const int NUM_BOOKS = 4;
	Book books[NUM_BOOKS] = { 
		{ "Of Mice and Men", "John Steinbeck", 1937, 107 }, 
		{ "Uncle Toms Cabin", "Harriet Beecher Stowe", 1851, 656},
		{ "Fahrenheit 451", "Unknown", -1, -1},
		{ "Mody Dick", "Herman Meville", 1851, 635}
	};

	//print all books
	for (int i = 0; i < NUM_BOOKS; i++) {
		cout << i + 1 << ". " << books[i].Title << "\n";
		cout << "Author: " << books[i].Author << "\n";
		cout << "Year Published: " << books[i].YearPublished << "\n";
		cout << "Number of Pages: " << books[i].NumPages << "\n\n";
	}

	// *** BEGINING OF UPDATE BOOK CODE ***

	//Get the Number of the Book to Update
	cout << "Enter the ID of the book you would like to update (1-4): ";
	int bookNum;
	cin >> bookNum;
	bookNum--;
	cout << "\n";

	//Verify Valid bookNum/Input
	if (bookNum > -1 && bookNum < 4) {
		//Valid Input: Prompt for, Print, and Update values
		
		//create temporary book struct to hold incoming input
		Book temp = books[bookNum];

		//display title of book being modified
		cout << bookNum + 1 << ". " << books[bookNum].Title << "\n";

		//Update Author
		cout << "Enter the Author: ("<< books[bookNum].Author <<"): ";
		cin >> temp.Author;

		//Update YearPublished
		cout << "Enter the Year Published: (" << books[bookNum].YearPublished << "): ";
		cin >> temp.YearPublished;

		//Update Page Count
		cout << "Enter the Number of Pages: (" << books[bookNum].NumPages << "): ";
		cin >> temp.NumPages;

		//Verify Desire to Save Changes
		string saveChanges;
		cout << "Save Changes? (Y/N):";
		cin >> saveChanges;

		if (saveChanges == "Y") {
			//Save changes from Temp Book to Books Book
			books[bookNum] = temp;

			//Print Updated Values
			cout << bookNum + 1 << ". " << books[bookNum].Title << "\n";
			cout << "Author: " << books[bookNum].Author << "\n";
			cout << "Year Published: " << books[bookNum].YearPublished << "\n";
			cout << "Number of Pages: " << books[bookNum].NumPages << "\n\n";
		}
		else {
			//Do Nothing - Disregard Modified Temp Book
		}
	}
	else {
		//Invalid Input: Inform User and Move On
		cout << "Invalid Input - End of Update Sequence";
	}

	// *** END OF UPDATE BOOK CODE ***

	//Hold Program Open and Return 0.
	(void)_getch();
	return 0;
}

/*
* Complete Data of the 4 Books
*{ "Of Mice and Men", "John Steinbeck", 1937, 107 }, 
*{ "Uncle Toms Cabin", "Harriet Beecher Stowe", 1851, 656},
*{ "Fahrenheit 451", "Ray Bradbury", 1953, 156},
*{ "Mody Dick", "Herman Meville", 1851, 635}
*/