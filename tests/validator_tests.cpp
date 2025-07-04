//
//  validator_tests.cpp
//  ArmSpaceTests
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#include "robotor_arm_validator.h"
#include "gtest/gtest.h"

using test_parameter_t = std::pair<nlohmann::json, bool>;

class RobotArmValidatorSchemeTest
    : public ::testing::TestWithParam<test_parameter_t> {};

TEST_P(RobotArmValidatorSchemeTest, SchemeTests) {
  auto jsonFileValid = GetParam();

  JSON::RobotorArmValidator v;
  v.validate_scheme(jsonFileValid.first);
  if (jsonFileValid.second) {
    EXPECT_TRUE(v.errors().empty());
  } else {
    EXPECT_FALSE(v.errors().empty());
  }
}
const nlohmann::json input1 = std::make_pair(R"({
        "robot_name": "TestBot",
        "joints": [
            {
                "name": "joint1",
                "position": [0.0, 1.0],
                "motors": [
                    {
                        "name": "motor1",
                        "rotation_axis": [1, 0, 0],
                        "ticks_per_revolution": 1024
                    }
                ]
            }
        ]
    })"_json,
                                             true);

const nlohmann::json input2 = std::make_pair(R"({
        "joints": []
    })"_json,
                                             false);

const nlohmann::json input3 = std::make_pair(R"({
  "robot_name": "SimpleBot",
  "joints": []
})"_json,
                                             true);

const nlohmann::json input4 = std::make_pair(R"({
  "robot_name": "TestBot",
  "joints": [
    {
      "name": "joint1",
      "position": [0.0, 1.0],
      "motors": [
        {
          "name": "motor1",
          "rotation_axis": [1, 0, 0],
          "ticks_per_revolution": 1024
        }
      ]
    }
  ]
})"_json,
                                             true);

const nlohmann::json input5 = std::make_pair(R"({
  "robot_name": "MegaBot",
  "joints": [
    {
      "name": "jointA",
      "position": [0.0, 0.5],
      "motors": [
        {
          "name": "motorA1",
          "rotation_axis": [0, 1, 0],
          "ticks_per_revolution": 512
        },
        {
          "name": "motorA2",
          "rotation_axis": [1, 0, 0],
          "ticks_per_revolution": 256
        }
      ]
    },
    {
      "name": "jointB",
      "position": [1.0, 1.5],
      "motors": [
        {
          "name": "motorB1",
          "rotation_axis": [0, 0, 1],
          "ticks_per_revolution": 128
        }
      ]
    }
  ]
})"_json,
                                             true);

const nlohmann::json input6 = std::make_pair(R"({
  "robot_name": "TestBot",
  "joints": [
    {
      "name": "joint1",
      "position": [0.0, 1.0]
    }
  ]
})"_json,
                                             false);

const nlohmann::json input7 = std::make_pair(R"({
  "robot_name": "BadBot",
  "joints": [
    {
      "name": "joint1",
      "position": [0.0, 1.0],
      "motors": [
        {
          "name": "motor1",
          "rotation_axis": [1, 0, 0],
          "ticks_per_revolution": "1024"
        }
      ]
    }
  ]
})"_json,
                                             false);

const nlohmann::json input8 = std::make_pair(R"({
  "robot_name": "BrokenBot",
  "joints": [
    {
      "name": "joint1",
      "position": [0.0, 1.0],
      "motors": [
        {
          "name": "motor1",
          "rotation_axis": "x",
          "ticks_per_revolution": 1024
        }
      ]
    }
  ]
})"_json,
                                             false);

INSTANTIATE_TEST_SUITE_P(Test, RobotArmValidatorSchemeTest,
                         ::testing::Values(input1, input2, input3, input4,
                                           input5, input6, input7, input8));
