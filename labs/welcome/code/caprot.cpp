#include <iostream>
#include <string>
#include <cstdlib> // for exit
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	// Check correct arguments
	if(argc != 2){
		cerr << "USAGE: caprot [rotation]" << endl;
		exit(1);
	}

	// Variables
	int numRotate = stoi(argv[1]), temp;
	string line;
	vector<bool> capitalize;

	// Get input
	getline(cin, line);
    numRotate %= line.size(); // simplify numRotate

	// Loop through line to save capitalizations
	for(int i = line.size()-1; i >= 0; i--){
		if(isupper(line[i])){
			capitalize.push_back(1);
		}
        else{
            capitalize.push_back(0);
        }
	}
	
	// Capitalize
	for(int i = 0; i < int(line.size()); i++){
		temp = i + numRotate;
		if(temp <= 0){ temp += line.size(); } // Negative Wrapping
		if(temp >= int(capitalize.size())){ temp -= line.size(); } // Wrapping

		if(capitalize[i]){
			line[temp] = toupper(line[temp]);
		}
		else{
			line[temp] = tolower(line[temp]);
		}
	}

	// Output
	cout << line << endl;

	return 0;
}
