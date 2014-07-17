class area
{
		double dPopulationKids; //ages 0-14
		double dPopulationYoung; //ages 15-24
		double dPopulationPrime; //ages 25-54
		double dPopulationDecline; //ages 55-64
		double dPopulationRetire; //ages 65+
		double dPopulationTotal; //Sum of all population age groups
		double dLifeExpectancyModifierKids;
		double dLifeExpectancyModifierYoung;
		double dLifeExpectancyModifierPrime;
		double dLifeExpectancyModifierDecline;
		double dLifeExpectancyModifierRetired;
		double dBirthRate;
		double dAreaMoney;
		double dAreaMediumIncome;
		int iAreaSize; //In square kilometers
		int iDevelopedAreaSize; //In square kilometers
		int iaAreaComposition [8]; //0=urban,1=rural,2=agriculture,3=energy,4=Raw Materials,5=Industrial,6=Finished,7=Services

	public:
		area();
		virtual ~area();
};




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
