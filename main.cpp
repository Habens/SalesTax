#include "SalesTax.h"
#include "Good.h"
#include "GoodCreator.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using std::string;

int main()
{
	typedef vector<Good*> listOfGood;
	listOfGood::iterator theIterator;

	listOfGood Basket;
	char answer = 'n';

	double totalprice = 0;
	double totaltax = 0;

	cout<<"1 for good with no sales tax and no import duty"<<endl;
	cout<<"2 for good with no sales tax only import duty"<<endl;
	cout<<"3 for good with only sales tax and no import duty"<<endl;
	cout<<"4 for good with both sales tax and import duty"<<endl;

	do
	{
		// 1. get good's category  
		int type_of_good;
		cout << "Enter the type of Good...1,2,3,4" << endl;
		cin >> type_of_good;

		GoodCreator* goodCreator = new GoodCreator();
		try
		{
			// 2. create new good with the category
			Good* good = goodCreator->Create(type_of_good);

			// 3. init new good
			cout << "Enter the title of the Good" << endl;
			string title;
			cin >> title;
			good->SetTitle(title);

			cout << "Enter the number of the Good" << endl;
			double num;
			cin >> num;
			good->SetNum(num);

			cout << "Enter the unit price of the Good" << endl;
			double price;
			cin >> price;
			good->SetPrice(price);

			// 4. add to vector
			Basket.push_back(good);
		}

		catch(Not_A_Standard_Good_Type_Exception& e)
		{
			e.printerrormsg();
		}

		cout << "Do you want to continue... Y/N"<<endl;
		cin >> answer;
	}
	while (answer =='y');

	theIterator = Basket.begin();

	/* 5. get total tax and total price */
	int pos = 0;
	while (theIterator != Basket.end())
	{
		Basket.at(pos)->CalculateTotalTax();
		totaltax += Basket.at(pos)->GetTax();
		Basket.at(pos)->CalculatePriceTaxed();
		double priceTaxed = Basket.at(pos)->GetPriceTaxed();
		totalprice += priceTaxed;
		cout << Basket.at(pos)->GetNum() << " " << Basket.at(pos)->GetTitle() << ": " << Basket.at(pos)->GetPrice() << endl;
		theIterator++;
		pos++;
	}
	cout << "------------" << endl;
	cout << "Toal tax " << totaltax << endl;
	cout << "Total price " << totalprice << endl;

	return 1;
}
