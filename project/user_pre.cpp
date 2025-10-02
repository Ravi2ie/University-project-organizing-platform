#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>

struct Feedback {
    int id;
    std::string register_number;
    std::string feedback_type;
    std::string feedback_text;
    std::string date;
    std::string time;
    int seen;
    int priority;

    // Adjust comparison logic to prioritize based on the priority field
    bool operator<(const Feedback& other) const {
        return priority < other.priority; // Higher priority number comes first
    }
};

int main() {
    std::ifstream infile("C:/Users/bhusb/OneDrive/Documents/project/templates/user_feedback.txt");
    std::ofstream outfile("C:/Users/bhusb/OneDrive/Documents/project/templates/prior_feed.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::priority_queue<Feedback> pq;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        Feedback fb;
        iss >> fb.id >> fb.register_number >> fb.feedback_type >> fb.feedback_text 
            >> fb.date >> fb.time >> fb.seen >> fb.priority;
        pq.push(fb);
    }

    infile.close();

    while (!pq.empty()) {
        Feedback fb = pq.top();
        pq.pop();
        outfile << fb.id << "\t" << fb.register_number << "\t" << fb.feedback_type << "\t"
                << fb.feedback_text << "\t" << fb.date << "\t" << fb.time << "\t" 
                << fb.seen << "\t" << fb.priority << std::endl;
    }

    outfile.close();

    return 0;
}
