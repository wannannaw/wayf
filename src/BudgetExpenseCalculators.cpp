#include "BudgetExpenseCalculators.h"

using namespace std;

double dfnDrinkingWaterExpenseCalculator(double dInfrastructureLevel, double dDrinkingWaterLevel,
		double dPopulationTotal)
{
	//The Range that levels can max at
	const double cdInfrastructureLevelRange=100;
	const double cdDrinkingWaterLevelRange=100;

	//What weight the different levels have on the equation.
	const double cdInfrastructureLevelWeight=.5;
	const double cdDrinkingWaterLevelWeight=.5;

	//// 3000$ for 127000 gallons/year (guatamala city) 200$ for 127000 gallons/year (Washington dc)
	const double cdDrinkingWaterExpenseMax=.02355;
	const double cdDrinkingWaterExpenseMin=.00157;


	double dDrinkingWaterExpenseRange;
	double dDrinkingWaterExpensesfromInfrastructureLevel;
	double dDrinkingWaterExpensesfromDrinkingWaterLevelCosts;
	double dDrinkingWaterExpensesPerDayPerPerson;
	double dDrinkingWaterExpenses;


	dDrinkingWaterExpenseRange = cdDrinkingWaterExpenseMax - cdDrinkingWaterExpenseMin;


	//The higher the urban population the lower the birth rate
	dDrinkingWaterExpensesfromInfrastructureLevel = ( 100 - dInfrastructureLevel ) *
			dDrinkingWaterExpenseRange *cdInfrastructureLevelWeight/cdInfrastructureLevelRange;

	dDrinkingWaterExpensesfromDrinkingWaterLevelCosts = ( 100 - dDrinkingWaterLevel ) *
			dDrinkingWaterExpenseRange * cdDrinkingWaterLevelWeight/dDrinkingWaterExpenseRange;

	dDrinkingWaterExpensesPerDayPerPerson = dDrinkingWaterExpensesfromInfrastructureLevel +
			dDrinkingWaterExpensesfromDrinkingWaterLevelCosts;

	dDrinkingWaterExpenses = dDrinkingWaterExpensesPerDayPerPerson * 365 * 100 * dPopulationTotal;

	return dDrinkingWaterExpenses;
}
