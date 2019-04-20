#include "pch.h"
#include "Solution.h"

Solution::Solution(const MaterialType material_type, const int screws)
{
	screws_ = screws;
	material_ = material_type;
	price_ = Price[material_type] * 10;
	man_hours_ = ManHours[material_type];
	display_text_ = DisplayText[material_type];
}

Solution::~Solution()
= default;
