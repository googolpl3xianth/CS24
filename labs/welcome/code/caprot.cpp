#include <iostream>
#include <string>
#include <cstdlib> // for exit
using namespace std;

int main(int argc, char *argv[]){
	// Check correct arguments
	if(argc != 2){
		cerr << "USAGE: caprot [rotation]" << endl;
		exit(1);
	}

	// Variables
	int numRotate = argc[1], temp;
	string line;
	bool * capitalize;

	// Get input
	cin >> line;
	capitalize = new bool[line.size()];

	// Loop through line to save capitalizations
	for(int i = line.size()-1; i >= 0; i--){
		if(isupper(line[i])){
			capitalize[i] = 1;
		}
	}
	
	// Capitalize
	for(int i = 0; i < line.size(); i++){
		temp = i + numRotate;
		while(temp <= 0){ temp += line.size(); } // Negative Wrapping
		while(temp >= line.size()){ temp -= line.size(); } // Wrapping

		if(capitalize[i]){
			line[temp] = toupper(line[temp]);
		}
		else{
			line[temp] = tolower(line[temp]);
		}
	}

	// Output
	cout << line << endl;

	// Cleanup
	delete[] capitalize;

	return 0;
}
