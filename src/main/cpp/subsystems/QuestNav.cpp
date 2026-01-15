#include <networktables/NetworkTableInstance.h>
#include <cmath>
#include <iostream>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <units/angle.h>

#include "systems/QuestNav.h"

QuestNav::QuestNav() {
    
};

std::shared_ptr<nt::NetworkTable> QuestNav::table = nt::NetworkTableInstance::GetDefault().GetTable("questnav");
frc::Pose2d m_offset = frc::Pose2d();

frc::Pose2d QuestNav::GetQuestPose() {
    auto position = table->GetEntry("position").GetFloatArray({});
    auto euler = table->GetEntry("eulerAngles").GetFloatArray({});

    if (position.size() < 2 || euler.size() < 1) {
        return frc::Pose2d();
    }

    double x = position[0];
    double y = position[2];
    double theta = euler[1] * M_PI / 180.0;
    
    frc::Pose2d rawPose(
        frc::Translation2d(units::meter_t{x}, units::meter_t{y}),
        frc::Rotation2d(units::radian_t{theta})
    );

    return rawPose.RelativeTo(m_offset);
};

void QuestNav::Calibrate() {
    m_offset = GetQuestPose();
}