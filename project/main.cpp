#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Loan {
    std::string projectName;
    std::string projectCase;
    std::string projectLevel;
    std::string allocationStatus;
    std::string startTime;
    std::string endTime;
};

// Comparison function for sorting loans based on starting and completion times
bool compareLoans(const Loan& a, const Loan& b) {
    if (a.startTime != b.startTime) {
        return a.startTime < b.startTime;  // Sort by starting time
    } else {
        // If starting times are equal, sort by completion time
        return a.endTime < b.endTime;
    }
}

int main() {
    // Define file paths
    std::string inputFilePath = "C:/Users/bhusb/OneDrive/Documents/project/templates/project.txt";
    std::string outputFilePath = "C:/Users/bhusb/OneDrive/Documents/project/templates/reverse_project.txt";

    // Read loan data from input file
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<Loan> loans;
    std::string line;

    // Read each line from the file and parse it into Loan struct
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Loan loan;
        if (std::getline(iss, loan.projectName, ',') &&
            std::getline(iss, loan.projectCase, ',') &&
            std::getline(iss, loan.projectLevel, ',') &&
            std::getline(iss, loan.allocationStatus, ',') &&
            std::getline(iss, loan.startTime, ',') &&
            std::getline(iss, loan.endTime)) {

            // Trim any leading/trailing whitespace from each field
            loan.projectName.erase(loan.projectName.find_last_not_of(" \n\r\t")+1);
            loan.projectCase.erase(loan.projectCase.find_last_not_of(" \n\r\t")+1);
            loan.projectLevel.erase(loan.projectLevel.find_last_not_of(" \n\r\t")+1);
            loan.allocationStatus.erase(loan.allocationStatus.find_last_not_of(" \n\r\t")+1);
            loan.startTime.erase(loan.startTime.find_last_not_of(" \n\r\t")+1);
            loan.endTime.erase(loan.endTime.find_last_not_of(" \n\r\t")+1);
            
            loans.push_back(loan);
        }
    }
    inputFile.close();

    // Sort the loan data based on starting and completion times
    std::sort(loans.begin(), loans.end(), compareLoans);

    // Write sorted loan data to output file
    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }

    for (const auto& loan : loans) {
        outputFile << loan.projectName << ", " << loan.projectCase << ", " << loan.projectLevel << ", " << loan.allocationStatus << ", " << loan.startTime << ", " << loan.endTime << std::endl;
    }
    outputFile.close();

    std::cout << "Datas sorted and written successfully." << std::endl;

    return 0;
}
