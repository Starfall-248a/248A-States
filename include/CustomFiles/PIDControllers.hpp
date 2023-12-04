#include "main.h"
#include "lemlib/api.hpp"

#pragma once

// forward/backward PID
lemlib::ControllerSettings lateralController {
	8, // kP
	30, // kD
	1, // smallErrorRange
	100, // smallErrorTimeout
	3, // largeErrorRange
	500, // largeErrorTimeout
	5 // slew rate
};

// turning PID
lemlib::ControllerSettings angularController {
	4, // kP
	40, // kD
	1, // smallErrorRange
	100, // smallErrorTimeout
	3, // largeErrorRange
	500, // largeErrorTimeout
	0 // slew rate
};
