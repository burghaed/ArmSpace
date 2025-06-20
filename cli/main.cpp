#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: No JSON file specified.\nUsage: " << argv[0]
              << " <input.json>" << std::endl;
    return 1;
  }

  const std::string filename = argv[1];
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error: Cannot open file " << filename << std::endl;
    return 1;
  }

  nlohmann::json input_json;
  try {
    file >> input_json;
  } catch (const nlohmann::json::parse_error &e) {
    std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
    return 1;
  }

  std::cout << "Success!" << std::endl;
  return 0;
}
