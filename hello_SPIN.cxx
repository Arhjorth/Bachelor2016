#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define COMMAND "spin -u200 -p /home/obel/dtu/bachelor/promelaTests/Lab2.pml"

int simpleRun() {
    cout << "using system to run spin:" << endl;
    system(COMMAND);
    return 0;
}

string exec(string command) {
    cout << "using exec to run spin:" << endl;
    FILE *in;
    char buff[512];
    char *cmd = new char[command.length()+1];
    strcpy(cmd , command.c_str());
    cout << cmd << endl;
    string out;
    if(!(in = popen(cmd, "r"))){
        return "error";
    }
    while(fgets(buff, sizeof(buff), in)!=NULL){
        out += buff;
    }
    pclose(in);
    return out;
}

int runWithPopen() {
    cout << "using popen to run spin:" << endl;
    FILE *in;
    char buff[512];
    if(!(in = popen(COMMAND, "r"))){
        return 1;
    }
    while(fgets(buff, sizeof(buff), in)!=NULL){
        cout << buff;
    }
    pclose(in);
    cout << string(buff) << endl;
    return 0;
}

int main(int arg1, char** arg2) {
    string i;
    cout << arg1 << endl;
    if (arg1==2) {
        string file = arg2[1];
        cout << file << endl;
        i = exec("spin -u200 -p "+file);
    } else {
        cout << "Must have one argument";
    }
    cout << i << endl;
}
