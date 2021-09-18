// 2ndproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<cstring>
#include<stdlib.h>
using namespace std;

int recNum;
int structArray[];
int groupInfo = 0;
int groupSize = 1;
//group size or the total number of records
//int i, j, k;

//the functions used
void inputUser();
void coutInfo();
void recordMove();
void delInfo();


//structure used in the program
struct userInfo {
    string recNum;
    string name;
    string age;
    string occupation;
    string phoneNum;
};
//2x3 array declared here
userInfo Info;
string arrayInfo[2][3] = { {Info.recNum,Info.name,Info.age},{Info.occupation,Info.phoneNum,""} };
string arrayName[2][3] = { {"Record Number: ","Name: ","Age: "},{"Occupation: ", "Phone Number: "," "} }; //used in a loop to output together with the data

string recordInfo[69420][2][3];
//string element = recordInfo[dataSize * size_z * size_y + j * size_z + k];

int main(){
    char choiceLetter;
    do {
        
        cout << "enter the choice" << endl<<"a. display all records\nb. add a record\nc. delete a record\nd. exit\n";
        cin >> choiceLetter;
        
        switch (choiceLetter) {
        case 'a'://display all
            system("CLS");
            cout << "displaying all records";
            coutInfo();
            break;
        case 'b':
            system("CLS");
            //add more
            inputUser();
            system("CLS");
            cout << "---data recorded---" << endl;
            break;
        case 'c':
            system("CLS");
            //delete 
            delInfo();
            break;
        }
    } while (choiceLetter != 'd');
    
    return 0;

}

void inputUser() {//this function is for the input of the data from the user. 
    userInfo* ptr = &Info; //this line is for the pointer. my bad I can't add a checking function because I lack time.

    //this part is for the input from the user. assign the input to the pointer
    cout << "Enter the necessary information below:" << endl;
    cout << "Enter record number" << endl;
    cin >> ptr->recNum;
    cout << "Enter name" << endl;
    cin >> ptr->name;
    cout << "Enter age" << endl;
    cin >> ptr->age;
    cout << "Enter occupation" << endl;
    cin >> ptr->occupation;
    cout << "Enter phone number" << endl;
    cin >> ptr->phoneNum;
    cout << endl;
    arrayInfo[0][0] = Info.recNum;
    arrayInfo[0][1] = Info.name;
    arrayInfo[0][2] = Info.age;
    arrayInfo[1][0] = Info.occupation;
    arrayInfo[1][1] = Info.phoneNum;
    recordMove();
}

void recordMove() {
    //save the data into the 3d array
    recordInfo[groupInfo][0][0] = Info.recNum;
    recordInfo[groupInfo][0][1] = Info.name;
    recordInfo[groupInfo][0][2] = Info.age;
    recordInfo[groupInfo][1][0] = Info.occupation;
    recordInfo[groupInfo][1][1] = Info.phoneNum;
    recordInfo[groupInfo][1][2] = "---end of record " + Info.recNum + "---\n\n";
    groupInfo++;
}
void coutInfo() {//shows all record
    cout << "showing all records\n\n";
    for (int x = 0; x < groupInfo; x++) {
        cout << "index: " << x+1 << endl;;
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 3; z++) {
                cout << arrayName[y][z] << recordInfo[x][y][z] << endl;

            }
        }
    }
}

void delInfo() {
    int delRec;
    cout << "choose the record you want to delete\n\n";
    coutInfo();
    cout << "enter the index: ";
    cin >> delRec;
    for (int x = delRec - 1; x < groupInfo; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 3; z++) {
                arrayInfo[y][z] = recordInfo[x + 1][y][z];
                //cout << arrayInfo[y][z] << endl;
                recordInfo[x][y][z] = arrayInfo[y][z];
            }
        }
    }
    groupInfo = groupInfo - 1;
    system("CLS");
    cout << "The data from index: " << delRec;
    system("CLS");
}