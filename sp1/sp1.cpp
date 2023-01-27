#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

class shopping
{
private:
	int pCode;
	float price;
	float dis;
	string pName;

public:
	void menu();
	void adminstrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};
void shopping::menu()
{
m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t________________________________________\n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t        SuperMarkter Main Menu          \n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t________________________________________\n";
	cout << "\t\t\t\t   1) Adminstrator   |\n";
	cout << "\t\t\t\t                     |\n";
	cout << "\t\t\t\t   2) Buyer          |\n";
	cout << "\t\t\t\t                     |\n";
	cout << "\t\t\t\t   3) Exit           |\n";
	cout << "\t\t\t\t                     |\n";
	cout << "\n\t\t\t  Please select! ";
	cin >> (choice);

	switch (choice)
	{
	case 1:
		cout << "\t\t\t Please Login \n";
		cout << "\t\t\t Enter Email \n";
		cin >> email;
		cout << "\t\t\t Password \n";
		cin >> password;

		if (email == "joul@email.com" && password == "joul123")
		{
			adminstrator();
		}
		else
		{
			cout << "Invalid Email or Password!";
		}
		break;

	case 2:
	{
		buyer();
		break;
	}

	case 3:
	{
		exit(0);
		break;

	}

	default:
	{
		cout << "Please select from the given options";

	}


	}
	goto m;

}

void shopping::adminstrator()
{
m:
	int choice;
	cout << "\n\n\n\t\t\t Adminstrator menu";
	cout << "\n\t\t\t|_____1) Add the product ____|";
	cout << "\n\t\t\t|                            |";
	cout << "\n\t\t\t|_____2) Modify the product__|";
	cout << "\n\t\t\t|                            |";
	cout << "\n\t\t\t|_____3) Delete the product__|";
	cout << "\n\t\t\t|                            |";
	cout << "\n\t\t\t|_____3) Back to main menu __|";

	cout << "\n\n\tPlease enter your choice!";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		add();
		break;
	}

	case 2:
	{
		edit();
		break;
	}

	case 3:
	{
		rem();
		break;
	}


	case 4:
	{
		menu();
		break;
	}

	default:
	{
		cout << "Invalid choice!";
	}
	}
	goto m;
}

void shopping::buyer()
{
m:
	int choice;
	cout << "\t\t\t 1) Buyer \n";
	cout << "\t\t\t______________  \n";
	cout << "                      \n";
	cout << "\t\t\t 2) Buy product \n";
	cout << "                      \n";
	cout << "\t\t\t 3) Go back     \n";
	cout << "\t\t\t Enter your choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		receipt();
		break;

	case 2:
		menu();

	default:
		cout << "invalid choice";
	}
	goto m;
}

void shopping::add()
{
m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Product code of the product";
	cin >> pCode;
	cout << "\n\n Name of the product";
	cin >> pName;
	cout << "\n\n Price of the product";
	cin >> price;
	cout << "\n\n Discount on product";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pCode << " " << pName << " " << price << " " << dis << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;

		while (!data.eof())
		{
			if (c == pCode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
		if (token == 1)
		{
			goto m;
		}
		else
		{
			data.open("database.txt", ios::app | ios::out);
			data << " " << pCode << " " << pName << " " << price << " " << dis << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Record inserted !";

}

void shopping::edit()
{
	fstream data, data1;
	int pKey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;

	cout << "\n\t\t\t Modify the reccord!";
	cout << "\n\t\t\t Enter product code :";
	cin >> pKey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n File doesn't exist! ";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);

		data >> pCode >> pName >> price >> dis;
		while (!data.eof())
		{
			if (pKey == pCode)
			{
				cout << "\n\t\t Product new code :";
				cin >> c;
				cout << "\n\t\t Name of the product : ";
				cin >> n;
				cout << "\n\t\t Price : ";
				cin >> p;
				cout << "\n\t\t Discount : ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record Edited! ";
			}
			else
			{
				data1 << " " << pCode << " " << pName << " " << price << " " << dis << "\n";
			}
			data >> pCode >> pName >> price >> dis;
		}
		data.close();
		data1.close();

		//rename functions.
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data, data1;
	int pKey;
	int token = 0;

	cout << "\n\n\t Delete product!";
	cout << "\n\n\t Enter product code : ";
	cin >> pKey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "File Doesnt Exist!";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pCode >> pName >> price >> dis;
		while (!data.eof())
		{
			if (pCode == pKey)
			{
				cout << "\n\n\t Product deleted succesfully!";
				token++;
			}
			else
			{
				data1 << " " << pCode << " " << pName << " " << price << " " << dis << "\n";
			}
			data >> pCode >> pName >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found!";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n ___________________________________________\n ";
	cout << "ProNo \t\t Name \t\t Price\n";
	cout << "\n\n ___________________________________________\n ";
	data >> pCode >> pName >> price >> dis;

	while (!data.eof())
	{
		cout << pCode << "\t\t" << pName << "\t\t" << price << "\n";
		data >> pCode >> pName >> price >> dis;
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;

	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);

	if (!data)
	{
		cout << "\n\n Empty Database!";
	}
	else
	{
		data.close();

		list();
		cout << "\n____________________________\n";
		cout << "\n|                           \n";
		cout << "\n    Please place the order  \n";
		cout << "\n|                           \n";
		cout << "\n____________________________\n";

		do
		{
		m:
			cout << "\n\n Enter Product code : ";
			cin >> arrc[c];
			cout << "\n\n Enter the product quantity : ";
			cout << arrq[c];
			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please enter a new one!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else n";
			cin >> choice;
		} while (choice == 'y');

		cout << "\n\n\t\t\t _____________RECEIPT_______________\n";
		cout << "\nProduct Number \t Product Name \t Product Quantity \t Price \t Amount \t Amout with discount \n";

		for (int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pCode >> pName >> price >> dis;
			while (!data.eof())
			{
				if (pCode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n" << pCode << "\t\t" << pName << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
				}
				data >> pCode >> pName >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n_________________________________\n";
	cout << "\n Total Amount : " << total;
}


int main()
{
	shopping s;
	s.menu();
}



