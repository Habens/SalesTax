#include "GoodCreator.h"
#include "Good.h"
#include "SalesTax.h"

#include <iostream>

using namespace std;

void Not_A_Standard_Good_Type_Exception::printerrormsg()
{
	cout<<"Not the right Good Type..."<<endl;
}

Good* GoodCreator::Create(int aGoodType)
{
	SalesTax* st = new SalesTax();

	switch(aGoodType)
	{
	case GOOD_WITH_NOSALESTAX_AND_IMPORTDUTY:
		return new Good(st);
		break;

	case GOOD_WITH_NOSALESTAX_ONLY_IMPORTDUTY:
		return new ImportedGood(st,IMPORT_DUTY_RATE);
		break;

	case GOOD_WITH_ONLY_SALESTAX_AND_NOIMPORTDUTY:
		return new NonFoodBookMedicalGood(st,SALES_TAX_RATE);
		break;

	case GOOD_WITH_BOTH_SALESTAX_AND_IMPORTDUTY:
		return new NormalGood(st,SALES_TAX_RATE,IMPORT_DUTY_RATE);
		break;

	default:
		throw Not_A_Standard_Good_Type_Exception();
	}
}
