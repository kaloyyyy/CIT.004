// 2ndprojV2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void outputInfo();
//void recordMove();
//void delInfo();

struct userInfo {
    string recNum;
    string name;
    string age;
    string occupation;
    string phoneNum;
};
void inputUser(userInfo(*)[3]);

string arrayName[2][3] = { {"Record Number: ","Name: ","Age: "},{"Occupation: ", "Phone Number: "," "} }; //used in a loop to output together with the data
string arrayInfo[2][3] = { {"","",""},{"","",""}};
userInfo dataArr[2][3] = { {"---empty---","---empty---","---empty---"},{"---empty---","---empty---","---empty---"} };
int dRow=0,dCol=0;
int colSize = 0, rowSize = 1;
string tempArr[5];
int totalInput = 0;
int main()
{
    userInfo(*ptrInfo)[3];
    
    ptrInfo = dataArr;
    char choiceLetter;
    do {

        cout << "enter the choice" << endl << "a. display all records\nb. add a record\nc. delete a record\nd. exit\n";
        cin >> choiceLetter;

        switch (choiceLetter) {
        case 'a'://display all
            system("CLS");
            outputInfo();
            break;
        case 'b':
            system("CLS");
            //add more
            inputUser(ptrInfo);
            system("CLS");
            cout << "---data recorded---" << endl;
                            
            break;
        case 'c':
            system("CLS");
            //delete 
            //delInfo();
            break;
        }
    } while (choiceLetter != 'd');

    return 0;
}

void outputInfo()
{

    cout << "showing all records\n\n";
    int x = 0, y = 0;
        for (int z = 0; z < totalInput; z++) {
            cout << arrayName[0][0] << dataArr[x][y].recNum << endl;
            cout << arrayName[0][1] << dataArr[x][y].name << endl;
            cout << arrayName[0][2] << dataArr[x][y].age << endl;
            cout << arrayName[1][0] << dataArr[x][y].occupation << endl;
            cout << arrayName[1][1] << dataArr[x][y].phoneNum << endl;
            cout << "end of data: " << (z + 1) << endl<<endl;
            if (z < 2) {
                y++;
            }
            else if (z > 2) {
                y = -1;
                y++;
                x = 1;
                }

    }
}

void inputUser(userInfo(*ptrInfo)[3]) {
    //this part is for the input from the user. assign the input to the pointer
    cout << "Enter the necessary information below:" << endl;
    cout << "Enter record number" << endl;
    cin >> ptrInfo[dRow][dCol].recNum;
    cout << "Enter name" << endl;
    cin >> ptrInfo[dRow][dCol].name;
    cout << "Enter age" << endl;
    cin >> ptrInfo[dRow][dCol].age;
    cout << "Enter occupation" << endl;
    cin >> ptrInfo[dRow][dCol].occupation;
    cout << "Enter phone number" << endl;
    cin >> ptrInfo[dRow][dCol].phoneNum;
    
    dataArr[dRow][dCol].recNum = ptrInfo[dRow][dCol].recNum;
    dataArr[dRow][dCol].name = ptrInfo[dRow][dCol].name;
    dataArr[dRow][dCol].age = ptrInfo[dRow][dCol].age;
    dataArr[dRow][dCol].occupation = ptrInfo[dRow][dCol].occupation;
    dataArr[dRow][dCol].phoneNum = ptrInfo[dRow][dCol].phoneNum;
    if (totalInput < 2) {
        dCol++;

    }
    else if (totalInput > 2) {
        dCol = -1;
        dCol++;
        dRow = 1;
    }
    else if(totalInput==6){
        cout << "2x3 array full! might lose some records" << endl;
        outputInfo();
        cout << "2x3 array full! might lose some records" << endl;
    }
    totalInput++;
}


void delInfo() {
    string arrayTemp[2][3] = { {"","",""},{"","",""} };
    cout << "choose the record you want to delete\n\n";
    outputInfo();
    cout << "enter the index: ";
    int delInfo;
    cin >> delInfo;
    int x = 0, y = 0;
    for (int z = 0; z < totalInput; z++) {
        


        cout << "end of data: " << (z + 1) << endl << endl;
        if (z < 2) {
            y++;
        }
        else if (z > 2) {
            y = -1;
            y++;
            x = 1;
        }

    }
}