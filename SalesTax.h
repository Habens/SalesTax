#ifndef _SALESTAX_H_
#define _SALESTAX_H_
class SalesTax
{
public:
	SalesTax();
	virtual double CalculateSalesTax(double aPrice, double aRate, double aImportduty);
private:
	//This is an helper function which will round off the sales tax
	double RoundOff(double aTax);
};

#endif /* _SALESTAX_H_ */
