#pragma once

#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/angular_velocity.h>
#include <units/velocity.h>

#include "Robot.h"
#include "Constants.h"
#include "systems/System.h"

using namespace ctre::phoenix6;

class SupaIntake : public System {
public:
    //Static Instance
    static SupaIntake &GetInstance() {
        static SupaIntake instance;
        return instance;
    }

    //void complex functions
    void beginIntake();
    void endIntake();

    //void basic functions
    //Motors (apply to both)
    void startIn(); 
    void startOut();
    void stopSpin();
    //Pistons (apply to both)
    void intakeExtend();
    void intakeRetract();

    //IDK
    void update(Robot::Mode mode, double t);
    bool armDown();
    bool intakeSafe();

    //spin state enum
    enum class spinCur {
        IN,
        OUT,
        IDLE
    };

    //Piston state enums 
    enum class pistLoc {
        UP,
        DOWN
    };


private:
    
    // Get 2 motors 
    hardware::TalonFX m_IntakeMotors[2];
    hardware::CANcoder m_IntakePneums[2];

    SupaIntake();
};