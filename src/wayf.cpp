#include <iostream>
#include <fstream>
#include <math.h>
#include "PopulationCalculators.h"
#include "WaterManagementInfrastructureCalculators.h"
#include "BudgetExpenseCalculators.h"

using namespace std;

const char* name="Albion";
int input;
int Linput;
/* float populationKids=20; //0-14
//float populationTeens=20; // 15-24
float populationPrime=20;//25 - 54
float populationDecline=20; //55 -64
float populationRetired=20; //65 +
float kidsLifeExpetancyModifier;
float teensLifeExpetancyModifier;
float primeLifeExpetancyModifier;
float declineLifeExpetancyModifier;
float retiredLifeExpetancyModifier;
float birthRate;
int maxSize=100; //square km
int currentSize;
int i;
int composition [8] = {0,1,0,0,0,0,0,0};
long money=1000000000;
float mediumIncome=10;
float tax=.1;
float urbanPercent;
float educationPercent=50;
float infantMortalityRate=.061; //.002-.120
float religiousAbortion=50;
float religiousContreception=50;
bool legalAbortion=0;
bool legalContreception=0;
float migrationRate=.005; // 85per 1000  -120 per 1000
float deathRate=.005; //18per1000 high 2/1000
float populationBirths;
float populationKidsAdvance;
float populationTeensAdvance;
float populationPrimeAdvance;
float populationDeclineAdvance;
float populationDeaths;
float populationTotal=100;
float popuplationCrowding;
float populationMax;
float populationPercent=0;
float populationTotalOld;
float lifeExpectancy;
float drinkingWaterPercent=0;
long drinkingWaterBudget=0;
float sanitationPercent=100;
float healthCarePercent=100;
float infrastructurePercent=0;
float war=1; //1=not war 0=war
float populationGrowthRate=0;
long drinkingWaterBudgetneeds;
float waterCosts;
float taxIncome;
float agricultureIncome;
float energyIncome;
float rawIncome;
float industrialIncome;
float finishedIncome;
float servicesIncome;
float income;
float expense;
float budgetBalance;
*/

