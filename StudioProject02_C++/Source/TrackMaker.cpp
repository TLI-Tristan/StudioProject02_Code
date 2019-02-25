#include "TrackMaker.h"



TrackMaker::TrackMaker()
{
	CRUSOR_X_POS = 0;
	CRUSOR_Y_POS = 0;
}


TrackMaker::~TrackMaker()
{
}


void TrackMaker::SaveMap(int x, int posX, int posY)
{
	ofstream ofs;
	ofs.open("Position.txt", ofstream::out | ofstream::app);
	ofs << x << endl;
	ofs << posX << endl;
	ofs << posY << endl;

	cout << x << " " << posX << " " << posY << endl;

	ofs.close();
}

vector<string> TrackMaker::GetMap()
{
	string line;
	ifstream file("Position.txt");
	allOBJ.clear();

	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << std::endl;
			allOBJ.push_back(line);
		}
		file.close();
	}

	return allOBJ;
}

