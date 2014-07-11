#include "PopulationCalculators.h"

//Function Calculates an Areas birth Rate
double dfnCalculateBirthRate(double dUrbanizationLevel, double dEducationLevel,
		double dInfantMortalityLevel, double dLevelOfReligionsForbiddingAbortion,
		double dLevelOfReligionsForbiddingContreception, bool bIsAbortionLegal,
		bool bIsContreceptionLegal, double dPopulationCrowdingLevel)
{
	//Max=.05 -- Min=.006 Taken from High/Low CIA World Fact Book
	const double cdBirthRateLevelMax=.05;
	const double cdBirthRateLevelMin=.006;

	//What weight the different levels have on the equation.
	const double cdUrbanizationLevelWeight=.25;
	const double cdEducationLevelWeight=.25;
	const double cdInfantMortalityLevelWeight=.25;
	const double cdLevelOfReligionsForbiddingAbortionWeight=.0625;
	const double cdLevelOfReligionsForbiddingContreceptionWeight=.0625;
	const double cdIsAbortionLegalWeight=.0625;
	const double cdIsContreceptionLegalWeight=.0625;

	//The Range that levels can max at
	const double cdUrbanizationLevelRange=100;
	const double cdEducationLevelRange=100;
	const double cdInfantMortalityLevelRange=118;
	const double cdLevelOfReligionsForbiddingAbortionRange=100;
	const double cdLevelOfReligionsForbiddingContreceptionRange=100;

	//The totals each birth rate levels generate
	double dBirthRateFromUrbanizationLevel;
	double dBrithRateFromEducationLevel;
	double dBirthRateFromInfantMortalityLevel;
	double dBirthRateFromLevelOfReligionsForbiddingAbortion;
	double dBirthRateFromLevelOfReligionsForbiddingContreception;
	double dBirthRateFromIsAbortionLegal;
	double dBirthRateFromIsContreceptionLegal;

	double dBirthRateRange;
	double dBirthRate;

	dBirthRateRange=cdBirthRateLevelMax-cdBirthRateLevelMin;

	//The higher the urban population the lower the birth rate
	dBirthRateFromUrbanizationLevel = (100 - dUrbanizationLevel) * dBirthRateRange *
			cdUrbanizationLevelWeight / cdUrbanizationLevelRange;
	//The higher the education population the lower the birth rate
	dBrithRateFromEducationLevel = (100 - dEducationLevel) * dBirthRateRange * cdEducationLevelWeight /
			cdEducationLevelRange;
	//The higher the infant mortality rate the higher the birth rate
	dBirthRateFromInfantMortalityLevel = ((dInfantMortalityLevel * 1000) - 2) * dBirthRateRange *
			cdInfantMortalityLevelWeight / cdInfantMortalityLevelRange;
	//The higher the religious forbidding the lower the higher the birth rate
	dBirthRateFromLevelOfReligionsForbiddingAbortion = (100 - dLevelOfReligionsForbiddingAbortion) * dBirthRateRange *
			cdLevelOfReligionsForbiddingAbortionWeight / cdLevelOfReligionsForbiddingAbortionRange;
	//The higher the religious forbidding the lower the higher the birth rate
	dBirthRateFromLevelOfReligionsForbiddingContreception = (100 - dLevelOfReligionsForbiddingContreception) * dBirthRateRange *
			cdLevelOfReligionsForbiddingContreceptionWeight / cdLevelOfReligionsForbiddingContreceptionRange;
	//If abortion is legal birth rates are lower
	dBirthRateFromIsAbortionLegal = (1 - bIsAbortionLegal) * dBirthRateRange * cdIsAbortionLegalWeight;
	//If birth control is legal birth rates are lower
	dBirthRateFromIsContreceptionLegal = (1 - bIsContreceptionLegal) * dBirthRateRange * cdIsContreceptionLegalWeight;

	dBirthRate = dBirthRateFromUrbanizationLevel + dBrithRateFromEducationLevel +
			dBirthRateFromInfantMortalityLevel + dBirthRateFromLevelOfReligionsForbiddingAbortion +
			dBirthRateFromLevelOfReligionsForbiddingContreception + dBirthRateFromIsAbortionLegal +
			dBirthRateFromIsContreceptionLegal * dPopulationCrowdingLevel;



	return dBirthRate;
}

