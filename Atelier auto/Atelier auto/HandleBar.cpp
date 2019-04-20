#include "pch.h"
#include "HandleBar.h"


HandleBar::HandleBar(const Solution::MaterialType major_malfunction_fix,
                     const Solution::MaterialType handle_bar_malfunction_fix,
                     const int major_malfunction_screws,
                     const int handle_bar_malfunction_screws,
                     const bool major_malfunction,
                     const bool handle_bar_malfunction)
		 :part(major_malfunction)
{
	handle_bar_malfunction_ = handle_bar_malfunction;

	major_malfunction_fix_ = major_malfunction_fix;
	handle_bar_malfunction_fix_ = handle_bar_malfunction_fix;

	major_malfunction_screws_ = major_malfunction_screws;
	handle_bar_malfunction_screws_ = handle_bar_malfunction_screws;
}

CheckResult HandleBar::check()
{
	const auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	if (handle_bar_malfunction_)
	{
		CheckResult c(handle_bar_malfunction_fix_, handle_bar_malfunction_screws_, !handle_bar_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

void HandleBar::start_handle_bar_break_down()
{
	handle_bar_malfunction_ = true;
}

HandleBar::~HandleBar()
= default;
