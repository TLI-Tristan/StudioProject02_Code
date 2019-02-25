#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class TrackMaker
{
public:
	TrackMaker();
	~TrackMaker();
	// create obj 
	void SaveMap(int, int, int); // can
	vector<string> GetMap();// can


private:
	vector<string> allOBJ;
	double CRUSOR_X_POS;
	double CRUSOR_Y_POS;
};

