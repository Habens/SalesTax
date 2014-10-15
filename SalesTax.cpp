#include "SalesTax.h"

SalesTax::SalesTax(){}

double SalesTax::CalculateSalesTax(double aPrice, double aRate, double aImportduty)
{
	double tx = (aPrice*aRate/(double(100))) + (aPrice*aImportduty/(double(100)));
	return RoundOff(tx);
}

double SalesTax::RoundOff(double aTax)
{
	int taxTemp = (int)aTax;
	double decimaltaxTemp = (double)(aTax - (int)taxTemp);
	int tempy = (int)(1000*decimaltaxTemp)/100;
	int tempz = (int)(1000*decimaltaxTemp - tempy*100);
	int temp = (int)(tempz/10);
	int t = tempz%10;
	if (t >= 5) {
		temp+=1;
	};

	return (double)(taxTemp + tempy*(0.1) + temp*(0.01));
}