void showMainMenu() {



	cout << "Your country " << name << "'s statistics\n\n";
	float displayPopulationTotal=floorf(populationTotal * 100 + 0.5) / 100;
	cout << "Population: " << displayPopulationTotal << "\n";
	float displaypopulationKids=floorf(populationKids * 100 + 0.5) / 100;
	cout << "\tPopulation 0-14 " << 	displaypopulationKids << "\n";
	float displaypopulationTeens=floorf(populationTeens * 100 + 0.5) / 100;
	cout << "\tPopulation 15-24 " << 	displaypopulationTeens << "\n";
	float displaypopulationPrime=floorf(populationPrime * 100 + 0.5) / 100;
	cout << "\tPopulation 25-54 " << 	displaypopulationPrime << "\n";
	float displaypopulationDecline=floorf(populationDecline * 100 + 0.5) / 100;
	cout << "\tPopulation 55-64 " << 	displaypopulationDecline << "\n";
	float displaypopulationRetired=floorf(populationRetired * 100 + 0.5) / 100;
	cout << "\tPopulation 65+ " << 	displaypopulationRetired << "\n";
	float displayBirthRate=floorf(birthRate * 100 + 0.5) / 100;
	cout << "\tBirth Rate: " << displayBirthRate << "\n";
	float displayMigrationRate=floorf(migrationRate * 100 + 0.5) / 100;
	cout << "\tMigration Rate: " << displayMigrationRate << "\n";
	cout << "\tPopulation Max: " << populationMax << "\n";
	cout << "\tPopulation Percent: " << populationPercent << "\n";
	cout << "\tPopulation Overcrowding: " << popuplationCrowding << "\n";
	float displayPopulationGrowthRate=floorf(populationGrowthRate * 100 + 0.5) / 100;
	cout << "\tPopulation Growth Rate: " << displayPopulationGrowthRate << "\n";
	cout << "\tLife Expectancy :"  << lifeExpectancy << "\n";
	cout << "Infrastructure Percent: " << infrastructurePercent << "\n";
	cout << "DrinkingWater Percent: " << drinkingWaterPercent << "\n";
	double displaymoney=floorf(money * 100 + 0.5) / 100;
	cout << "Money: " << displaymoney << "\n";
	cout << "\tTax Rate: " << tax << "\n";
	float displayincome=floorf(income * 100 + 0.5) / 100;
	cout << "\tIncome: " << displayincome << "\n";
	float displaytaxIncome=floorf(taxIncome * 100 + 0.5) / 100;
	cout << "\t\tTax Income: " << displaytaxIncome << "\n";
	cout << "\t\tAgriculture Income: " << agricultureIncome << "\n";
	cout << "\t\tEnergy Income: " << energyIncome << "\n";
	cout << "\t\tRaw Income: " << rawIncome << "\n";
	cout << "\t\tIndustrial Income: " << industrialIncome << "\n";
	cout << "\t\tFinished Income: " << finishedIncome << "\n";
	cout << "\t\tServices Income: " << servicesIncome << "\n";
	cout << "\tExpense: " << expense << "\n";
	cout << "\t\tDrinking Water Expense: " << drinkingWaterBudget << "\n";
	float displaybudgetBalance=floorf(budgetBalance * 100 + 0.5) / 100;
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

void advanceYear() {
	float populationPrimeMigration=0;

	currentSize=0;
	for (i=0; i<8; i++) {
		currentSize+=composition[i];
	}

	drinkingWaterPercent=dfnCalculateDrinkingWaterLevel(drinkingWaterPercent, drinkingWaterBudgetneeds, drinkingWaterBudget);

	urbanPercent=composition[0]/currentSize*100;

	populationMax=(composition[0]*75000)+(composition[1]*2000)+((currentSize-composition[0]-composition[1])*100);
	populationPercent=populationTotal/populationMax;

	if (( populationPercent >= .75) && (populationPercent < .80)) {
		popuplationCrowding = .9;
	}
	else if (( populationPercent >= .80 ) && (populationPercent < .85)) {
		popuplationCrowding = .8;
	}
	else if (( populationPercent >= .85 ) && (populationPercent < .90)) {
		popuplationCrowding = .65;
	}
	else if (( populationPercent >= .90 ) && (populationPercent < .95)) {
		popuplationCrowding = .5;
	}
	else if (( populationPercent >= .9 ) && (populationPercent < 1)) {
		popuplationCrowding = .25;
	}
	else if ( populationPercent >= 1 ) {
		popuplationCrowding = 0;
	}
	else {
		popuplationCrowding = 1;
	}

	lifeExpectancy=dfnCalculateLifeExpectancy(educationPercent, drinkingWaterPercent, sanitationPercent, healthCarePercent, war);
	birthRate=dfnCalculateBirthRate(urbanPercent,educationPercent,infantMortalityRate,religiousAbortion,religiousContreception,legalAbortion,legalContreception,popuplationCrowding);
	migrationRate=dfnCalculateMigrationRate(tax, lifeExpectancy, drinkingWaterPercent, sanitationPercent, healthCarePercent, war, educationPercent, populationPercent);

	if ( lifeExpectancy > 65 ) {
		kidsLifeExpetancyModifier=0;
		teensLifeExpetancyModifier=0;
		primeLifeExpetancyModifier=0;
		declineLifeExpetancyModifier=0;
		retiredLifeExpetancyModifier=(lifeExpectancy-65)/35/10;
	}
	else if ((lifeExpectancy > 55 ) && ( lifeExpectancy < 65 )) {
		kidsLifeExpetancyModifier=0;
		teensLifeExpetancyModifier=0;
		primeLifeExpetancyModifier=0;
		declineLifeExpetancyModifier=(lifeExpectancy-55)/10;
		retiredLifeExpetancyModifier=.95;
	}
	else if ((lifeExpectancy > 25 ) && ( lifeExpectancy < 55 )) {
		kidsLifeExpetancyModifier=0;
		teensLifeExpetancyModifier=0;
		primeLifeExpetancyModifier=(lifeExpectancy-25)/30;
		declineLifeExpetancyModifier=.95;
		retiredLifeExpetancyModifier=.95;
	}
	else if ((lifeExpectancy > 15 ) && ( lifeExpectancy < 25 )) {
		kidsLifeExpetancyModifier=0;
		teensLifeExpetancyModifier=(lifeExpectancy-10)/10;
		primeLifeExpetancyModifier=.95;
		declineLifeExpetancyModifier=.95;
		retiredLifeExpetancyModifier=.95;
	}
	else if ( lifeExpectancy < 15 ) {
		kidsLifeExpetancyModifier=lifeExpectancy/15/10;
		teensLifeExpetancyModifier=.95;
		primeLifeExpetancyModifier=.95;
		declineLifeExpetancyModifier=.95;
		retiredLifeExpetancyModifier=.95;
	}

	float populationKidsDie=populationKids*kidsLifeExpetancyModifier;
	float populationTeensDie=populationTeens*teensLifeExpetancyModifier;
	float populationPrimeDie=populationPrime*primeLifeExpetancyModifier;
	float populationDeclineDie=populationDecline*declineLifeExpetancyModifier;
	float populationRetiredDie=populationRetired*retiredLifeExpetancyModifier;


	populationBirths=(populationTeens*birthRate/2)+(populationPrime*birthRate)+(populationDecline*birthRate);
	populationKidsAdvance=populationKids/15;
	populationTeensAdvance=populationTeens/10;
	populationPrimeAdvance=populationPrime/30;
	populationDeclineAdvance=populationDecline/10;
	populationDeaths=populationRetired/35;

	populationPrimeMigration=populationPrime*migrationRate;

	populationKids+=populationBirths-populationKidsAdvance-populationKidsDie;
	populationTeens+=populationKidsAdvance-populationTeensAdvance-populationTeensDie;
	populationPrime+=populationTeensAdvance-populationPrimeAdvance-populationPrimeDie+populationPrimeMigration;
	populationDecline+=populationPrimeAdvance-populationDeclineAdvance-populationDeclineDie;
	populationRetired+=populationDeclineAdvance-populationDeaths-populationRetiredDie;

	populationTotalOld=populationTotal;
	populationTotal=populationKids+populationTeens+populationPrime+populationDecline+populationRetired;
	populationGrowthRate=populationTotal/populationTotalOld;



	taxIncome=populationTotal * mediumIncome * tax;
	agricultureIncome=composition[2]*100*2;
	energyIncome=composition[3]*100*2;
	rawIncome=composition[4]*100*10;
	industrialIncome=composition[5]*100*15;
	finishedIncome=composition[6]*100*15;
	servicesIncome=composition[7]*100*15;
	income = taxIncome + agricultureIncome + energyIncome + rawIncome + industrialIncome + finishedIncome + servicesIncome;
	expense = drinkingWaterBudget;
	money = money + income - expense;
	budgetBalance = income - expense;
}

int main()
{
	bool bQuit = false;
	int iMainMenuSelection;
	char compositionMove ='z';
	double displaydrinkingWaterBudget;
	double displaydrinkingWaterBudgetNeeds;

	cout << fixed;
	cout.precision(2);

	while(!bQuit)
	{
		showMainMenu();

		cin >> iMainMenuSelection;

		switch (iMainMenuSelection)
		{
			case 1:
				break;
			case 2:
				advanceYear();
				break;
			case 3:
				cout << "What is the new tax rate? 10%=.10: ";
				cin >> tax;
				break;
			case 4:
				if ( currentSize < 100 )
				{
					showCompositionMenu();
					cin >> compositionMove;
						switch (compositionMove)
						{
							case '1':
								if(money < 100000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[0]=composition[0]+1;
									money=money-100000;
								}
								break;
							case '2':
								if(money < 2000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[1]=composition[1]+1;
									money=money-2000;
								}
								break;
							case '3':
								if(money < 5000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[2]=composition[2]+1;
									money=money-5000;
								}
								break;
							case '4':
								if(money < 10000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[3]=composition[3]+1;
									money=money-10000;
								}
								break;
							case '5':
								if(money < 10000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[4]=composition[4]+1;
									money=money-10000;
								}
								break;
							case '6':
								if(money < 50000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[5]=composition[5]+1;
									money=money-50000;
								}
								break;
							case '7':
								if(money < 100000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[6]=composition[6]+1;
									money=money-100000;
								}
								break;
							case '8':
								if(money < 500000) {
									cout << "Sorry you can't afford this";
									break;
								}
								else {
									composition[7]=composition[7]+1;
									money=money-500000;
								}
								break;
							case '9':
								break;
							default:
								std::cout << "Bad Input, Try again " << std::endl;
								break;
						}
				}
				else {
					cout << "You need to aquire addition land for your country before you can develope it\n";
				}
				break;
			case 5:
				drinkingWaterBudgetneeds=dfnDrinkingWaterExpenseCalculator(infrastructurePercent,
						drinkingWaterPercent, populationTotal);
				displaydrinkingWaterBudget=floorf(drinkingWaterBudget * 100 + 0.5) / 100;
				cout << "Water Budget: " << displaydrinkingWaterBudget << "\n";
				displaydrinkingWaterBudgetNeeds=floorf(drinkingWaterBudgetneeds * 100 + 0.5) / 100;
				cout << "Water Budget Needs " << displaydrinkingWaterBudgetNeeds << " to maintain current Drinking Water Levels.";
				cin >> drinkingWaterBudget;
				break;
            case 6:
                bQuit = true;
                return 0;
                break;
			default:
				std::cout << "Bad Input, Try again " << std::endl;
				break;
			}
		}
return 0;
}
