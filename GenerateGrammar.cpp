#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map< std::string, std::vector<std::string> >  RULES;

int main() {
  std::string line;
  std::string current_rule;
  
  while (std::getline(std::cin, line)) {
    auto colon_loc = line.find(':');
    if (colon_loc != line.end()) {
      std::string new_rule = std::string(line.begin(), colon_loc);

      RULES[new_rule] = std::vector<std::string>();
    }

    
  }

}
