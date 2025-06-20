//
//  robotor_arm_validator.cpp
//  ArmSpace
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#include "robotor_arm_validator.h"
#include "errors.h"
#include "input_scheme.h"
#include <exception>
#include <iostream>

namespace JSON {

void RobotorArmValidator::loadSchema(const std::string &schemaPath) {
  nlohmann::json schema_json = nlohmann::json::parse(std::string(
      reinterpret_cast<const char *>(
          _Users_eduardtburghardt_Documents_Codding_ArmSpace_schemes_input_scheme_json),
      _Users_eduardtburghardt_Documents_Codding_ArmSpace_schemes_input_scheme_json_len));

  validator.set_root_schema(schema);
}
void RobotorArmValidator::validate_scheme(const nlohmann::json &input) {
  try {
    loadSchema(SCHEME_PATH);
  } catch (nlohmann::json::parse_error &ex) {
    error_.emplace_back(
        Errors::ERROR::MAILFORMED_JSON,
        Errors::error_code_to_message_table.at(
            static_cast<size_t>(Errors::ERROR::MAILFORMED_JSON)),
        ex.what());
  } catch (std::exception &ex) {
    error_.emplace_back(
        Errors::ERROR::NO_JSON_FILE_SPECIFIED,
        Errors::error_code_to_message_table.at(
            static_cast<size_t>(Errors::ERROR::NO_JSON_FILE_SPECIFIED)),
        ex.what());
  }
}

} // namespace JSON
