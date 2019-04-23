#pragma once
#include "Part.h"

class HandleBar : public part
{
	bool handle_bar_malfunction_;

	Solution::MaterialType handle_bar_malfunction_fix_;

	int handle_bar_malfunction_screws_;

public:
	HandleBar(Solution::MaterialType major_malfunction_fix = Solution::no_fix, 
			  Solution::MaterialType handle_bar_malfunction_fix = Solution::no_fix, 
			  int major_malfunction_screws = 5, 
			  int handle_bar_malfunction_screws = 5, 
			  bool = false, bool = false);
	CheckResult check() override;
	void start_handle_bar_break_down();
	~HandleBar();
};
