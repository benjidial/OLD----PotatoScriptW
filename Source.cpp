#include <iostream>  // Console IO
#include <fstream>   // File IO
#include <string>    // Easier Strings
#include <math.h>    // exponents
void COOLSTUFF(char *file);
int main(int argc, char *argv[ ]) // Program enters here.
{
	using namespace std; // Makes some code shorter.
	if (argc == 1)
	{
		cout << "No file supplied!" << endl;
		cout << "Try clicking and dragging a file to this one." << endl;
		cin.clear();
		cin.get();
		exit(-1);
	}
	for (int nArg = 1; nArg < argc; nArg++)  // Allows multiple files.
	{
		ofstream outf("logfile.txt");
		outf << "Begin processing file " << nArg <<
			" of " << argc - 1 << ": " << argv[nArg] << endl;

		try
		{
			COOLSTUFF(argv[nArg]);
		}
		catch (char* strException)
		{
			outf << strException << endl;
		}
		outf << "Finished processing file " << nArg <<
			" of " << argc - 1 << ": " << argv[nArg] << endl;
		if (nArg == argc - 1)
		{
			cout << "Finished all interpereting jobs!" << endl;
			cout << "Press enter to close this window." << endl;
		}
		else
		{
			cout << "Finished interpeteting job " << nArg <<
				" of " << argc - 1 << "." << endl;
			cout << "Press enter to start nex job." << endl;
		}
		cin.clear();
		cin.get();
	}
	return 0;  // Lets the OS know there were no problems.
}
void COOLSTUFF(char *file)
{
	using namespace std;
	ifstream inf(file);
	if (!inf)
		throw "Could not open file.";
	while (inf)
	{
		string strQ;
		inf >> strQ;
		if (strQ == "alert")
		{
			cout << static_cast<char>(7);
		}
		else if (strQ == "clearscreen")
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		else if (strQ == "display")
		{
			getline(inf, strQ);
			cout << strQ << endl;
		}
		
		else if (strQ == "exit")
			throw "Hit exit. (This is harmless.)";
		else if (strQ == "wait")
		{
			cin.clear();
			cin.get();
		}
		else
			throw "Unrecognized command.";
	}
}