#pragma once
#include "errors.h"
#include <nlohmann/json.hpp>

namespace JSON {
    class RobotorArmValidator {
        const char* SCHEME_NAME = "../schemes/input_scheme.json";
    public:
        
        void validate_scheme(const nlohmann::json& input);
        
        void validate_content(const nlohmann::json& input);
        
    };
}
