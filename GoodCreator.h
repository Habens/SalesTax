#ifndef _GOODCREATOR_H_
#define _GOODCREATOR_H_
#include "Good.h"

const int GOOD_WITH_NOSALESTAX_AND_IMPORTDUTY = 1;
const int GOOD_WITH_NOSALESTAX_ONLY_IMPORTDUTY = 2;
const int GOOD_WITH_ONLY_SALESTAX_AND_NOIMPORTDUTY = 3;
const int GOOD_WITH_BOTH_SALESTAX_AND_IMPORTDUTY = 4;

const double SALES_TAX_RATE = 10;
const double IMPORT_DUTY_RATE = 5;

class Not_A_Standard_Good_Type_Exception
{
public:
	void printerrormsg();
};

class GoodCreator
{
public:
	virtual Good* Create(int goodType);
};

#endif /* _GOODCREATOR_H_ */
