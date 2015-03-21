#include <iostream>  // Console IO
#include <fstream>   // File IO
#include <string>    // Easier Strings
template <typename Type>
void COOLSTUFF(Type file);
int main(int argc, char *argv[]) // Program enters here.
{
	using namespace std; // Makes some code shorter.
	int nFiles = argc - 1;
	if (!nFiles)
	{
		cout << "No file supplied!" << endl;
		cout << "Press enter to close this window." << endl;
		cin.clear();
		cin.get();
	}
	for (int nArg = 1; nArg <= nFiles; nArg++)  // Allows multiple files.
	{
		ofstream outf("logfile.txt");
		outf << "Begin processing file " << nArg << " of " << nFiles << ": \"" << argv[nArg] << "\"" << endl;
		outf.flush();
		try
		{
			outf.close();
			COOLSTUFF(argv[nArg]);
		}
		catch (char* strException)
		{
			outf.open("logfile.txt", ios::app);
			outf << strException << endl;
			outf.close();
		}
		outf.open("logfile.txt", ios::app);
		outf << "Finished processing file " << nArg << " of " << nFiles << ": \"" << argv[nArg] << "\"" << endl;
		outf.flush();
		if (nArg == nFiles)
		{
			cout << "Finished all interpereting jobs!" << endl;
			cout << "Press enter to close this window." << endl;
		}
		else
		{
			cout << "Finished interpeteting job " << nArg << " of " << nFiles << "." << endl;
			cout << "Press enter to start next job." << endl;
		}
		cin.clear();
		cin.get();
	}
	return 0;  // Lets the OS know there were no problems.
}

template <typename Type>
void COOLSTUFF(Type file)
{
	using namespace std;
	string strQ;
	ifstream inf(file);
	if (!inf)
		throw "Could not open file.";
	ofstream outf("logfile.txt", ios::app);
	while (inf)
	{
		cin.clear();
		inf >> strQ;
		if (strQ == "alert") // logs
		{
			cout << static_cast<char>(7); // bell
			outf << "Alert triggered." << endl;
			outf.flush();
		}
		else if (strQ == "beep")  // doesn't log
			cout << static_cast<char>(7);
		else if (strQ == "clearscreen")
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		else if (strQ == "display")
		{
			getline(inf, strQ);
			cout << strQ << endl;
		}
		else if (strQ == "exit")
		{
			outf << "Hit exit. (This is probably harmless.)" << endl;
			outf.close();
			break;
		}
		else if (strQ == "log")
		{
			getline(inf, strQ);
			outf << strQ << endl;
			outf.flush();
		}
		else if (strQ == "wait")
		{
			cin.clear();
			cin.get();
		}
		else
			outf << "Unrecognized command or blank line: \"" << strQ << "\"" << endl;
	}
}