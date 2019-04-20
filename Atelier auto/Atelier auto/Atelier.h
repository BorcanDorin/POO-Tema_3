#pragma once
#include "CheckResult.h"
#include "vehicle.h"

class Atelier
{
public:
	Atelier();
	CheckResult diagnose_vehicle(vehicle&);
	~Atelier();
};

