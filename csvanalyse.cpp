#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

void createFrequencyTable(const std::string& filename) {
    // Initialize an unordered_map to count occurrences of numbers 1-30
    std::unordered_map<int, int> frequencyTable;
    // Open the CSV file
    std::ifstream file(filename);
    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    std::string line, entry;
    // Read each line from the file
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        // Read each entry separated by commas
        while (std::getline(iss, entry, ',')) {
            // Convert entry to an integer
            int num;
            std::istringstream(entry) >> num;
            // Check if the number is between 1 and 30
            if (num >= 0 && num <= 30) {
                // Increment the count in the frequency table
                frequencyTable[num]++;
            }
        }
    }
    // Print the frequency table
    std::cout << "Number\tFrequency" << std::endl;
    for (int i = 0; i <= 30; ++i) {
        std::cout << i << "\t" << frequencyTable[i] << std::endl;
    }
}

int main() {
    // Provide the path to the input CSV file
    std::string filename = "output2.csv";
    createFrequencyTable(filename);
    return 0;
}
