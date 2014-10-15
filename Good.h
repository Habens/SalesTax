#ifndef _GOOD_H_
#define _GOOD_H_

#include <iostream>
#include <cstring>
using namespace std;
using std::string;

class SalesTax;

class Good
{
public:
	Good();
	Good(SalesTax* salesTax);
	virtual ~Good();

	virtual void CalculatePriceTaxed();	// 税后单价
	virtual void CalculateTotalTax();	// 总稅支出
	void   SetTitle(string title);
	string GetTitle();
	void   SetNum(double num);
	double GetNum();
	void   SetPrice(double price);
	double GetPrice();
	double GetPriceTaxed();
	double GetTax();

protected:
	string title;
	double num;
	double price;	   // 原价
	double priceTaxed; // 税后价格
	double totalTax;   // 需要缴纳的总税

protected:
	SalesTax* salesTax;// 税收计算法
};

class ImportedGood : virtual public Good
{
public:
	ImportedGood();
	ImportedGood(SalesTax* salesTax, double importDuty);
	virtual ~ImportedGood();

	virtual void CalculateTotalTax();

protected:
	double importDuty;
};

class NonFoodBookMedicalGood : virtual public Good
{
public:
	NonFoodBookMedicalGood();
	NonFoodBookMedicalGood(SalesTax* salesTax, double rate);
	virtual ~NonFoodBookMedicalGood();

	virtual void CalculateTotalTax();

protected:
	double rate;
};

class NormalGood : virtual public ImportedGood, virtual public NonFoodBookMedicalGood
{
public:
	NormalGood();
	NormalGood(SalesTax* salesTax, double rate, double importDuty);
	virtual ~NormalGood();

	virtual void CalculateTotalTax();
};

#endif /* _GOOD_H_ */
