#pragma once

#include <frc/XboxController.h>

class Controllers {
public:
    static Controllers &GetInstance() {
        static Controllers instance;
        return instance;
    }

    frc::XboxController &GetDriverController();
    frc::XboxController &GetOperatorController();

private:
    frc::XboxController m_driverController;
    frc::XboxController m_operatorController;

    Controllers();
};