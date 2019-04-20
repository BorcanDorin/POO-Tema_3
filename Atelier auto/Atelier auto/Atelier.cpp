#include "pch.h"
#include "Atelier.h"


Atelier::Atelier()
{
	std::cout << "Welcome!" << std::endl;
}

CheckResult Atelier::diagnose_vehicle(vehicle& veh)
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);
	auto c = veh.check_breaks_category();
	*check_result += c;
	auto c1 = veh.check_steering_category();
	*check_result += c1;
	auto c2 = veh.custom_check();
	*check_result += c2;
	return *check_result;
	//return *new CheckResult(*new std::vector<Solution>, true);
}


Atelier::~Atelier() 
= default;
