// Code Written and maintained by Daniel Jajliardo @ TheTechSphere
// Copywrite 2017 Daniel Jajliardo @ TheTechSphere
// This is a small utiliy file for File Reading and writing
// Version 1.0 Updated 01/20/17 Daniel Jajliardo

// Usage:
// #include "fileManager.h"
// 
// fmanager::FileManager fman;
// string fileAsString         = fman.readfile_s("file.txt");
// vector<string> fileAsVector = fman.readfile_v("file.txt");
//
// fman.writeFile ("file.txt", "Overwrite file contents with this.");
// fman.appendFile("file.txt", "Append this content to file.");

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define _FileManager true

#pragma once

using namespace std;
namespace fmanager {

	class FileManager {
	private:
		fstream fs;

	public:
		FileManager() {}
		~FileManager() {}

		string readFile_s(string FileName) {
			string result = "";
			fs.open(FileName, fstream::in);
			char c;
			while (fs.get(c))
				result += c;

			fs.close();
			return result;
		}

		vector<string> readFile_v(string FileName) {
			vector<string> result;
			fs.open(FileName, fstream::in);
			string out;
			while (getline(fs, out))
				result.push_back(out);
			fs.close();
			return result;
		}

		void writeFile(string filename, string content) {
			ofstream fo;
			fo.open(filename, fstream::out);
			fo << content << "\n";
			fo.close();
		}

		void appendFile(string filename, string content) {
			fs.open(filename, fstream::app);
			fs << content << "\n";
			fs.close();
		}

	};
}