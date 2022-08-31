// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;


class  market
{

private:
	int pcode;
	float price;
	float dis;
	string pname;
	 market();
	~ market();

public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
	

};

void market::menu() {
	int choise;
	string email;
	int passord;
	m :

	cout << "\t\t\t\t________________________________\n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t       market main menu         \n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t________________________________\n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t 1-Administrator                \n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t 2-Buyer                        \n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t 3-Exit                         \n";
	cout << "\t\t\t\t                                \n";
	cout << "\t\t\t\t      pleas selsct              \n";

	cin >> choise;
	switch ( choise ){
	case 1:
		cout << "\t\t\t plaese login" << endl;
		cout << "\t\t\t enter your "  << endl;
		cin >> email;
		cout << "\t\t\t enter passord "<<endl;
		cin >> passord;

		break;

	case 2:
	{
		buyer();
	}
	break;
	case 3 :
	{
		exit(0);
	}
	break;
	default:
		cout << "eror...pleas selact from menu " << endl;
		{
			goto m;
		}
		break;
	}
}

void market::administrator() {
	int choise;
	m:
	cout << "\n\n\n\n\t\t\t administrator mune ";
	cout << "\n\t\t\t 1-Add the prodact   ";
	cout << "\n\t\t\t                     ";
	cout << "\n\t\t\t 2-Modify the prodact";
	cout << "\n\t\t\t                     ";
	cout << "\n\t\t\t 3-Delete the prodact";
	cout << "\n\t\t\t                     ";
	cout << "\n\t\t\t--- 4-Back to menu---";

	cout << "\n\n\t plase enter your choise :";
	cin >> choise;
	switch (choise)
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "eror ...you choise";
		break;
	}
	goto m;
}
 void market ::buyer (){
	 int choise;
	 m :
	 cout << "\t\t\t      Buyer     \n";
	 cout << "\t\t\t----------------\n";
	 cout << "\t\t\t 1-Buyer Product\n";
	 cout << "\t\t\t                \n";
	 cout << "\t\t\t 2-Go Back      \n";
	 cout << "\n\t enter your choise :";
	 cin >> choise;
	 switch (choise)
	 {
	 case 1 :
		 receipt();
		 break;
	 case 2:
		 menu();
		 break;
	 default:
		 cout << "eror ....your choise woring ";
		 break;
	 }
	 goto m;
 }
 void market::add() {
	 fstream data;
	 int c;
	 int token = 0;
	 float p;
	 float d;
	 string n;
	 m:
	 cout << "\n\n\t\t\t Add new prodact \n";
	 cout << "\n\n\t prodact code of the product \n";
	 cin  >> pcode;
	 cout << "\n\n name the prodact :";
	 cin  >> pname;
	 cout << "\n\n prico of the prodact :";
	 cin  >> price;
	 cout << "\n\n Discount on prodact :";
	 cin >> dis;
	 data.open("databease.txt",ios::in);
	 if (!data) {
		 data.open("databease.txt", ios::app | ios::out);
		 data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		 data.close();
	 }
	 else {
		 data >>c>>n>>p>>d;
		 while (!data.eof())
		 {
			 if (c == pcode) {
				 token++;
			 }
			 data >> c >> n >> p >> d;
		 }
		 data.close();
	 }
	 if (token == 1) {
		 goto m;
	 }
	 else {
		 data.open("databease.txt", ios::app | ios::out);
		 data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		 data.close();
	 }
	 cout << "\n\n\t\t Rocord inserted ";
 }

 void market::edit() {
	 fstream data, data1;
	 int pkey;
	 int token=0;
	 int c;
	 float p;
	 float d;
	 string n;

	 cout << "\n\t\t\t modifl the record ";
	 cout << "\n\t\t\t product code      ";
	 cin >> pkey;

	 data.open("databease.txt", ios::in);
	 if (!data) {
		 cout << "\n\n file dosnt exist ";

	 }
	 else {
		 data.open("databease.txt", ios::app | ios::out);
		 data >> pcode >> pname >> price >> dis;
		 while (!data) {
			 if (pkey == pcode) {
				 cout << "\n\t\t prodact new code :";
				 cin >> c;
				 cout << "\\t\t name of the prodact :";
				 cin >> n;
				 cout << "\n\t\t price :";
				 cin >> p;
				 cout << "\n\t\t discound :";
				 cin >> d;
				 data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				 cout << "\n\n\t\t recode edied ";
				 token++;

			 }
			 else {
				 data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

			 }
			 data >> pcode >> pname >> price >> dis;
		 }
		 data.close();
		 data1.close();

		 remove("databease.txt");
		 rename("databease1.txt", "databease.txt");
		 if (token == 0) {
			 cout << "\n\n recode not found sorry";
		 }
	 }



 }

 void market::rem() {
	 fstream data, data1;
	 int pkey;
	 int token = 0;
	 cout << "\n\n\t Delet product ";
	 cout << "\n\n\t prodacut code :";
	 cin >> pkey;
	 data.open("databease.txt", ios::in);
	 if (!data) {
		 cout << "file dosent exits";

	 }
	 else {
		 data1.open("databease.txt", ios::app | ios::out);
		 data >> pcode >> pname >> price >> dis;
		 while (!data.eof()) {
			 if (pcode == pkey) {
				 cout << "\n\n\t prodauct deleted scssfule ";
				 token++;
			 }
			 else {
				 data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

			 }
			 data >> pcode >> pname >> price >> dis;
		 }
		 data.close();
		 data1.close();
		 //rename("databease.txt");
		 rename("databease1.txt","databease.txt");

		 if (token == 0) {
			 cout << "\n\n recode not found ";
		 }

	 }
 }

 void market::list() {
	 fstream data;
	 data.open("databeas.txt", ios::in);
	 cout << "\n\n--------------------------------------------\n";
	 cout << "prono \t\tname\t\tprice ";
	 cout << "\n\n---------------------------------------------\n";
	 data >> pcode >> pname >> price >> dis;
	 while (!data.eof()) {
		 cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		 data >> pcode >> pname >> price >> dis;
	 }
	 data.close();
		 
 }
 void market::receipt() {
	 m:
	 fstream data;
	 int arrc[100];
	 int arrq[100];
	 char choise;
	 int c = 0;
	 float amount=0;
	 float dis = 0;
	 float totle = 0;
	 cout << "\n\n\t\t\t\t RECEIPT";
	 data.open("databease.txt", ios::in);
		 if(!data) {
			 cout << "\n\n empty databease ";

		 }else 
		 {
			 data.close();
			 list();
			 cout << "\n-----------------------------------------------\n";
			 cout << "\n|                                              \n";
			 cout << "\n           plase place the oder                \n";
			 cout << "\n|                                              \n";
			 cout << "\n-----------------------------------------------\n";
			 do {
				 cout << "\n\n Enter prodact code :";
				 cin  >> arrc[c];
				 cout << "\n\n Enter the prodact quantiy :";
				 cin >> arrq[c];
				 for (int i = 0;i < c;i++) {
					 if (arrc[c] == arrc[i]) {
						 cout << "\n\n Duplicate product code . plese try agine !";
						 goto m;
					 }
				 }
				 c++;
				 cout << "\n\n Do you went buy anther prodact ? if yes than press y else no";
			 } while (choise == 'y');
			 cout << "\n\n\t\t\t--------------------RECEIPT--------------------\n";
			 cout << "\n prodact number no \t prodact name \t prodact qunantity \t price \t amount \t aount whit discound ";
			 for (int i = 0;i < c; i++) {
				 data.open("databeas.txt", ios::in);
				 data >> pcode >> pname >> price >> dis;
				 while (!data.eof()) {
					 if (pcode == arrc[i]) {
						 amount = price * arrq[i];
						 dis = amount - (amount * dis / 100);
						 totle = totle * dis;
						 cout << "\n " << pcode <<"\t\t"<< pname <<"\t\t" << arrq[i]  <<"\t\t"<< price <<"\t\t"<< amount <<"\t\t"<< dis;

					 }
					 data >> pcode >> pname >> price >> dis;
				 }
			 }
			 data.close();
		 }
		 cout << "\n\n----------------------------------------------------------";
		 cout << "\n TOTLE AMOUNT :" << totle;
 }
 
 market:: market()
{
}

 market::~ market()
{
}


int main()
{
  
	market a1;
	a1.menu();
	
	return 0;
}


