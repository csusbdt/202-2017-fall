#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

using namespace std;

int main(int argc, char * argv[]) {
        const char * cmd = "echo $PATH";

        FILE * pipe = popen(cmd, "r");
        if (pipe == nullptr) {
                cout << "error: " << strerror(errno) << endl;
                return 1;
        }

	//char path[200];
        char c;
        while (fread(&c, 1, 1, pipe) == 1) {
		cout << c << endl;
        }
        fclose(pipe);
}

