#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_fastq_file> <output_fna_file>" << endl;
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    ifstream input_file(input_filename);
    ofstream output_file(output_filename);

    if (!input_file) {
        cout << "Error: Could not open input file: " << input_filename << endl;
        return 1;
    }

    if (!output_file) {
        cout << "Error: Could not open output file: " << output_filename << endl;
        return 1;
    }

    string line;
    bool reading_sequence = false;

    while (getline(input_file, line)) {
        if (line.empty()) {
            reading_sequence = false;
            continue;
        }

        if (reading_sequence) {
            output_file << line << endl;
        }

        if (line[0] == '@') {
            reading_sequence = true;
            output_file << ">" << line.substr(1) << endl;
        }
    }

    input_file.close();
    output_file.close();

    cout << "Conversion complete!" << endl;

    return 0;
}
