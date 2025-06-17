//
//  robotor_arm_validator.cpp
//  ArmSpace
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#include "robotor_arm_validator.h"
#include <nlohmann/json.hpp>

namespace JSON {
    RobotorArmValidator::RobotorArmValidator(const nlohmann::jason& input ) : input_(&input) {
        
    }
}

