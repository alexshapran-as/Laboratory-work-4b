/*
Лабораторная работа №4b
Алексей Шапран 
Группа: ИУ8-14
*/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>
using namespace std;

struct Booking 
{
	char name[64]; 
	int num_B; 
};

struct Address 
{
	char street[64]; 
	int num_H; 
	int num_F;
};

struct Customer  
{
	char fio[128]; 
	Address address;
	Booking booking; 
	char sex;   
	int age; 
};

int main(void)
{
	Customer *pC = 0;
	int serial_number;
	int k = 0; 
	int n = 0; 

	cout << " The number of array elements: "; 
	cin >> n; 
	cout << endl;

	pC = (Customer *)malloc(n*sizeof(Customer)); 

	for (int i = 0; i<n; i++)
	{
		cout << " Customer " << i+1 << endl;
		cout << " Full name: "; 
		_flushall(); 
		cin.getline(pC[i].fio, 128);
		_flushall(); 
		cout << " Sex: ";
		cin >> pC[i].sex;
		_flushall(); 
		cout << " Age: ";
		cin >> pC[i].age;
		_flushall(); 
		cout << " Address";
		cout << endl << " Street: ";
		_flushall(); 
		cin.getline(pC[i].address.street, 64);
		fflush(stdin);
		cout << " House: ";
		cin >> pC[i].address.num_H;
		cout << " Flat: ";
		cin >> pC[i].address.num_F;
		fflush(stdin);
		cout << " Booking";
		cout << endl << " Name of booking: ";
		_flushall(); 
		cin.getline(pC[i].booking.name, 64);
		fflush(stdin);
		cout << " Serial number of booking: ";
		cin >> pC[i].booking.num_B;
		fflush(stdin);
	}

	for (int i = 0; i<n; i++) 
	{
		cout << endl << "Customer " << i+1 << " "<< pC[i].fio << " " << pC[i].sex << " "<< pC[i].age << " ";
		cout << pC[i].address.street << " "<< pC[i].address.num_H << " ";
		cout << pC[i].address.num_F << " " << pC[i].booking.name << " ";
		cout << pC[i].booking.num_B;
	}

	cout << endl << " Print the desired product number: ";
	cin >> serial_number;
	for (int i = 0; i<n; i++) 
	{
		if (serial_number == pC[i].booking.num_B) k++;
	}
	fflush(stdin); 
	cout << endl << " The number of people who have booked this product: " << k;
	
	fflush(stdin); 
	free(pC);

		cout << endl << endl << "Press any button to exit the program" << endl;
	_getch();

	return 0;
}
