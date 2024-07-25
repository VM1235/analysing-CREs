#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath> // for abs

using namespace std;

void count_distances_within_threshold(const string& filename, const string& str1, const string& str2) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string current_line, sequence;
    vector<int> distances;
    size_t pos_str1 = string::npos;
    size_t pos_str2 = string::npos;

    while (getline(file, current_line)) {
        // Check if line starts with ">" (FASTA header)
        if (current_line.empty() || current_line[0] == '>') {
            continue;
        }

        sequence += current_line;
    }

    // Find occurrences of both strings
    size_t start_pos = 0;
    while ((pos_str1 = sequence.find(str1, start_pos)) != string::npos) {
        start_pos = pos_str1 + 1; // Update start position for next search
        pos_str2 = sequence.find(str2, pos_str1 + str1.length());
        if (pos_str2 != string::npos) {
            // Calculate distance between occurrences
            int distance = abs(static_cast<int>(pos_str2) - static_cast<int>(pos_str1) - static_cast<int>(str1.length()));
            if (distance >= 0 && distance <= 30) {
                distances.push_back(distance);
            }
        }
    }

    // Write distances to CSV file
    ofstream output_file("output2.csv");
    if (!output_file.is_open()) {
        cerr << "Error: Could not create or open output.csv for writing." << endl;
        return;
    }

    if (!distances.empty()) {
        output_file << "Distances between \"" << str1 << "\" and \"" << str2 << "\" (positive, <= 30):" << endl;
        for (size_t i = 0; i < distances.size(); ++i) {
            output_file << distances[i];
            if (i != distances.size() - 1) {
                output_file << ",";
            }
        }
        output_file << endl;
    } else {
        output_file << "No positive distances less than or equal to 30 found between \"" << str1 << "\" and \"" << str2 << "\"." << endl;
    }

    output_file.close();
}

int main() {
    string filename;
    cout << "Enter the FASTA file name: ";
    cin >> filename;

    string str1, str2;
    cout << "Enter the first 4-character sequence: ";
    cin >> str1;
    cout << "Enter the second 4-character sequence: ";
    cin >> str2;

    count_distances_within_threshold(filename, str1, str2);

    return 0;
}
