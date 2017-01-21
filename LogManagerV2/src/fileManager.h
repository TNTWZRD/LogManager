// Code Written and maintained by Daniel Jajliardo @ TheTechSphere
// Copywrite 2017 Daniel Jajliardo @ TheTechSphere
// This is a small utiliy file for File Reading and writing
// Version 1.0 Updated 01/20/17 Daniel Jajliardo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#pragma once

namespace fmanager {

	class FileManager {
	private:
		std::fstream fs;

	public:
		FileManager() {}

		std::string readFile_s(std::string FileName) {
			std::string result = "";
			fs.open(FileName, std::fstream::in);
			char c;
			while (fs.get(c))
				result += c;

			fs.close();
			return result;
		}

		std::vector<std::string> readFile_v(std::string FileName) {
			std::vector<std::string> result;
			fs.open(FileName, std::fstream::in);
			std::string out;
			while (std::getline(fs, out))
				result.push_back(out);
			fs.close();
			return result;
		}

		void writeFile(std::string filename, std::string content) {
			std::ofstream fo;
			fo.open(filename, std::fstream::out);
			fo << content << "\n";
			fo.close();
		}

		void appendFile(std::string filename, std::string content) {
			fs.open(filename, std::fstream::app);
			fs << content << "\n";
			fs.close();
		}

	};
}