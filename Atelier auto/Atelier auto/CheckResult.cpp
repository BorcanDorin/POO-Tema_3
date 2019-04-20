#include "pch.h"
#include "CheckResult.h"


CheckResult::CheckResult(std::vector<Solution>& sol, const bool check)
{
	check_ = check;
	solutions_ = sol;
}

CheckResult::CheckResult(Solution::MaterialType fix, int screws, bool non_check)
{
	solutions_ = *new std::vector<Solution>;
	solutions_.push_back(*new Solution(fix, screws));
	check_ = non_check;
}

CheckResult::CheckResult(const CheckResult& var)
{
	check_ = var.check_;
	solutions_ = var.solutions_;
}

CheckResult CheckResult::operator+=(CheckResult& check)
{
	if (check.check_)
		return *this;
	check_ = check.check_;
	solutions_.insert(solutions_.end(), check.solutions_.begin(), check.solutions_.end());
	return *this;
}

CheckResult::~CheckResult()
= default;
