#include "pch.h"
#include "engine.h"


engine::engine(const Solution::MaterialType major_malfunction_fix,
	const Solution::MaterialType low_oil_level_fix,
	const int major_malfunction_screws,
	const int low_oil_level_screws,
	const bool major_malfunction,
	const bool low_oil_malfunction)
	:part(major_malfunction, major_malfunction_fix, major_malfunction_screws)
{
	low_oil_level_ = low_oil_malfunction;

	low_oil_level_fix_ = low_oil_level_fix;

	low_oil_level_screws_ = low_oil_level_screws;
}

CheckResult engine::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	if (low_oil_level_)
	{
		CheckResult c(low_oil_level_fix_, low_oil_level_screws_, !low_oil_level_);
		*check_result += c;
	}
	return *check_result;
}

void engine::start_low_oil_level()
{
	low_oil_level_ = true;
}

engine::~engine()
= default;
