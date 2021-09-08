#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_lines(string file_path) {
    ifstream file(file_path);
    vector<string> lines;
    string line;

    while (getline(file, line))
        lines.push_back(line);

    return lines;
}
