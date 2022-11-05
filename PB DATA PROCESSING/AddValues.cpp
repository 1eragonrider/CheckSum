/* ---------------------------------------------------------------------------------------------
|	This program takes a range of numbers and iterates through it to find the numbers 
|	whose sum equals a user defined values. You can choose to find sets of 2, 3, 4, or 5 
|	numbers which meet this criteria. This program outputs a file which lists these values.
|
|	Andrew Hanna
|	November 5th, 2022
|	Dependencies: none
------------------------------------------------------------------------------------------------*/


#include<iostream>
#include<string>
#include<fstream>

// function declarations
void FileAmend(std::ofstream& _file_par, std::string _string_par);
void CheckSum2(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par);
void CheckSum3(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par);
void CheckSum4(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par);
void CheckSum5(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par);
// end function declarations

int main()
{
	
	// declarations
	int _num_values_to_add;
	int _range_min; 
	int _range_max;
	int _chk_sum;
	int _min_chk_sum;
	int _max_chk_sum;
	std::string _print_string;

	// File preparation
	std::ofstream _out_file;
	_out_file.open("Permutation of addition within range.txt",std::ios::out);

	// user input
	std::cout << "Program to Calculate a number of values in a given range that add to a given number" << std::endl;
	std::cout << "Number of values that must be added to equal the desired sum: ";
	std::cin >> _num_values_to_add;
	std::cout << "Minimum value in range (inclusive): ";
	std::cin >> _range_min;
	std::cout << "Maximum value in range (inclusive): ";
	std::cin >> _range_max;
	std::cout << "Minimum value to check sum (inclusive): ";
	std::cin >> _min_chk_sum;
	std::cout << "Maximum value to check sum (exclusive): ";
	std::cin >> _max_chk_sum;

	// loop propagation
	for (_chk_sum = _min_chk_sum; _chk_sum <= _max_chk_sum; _chk_sum++)
	// loop through each sum target in the range provided by the user and output to a file.
	{
		_out_file << "The following values sum to " << _chk_sum << "\n\n";

		switch (_num_values_to_add)
		{
		case 1:
			std::cout << "Addition of one (1) is not a valid input." << std::endl;
			break;
		case 2:
			CheckSum2(_chk_sum, _range_min, _range_max, _out_file, _print_string);
			break;
		case 3:
			CheckSum3(_chk_sum, _range_min, _range_max, _out_file, _print_string);
			break;
		case 4:
			CheckSum4(_chk_sum, _range_min, _range_max, _out_file, _print_string);
			break;
		case 5:
			CheckSum5(_chk_sum, _range_min, _range_max, _out_file, _print_string);
			break;
		default:
			std::cout << "The maximum number of adders is 5" << std::endl;
			break;
		}
		_out_file << "\n\n";
	}

	// clean up
	_out_file.close();

	return 0;
}

void FileAmend(std::ofstream& _file_par, std::string _string_par)
{
	if (_file_par.is_open())
	{
		_file_par << _string_par << "\n";
	}
	else
	{
		std::cout << "The File cannot be amended." << std::endl;
	}
}

void CheckSum2(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par)
{
	for (int i = _range_min_par; i < _range_max_par; i++)
	{
		if (_chk_sum_par - (i + (i + 1)) < 0)
		{
			break;
		}

		for (int j = i + 1; j <= _range_max_par; j++)
		{
			if (_chk_sum_par - (i + j) < 0)
			{
				break;
			}
			else if (i + j == _chk_sum_par)
			{
				_string_par = std::to_string(i) + ", " 
					+ std::to_string(j);
				FileAmend(_file_par, _string_par);
			}
		}
	}
}

void CheckSum3(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par)
{
	for (int i = _range_min_par; i < _range_max_par; i++) // first number
	{
		if (_chk_sum_par - (i + (i + 1)) < 0)
		{
			break;
		}

		for (int j = i + 1; j <= _range_max_par; j++) // second number
		{
			if (_chk_sum_par - (i + j + (j + 1)) < 0)
			{
				break;
			}

			for (int k = j + 1; j <= _range_max_par; k++) // third number
			{
				if (_chk_sum_par - (i + j + k) < 0)
				{
					break;
				}
				else if (i + j + k == _chk_sum_par)
				{
					_string_par = std::to_string(i) + ", "
						+ std::to_string(j) + ", "
						+ std::to_string(k);
					FileAmend(_file_par, _string_par);
				}
			}
		}
	}
}

void CheckSum4(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par)
{
	for (int i = _range_min_par; i < _range_max_par; i++) // first number
	{
		if (_chk_sum_par - (i + (i + 1)) < 0)
		{
			break;
		}

		for (int j = i + 1; j <= _range_max_par; j++) // second number
		{
			if (_chk_sum_par - (i + j + (j + 1)) < 0)
			{
				break;
			}

			for ( int k = j + 1; j <= _range_max_par; k++) // third number
			{
				if (_chk_sum_par - (i + j + k + (k + 1)) < 0)
				{
					break;
				}

				for (int l = k + 1; l <= _range_max_par; l++) // fourth number
				{
					if (_chk_sum_par - (i + j + k + l) < 0)
					{
						break;
					}
					else if (i + j + k + l == _chk_sum_par)
					{
						_string_par = std::to_string(i) + ", "
							+ std::to_string(j) + ", "
							+ std::to_string(k) + ", "
							+ std::to_string(l);
						FileAmend(_file_par, _string_par);
					}
				}
			}
		}
	}
}

void CheckSum5(int _chk_sum_par, int _range_min_par, int _range_max_par, std::ofstream& _file_par, std::string _string_par)
{
	for (int i = _range_min_par; i < _range_max_par; i++) // first number
	{
		if (_chk_sum_par - (i + (i + 1)) < 0)
		{
			break;
		}

		for (int j = i + 1; j <= _range_max_par; j++) // second number
		{
			if (_chk_sum_par - (i + j + (j + 1)) < 0)
			{
				break;
			}

			for (int k = j + 1; j <= _range_max_par; k++) // third number
			{
				if (_chk_sum_par - (i + j + k + (k + 1)) < 0)
				{
					break;
				}

				for (int l = k + 1; l <= _range_max_par; l++) // fourth number
				{
					if (_chk_sum_par - (i + j + k + l + (l + 1)) < 0)
					{
						break;
					}

					for (int m = l + 1; m <= _range_max_par; m++) // fifth number
					{
						if (_chk_sum_par - (i + j + k + l + m) < 0)
						{
							break;
						}
						else if (i + j + k + l + m == _chk_sum_par)
						{
							_string_par = std::to_string(i) + ", "
								+ std::to_string(j) + ", "
								+ std::to_string(k) + ", "
								+ std::to_string(l) + ", "
								+ std::to_string(m);
							FileAmend(_file_par, _string_par);
						}
					}
				}
			}
		}
	}
}