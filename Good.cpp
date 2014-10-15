#include "Good.h"
#include "SalesTax.h"

Good::Good(){}

Good::Good(SalesTax* salesTax):salesTax(salesTax), price(0), priceTaxed(0), totalTax(0){}

Good::~Good(){}

void Good::CalculatePriceTaxed()
{
	priceTaxed = num * (price + totalTax);
}

void Good::CalculateTotalTax()
{
	totalTax = num * salesTax->CalculateSalesTax(price, 0, 0);
}

string Good::GetTitle()
{
	return title;
}

void Good::SetNum(double aNum)
{
	num = aNum;
}

double Good::GetNum()
{
	return num;
}

void Good::SetTitle(string aTitle)
{
	title = aTitle;
}

void Good::SetPrice(double aprice)
{
	price = aprice;
}

double Good::GetPrice()
{
	return price;
}

double Good::GetPriceTaxed()
{
	return priceTaxed;
}

double Good::GetTax()
{
	return totalTax;
}

/**
 * ImportedGood
 */

ImportedGood::ImportedGood(){}

ImportedGood::ImportedGood(SalesTax* aSalesTax, double aImportDuty):Good(aSalesTax)
{
	importDuty = aImportDuty;
}

ImportedGood::~ImportedGood(){}

void ImportedGood::CalculateTotalTax()
{
	totalTax = num * salesTax->CalculateSalesTax(price, 0, importDuty);
}

/**
 * NonFoodBookMedialGood
 */
NonFoodBookMedicalGood::NonFoodBookMedicalGood(){}

NonFoodBookMedicalGood::NonFoodBookMedicalGood(SalesTax* aSalesTax, double aRate):Good(aSalesTax)
{
	rate = aRate;
}

NonFoodBookMedicalGood::~NonFoodBookMedicalGood(){}

void NonFoodBookMedicalGood::CalculateTotalTax()
{
	totalTax = num * salesTax->CalculateSalesTax(price, rate, 0);
}

NormalGood::NormalGood() {}

NormalGood::NormalGood(SalesTax* aSalesTax, double aRate, double aImportDuty):Good(aSalesTax)
{
	rate = aRate;
	importDuty = aImportDuty;
}

NormalGood::~NormalGood() {}

void NormalGood::CalculateTotalTax()
{
	totalTax = num * salesTax->CalculateSalesTax(price, rate, importDuty);
}
