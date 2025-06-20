#pragma once
#include "errors.h"
#include <fstream>
#include <nlohmann/json-schema.hpp>
#include <nlohmann/json.hpp>

namespace JSON {
class RobotorArmValidator {
  const char *SCHEME_PATH = "schemes/input_scheme.json";
  std::vector<Errors::ERROR> error_;
  nlohmann::json_schema::json_validator validator;
  nlohmann::json schema;

  void loadSchema(const std::string &schemaPath) {
    std::ifstream file(schemaPath);
    if (!file) {
      throw std::runtime_error("Error: Unable to open schema file.");
    }

    try {
      file >> schema;
      validator.set_root_schema(schema);
    } catch (const nlohmann::json::parse_error &e) {
      throw std::runtime_error("Schema Parsing Error: " +
                               std::string(e.what()));
    }
  }

public:
  void validate_scheme(const nlohmann::json &input);

  void validate_content(const nlohmann::json &input);

  bool is_success() const { return error_.empty(); }

  const std::vector<Errors::ERROR> &errors() const { return error_; }
};
} // namespace JSON
