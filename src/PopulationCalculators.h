double dfnCalculateBirthRate(double dUrbanizationLevel, double dEducationLevel,
		double dInfantMortalityLevel, double dLevelOfReligionsAllowingAbortion,
		double dLevelOfReligionsAllowingContreception, bool bIsAbortionLegal,
		bool bIsContreceptionLegal, double dPopulationCrowdingLevel);

double dfnCalculateLifeExpectancy (double dAreaEducationLevel, double dAreaDrinkingWaterLevel,
		double dAreaSanitationLevel, double dHealthCareLevel, double dAreaWarLevel);

double dfnCalculateMigrationRate(double dTaxRate, double dAgeOfLifeExpectancy,
		double dDrinkingWaterLevel, double dSanitationLevel, double dHealthCarelevel,
		double dAreaWarLevel, double dEducationLevel, double dPopulationCrowdingLevel);