//Function calculates the areas life expectancy
double dfnCalculateLifeExpectancy(double dAreaEducationLevel, double dAreaDrinkingWaterLevel,
		double dAreaSanitationLevel, double dHealthCareLevel, double dAreaWarLevel)
{
	//What weight the different levels have on the equation.
	const double cdAreaEducationLevelWeight=.1;
	const double cdAreaDrinkingWaterLevelWeight=.4;
	const double cdAreaSanitationLevelWeight=.3;
	const double cdHealthCareLevelWeight=.1;
	const double cdAreaWarLevelWeight=.1;

	//The totals of life Expectancy each level generates.
	double dLifeExpectancyFromEducationLevel;
	double dLifeExpectancyFromDrinkingWaterLevel;
	double dLifeExpectancyFromSanitationLevel;
	double dLifeExpectancyFromHealthCareLevel;
	double dLifeExpectancyFromdAreaWarLevel;

	//The total Life Expectancy
	double dAgeOfLifeExpectancy;

	//Formulas for generating the age of life expectancy
	dLifeExpectancyFromEducationLevel = dAreaEducationLevel * cdAreaEducationLevelWeight;
	dLifeExpectancyFromDrinkingWaterLevel = dAreaDrinkingWaterLevel * cdAreaDrinkingWaterLevelWeight;
	dLifeExpectancyFromSanitationLevel = dAreaSanitationLevel * cdAreaSanitationLevelWeight;
	dLifeExpectancyFromHealthCareLevel = dHealthCareLevel * cdHealthCareLevelWeight;
	dLifeExpectancyFromdAreaWarLevel = (100-dAreaWarLevel) * cdAreaWarLevelWeight;

	//Adding up the totals.
	dAgeOfLifeExpectancy = dLifeExpectancyFromEducationLevel + dLifeExpectancyFromDrinkingWaterLevel +
			dLifeExpectancyFromSanitationLevel + dLifeExpectancyFromHealthCareLevel +
			dLifeExpectancyFromdAreaWarLevel;

	return dAgeOfLifeExpectancy;
}

//Function calculates the areas migration rate
double dfnCalculateMigrationRate(double dTaxRate, double dAgeOfLifeExpectancy,
		double dDrinkingWaterLevel, double dSanitationLevel, double dHealthCarelevel,
		double dAreaWarLevel, double dEducationLevel, double dPopulationCrowdingLevel)
{
	//min-max retrieved from CIA World Fact Book
	const double cdMigrationRateMin=-.12;
	const double cdMigrationRateMax=.085;

	//What weight the different levels have on the equation.
	const double cdTaxRateWeight=.1;
	const double cdAgeOfLifeExpectancyWeight=.1;
	const double cdDrinkingWaterLevelWeight=.1;
	const double cdSanitationLevelWeight=.1;
	const double cdHealthCarelevelWeight=.1;
	const double cdAreaWarLevelWeight=.1;
	const double cdEducationLevelWeight=.1;
	const double cdPopulationCrowdingLevelWeight=.3;

	//The totals of Migration Rate each level generates.
	double dMigrationRateFromTaxRate;
	double dMigrationRateFromAgeOfLifeExpectancy;
	double dMigrationRateFromDrinkingWaterLevel;
	double dMigrationRateFromSanitationLevel;
	double dMigrationRateFromHealthCarelevel;
	double dMigrationRateFromAreaWarLevel;
	double dMigrationRateFromEducationLevel;
	double dMigrationRateFromPopulationCrowdingLevel;

	double dMigrationRateRange;
	double dMigrationRate;

	dMigrationRateRange=cdMigrationRateMax-cdMigrationRateMin;

	dMigrationRateFromTaxRate = (dTaxRate * 1000) * dMigrationRateRange * cdTaxRateWeight / 100;
	dMigrationRateFromAgeOfLifeExpectancy = dAgeOfLifeExpectancy * dMigrationRateRange *
			cdAgeOfLifeExpectancyWeight / 100;
	dMigrationRateFromDrinkingWaterLevel = dDrinkingWaterLevel * dMigrationRateRange *
			cdDrinkingWaterLevelWeight / 100;
	dMigrationRateFromSanitationLevel = dSanitationLevel * dMigrationRateRange *
			cdSanitationLevelWeight / 100;
	dMigrationRateFromHealthCarelevel = dHealthCarelevel * dMigrationRateRange *
			cdHealthCarelevelWeight / 100;
	dMigrationRateFromAreaWarLevel = dAreaWarLevel * dMigrationRateRange * cdAreaWarLevelWeight / 100;
	dMigrationRateFromEducationLevel = dEducationLevel * dMigrationRateRange *
			cdEducationLevelWeight / 100;
	dMigrationRateFromPopulationCrowdingLevel = (1 - dPopulationCrowdingLevel ) * 1000 *
			dMigrationRateRange * cdPopulationCrowdingLevelWeight / 100;

	dMigrationRate = dMigrationRateFromTaxRate + dMigrationRateFromAgeOfLifeExpectancy +
			dMigrationRateFromDrinkingWaterLevel + dMigrationRateFromSanitationLevel +
			dMigrationRateFromHealthCarelevel + dMigrationRateFromAreaWarLevel +
			dMigrationRateFromEducationLevel + dMigrationRateFromPopulationCrowdingLevel - .12;

	return dMigrationRate;
}
