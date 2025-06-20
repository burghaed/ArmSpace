#pragma once
#include "errors.h"
#include <fstream>
#include <nlohmann/json-schema.hpp>
#include <nlohmann/json.hpp>

namespace JSON {
using error_container_t = std::vector<Errors::error_t>;
class RobotorArmValidator {
  error_container_t error_;
  nlohmann::json_schema::json_validator validator_;

  void loadSchema();

public:
  void validate_scheme(const nlohmann::json &input);

  void validate_content(const nlohmann::json &input);

  bool is_success() const { return error_.empty(); }

  const error_container_t &errors() const { return error_; }
};
} // namespace JSON
