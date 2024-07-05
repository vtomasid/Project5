#include <iostream>
using namespace std;


/*
Class: CMSC140 CRN 41340
Program : Project 5
Instructor: Ara Kechiantz
Summary of Description : For this final project the student has to develop a program that simulates the Lo Shu Magic Square using 
one dimentional parallel array, functions, and loops.
Due Date : 07/05
Integrity Pledge : I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : _Victoria Tomasi Moody._________
*/

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;   // The value of the smallest number
const int MAX = 9;   // The value of the largest number

// Function prototypes
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main()
{
    //Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid
    int magicArrayRow0[COLS], magicArrayRow1[COLS], magicArrayRow2[COLS];
    // Define variable to check user input and allow to try again
    char tryAgain;

    do {
    // Fill the magic square arrays
    fillArray(magicArrayRow0, magicArrayRow1, magicArrayRow2, COLS);

    // Show the magic square arrays
    cout << "Magic Square:" << endl;
    showArray(magicArrayRow0, magicArrayRow1, magicArrayRow2, COLS);

    // Check if it is a magic square
    if (isMagicSquare(magicArrayRow0, magicArrayRow1, magicArrayRow2, COLS)) {
        cout << "This is a Lo Shu Magic Square!" << endl;
        break; // Exit the loop if it's a magic square

    }else {
        cout << "This is NOT a Lo Shu Magic Square." << endl;
        cout << "Do you want to try again? (Enter 'Y' for Yes, 'N' for No): ";
        cin >> tryAgain;
        
        }
    }
         while (tryAgain == 'Y' || tryAgain == 'y');

    cout << "Name: Victoria Moody \n"
        << "Project #5 \n"
        << "Due Date: 07/05";

    return 0;
}


// Function definitions

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    cout << "Enter values for the Magic Square row by row and column by column:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Enter the number for Row " << i << " and Column " << j << ": ";
            if (i == 0) {
                cin >> arrayRow1[j];  // For row 0
            }
            else if (i == 1) {
                cin >> arrayRow2[j];  // For row 1
            }
            else if (i == 2) {
                cin >> arrayRow3[j];  // For row 2
            }
        }
    }
}


void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arrayRow1[i] << " " << arrayRow2[i] << " " << arrayRow3[i] << endl;
    }
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
        checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        if (arrayRow1[i] < min || arrayRow1[i] > max ||
            arrayRow2[i] < min || arrayRow2[i] > max ||
            arrayRow3[i] < min || arrayRow3[i] > max) {
            return false;
        }
    }
    return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arrayRow1[i] == arrayRow1[j] ||
                arrayRow2[i] == arrayRow2[j] ||
                arrayRow3[i] == arrayRow3[j]) {
                return false;
            }
        }
    }
    return true;
}


bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum = arrayRow1[0] + arrayRow1[1] + arrayRow1[2]; // Assuming COLS = 3
    for (int i = 1; i < size; ++i) {
        if (arrayRow2[0] + arrayRow2[1] + arrayRow2[2] != sum ||
            arrayRow3[0] + arrayRow3[1] + arrayRow3[2] != sum) {
            return false;
        }
    }
    return true;
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum = arrayRow1[0] + arrayRow2[0] + arrayRow3[0]; // Assuming ROWS = 3
    for (int i = 1; i < size; ++i) {
        if (arrayRow1[i] + arrayRow2[i] + arrayRow3[i] != sum) {
            return false;
        }
    }
    return true;
}


bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int sum2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    return sum1 == sum2; // Both diagonals should be equal in a magic square
}
