#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void compareFiles(string file1, string file2) 
{
    ifstream f1(file1);
    ifstream f2(file2);
    if (f1 && f2) 
    {
        string line1, line2;
        int lineNumber = 1;
        while (!f1.eof() && !f2.eof())
        {
            getline(f1, line1);
            getline(f2, line2);
            if (line1 != line2) 
            {
                cerr << "\033[31mWrong answer. Difference found at line: " << lineNumber << ".\033[0m" << endl;
                cerr << file1 << ": " << line1 << endl;
                cerr << file2 << ": " << line2 << endl;
                return;
            }
            lineNumber++;
        }
        if (f1.eof() && f2.eof()) 
            cerr << "\033[32mAccept. The files are identical.\033[0m" << endl;
    } 
    else
        cerr << "Failed to open files." << endl;
}
int main() 
{
    string file1 = "grassplant.out";
    string file2 = "grassplant.ans";
    compareFiles(file1, file2);
}