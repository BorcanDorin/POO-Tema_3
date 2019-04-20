#include "pch.h"
#include "Wheel.h"

Wheel::Wheel(const Solution::MaterialType major_malfunction_fix,
			 const Solution::MaterialType wheel_malfunction_fix,
			 const int major_malfunction_screws,
			 const int wheel_malfunction_screws,
			 const bool major_malfunction,
			 const bool wheel_malfunction)
	  :part(major_malfunction)
{
	wheel_malfunction_ = wheel_malfunction;

	major_malfunction_fix_ = major_malfunction_fix;
	wheel_malfunction_fix_ = wheel_malfunction_fix;

	major_malfunction_screws_ = major_malfunction_screws;
	wheel_malfunction_screws_ = wheel_malfunction_screws;
}

CheckResult Wheel::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	if (wheel_malfunction_)
	{
		CheckResult c(wheel_malfunction_fix_, wheel_malfunction_screws_, !wheel_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

void Wheel::start_wheel_break_down()
{
	wheel_malfunction_ = true;
}

Wheel::~Wheel()
= default;