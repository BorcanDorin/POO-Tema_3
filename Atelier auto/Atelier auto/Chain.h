#pragma once
#include "Part.h"

class Chain : public part
{
	bool chain_malfunction_;

	Solution::MaterialType major_malfunction_fix_;
	Solution::MaterialType chain_malfunction_fix_;

	int major_malfunction_screws_;
	int chain_malfunction_screws_;

public:
	Chain(Solution::MaterialType major_malfunction_fix = Solution::no_fix, Solution::MaterialType chain_malfunction_fix = Solution::no_fix, int major_malfunction_screws = 5, int chain_malfunction_screws = 5, bool = false);
	CheckResult check() override;
	void start_chain_usage();
	~Chain();
};
