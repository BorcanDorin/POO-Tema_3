#include "pch.h"
#include "AutoExteriorPart.h"


AutoExteriorPart::AutoExteriorPart(const Solution::MaterialType major_malfunction_fix,
                                   const Solution::MaterialType part_replacement_malfunction_fix,
                                   const int major_malfunction_screws,
                                   const int part_replacement_malfunction_screws,
                                   const bool major_malfunction,
                                   const bool part_malfunction)
				:part(major_malfunction, major_malfunction_fix, major_malfunction_screws)
{
	part_replacement_malfunction_ = part_malfunction;
	part_replacement_malfunction_fix_ = part_replacement_malfunction_fix;
	part_replacement_malfunction__screws_ = part_replacement_malfunction_screws;
}

CheckResult AutoExteriorPart::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	if (part_replacement_malfunction_)
	{
		CheckResult c(part_replacement_malfunction_fix_, part_replacement_malfunction__screws_, !part_replacement_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

void AutoExteriorPart::start_part_break_down()
{
	part_replacement_malfunction_ = true;
}

AutoExteriorPart::~AutoExteriorPart()
= default;