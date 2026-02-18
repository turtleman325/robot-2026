#include "systems/SupaIntake.h"

#include "Constants.h"
#include "systems/System.h"

//where is Intake booleans
bool intakeOut = false;
bool intakeIn = true;

//bool for Stopping robot
bool safeQuit;
//general multi-command functions

//begin Intake
void SupaIntake::beginIntake() {
    SupaIntake::spinCur::IN;
    SupaIntake::pistLoc::DOWN;
};

//end the Intake
void SupaIntake::endIntake() {
    SupaIntake::spinCur::OUT;
    SupaIntake::pistLoc::UP;
    SupaIntake::spinCur::IDLE;
};

//general single-command functions

//Intake Motor Controls
void SupaIntake::startIn () {spinCur::IN;};
void SupaIntake::startOut () {spinCur::OUT;};
void SupaIntake::stopSpin () {spinCur::IDLE;};

//Intake Pistons Control
void SupaIntake::intakeExtend () {pistLoc::DOWN;};
void SupaIntake::intakeRetract () {pistLoc::UP;};

//Misc IDK functions  NEED FIX
void SupaIntake::update(Robot::Mode mdoe, double t) {};