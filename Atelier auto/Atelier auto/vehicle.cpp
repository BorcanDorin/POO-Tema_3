#include "pch.h"
#include "vehicle.h"
#include <complex.h>


vehicle::vehicle(const std::string& id_number, int year_of_prod)
{
	id_number_.assign(id_number);
	year_of_production_ = year_of_prod;
}


std::string vehicle::get_id_number() const
{
	return id_number_;
}

CheckResult vehicle::check_breaks_category()
{
	return *new CheckResult(*new std::vector<Solution>, true);
}

CheckResult vehicle::check_steering_category()
{
	return *new CheckResult(*new std::vector<Solution>, true);
}

CheckResult vehicle::custom_check()
{
	return *new CheckResult(*new std::vector<Solution>, true);
}

vehicle::~vehicle()
= default;

car::car(const std::string& id, int year_of_prod, bool burn_oil):vehicle(id, year_of_prod)
{
	burn_oil_ = burn_oil;

	left_front_break_ = *new break_auto_moto(Solution::no_fix, Solution::auto_break_pad_front_left, Solution::auto_break_disk_front_left, 3, 6, 8);
	left_back_break_ = *new break_auto_moto(Solution::no_fix, Solution::auto_break_pad_back_left, Solution::auto_break_disk_back_left, 3, 6, 8);
	right_front_break_ = *new break_auto_moto(Solution::no_fix, Solution::auto_break_pad_front_right, Solution::auto_break_disk_front_right, 3, 6, 8);
	right_back_break_ = *new break_auto_moto(Solution::no_fix, Solution::auto_break_pad_back_right, Solution::auto_break_disk_back_right, 3, 6, 8);

	front_left_wheel_ = *new Wheel(Solution::no_fix, Solution::auto_wheel, 6, 5);
	front_right_wheel_ = *new Wheel(Solution::no_fix, Solution::auto_wheel, 6, 5);
	back_left_wheel_ = *new Wheel(Solution::no_fix, Solution::auto_wheel, 6, 5);
	back_right_wheel_ = *new Wheel(Solution::no_fix, Solution::auto_wheel, 6, 5);

	engine_ = *new engine(Solution::no_fix, Solution::auto_moto_oil_replacement, 5, 8);
	carburator_ = *new carburator(Solution::no_fix, 6);

	front_left_wing_ = *new AutoExteriorPart(Solution::auto_body_wing_front_left_new, Solution::auto_body_wing_front_left_fix, 7, 8);
	front_right_wing_ = *new AutoExteriorPart(Solution::auto_body_wing_front_right_new, Solution::auto_body_wing_front_right_fix, 7, 8);
	back_left_wing_ = *new AutoExteriorPart(Solution::auto_body_wing_back_left_new, Solution::auto_body_wing_back_left_fix, 7, 8);
	back_right_wing_ = *new AutoExteriorPart(Solution::auto_body_wing_back_right_new, Solution::auto_body_wing_back_right_fix, 7, 8);

	front_bar_ = *new AutoExteriorPart(Solution::auto_body_bar_front_new, Solution::auto_body_bar_front_fix, 7, 8);
	back_bar_ = *new AutoExteriorPart(Solution::auto_body_bar_back_new, Solution::auto_body_bar_back_fix, 7, 8);

	hood_ = *new AutoExteriorPart(Solution::auto_body_hood_new, Solution::auto_body_hood_fix, 7, 8);

	custom_parts_[0] = &engine_;
	custom_parts_[1] = &carburator_;
	custom_parts_[2] = &front_left_wing_;
	custom_parts_[3] = &front_right_wing_;
	custom_parts_[4] = &back_left_wing_;
	custom_parts_[5] = &back_right_wing_;
	custom_parts_[6] = &front_bar_;
	custom_parts_[7] = &back_bar_;
	custom_parts_[8] = &hood_;
}

CheckResult car::check_breaks_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = left_front_break_.check();
	*check_result += c1;

	auto c2 = left_back_break_.check();
	*check_result += c2;

	auto c3 = right_front_break_.check();
	*check_result += c3;

	auto c4 = right_back_break_.check();
	*check_result += c4;

	return  *check_result;
}

