//
//  validator_tests.cpp
//  ArmSpaceTests
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#include "robotor_arm_validator.h"
#include "gtest/gtest.h"
#include <nlohmann/json.hpp>

TEST(ValidatorTests, CtrTest){
    nlohmann::json json_input;
    JSON::RobotorArmValidator v(json_input);
    
}
