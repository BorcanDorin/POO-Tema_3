#pragma once
#include <string>
#include "Break.h"
#include "Chain.h"
#include "Wheel.h"
#include "engine.h"
#include "carburator.h"
#include "AutoExteriorPart.h"

class vehicle
{
	std::string id_number_;
	CheckResult diagnostics_ = *new CheckResult(*new std::vector<Solution>);
protected:
	int year_of_production_;

public:
	explicit vehicle(const std::string&, int = 2000);
	std::string get_id_number() const;

	virtual CheckResult check_breaks_category();
	virtual CheckResult check_steering_category();
	virtual CheckResult custom_check();

	virtual ~vehicle();
};


class car : public vehicle
{
	bool burn_oil_;

	break_auto_moto left_front_break_;
	break_auto_moto right_front_break_;
	break_auto_moto left_back_break_;
	break_auto_moto right_back_break_;

	Wheel front_left_wheel_;
	Wheel front_right_wheel_;
	Wheel back_left_wheel_;
	Wheel back_right_wheel_;

	engine engine_;
	carburator carburator_;

	AutoExteriorPart front_left_wing_;
	AutoExteriorPart front_right_wing_;
	AutoExteriorPart back_left_wing_;
	AutoExteriorPart back_right_wing_;

	AutoExteriorPart front_bar_;
	AutoExteriorPart back_bar_;

	AutoExteriorPart hood_;

	static const int part_count = 9;
	part* custom_parts_[part_count];

public:
	explicit car(const std::string& = *new std::string, int = 2000, bool = false);

	virtual CheckResult check_breaks_category() override;
	virtual CheckResult check_steering_category() override;
	CheckResult custom_check() override;

	virtual void perform_front_left_break_major_incident();
	virtual void perform_back_left_break_major_incident();
	virtual void perform_front_left_break_disk_incident();
	virtual void perform_front_left_break_pad_incident();
	virtual void perform_back_left_break_disk_incident();
	virtual void perform_back_left_break_pad_incident();

	virtual void perform_front_right_break_major_incident();
	virtual void perform_back_right_break_major_incident();
	virtual void perform_front_right_break_disk_incident();
	virtual void perform_front_right_break_pad_incident();
	virtual void perform_back_right_break_disk_incident();
	virtual void perform_back_right_break_pad_incident();

	void perform_front_left_wheel_major_incident();
	void perform_front_left_wheel_incident();
	void perform_back_left_wheel_major_incident();
	void perform_back_left_wheel_incident();

	void perform_front_right_wheel_major_incident();
	void perform_front_right_wheel_incident();
	void perform_back_right_wheel_major_incident();
	void perform_back_right_wheel_incident();

	void perform_engine_major_incident();
	void perform_engine_low_oil();

	void perform_major_carburator_incident();

	void perform_front_left_wing_major_incident();
	void perform_front_right_wing_major_incident();
	void perform_back_left_wing_major_incident();
	void perform_back_right_wing_major_incident();

	void perform_front_left_wing_incident();
	void perform_front_right_wing_incident();
	void perform_back_left_wing_incident();
	void perform_back_right_wing_incident();

	void perform_front_bar_major_incident();
	void perform_front_bar_incident();

	void perform_back_bar_major_incident();
	void perform_back_bar_incident();

	void perform_hood_major_incident();
	void perform_hood_incident();

	void total_destruction();

	~car();
};


class bicycle : public vehicle
{
	Break front_break_;
	Break back_break_;

protected:
	Chain chain_;

	Wheel front_wheel_;
	Wheel back_wheel_;

public:
	explicit bicycle(const std::string& = *new std::string, int = 2000);
	virtual CheckResult check_breaks_category() override;
	virtual CheckResult check_steering_category() override;
	CheckResult custom_check() override;

	virtual void perform_front_break_major_incident();
	virtual void perform_back_break_major_incident();

	void perform_chain_major_incident();
	void perform_chain_usage_incident();

	void perform_front_wheel_major_incident();
	void perform_front_wheel_incident();
	void perform_back_wheel_major_incident();
	void perform_back_wheel_incident();

	virtual void total_destruction();

	~bicycle();
};


class motorcycle : public bicycle
{
	bool burn_oil_;
	break_auto_moto front_break_;
	break_auto_moto back_break_;
	engine engine_;

public:
	explicit motorcycle(const std::string& = *new std::string, int = 2000, bool = false);

	virtual CheckResult check_breaks_category() override;
	virtual CheckResult check_steering_category() override;
	CheckResult custom_check() override;

	virtual void perform_front_break_major_incident() override;
	virtual void perform_back_break_major_incident() override;

	virtual void perform_front_break_disk_incident();
	virtual void perform_front_break_pad_incident();
	virtual void perform_back_break_disk_incident();
	virtual void perform_back_break_pad_incident();

	void perform_engine_major_incident();
	void perform_engine_low_oil();

	void total_destruction() override;

	~motorcycle();
};