CheckResult car::check_steering_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = front_left_wheel_.check();
	*check_result += c1;

	auto c2 = front_right_wheel_.check();
	*check_result += c2;

	auto c3 = back_left_wheel_.check();
	*check_result += c3;

	auto c4 = back_right_wheel_.check();
	*check_result += c4;

	return *check_result;
}

CheckResult car::custom_check()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if(burn_oil_)
	{
		auto c = *new CheckResult(Solution::auto_moto_oil_replacement, 6);
		*check_result += c;
	}
	if(year_of_production_ < 2000)
	{
		auto c = *new CheckResult(Solution::auto_moto_oil_replacement, 6);
		*check_result += c;
	}

	for (auto& custom_part : custom_parts_)
	{
		auto c = custom_part->check();
		*check_result += c;
	}
	return *check_result;
}

void car::perform_front_left_break_major_incident()
{
	left_front_break_.start_major_malfunction();
}

void car::perform_back_left_break_major_incident()
{
	left_back_break_.start_major_malfunction();
}

void car::perform_front_left_break_disk_incident()
{
	left_front_break_.start_break_disk_malfunction();
}

void car::perform_front_left_break_pad_incident()
{
	left_front_break_.start_break_pad_malfunction();
}

void car::perform_back_left_break_disk_incident()
{
	left_back_break_.start_break_disk_malfunction();
}

void car::perform_back_left_break_pad_incident()
{
	left_back_break_.start_break_pad_malfunction();
}

void car::perform_front_right_break_major_incident()
{
	right_front_break_.start_major_malfunction();
}

void car::perform_back_right_break_major_incident()
{
	right_back_break_.start_major_malfunction();
}

void car::perform_front_right_break_disk_incident()
{
	right_front_break_.start_break_disk_malfunction();
}

void car::perform_front_right_break_pad_incident()
{
	right_front_break_.start_break_pad_malfunction();
}

void car::perform_back_right_break_disk_incident()
{
	right_back_break_.start_break_disk_malfunction();
}

void car::perform_back_right_break_pad_incident()
{
	right_back_break_.start_break_pad_malfunction();
}

void car::perform_front_left_wheel_major_incident()
{
	front_left_wheel_.start_major_malfunction();
}

void car::perform_front_left_wheel_incident()
{
	front_left_wheel_.start_wheel_break_down();
}

void car::perform_back_left_wheel_major_incident()
{
	back_left_wheel_.start_major_malfunction();
}

void car::perform_back_left_wheel_incident()
{
	back_left_wheel_.start_wheel_break_down();
}

void car::perform_front_right_wheel_major_incident()
{
	front_right_wheel_.start_major_malfunction();
}

void car::perform_front_right_wheel_incident()
{
	front_right_wheel_.start_wheel_break_down();
}

void car::perform_back_right_wheel_major_incident()
{
	back_right_wheel_.start_major_malfunction();
}

void car::perform_back_right_wheel_incident()
{
	back_right_wheel_.start_wheel_break_down();
}

void car::perform_engine_major_incident()
{
	engine_.start_major_malfunction();
}

void car::perform_engine_low_oil()
{
	engine_.start_low_oil_level();
}

void car::perform_major_carburator_incident()
{
	carburator_.start_major_malfunction();
}

void car::perform_front_left_wing_major_incident()
{
	front_left_wing_.start_major_malfunction();
}

void car::perform_front_right_wing_major_incident()
{
	front_right_wing_.start_major_malfunction();
}

void car::perform_back_left_wing_major_incident()
{
	back_left_wing_.start_major_malfunction();
}

void car::perform_back_right_wing_major_incident()
{
	back_right_wing_.start_major_malfunction();
}

void car::perform_front_left_wing_incident()
{
	front_left_wing_.start_part_break_down();
}

void car::perform_front_right_wing_incident()
{
	front_right_wing_.start_part_break_down();
}

void car::perform_back_left_wing_incident()
{
	back_left_wing_.start_part_break_down();
}

void car::perform_back_right_wing_incident()
{
	back_right_wing_.start_part_break_down();
}

