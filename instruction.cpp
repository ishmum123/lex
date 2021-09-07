#include <string>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;

class Instruction {
    private:
        const vector<string> regeces;
        const string cmd;
    public:
        Instruction(string cmd, vector<string> regeces) : cmd(cmd), regeces(regeces) {}
        bool match_cmd(string cmd);
        string match_args(string argstr);

};

bool Instruction::match_cmd(string cmd) {
    return cmd == this->cmd;
}

string Instruction::match_args(string argstr) {
    stringstream argstream(argstr);

    string arg;
    vector<string> args;

    while (getline(argstream, arg))
        args.push_back(arg);

    if (args.size() != regeces.size())
        return "Invalid number of arguments";

    for (int i = 0; i < args.size(); i++)
        if (!regex_match(args[i], regex(regeces[i])))
            return "Argument " + args[i] + " does not match the required pattern";

    return NULL;
}

