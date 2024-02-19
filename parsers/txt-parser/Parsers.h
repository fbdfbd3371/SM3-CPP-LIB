#pragma once
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getFileNames() {
    std::string helpfilename = "fileForGetFiles.txt";
    std::string command = "dir /b > " + helpfilename;
    std::vector<std::string> ans;
    std::string line;
    system(command.c_str());
    std::ifstream in(helpfilename);
    if (in.is_open()) {
        while (std::getline(in, line)) {
            if (line.find(".txt") != std::string::npos && line != helpfilename) {
                ans.push_back(line);
            }
        }
    }
    in.close();
    remove(helpfilename.c_str());
    return ans;
}


std::vector<double> getValuesFromFile(std::string filename) {
    std::string line;
    std::ifstream in(filename);
    std::vector<double> ans;
    if (in.is_open()) {
        while (std::getline(in, line)) {
            ans.push_back(std::stod(line));
        }
    }
    in.close();
    return ans;
}
