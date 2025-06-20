//
//  Errors.h
//  ArmSpace
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#pragma once
#include <array>
#include <string>
#include <tuple>

namespace Errors {
enum class ERROR : unsigned short {
  NO_JSON_FILE_SPECIFIED,
  MAILFORMED_JSON,
  JASON_PARSING_ERROR,
  INVALID_ARM_LENGTH,
  DISCONECTED_JOINT,
  MOTOR_DATA_MISSING,
  UNSUPPORTED_JOINT_COUNT,
  INVALID_ROTATION_AXIS,
  QUANTERNION_CALCULATION_FAILED,
  NUM_ERR
};

using error_code_to_string_table_t =
    std::array<std::string, static_cast<size_t>(ERROR::NUM_ERR)>;

using message_t = std::string;
using description_t = std::string;

using error_t = std::tuple<ERROR, message_t, description_t>;

static error_code_to_string_table_t error_code_to_message_table = {
    "No JSON file specified",
    "Malformed JSON",
    "JSON Parsing Error",
    "Invalid Arm Length",
    "Disconected Joint",
    "Motor Data Missing",
    "Unsupported Joint Count",
    "Invalid Rotation Axis",
    "Quternion Calculation Failed",
};

static error_code_to_string_table_t error_code_to_description_table = {
    "Wrong path or file does not exist",
    "",
    "JSON Parsing Error",
    "Invalid Arm Length",
    "Disconected Joint",
    "Motor Data Missing",
    "Unsupported Joint Count",
    "Invalid Rotation Axis",
    "Quternion Calculation Failed",
};
} // namespace Errors
