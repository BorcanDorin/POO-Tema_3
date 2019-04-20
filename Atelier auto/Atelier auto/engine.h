#pragma once
#include "Part.h"
class engine : public part
{
	bool low_oil_level_;

	Solution::MaterialType major_malfunction_fix_;
	Solution::MaterialType low_oil_level_fix_;

	int major_malfunction_screws_;
	int low_oil_level_screws_;

public:
	engine(Solution::MaterialType major_malfunction_fix = Solution::no_fix,
			Solution::MaterialType low_oil_level_fix = Solution::no_fix,
			int major_malfunction_screws = 5,
			int low_oil_level_screws = 5,
			bool = false, bool = false);
	CheckResult check() override;
	void start_low_oil_level();
	~engine();
};