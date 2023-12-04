#include "main.h"
#include "lemlib/api.hpp"
#include "Globals.hpp"
#include "PIDControllers.hpp"

#pragma once

lemlib::Drivetrain drivetrain {
	&Leftsidedrive, // left drivetrain motors
	&Rightsidedrive, // right drivetrain motors
	11.3, // track width
	2.75, // wheel diameter
	450, // wheel rpm
	10, //chase power
};

// tracking wheels
lemlib::TrackingWheel back_tracking_wheel(
	&brot, // uses "brot" as the encoder.
	2.75, // 2.75" wheel diameter
	4.3, // 4.3" offset from tracking center
	1 // 1:1 gear ratio
);

// odometry struct
lemlib::OdomSensors sensors {
	nullptr, // vertical tracking wheel 1
	nullptr, // vertical tracking wheel 2
	&brot, // horizontal tracking wheel 1
	nullptr, // we don't have a second tracking wheel, so we set it to nullptr
	&inertial_sensor // inertial sensor
};

// Chassis constructor
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);