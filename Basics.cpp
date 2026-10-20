#include <iostream> // include the input-output stream library for cin and cout
#include <string>   // include string library for string data type and operations
#include <fstream>  // include fstream library for file input and output operations (ifstream, ofstream)

using namespace std; // use the standard namespace to avoid writing std constantly

// define a structure named Student to hold related academic data for a single student
struct Student
{
	string name; // store the student's name as a string
	int math;    // store the math grade as an integer
	int physics; // store the physics grade as an integer
};

int main()
{
	// set the locale to support Hungarian characters in the console output
	setlocale(LC_ALL, "hu_HU.UTF-8");

	// declare an array of Student structures capable of holding up to 12 records
	Student students[12];

	// open the input file stream to read data from jegyek01.txt
	ifstream reader("jegyek01.txt");

	// check if the file was successfully opened
	if (!reader.is_open())
	{
		// print error message if file opening fails
		cout << "file not found. ";
		return 1; // exit program with error code 1
	}

	// initialize counter index variable to track the number of students read from the file
	int i = 0;

	// loop until the end of the file is reached
	while (!reader.eof())
	{
		// read math grade name and physics grade sequentially from the file into the structure array
		reader >> students[i].math >> students[i].name >> students[i].physics;

		// increment student counter index
		i++;
	}

	// close the input file stream after reading is complete
	reader.close();

	// store the total count of students read into the headcount variable
	int headcount = i;

	// iterate through the array to display each student's details in the console
	for (int i = 0; i < headcount; i++)
	{
		// print student name math grade and physics grade separated by spaces
		cout << students[i].name << "  " << students[i].math << "  " << students[i].physics << endl;
	}

	// open the output file stream to write data into students.txt
	ofstream writer("students.txt");

	// check if the output file was successfully opened or created
	if (!writer.is_open())
	{
		// print error message if output file creation fails
		cout << "error. ";
		return 1; // exit program with error code 1
	}

	// iterate through the student array to write each record into the output file
	for (int i = 0; i < headcount; i++)
	{
		// write student name math grade and physics grade separated by spaces into the file
		writer << students[i].name << "  " << students[i].math << "  " << students[i].physics << endl;
	}

	// close the output file stream after writing is complete
	writer.close();

	// return 0 to indicate that the program executed successfully
	return 0;

}