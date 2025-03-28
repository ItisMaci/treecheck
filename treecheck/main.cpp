#include "include/ProgramManager.h"

int main(int argc, char* argv[]){
    ProgramManager Program;
    
    if (argc < 2 || argc > 3) { // too little/too many arguments
        std::cerr << "Invalid arguments!" << std::endl;
        return 1;
    }

    if (argc == 2) { // 1 argument --> import file
        std::string file = argv[1];
        Program.treecheck(file);
    }

    if (argc == 3) { // 2 arguments --> search subtree in tree
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        Program.treecheck(file1, file2);
    }
    
    return 0;
}