#pragma once
#include <vector>
#include "Solution.h"
#include <ostream>
#include <iostream>
#include <algorithm>

class CheckResult
{
	bool check_;
	std::vector<Solution> solutions_;
public:
	explicit CheckResult(std::vector<Solution>&, bool = true);
	explicit CheckResult(Solution::MaterialType material_type, int screws = 5, bool = false);
	CheckResult(const CheckResult&);
	CheckResult operator+=(CheckResult& check);
	CheckResult operator= (CheckResult check) const;
	
	friend std::ostream& operator<<(std::ostream& os, CheckResult& check)
	{
		if (check.check_)
		{
			os << "Vehicle is working properly!" << std::endl;
			return os;
		}
		os << "Recommended solutions:" << std::endl;
		//std::sort(check.solutions_.begin(), check.solutions_.end());
		for (auto it = check.solutions_.begin(); it != check.solutions_.end(); ++it)
			os << "\t" << *it << std::endl;
		return os;
	}
	void show_report();
	~CheckResult();
};

