#include "main.h"
#include "init.h"

#define NUM_SCRIPTS 5										// Number of autonomous scripts

// array fo scripts descriptions/names displayed in selection menu
const char* titles[] = {"Skills", "autoRedLeft", "AutoBlueLeft", "autoRedRight", "autoBlueRight"};

int selection;													// Select script to run
unsigned int scriptNumber = 0;					// scriptNumber which will be passed
																				// to autonomous() and run matching function
																			  // via hte glabal selection

static bool selectionMade = false;

void on_left_button() {
	static bool pressed = false;
  if(!selectionMade){
		pros::lcd::clear_line(4);
		if (scriptNumber != 0) {
			scriptNumber--;
		  pros::lcd::print(2, "Script#: %d\n", scriptNumber);
      pros::lcd::print(3, titles[scriptNumber]);
 	  } else {
		  pros::lcd::print(2, "Script#: %d Can't decrement\n", scriptNumber);
		  pros::lcd::print(3, titles[scriptNumber]);
	  }
	}
}

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		selection = scriptNumber;
		pros::lcd::set_text(4, "<< SELECTED >>");
		selectionMade = true;
	} else {
		pros::lcd::set_text(4, "<< DE-SELECTED >>");
		selection = 0;					// Reset selection
    selectionMade = false;
	}
}

void on_right_button() {
	static bool pressed = false;
  if(!selectionMade){
		pros::lcd::clear_line(4);
		if (scriptNumber < (NUM_SCRIPTS - 1)) {
			scriptNumber++;
		  pros::lcd::print(2, "Script#: %d\n", scriptNumber);
		  pros::lcd::print(3, titles[scriptNumber]);
		} else {
			pros::lcd::print(2, "Script#: %d Can't increment\n", scriptNumber);
		  pros::lcd::print(3, titles[scriptNumber]);
		}
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::lcd::set_text(1, "Autonomous Mode Select");

  pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);

}
