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

void RobotorArmValidator::loadSchema() {
  nlohmann::json schema_json = nlohmann::json::parse(
      std::string(reinterpret_cast<const char *>(input_scheme_json),
                  input_scheme_json_len));

  validator_.set_root_schema(schema_json);
}
void RobotorArmValidator::validate_scheme(const nlohmann::json &input) {
  try {
    loadSchema();
    validator_.validate(input);
  } catch (nlohmann::json::parse_error &ex) {
    error_.emplace_back(
        Errors::ERROR::MAILFORMED_JSON,
        Errors::error_code_to_message_table.at(
            static_cast<size_t>(Errors::ERROR::MAILFORMED_JSON)),
        ex.what());
    std::cerr << "Error: "
              << Errors::error_code_to_message_table.at(
                     static_cast<size_t>(Errors::ERROR::MAILFORMED_JSON))
              << " " << ex.what();
  } catch (std::exception &ex) {
    error_.emplace_back(
        Errors::ERROR::NO_JSON_FILE_SPECIFIED,
        Errors::error_code_to_message_table.at(
            static_cast<size_t>(Errors::ERROR::NO_JSON_FILE_SPECIFIED)),
        ex.what());
    std::cerr << "Error: "
              << Errors::error_code_to_message_table.at(
                     static_cast<size_t>(Errors::ERROR::NO_JSON_FILE_SPECIFIED))
              << " " << ex.what();
  }
}

} // namespace JSON
