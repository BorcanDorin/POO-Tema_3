#include "pch.h"
#include "Part.h"

part::part(const bool major_malfunction,
           const Solution::MaterialType major_malfunction_fix,
           const int major_malfunction_screws)
{
	major_malfunction_ = major_malfunction;
	major_malfunction_fix_ = major_malfunction_fix;
	major_malfunction_screws_ = major_malfunction_screws;
}

void part::start_major_malfunction()
{
	major_malfunction_ = true;
}

part::~part()
= default;
