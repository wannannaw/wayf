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
int i;



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
	char cAreaName="Utah";

	cout << fixed;
	cout.precision(2);

	area Utah;

	while(!bQuit)
	{
		iMainMenuSelection=showMainMenu(cAreaName, cAreaName.dPopulationTotal);

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
