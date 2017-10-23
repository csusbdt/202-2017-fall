#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstring>
#include <vector>

using namespace std;

// Return a list of directories in the system path.
vector<string> getDirList() {
	string envPath = getenv("PATH");

	// Replace colons with new lines.
	for (int i = 0; i < envPath.size(); ++i) {
		if (envPath[i] == ':') envPath[i] = '\n';
	}

	stringstream ss(envPath);
	string path;
	vector<string> dirList;
	while (ss.good()) {
		ss >> path;
		dirList.push_back(path);
	}
	return dirList;
}

// Return a list of files in the given directory.
vector<string> getFileList(string dirPath) {
	string cmd = "ls " + dirPath;
	FILE * pipe = popen(cmd.c_str(), "r");
	if (pipe == nullptr) {
		cout << "error: " << strerror(errno) << endl;
		exit(1);
	}
	vector<string> fileList;
	char filename[1024];
	while (fgets(filename, 1024, pipe) != nullptr) {
		int len = strlen(filename);
		filename[len - 1] = '\0';
		fileList.push_back(string(filename));
	}
        fclose(pipe);
	return fileList;
}

int main(int argc, char * argv[]) {
	if (argc < 2) return 0;
	string cmd = argv[1];
	vector<string> dirList = getDirList();
	for (int i = 0; i < dirList.size(); ++i) {
		cout << dirList[i] << endl;
		vector<string> fileList = getFileList(dirList[i]);
		for (int j = 0; j < fileList.size(); ++j) {
			if (fileList[j] == "ls") {
				cout << "found" << endl;
			}
		}
	}
}


