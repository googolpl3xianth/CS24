#include <iostream>
#include <string>
#include <cstdlib> // for exit

int main(int argc, char *argv[]){
	// Check correct arguments
	if(argc != 2){
		cerr << "USAGE: caprot [rotation]" << endl;
		exit(1);
	}

	// Variables
	int numRotate = argc[1], temp;
	string line;
	bool *capitalize = new bool[numRotate];

	// Get input
	cin >> line;

	// Loop through line to save capitalizations
	for(int i = line.size()-1; i >= 0 i--){
		if(isupper(line[i])){
			capitalize[i] = 1;
		}
	}
	
	// Capitalize
	for(int i = 0; i < capitalize.size(); i++){
		temp = i + numRotate;
		if(temp >= size){ temp -= size; } // Wrapping

		if(capitalize[i]){
			toupper(line[i+numRotate]);
		}
		else{
			tolower(line[i+numRotate]);
		}
	}

	// Output
	cout << line << endl;

	// Cleanup
	delete capitalize[];

	return 0;
}
