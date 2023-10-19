#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Data {
    std::string instance_name;
    double modified_solution_cost;
    double original_solution_cost;
    double modified_runtime;
    double original_runtime;
    double modified_f_min_value;
    double original_f_min_value;
    int modified_num_descendants;
    int original_num_descendants;
    int num_duplicate_conflicts;
};

int main() {
    std::ifstream input_file("/home/hiuching-g/CLionProjects/csvConverter/maze-8-8.csv");
    std::ofstream output_file("/home/hiuching-g/CLionProjects/csvConverter/maze-8-8-output.csv");

    std::string line1, line2;

    // Write headers
    output_file << "instance name,Modified_solution_cost,Original_solution_cost,"
                   "Modified_runtime,Original_runtime,Modified_f_min_value,"
                   "Original_f_min_value,Modified_number_of_descendants,"
                   "Original_number_of_descendants,number_of_duplicate_conflict\n";
    std::getline(input_file, line1);
    while (std::getline(input_file, line1) && std::getline(input_file, line2)) {
        std::istringstream iss1(line1);
        std::istringstream iss2(line2);
        Data data;
        std::vector<std::string> tokens1;
        std::vector<std::string> tokens2;

        std::string token;

        // Read instance name
        while (std::getline(iss1, token, ',')) {
            tokens1.push_back(token);
        }

        // Read tokens from the second line
        while (std::getline(iss2, token, ',')) {
            tokens2.push_back(token);
        }

        // Assign values based on token indices
        data.instance_name = tokens1[34].substr(0, 40);
        data.modified_solution_cost = std::stod(tokens1[5]);
        data.original_solution_cost = std::stod(tokens2[5]);
        data.modified_runtime = std::stod(tokens1[0]);
        data.original_runtime = std::stod(tokens2[0]);
        data.modified_f_min_value = std::stod(tokens1[6]);
        data.original_f_min_value = std::stod(tokens2[6]);
        data.modified_num_descendants = std::stoi(tokens1[31]);
        data.original_num_descendants = std::stoi(tokens2[31]);
        data.num_duplicate_conflicts = std::stoi(tokens1[25]);

        // Write combined data to output file
        output_file << data.instance_name << ","
                    << data.modified_solution_cost << ","
                    << data.original_solution_cost << ","
                    << data.modified_runtime << ","
                    << data.original_runtime << ","
                    << data.modified_f_min_value << ","
                    << data.original_f_min_value << ","
                    << data.modified_num_descendants << ","
                    << data.original_num_descendants << ","
                    << data.num_duplicate_conflicts << "\n";
    }

    input_file.close();
    output_file.close();

    std::cout << "Output file 'output.csv' created successfully!" << std::endl;

    return 0;
}
