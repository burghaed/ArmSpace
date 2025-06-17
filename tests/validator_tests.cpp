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
    nlohmann::json i =  {
        {"robot_name", "ArmSpaceBot"},
        {"joints", {
            {
                {"name", "shoulder"},
                {"position", {0, 0, 0}},
                {"motors", {
                    {
                        {"name", "motor_x"},
                        {"rotation_axis", {1, 0, 0}},
                        {"ticks_per_revolution", 1000}
                    }
                }}
            },
            {
                {"name", "elbow"},
                {"position", {10, 0, 0}},
                {"motors", {
                    {
                        {"name", "motor_y"},
                        {"rotation_axis", {0, 1, 0}},
                        {"ticks_per_revolution", 1200}
                    }
                }}
            }
        }},
        {"end_effector", {
            {"position", {10, 7, 5}},
            {"tool", "gripper"}
        }},
        {"status", "operational"}
    };
    JSON::RobotorArmValidator test;
}
