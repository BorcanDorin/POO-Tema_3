#pragma once
#include "CheckResult.h"
#include "Part.h"

class Break : public part
{
public:
	Break(Solution::MaterialType major_malfunction_fix = Solution::no_fix, 
		  int major_malfunction_screws = 5, 
		  bool = false);
	CheckResult check() override;
	~Break();
};


class break_auto_moto : public Break
{
	bool break_pad_malfunction_;
	bool break_disk_malfunction_;

	Solution::MaterialType break_pad_malfunction_fix_;
	Solution::MaterialType break_disk_malfunction_fix_;

	int break_pad_malfunction_screws_;
	int break_disk_malfunction_screws_;

public:
	break_auto_moto(Solution::MaterialType major_malfunction_fix = Solution::no_fix,
					Solution::MaterialType break_pad_malfunction_fix = Solution::no_fix,
					Solution::MaterialType break_disk_malfunction_fix = Solution::no_fix,
					const int major_malfunction_screws = 5,
					const int break_pad_malfunction_screws = 5,
					const int break_disk_malfunction_screws = 5,
					bool = false, bool = false, bool = false);
	void start_break_pad_malfunction();
	void start_break_disk_malfunction();
	CheckResult check() override;
	~break_auto_moto();
};