#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream input_file;
	ofstream output_file;

	input_file.open("PB DATA.txt", ios::in);
	output_file.open("PB DATA (EXCEL READABLE).txt", ios::out);

	int start_line = 0;
	string line;
	string prefix_check = "POWER";

	if (input_file.is_open())
	{
		while (!input_file.eof())
		{
			for (int i = start_line; i < start_line + 8; i++)
			{	
				getline(input_file, line);
				if (line.rfind(prefix_check, 0) == 0)
				{
					output_file << line;
				}
				else
				{
					output_file << line << ", ";
				}
			}
			output_file << "\n";
			start_line += 8;
		}
	}

	input_file.close();
	output_file.close();

	return 0;
}