void car::perform_front_bar_major_incident()
{
	front_bar_.start_major_malfunction();
}

void car::perform_front_bar_incident()
{
	front_bar_.start_part_break_down();
}

void car::perform_back_bar_major_incident()
{
	back_bar_.start_major_malfunction();
}

void car::perform_back_bar_incident()
{
	back_bar_.start_part_break_down();
}

void car::perform_hood_major_incident()
{
	hood_.start_major_malfunction();
}

void car::perform_hood_incident()
{
	hood_.start_part_break_down();
}

void car::total_destruction()
{
	left_front_break_.start_major_malfunction();
	left_front_break_.start_break_pad_malfunction();
	left_front_break_.start_break_disk_malfunction();
	left_back_break_.start_major_malfunction();
	left_back_break_.start_break_disk_malfunction();
	left_back_break_.start_break_pad_malfunction();
	right_front_break_.start_major_malfunction();
	right_front_break_.start_break_disk_malfunction();
	right_front_break_.start_break_pad_malfunction();
	right_back_break_.start_major_malfunction();
	right_back_break_.start_break_disk_malfunction();
	right_back_break_.start_break_pad_malfunction();

	front_left_wheel_.start_major_malfunction();
	front_left_wheel_.start_wheel_break_down();
	front_right_wheel_.start_major_malfunction();
	front_right_wheel_.start_wheel_break_down();
	back_right_wheel_.start_major_malfunction();
	back_right_wheel_.start_wheel_break_down();
	back_left_wheel_.start_major_malfunction();
	back_left_wheel_.start_wheel_break_down();

	engine_.start_major_malfunction();
	engine_.start_low_oil_level();

	carburator_.start_major_malfunction();

	burn_oil_ = true;

	front_bar_.start_major_malfunction();
	front_bar_.start_part_break_down();
	back_bar_.start_part_break_down();
	back_bar_.start_major_malfunction();

	hood_.start_major_malfunction();
	hood_.start_part_break_down();

	front_left_wing_.start_part_break_down();
	front_left_wing_.start_major_malfunction();
	front_right_wing_.start_part_break_down();
	front_right_wing_.start_major_malfunction();

	back_left_wing_.start_part_break_down();
	back_left_wing_.start_major_malfunction();
	back_right_wing_.start_part_break_down();
	back_right_wing_.start_major_malfunction();
}

car::~car()
= default;


bicycle::bicycle(const std::string& id, int year_of_prod):vehicle(id, year_of_prod)
{
	front_break_ = *new Break(Solution::no_fix, 3);
	back_break_ = *new Break(Solution::no_fix, 3);

	chain_ = *new Chain(Solution::no_fix, Solution::bike_chain, 3, 6);

	front_wheel_ = *new Wheel(Solution::no_fix, Solution::bike_wheel_front, 2, 4);
	back_wheel_ = *new Wheel(Solution::no_fix, Solution::bike_wheel_back, 6, 13);
}

CheckResult bicycle::check_breaks_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = front_break_.check();
	*check_result += c1;

	auto c2 = back_break_.check();
	*check_result += c2;

	auto c3 = chain_.check();
	*check_result += c3;

	return *check_result;
}

CheckResult bicycle::check_steering_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = front_wheel_.check();
	*check_result += c1;

	auto c2 = back_wheel_.check();
	*check_result += c2;

	return *check_result;
}

CheckResult bicycle::custom_check()
{
	return *new CheckResult(*new std::vector<Solution>);
}

void bicycle::perform_front_break_major_incident()
{
	front_break_.start_major_malfunction();
}

void bicycle::perform_back_break_major_incident()
{
	back_break_.start_major_malfunction();
}

void bicycle::perform_chain_major_incident()
{
	chain_.start_major_malfunction();
}

void bicycle::perform_chain_usage_incident()
{
	chain_.start_chain_usage();
}

void bicycle::perform_front_wheel_major_incident()
{
	front_wheel_.start_major_malfunction();
}

void bicycle::perform_front_wheel_incident()
{
	front_wheel_.start_wheel_break_down();
}

