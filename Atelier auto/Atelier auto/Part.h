#pragma once
#include "CheckResult.h"

class part
{
protected:
	bool major_malfunction_;
public:
	explicit part(bool = false);
	void start_major_malfunction();
	virtual CheckResult check() = 0;
	virtual ~part();
};