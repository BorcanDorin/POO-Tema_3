#include "pch.h"
#include "Part.h"

part::part(const bool major_malfunction)
{
	major_malfunction_ = major_malfunction;
}

void part::start_major_malfunction()
{
	major_malfunction_ = true;
}

part::~part()
= default;
