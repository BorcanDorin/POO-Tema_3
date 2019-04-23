#pragma once
#include "Part.h"
class AutoExteriorPart : public part
{
	bool part_replacement_malfunction_;

	Solution::MaterialType part_replacement_malfunction_fix_;

	int part_replacement_malfunction__screws_;

public:
	AutoExteriorPart(Solution::MaterialType major_malfunction_fix = Solution::no_fix,
		Solution::MaterialType part_replacement_malfunction_fix = Solution::no_fix,
		int major_malfunction_screws = 5,
		int part_replacement_malfunction_screws = 5,
		bool = false, bool = false);
	CheckResult check() override;
	void start_part_break_down();
	~AutoExteriorPart();
};