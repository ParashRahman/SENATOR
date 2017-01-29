#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <streambuf>
#include <stringstream>

std::map< std::string, std::vector<std::string> >  RULES;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
// http://stackoverflow.com/questions/236129/split-a-string-in-c

std::string CODE_P1 =
  "#include <iostream>\n" +
  "#include <string>\n" +
  "#include <cstdlib>\n" +
  "#include <vector>\n" +
  "#include <cstdlib>\n" +
  "class ";

std::string CODE_P2 =
  "{\n" +
  "private:";

std::string CODE = "";

int main() {  
  std::string line;
  std::string current_rule = "";
  
  std::string title;
  
  std::getline(std::cin, title);

  CODE += CODE_P1;
  CODE += title;
  CODE += CODE_P2;

  std::string private_variables =
    "private: \n";

  std::string public_variables =
    "public: \n";
  
  while (std::getline(std::cin, line)) {
    int colon_index = line.find(':');
    std::cout << colon_index << std::endl;
    
    auto colon_loc = line.begin() + colon_index;

    std::vector<std::string> split_line = split(line, ' ');

    std::string title = std::string(line.begin(), colon_loc);

    if (li == 0) {
      public_variables += ("std::string " + title + "(int complexity) {\n");
      public_variables += ("int NUM_RULES = " + std::to_string(split_line.size()) + ";\n");
      public_variables += "int random_choice = rand() % NUM_RULES;";
    }
    
    
    if (li == 0) {
      public_variables += ("if(complexity <= 0) {");
      for (int li = 0; li < split_line.size(); ++li) {
	std::string portion = split_line[li];
	if (portion.find(".txt") != -1) {
	  // load file into string
	  std::ifstream ifs(portion);
	  std::string string_rep ((std::istreambuf_iterator<char>(ifs)),
				  std::istreambuf_iterator<char>());
	  std::istringstream iss(string_rep);
	  
	  std::string file_line;
	  private_variable += "std::vector<std::string> "; 
	  while (std::getline(iss, file_line)) {
	    private_variables += ("\"" + file_line + "\",\n");
	  }

	  public_variables += ("
	} else {
	  public_variables += ("std::string p" + std::to_string(li) + " = " +portion + "(complexity - 1);");
	}
      }

      
    }
    
      
      
      
  }
  
  std::string filePath = "bin/" + title + ".txt";
  std::ofstream o(filePath);
  
  if (o.is_open()) {
    std::cout << "FILE OPENED! " << filePath << std::endl;
  } else {
    std::cout << "FILE UNOPENED :( " << filePath << std::endl;
  }
}
