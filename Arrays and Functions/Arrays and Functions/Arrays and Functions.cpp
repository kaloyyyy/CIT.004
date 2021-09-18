#include <iostream>
#include <cmath>//don't need to include this since I am using Visual studio 2019, it does not work in different IDEs without cmath.
using namespace std;
int tempT = 1;
int inputarray[] = { 0,0,0,0,0,0,0 }; //declare my array throughout the code since I am going to use it in different functions. the zeroes are just temporary
int n = 7;
int i, j, temp;
void userInput();//functiion that asks the user to input seven numbers that replaces the zeroes in the array
void userChoice();//ask the user to choose between ascending or descending sort.
void sortbyascending();//functions for sorting
void sortbydescending();
void Ave();//fuction for getting the average of the array then round it off then finds out if it is odd or even.

int main() {
    cout << "input 7 numbers:\n";
    userInput();
    userChoice();
    //inputs the sorted numbers
    cout << "The sorted numbers are: ";
    for (i = 0; i < n; i++)
    {
        cout << inputarray[i] << " ";
    }
    cout << endl;
    Ave();
    return 0;
}

void userInput() {
    i = 0;
    j = 0;
    //asks the user to input 7 integers
    do {
        do {//checks if the input is an integer. clears it then i = j thus go backs to index of the wrong input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please put a integer\n";
                i = j;
                }

            } while (cin.fail());
            cin >> inputarray[i];
            i++;
            j = i - 1;
            //cout <<"input: " << j <<i << endl;
            /*do {// cout << inputarray[z] << "  ";
            z++;
            } while (z < i);
             */
        }while (i < n);
}

void userChoice() {
    char letter = 'a';
    
    do {//this loops it the user fails to enter letter "a" or "b"
        cout << "input the letter for sorting\na. ascending\nb. descending\n";
        cin >> letter;//lets the user choose the sorting order

        if (letter == 'a' || letter == 'b') {
            tempT = 1;
        }
        else
            tempT = 0;

        }while(tempT==0);

    if (letter == 'a') {
        sortbyascending();
    }

    else if (letter == 'b') {
        sortbydescending();
    }
    else
        cout << endl;

}

void sortbyascending() {
     //Sorting the array in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (inputarray[j] < inputarray[i])
            {
                temp = inputarray[i];
                inputarray[i] = inputarray[j];
                inputarray[j] = temp;
            }
        }
    }     
}

void sortbydescending() {
        //sorting the arrary in descending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (inputarray[i] < inputarray[j])
            {
                temp = inputarray[i];
                inputarray[i] = inputarray[j];
                inputarray[j] = temp;
            }
        }
    }
}

void Ave() {
    int sum = 0;
    i = 0;
    float average;
    int rndAve;
        // Find sum of all array elements
    for (i = 0; i < n; i++) 
    {
        sum += inputarray[i];
    }
    average = (float)sum / n;
        //cout << "Average = " << average<<endl;
    rndAve = round(average);//round offs the average of the array. Sometimes it only works in VS 2019
        //cout << "Rounded-off Average = " << rndAve;
    (rndAve % 2 == 0) ? cout  << "The Average of the numbers is even." : cout  << "The average of the numbers is odd.\n";

}
//Prince John Carlo F. Austria
//190041
