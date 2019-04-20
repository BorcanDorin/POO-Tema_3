#pragma once
#include <map>
#include <string>

class Solution
{
public: 
	enum MaterialType
	{
		auto_break_pad_front_left,
		auto_break_pad_front_right,
		auto_break_pad_back_left,
		auto_break_pad_back_right,

		auto_break_disk_front_left,
		auto_break_disk_front_right,
		auto_break_disk_back_left,
		auto_break_disk_back_right,


		auto_carburettor,


		auto_wheel,


		auto_body_wing_front_left_new,
		auto_body_wing_front_right_new,
		auto_body_wing_back_left_new,
		auto_body_wing_back_right_new,

		auto_body_bar_front_new,
		auto_body_bar_back_new,

		auto_body_hood_new,


		auto_body_wing_front_left_fix,
		auto_body_wing_front_right_fix,
		auto_body_wing_back_left_fix,
		auto_body_wing_back_right_fix,

		auto_body_bar_front_fix,
		auto_body_bar_back_fix,

		auto_body_hood_fix,


		moto_chain,

		moto_break_pad_front,
		moto_break_pad_back,

		moto_break_disk_front,
		moto_break_disk_back,


		moto_handle_bar,


		moto_wheel_front,
		moto_wheel_back,



		bike_chain,

		bike_break_front,
		bike_break_back,

		bike_handle_bar,

		bike_wheel_front,
		bike_wheel_back,



		auto_moto_oil_replacement,
		no_fix,
		MaterialType_MAX = no_fix
	};
	const float Price[MaterialType_MAX + 1] = { 4, 7, 5, 4, 3, 6, 2, 6, 5, 3, 3, 2, 3, 5, 6, 2, 1, 4, 7, 6, 2, 1, 9, 3, 5, 9, 4, 5, 4, 6, 1, 8, 5, 7, 5, 9, 2, 2, 7, 3 };
	const float ManHours[MaterialType_MAX + 1] = { 4, 7, 5, 4, 3, 6, 2, 6, 5, 3, 3, 2, 3, 5, 6, 2, 1, 4, 7, 6, 2, 1, 9, 3, 5, 9, 4, 5, 4, 6, 1, 8, 5, 7, 5, 9, 2, 2, 7, 3 };
	const std::string DisplayText[MaterialType_MAX + 1] =
	{
		"Replace auto_break_pad_front_left",
		"Replace auto_break_pad_front_right",
		"Replace auto_break_pad_back_left",
		"Replace auto_break_pad_back_right",

		"Replace auto_break_disk_front_left",
		"Replace auto_break_disk_front_right",
		"Replace auto_break_disk_back_left",
		"Replace auto_break_disk_back_right",


		"Replace auto_carburettor",


		"Replace auto_wheel",


		"Replace auto_body_wing_front_left_new",
		"Replace auto_body_wing_front_right_new",
		"Replace auto_body_wing_back_left_new",
		"Replace auto_body_wing_back_right_new",

		"Replace auto_body_bar_front_new",
		"Replace auto_body_bar_back_new",

		"Replace auto_body_hood_new",


		"Replace auto_body_wing_front_left_fix",
		"Replace auto_body_wing_front_right_fix",
		"Replace auto_body_wing_back_left_fix",
		"Replace auto_body_wing_back_right_fix",

		"Replace auto_body_bar_front_fix",
		"Replace auto_body_bar_back_fix",

		"Replace auto_body_hood_fix",


		"Replace moto_chain",

		"Replace moto_break_pad_front",
		"Replace moto_break_pad_back",

		"Replace moto_break_disk_front",
		"Replace moto_break_disk_back",


		"Replace moto_handle_bar",


		"Replace moto_wheel_front",
		"Replace moto_wheel_back",



		"Replace bike_chain",

		"Replace bike_break_front",
		"Replace bike_break_back",

		"Replace bike_handle_bar",

		"Replace bike_wheel_front",
		"Replace bike_wheel_back",



		"Replace auto_moto_oil_replacement",
		"no_fix"
	};

private:
	int screws_;
	MaterialType material_;
	float price_;
	float man_hours_;
	std::string display_text_;

public:
	explicit Solution(MaterialType material_type, int screws = 5);
	Solution& operator =(const Solution& sol)
	{
		return *new Solution(sol.material_, sol.screws_);
	}

	friend std::ostream& operator<<(std::ostream& os, Solution& sol)
	{
		os << sol.display_text_ << " - Man hours: " << sol.man_hours_ << " - Price:" << sol.price_;
		return os;
	}
	~Solution();
};

