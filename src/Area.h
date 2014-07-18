class area
{
	public:
		double dPopulationTotal; //Sum of all population age groups
		double dPopulationKids; //ages 0-14
		double dPopulationYoung; //ages 15-24
		double dPopulationPrime; //ages 25-54
		double dPopulationDecline; //ages 55-64
		double dPopulationRetire; //ages 65+
		double dLifeExpectancyModifierKids;
		double dLifeExpectancyModifierYoung;
		double dLifeExpectancyModifierPrime;
		double dLifeExpectancyModifierDecline;
		double dLifeExpectancyModifierRetired;
		double dBirthRate;
		double dAreaMoney;
		double dAreaMediumIncome;
		double dUrbanizationLevel;
		double dEducationLevel;
		double dLevelOfReligionsForbiddingAbortion;
		double dLevelOfReligionsForbiddingContreception;
		double dInfantMortalityRate; //.002-.120
		double dMigrationRate; // 85per 1000  -120 per 1000
		double dDeathRate; //18per1000 high 2/1000
		double dPopulationGrowthKids;
		double dPopulationKidsToYoung;
		double dPopulationYoungToPrime;
		double dPopulationPrimeToDecline;
		double dPopulationDeclineToRetired;
		double dPopulationDeclineRetired;
		double dPopulationCrowdingLevel;
		double dPopulationSupportedMax;
		double dPopulationLevel;
		double dPopulationTotalOld;
		double dLifeExpectancyRate;
		double dDrinkingWaterLevel;
		double dSanitationLevel;
		double dHealthCareLevel;
		double dInfrastructureLevel;
		double dAreaWarLevel;
		double dPopulationGrowthRate;

		double dDrinkingWaterExpenses;

		double dBudgetForDrinkingWater;

		double dTaxIncome;
		double dAgricultureIncome;
		double dEnergyIncome;
		double dRawIncome;
		double dIndustrialIncome;
		double dFinishedIncome;
		double dServicesIncome;
		double dIncomeTotal;
		double dExpenseTotal;
		double dBudgetBalance;

		bool bIsAbortionLegal;
		bool bIsContreceptionLegal;

		int iAreaSize; //In square kilometers
		int iDevelopedAreaSize; //In square kilometers
		int iaAreaComposition [8]; //0=urban,1=rural,2=agriculture,3=energy,4=Raw Materials,5=Industrial,6=Finished,7=Services

		area();
		virtual ~area();
};