void bicycle::perform_back_wheel_major_incident()
{
	back_wheel_.start_major_malfunction();
}

void bicycle::perform_back_wheel_incident()
{
	back_wheel_.start_wheel_break_down();
}

void bicycle::total_destruction()
{
	front_break_.start_major_malfunction();

	back_break_.start_major_malfunction();

	front_wheel_.start_wheel_break_down();
	front_wheel_.start_major_malfunction();

	back_wheel_.start_wheel_break_down();
	back_wheel_.start_major_malfunction();

	chain_.start_chain_usage();
	chain_.start_major_malfunction();
}

bicycle::~bicycle()
= default;


motorcycle::motorcycle(const std::string& id, int year_of_prod, bool burn_oil):bicycle(id, year_of_prod)
{
	burn_oil_ = burn_oil;
	front_break_ = *new break_auto_moto(Solution::no_fix, Solution::moto_break_pad_front, Solution::moto_break_disk_front, 3, 6, 8);
	back_break_ = *new break_auto_moto(Solution::no_fix, Solution::moto_break_pad_back, Solution::moto_break_disk_back, 3, 6, 8);
	
	chain_ = *new Chain(Solution::no_fix, Solution::moto_chain, 3, 12);

	front_wheel_ = *new Wheel(Solution::no_fix, Solution::moto_wheel_front, 2, 4);
	back_wheel_ = *new Wheel(Solution::no_fix, Solution::moto_wheel_back, 6, 13);
	engine_ = *new engine(Solution::no_fix, Solution::auto_moto_oil_replacement, 3, 6);
}

CheckResult motorcycle::check_breaks_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = front_break_.check();
	*check_result += c1;

	auto c2 = back_break_.check();
	*check_result += c2;

	auto c3 = chain_.check();
	*check_result += c3;

	return *check_result;
}

CheckResult motorcycle::check_steering_category()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);

	auto c1 = front_wheel_.check();
	*check_result += c1;

	auto c2 = back_wheel_.check();
	*check_result += c2;

	return *check_result;
}

CheckResult motorcycle::custom_check()
{
	auto check_result = new CheckResult(*new std::vector<Solution>, true);
	if (burn_oil_)
	{
		auto c = *new CheckResult(Solution::auto_moto_oil_replacement, 6);
		*check_result += c;
	}
	if (year_of_production_ < 2000)
	{
		auto c = *new CheckResult(Solution::auto_moto_oil_replacement, 6);
		*check_result += c;
	}
	
	auto c = engine_.check();
	*check_result += c;

	return *check_result;
}

void motorcycle::perform_front_break_major_incident()
{
	front_break_.start_major_malfunction();
}

void motorcycle::perform_back_break_major_incident()
{
	back_break_.start_major_malfunction();
}

void motorcycle::perform_front_break_disk_incident()
{
	front_break_.start_break_disk_malfunction();
}

void motorcycle::perform_front_break_pad_incident()
{
	front_break_.start_break_pad_malfunction();
}

void motorcycle::perform_back_break_disk_incident()
{
	back_break_.start_break_disk_malfunction();
}

void motorcycle::perform_back_break_pad_incident()
{
	back_break_.start_break_pad_malfunction();
}

void motorcycle::perform_engine_major_incident()
{
	engine_.start_major_malfunction();
}

void motorcycle::perform_engine_low_oil()
{
	engine_.start_low_oil_level();
}

void motorcycle::total_destruction()
{
	front_break_.start_break_disk_malfunction();
	front_break_.start_break_pad_malfunction();
	front_break_.start_major_malfunction();

	back_break_.start_break_disk_malfunction();
	back_break_.start_break_pad_malfunction();
	back_break_.start_major_malfunction();

	front_wheel_.start_wheel_break_down();
	front_wheel_.start_major_malfunction();

	back_wheel_.start_wheel_break_down();
	back_wheel_.start_major_malfunction();

	chain_.start_chain_usage();
	chain_.start_major_malfunction();

	engine_.start_low_oil_level();
	engine_.start_major_malfunction();

	perform_engine_low_oil();
}

motorcycle::~motorcycle()
= default;
