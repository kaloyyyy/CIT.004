
#include<iostream>
#include<stdlib.h>//for system("CLS");
#include<string>//for getline for string;
#include<limits>//for limit in cin.ignore
using namespace std;

int main()
{
	int* x;
int y = 10;
x = &y;
y = *x + *x;
cout << *x << " " << &y;
}