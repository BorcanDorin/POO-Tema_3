#pragma once
#include "Part.h"

class Wheel : public part
{
	bool wheel_malfunction_;

	Solution::MaterialType major_malfunction_fix_;
	Solution::MaterialType wheel_malfunction_fix_;

	int major_malfunction_screws_;
	int wheel_malfunction_screws_;

public:
	Wheel(Solution::MaterialType major_malfunction_fix = Solution::no_fix, 
		  Solution::MaterialType wheel_malfunction_fix = Solution::no_fix, 
		  int major_malfunction_screws = 5, 
		  int wheel_malfunction_screws = 5, 
		  bool = false, bool = false);
	CheckResult check() override;
	void start_wheel_break_down();
	~Wheel();
};
