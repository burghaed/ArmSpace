//
//  Errors.h
//  ArmSpace
//
//  Created by Eduardt Burghardt on 17.06.25.
//

#pragma once
#include <map>
#include <vector>

namespace Errors {
    enum class ERROR : unsigned short {
        ERR001, ERR002, ERR003, ERR004, ERR005, ERR006, ERR007, ERR008, ERR009,  ERR0010, ERR011, NUM_ERR
    };
    
    using error_map_t = std::map< ERROR, std::string>;
    using error_table_t = std::array<std::string, static_cast<size_t>(ERROR::NUM_ERR)>;
    
    error_table_t  error_table = {
        "Invalid Arm Length", "Disconected Joint", "Malformed JSON", "Motor Data Missing", "Unsupported Joint Count", "Invalid Rotation Axis", "Quternion Calculation Failed", "Tick Calculation Overflow", "No JSON file specified", "Cannot open file", "JSON Parsing Error"
    };
}
