#pragma once
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getFileNames();

std::vector<double> getValuesFromFile(std::string filename);