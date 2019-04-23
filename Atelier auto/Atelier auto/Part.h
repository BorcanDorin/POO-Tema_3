#pragma once
#include "CheckResult.h"

class part
{
protected:
	bool major_malfunction_;

	Solution::MaterialType major_malfunction_fix_;

	int major_malfunction_screws_;

public:
	explicit part(bool major_malfunction  = false, Solution::MaterialType major_malfunction_fix = Solution::no_fix, int major_malfunction_screws = 5);
	void start_major_malfunction();
	virtual CheckResult check() = 0;
	virtual ~part();
};