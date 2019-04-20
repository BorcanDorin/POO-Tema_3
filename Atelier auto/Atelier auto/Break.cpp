#include "pch.h"
#include "Break.h"

Break::Break(const Solution::MaterialType major_malfunction_fix,
             const int major_malfunction_screws, 
			 const bool major_malfunction)
	 :part(major_malfunction)
{
	major_malfunction_fix_ = major_malfunction_fix;
	major_malfunction_screws_ = major_malfunction_screws;
}

CheckResult Break::check()
{
	auto check_result = new CheckResult(*new std::vector<Solution>);
	if (major_malfunction_)
	{
		CheckResult c(major_malfunction_fix_, major_malfunction_screws_, !major_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

Break::~Break()
= default;

break_auto_moto::break_auto_moto(const Solution::MaterialType major_malfunction_fix,
                                 const Solution::MaterialType break_pad_malfunction_fix,
                                 const Solution::MaterialType break_disk_malfunction_fix,
								 const int major_malfunction_screws,
								 const int break_pad_malfunction_screws,
								 const int break_disk_malfunction_screws,
                                 const bool major_malfunction,
                                 const bool break_pad_malfunction,
                                 const bool break_disk_malfunction)
				:Break(major_malfunction_fix, major_malfunction)
{
	break_disk_malfunction_ = break_disk_malfunction;
	break_pad_malfunction_ = break_pad_malfunction;

	break_disk_malfunction_fix_ = break_disk_malfunction_fix;
	break_pad_malfunction_fix_ = break_pad_malfunction_fix;

	break_disk_malfunction_screws_ = break_disk_malfunction_screws;
	break_pad_malfunction_screws_ = break_pad_malfunction_screws;
}

void break_auto_moto::start_break_pad_malfunction()
{
	break_pad_malfunction_ = true;
}

void break_auto_moto::start_break_disk_malfunction()
{
	break_disk_malfunction_ = true;
}

CheckResult break_auto_moto::check()
{
	auto check_result = new CheckResult(Break::check());
	if (break_disk_malfunction_)
	{
		CheckResult c(break_disk_malfunction_fix_, break_disk_malfunction_screws_, !break_disk_malfunction_);
		*check_result += c;
	}
	if (break_pad_malfunction_)
	{
		CheckResult c(break_pad_malfunction_fix_, break_pad_malfunction_screws_, !break_pad_malfunction_);
		*check_result += c;
	}
	return *check_result;
}

break_auto_moto::~break_auto_moto() 
= default;