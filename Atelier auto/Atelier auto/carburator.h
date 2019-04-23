#pragma once
#include "Part.h"
class carburator : public part
{
public:
	carburator(Solution::MaterialType major_malfunction_fix = Solution::no_fix,
				int major_malfunction_screws = 5,
				bool = false);
	CheckResult check() override;
	~carburator();
};

