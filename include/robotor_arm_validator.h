#pragma once
#include "errors.h"

namespace nlohmann {
class jason;
}

namespace JSON {
    class RobotorArmValidator {
        const char* SCHEME_NAME = "../schemes/input_scheme.json";
        const nlohmann::jason* input_ = nullptr;
    public:
     
        RobotorArmValidator(const  nlohmann::jason& input );
        
        void validate_scheme();
        
        void validate_content();
        
        Errors::erro_map_t get_errors() const;
    };
}
