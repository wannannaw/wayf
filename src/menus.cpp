#include <iostream>
#include <iomanip>

using namespace std;

int showMainMenu(char cAreaName, double dPopulationTotal)
{
	int iMainMenuSelection;
	double displayPopulationTotal;


	cout << "Your country " << cAreaName << "'s statistics\n\n";
	cout << setprecision(0) << fixed <<  "Population: " << displayPopulationTotal << "\n";
	cout << "\tPopulation 0-14 " << 	displaypopulationKids << "\n";
	cout << "\tPopulation 15-24 " << 	displaypopulationTeens << "\n";
	cout << "\tPopulation 25-54 " << 	displaypopulationPrime << "\n";
	cout << "\tPopulation 55-64 " << 	displaypopulationDecline << "\n";
	cout << "\tPopulation 65+ " << 	displaypopulationRetired << "\n";
	cout << "\tBirth Rate: " << displayBirthRate << "\n";
	cout << "\tMigration Rate: " << displayMigrationRate << "\n";
	cout << "\tPopulation Max: " << populationMax << "\n";
	cout << "\tPopulation Percent: " << populationPercent << "\n";
	cout << "\tPopulation Overcrowding: " << popuplationCrowding << "\n";
	cout << "\tPopulation Growth Rate: " << displayPopulationGrowthRate << "\n";
	cout << "\tLife Expectancy :"  << lifeExpectancy << "\n";
	cout << "Infrastructure Percent: " << infrastructurePercent << "\n";
	cout << "DrinkingWater Percent: " << drinkingWaterPercent << "\n";
	cout << "Money: " << displaymoney << "\n";
	cout << "\tTax Rate: " << tax << "\n";
	cout << "\tIncome: " << displayincome << "\n";
	cout << "\t\tTax Income: " << displaytaxIncome << "\n";
	cout << "\t\tAgriculture Income: " << agricultureIncome << "\n";
	cout << "\t\tEnergy Income: " << energyIncome << "\n";
	cout << "\t\tRaw Income: " << rawIncome << "\n";
	cout << "\t\tIndustrial Income: " << industrialIncome << "\n";
	cout << "\t\tFinished Income: " << finishedIncome << "\n";
	cout << "\t\tServices Income: " << servicesIncome << "\n";
	cout << "\tExpense: " << expense << "\n";
	cout << "\t\tDrinking Water Expense: " << drinkingWaterBudget << "\n";
	cout << "\tBudget Blance: " << displaybudgetBalance << "\n";
	cout << "Land\n";
	cout << "\tMax Size: " << maxSize << " square miles\n";
	cout << "\tCurrent developed Size: " << currentSize << " square miles\n";
	cout << "\tUrban: " << composition[0] << "\n";
	cout << "\tRural: " << composition[1] << "\n";
	cout << "\tAgriculture: " << composition[2] << "\n";
	cout << "\tEnergy: " << composition[3] << "\n";
	cout << "\tRaw Materials: " << composition[4] << "\n";
	cout << "\tIndustrial: " << composition[5] << "\n";
	cout << "\tFinished: " << composition[6] << "\n";
	cout << "\tServices: " << composition[7] << "\n\n\n";
	cout << "Which of the following do you want to do?\n";
	cout << "1) Nothing\n";
	cout << "2) Advance Year\n";
	cout << "3) Change tax rate\n";
	cout << "4) Change land Composition\n";
	cout << "5) Change your water budget\n";
	cout << "6) Quit\n";
	cout << "What you're decision: " << endl;
	cin >> iMainMenuSelection;

	return iMainMenuSelection;

}

void showCompositionMenu() {
	cout << "What type of land do you want to develop? \n";
	cout << "Money: " << money << "\n";
	cout << "1) Urban (Cost $100,000)\n";
	cout << "2) Rural (Cost $2,000)\n";
	cout << "3) Agriculture ($5,000)\n";
	cout << "4) Energy ($10,000) \n";
	cout << "5) Raw Materials ($10,000)\n";
	cout << "6) Industrial ($50,000)\n";
	cout << "7) Finished ($100,000)\n";
	cout << "8) Services ($500,000)\n";
	cout << "9) Nevermind (Return to previous Menu)\n";
	cout << "What you're decision: " << endl;
}
