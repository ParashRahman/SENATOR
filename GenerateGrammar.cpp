#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

std::map< std::string, std::vector<std::string> >  RULES;

int main() {
  std::string line;
  std::string current_rule;

  std::string title;
  
  std::getline(std::cin, title);
  
  while (std::getline(std::cin, line)) {
    int colon_index = line.find(':');
    std::cout << colon_index << std::endl;

    auto colon_loc = line.begin() + colon_index;
    
    if (colon_index == -1) {
      colon_loc = line.end();
    }
        
    if (colon_loc != line.end()) {
      current_rule = std::string(line.begin(), colon_loc);
      RULES[current_rule] = std::vector<std::string>();
    }
    
    RULES[current_rule].push_back(line);
  }

  std::string filePath = "bin/" + title + ".txt";
  std::ofstream o(filePath);
  
  if (o.is_open()) {
    std::cout << "FILE OPENED! " << filePath << std::endl;
  } else {
    std::cout << "FILE UNOPENED :( " << filePath << std::endl;
  }
  
  for (auto map_elem : RULES) {
    std::string rule_name = map_elem.first;
    std::vector<std::string> rules = RULES[rule_name];

    for (int i = 0; i < rules.size(); ++i) {
      // this  is where the rules are processed properly
      o << rules[i] << std::endl;
    }
  }
  
  
}
