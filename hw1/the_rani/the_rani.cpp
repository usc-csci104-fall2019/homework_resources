#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class TheRani {
public:
    TheRani(char* input_path, char* output_path);
    ~TheRani();

    // Call execute and handles exceptions
    void main();

private:
    int experiment_count;       // You will need to track the number of experiments
    int* subject_counts;        // For each, the number of subjects
    string** subject_history;   // And for each subject, their history

    ifstream input;             // Input file stream
    ofstream output;            // Output file stream

    // Called in the main method
    void execute(const string& line);

    // Possible helper: deallocate all current members
};

TheRani::TheRani(char* input_path, char* output_path) : experiment_count(0), input(input_path), output(output_path) {

}

TheRani::~TheRani() {

}

// Possible helper: read an integer argument from a stream

void TheRani::main() {
    string line;
    while (getline(input, line)) {
        try {
            this->execute(line);
        } catch(exception& e) {
            // If you use exceptions, make sure the line number is printed here
            this->output << "Error on line ?: " << e.what() << endl;
        }
    }
}

void TheRani::execute(const string& line) {
    string command;
    stringstream stream(line);  // Initialize the stream with the line
    stream >> command;          // Read the first word, which is the command

    if (command == "START") {   // This code should be edited for error checking
        int subject_pool_count;
        stream >> subject_pool_count;
        if (subject_pool_count < 0) {
            throw out_of_range("argument out of range");
        }

        // Your code here

    } // else if (more conditions) { ...
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Please provide an input and output file!" << endl;
        return 1;
    }

    TheRani tr(argv[1], argv[2]);
    tr.main();
    return 0;
}
