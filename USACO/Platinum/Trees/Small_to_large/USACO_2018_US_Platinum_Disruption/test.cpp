#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (f1 && f2) {
        std::string line1, line2;
        int lineNumber = 1;

        while (std::getline(f1, line1) && std::getline(f2, line2)) {
            if (line1 != line2) {
                std::cout << "Difference found at line " << lineNumber << ":" << std::endl;
                std::cout << file1 << ": " << line1 << std::endl;
                std::cout << file2 << ": " << line2 << std::endl;
                return;
            }
            lineNumber++;
        }

        if (f1.eof() && f2.eof()) {
            std::cout << "The files are identical." << std::endl;
        } else {
            std::cout << "Difference found at line " << lineNumber << ":" << std::endl;
            std::cout << "One file has more lines than the other." << std::endl;
        }
    } else {
        std::cout << "Failed to open files." << std::endl;
    }
}

int main() {
    std::string file1 = "disrupt.out";
    std::string file2 = "disrupt.ans";

    compareFiles(file1, file2);

    return 0;
}
