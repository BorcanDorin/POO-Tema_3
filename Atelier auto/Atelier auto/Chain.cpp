#include "pch.h"
#include "Chain.h"


Chain::Chain(const Solution::MaterialType major_malfunction_fix,
             const Solution::MaterialType chain_malfunction_fix,
             const int major_malfunction_screws,
             const int chain_malfunction_screws,
             const bool major_malfunction)
	:part(major_malfunction)
{
	chain_malfunction_fix_ = chain_malfunction_fix;
	major_malfunction_fix_ = major_malfunction_fix;

	chain_malfunction_screws_ = chain_malfunction_screws;
	major_malfunction_screws_ = major_malfunction_screws;
}

CheckResult Chain::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	if (chain_malfunction_)
	{
		CheckResult c(chain_malfunction_fix_, chain_malfunction_screws_, !chain_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

void Chain::start_chain_usage()
{
	chain_malfunction_ = true;
}

Chain::~Chain()
= default;