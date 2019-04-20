#include "pch.h"
#include "carburator.h"

carburator::carburator(const Solution::MaterialType major_malfunction_fix,
						const int major_malfunction_screws,
						const bool major_malfunction)
		  :part(major_malfunction)
{
	major_malfunction_fix_ = major_malfunction_fix;

	major_malfunction_screws_ = major_malfunction_screws;
}

CheckResult carburator::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

carburator::~carburator()
= default;