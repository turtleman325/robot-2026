#include "Controllers.h"

#include "Constants.h"

Controllers::Controllers()
    : m_driverController{Constants::kDriverID}.
      m_operatorController{Constants::kOperatorID} {}

frc::XboxController &Controllers::GetDriverController() {
    return m_driverController;
}

frc::XboxController &Controllers::GetOperatorController() {
    return m_operatorController;
}