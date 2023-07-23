#include <iostream>
#include <string>
#include <fstream> 
using namespace std; 


int main(int argc, char **argv) {

    ofstream bigFileOut("BigFile.Text"); 

    for (int i = 0; i < 214748364; i++) {
        bigFileOut << "This is a test line for large file.................................." << endl;
    }

    bigFileOut.close();

}