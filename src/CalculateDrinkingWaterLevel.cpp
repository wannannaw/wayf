#include "CalculateDrinkingWaterLevel.h"

//Function calculates the drinking water level
double dfnCalculateDrinkingWaterLevel(double dDrinkingWaterLevel,
		double dDrinkingWaterMaintenanceCosts, double dDrinkingWaterBudgetExpenses)
{


	double dDrinkingWaterModifiedLevel;
	double dDrinkingWaterNewLevel;
	double dDrinkingWaterOldLevel;

	dDrinkingWaterOldLevel = dDrinkingWaterLevel;

	if ( dDrinkingWaterBudgetExpenses < dDrinkingWaterMaintenanceCosts)
	{
		dDrinkingWaterModifiedLevel = ( dDrinkingWaterMaintenanceCosts - dDrinkingWaterBudgetExpenses ) /
				dDrinkingWaterMaintenanceCosts * 5;
		dDrinkingWaterNewLevel = dDrinkingWaterOldLevel - dDrinkingWaterModifiedLevel;

		if ( dDrinkingWaterNewLevel < 0)
		{
			dDrinkingWaterNewLevel = 0;
		}
	}
	else if (dDrinkingWaterBudgetExpenses > dDrinkingWaterMaintenanceCosts )
	{
		dDrinkingWaterModifiedLevel = dDrinkingWaterBudgetExpenses / dDrinkingWaterMaintenanceCosts /
				10.0;
		dDrinkingWaterNewLevel = dDrinkingWaterOldLevel + dDrinkingWaterModifiedLevel;

		if ( dDrinkingWaterNewLevel > 100 )
		{
			dDrinkingWaterNewLevel = 100;
		}
	}

	return dDrinkingWaterNewLevel;
}
