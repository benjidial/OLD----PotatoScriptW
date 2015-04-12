/*
PotatoScriptW Alpha 0.2.1 Reader
Copyright (C) 2015  Benji Dial

This program is free software; you can redistribute it and/or modify
if under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <iostream>  // Console IO
#include <fstream>   // File IO
#include <string>    // Makes strings easier.
#include <sstream>   // Makes parsing strings easier.
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
			cout << "\nFinished all interpereting jobs!" << endl;
			cout << "Press enter to close this window." << endl;
		}
		else
		{
			cout << "\nFinished interpeteting job " << nArg << " of " << nFiles << "." << endl;
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
	string strQ; // Various trivial things.
	string strW; // Various trivial things.
	string strE; // Various trivial things.
	string str0; // _str0 in PSW
	string str1; // _str1 in PSW
	string str2; // _str2 in PSW
	string str3; // _str3 in PSW
	string str4; // _str4 in PSW
	string str5; // _str5 in PSW
	string str6; // _str6 in PSW
	string str7; // _str7 in PSW
	string str8; // _str8 in PSW
	string str9; // _str9 in PSW
	stringstream pswio; // IO stream for PSW
	pswio.str();
	ifstream inf(file); // Input file
	if (!inf)
		throw "Could not open file.";
	ofstream outf("logfile.txt", ios::app); // Output file
	while (inf)
	{
		pswio.str();
		pswio.clear();
		strQ = "";
		cin.clear();
		inf >> strQ;
		if (strQ == "alert") // logs
		{
			cout << static_cast<char>(7); // bell
			outf << "Alert triggered." << endl;
			outf.flush();
		}
		else if (strQ == "beep")  // doesn't log
			cout << static_cast<char>(7); // bell
		else if (strQ == "clearscreen")
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		else if (strQ == "comment")
			break;
		else if (strQ == "display")
		{
			inf.ignore();
			getline(inf, strQ);
			pswio.str();
			pswio.str(strQ);
			bool bPrevDef = false;
			cout << " ";  // for security
			bool bDef;
			while (pswio)
			{
				pswio >> strQ;
				pswio.ignore();
				bDef = false;
				if (strQ == "_str1")
					cout << str1;	
				else if (strQ == "_str2")
					cout << str2;
				else if (strQ == "_str3")
					cout << str3;
				else if (strQ == "_str4")
					cout << str4;
				else if (strQ == "_str5")
					cout << str5;
				else if (strQ == "_str6")
					cout << str6;					
				else if (strQ == "_str7")
					cout << str7;					
				else if (strQ == "_str8")
					cout << str8;					
				else if (strQ == "_str9")
					cout << str9;
				else if (strQ == "_str0")
					cout << str0;
				else if (strQ == "_space")
					cout << " ";
				else if (strQ == "_underscore")
					cout << "_";
				else
				{
					if (bPrevDef)
						cout << " ";
					cout << strQ;
					bDef = true;
				}
				bPrevDef = bDef;
			}
			pswio.str();
			cout << endl;
		}
		else if (strQ == "end")
		{
			inf.ignore();
			getline(inf, strQ);
			if (strQ != "if")
			    outf << "\"" << strQ << "\" has not been started." << endl;
		}
		else if (strQ == "exit")
		{
			outf << "Hit exit. (This is probably harmless.)" << endl;
			outf.close();
			break;
		}
		else if (strQ == "if")
		{
			inf >> strQ;
			if (strQ == "_str1")
				strW = str1;
			else if (strQ == "_str2")
				strW = str2;
			else if (strQ == "_str3")
				strW = str3;
			else if (strQ == "_str4")
				strW = str4;
			else if (strQ == "_str5")
				strW = str5;
			else if (strQ == "_str6")
				strW = str6;
			else if (strQ == "_str7")
				strW = str7;
			else if (strQ == "_str8")
				strW = str8;
			else if (strQ == "_str9")
				strW = str9;
			else if (strQ == "_str0")
				strW = str0;
			else outf << "Unrecognized variable \"" << strQ << "\"." << endl;
			inf.ignore();
			getline(inf, strQ);
			pswio.str();
			pswio.str(strQ);
			bool bPrevDef = false;
			bool bDef;
			strE = "";
			while (pswio)
			{
				pswio >> strQ;
				pswio.ignore();
				bDef = false;
				if (strQ == "_str1")
					strE += str1;
				else if (strQ == "_str2")
					strE += str2;
				else if (strQ == "_str3")
					strE += str3;
				else if (strQ == "_str4")
					strE += str4;
				else if (strQ == "_str5")
					strE += str5;
				else if (strQ == "_str6")
					strE += str6;
				else if (strQ == "_str7")
					strE += str7;
				else if (strQ == "_str8")
					strE += str8;
				else if (strQ == "_str9")
					strE += str9;
				else if (strQ == "_str0")
					strE += str0;
				else if (strQ == "_space")
					strE += " ";
				else if (strQ == "_underscore")
					strE += "_";
				else
				{
					if (bPrevDef)
						strE += " ";
					strE += strQ;
					bDef = true;
				}
				bPrevDef = bDef;
			}
			pswio.str();
			if (strW != strE)
				while (true)
				{
					getline(inf, strQ);
					if (strQ == "end if")
						break;
				}
		}
		else if (strQ == "input")
		{
			inf.ignore();
			inf >> strW;
			inf.ignore();
			getline(inf, strQ);
			pswio.str();
			pswio.str(strQ);
			bool bPrevDef = false;
			cout << " ";  // for security
			bool bDef;
			while (pswio)
			{
				pswio >> strQ;
				pswio.ignore();
				bDef = false;
				if (strQ == "_str1")
					cout << str1;					
				else if (strQ == "_str2")
					cout << str2;					
				else if (strQ == "_str3")
					cout << str3;					
				else if (strQ == "_str4")
					cout << str4;					
				else if (strQ == "_str5")
					cout << str5;					
				else if (strQ == "_str6")
					cout << str6;					
				else if (strQ == "_str7")
					cout << str7;					
				else if (strQ == "_str8")
					cout << str8;					
				else if (strQ == "_str9")
					cout << str9;
				else if (strQ == "_str0")
					cout << str0;					
				else if (strQ == "_space")
					cout << " ";					
				else if (strQ == "_underscore")
					cout << "_";
				else
				{
					if (bPrevDef)
						cout << " ";
					cout << strQ;
					bDef = true;
				}
				bPrevDef = bDef;
			}
			pswio.str();
			cout << endl;
			cout << " ";
			getline(cin, strQ);
			if (strW == "_str1")
				str1 = strQ;				
			else if (strW == "_str2")
				str2 = strQ;				
			else if (strW == "_str3")
				str3 = strQ;				
			else if (strW == "_str4")
				str4 = strQ;				
			else if (strW == "_str5")
				str5 = strQ;				
			else if (strW == "_str6")
				str6 = strQ;				
			else if (strW == "_str7")
				str7 = strQ;				
			else if (strW == "_str8")
				str8 = strQ;				
			else if (strW == "_str9")
				str9 = strQ;				
			else if (strW == "_str0")
				str0 = strQ;				
			else
				outf << "Unrecognized variable \"" << strW << "\"." << endl;
			pswio.str();
		}
		else if (strQ == "log")
		{
			inf.ignore();
			getline(inf, strQ);
			pswio.str();
			pswio.str(strQ);
			bool bPrevDef = false;
			bool bFirst = true;
			bool bDef;
			while (pswio)
			{
				pswio >> strQ;
				pswio.ignore();
				if (bFirst)
					outf << " ";
				bFirst = false;
				bDef = false;
				if (strQ == "_str1")
					outf << str1;					
				else if (strQ == "_str2")
					outf << str2;					
				else if (strQ == "_str3")
					outf << str3;					
				else if (strQ == "_str4")
					outf << str4;					
				else if (strQ == "_str5")
					outf << str5;					
				else if (strQ == "_str6")
					outf << str6;					
				else if (strQ == "_str7")
					outf << str7;					
				else if (strQ == "_str8")
					outf << str8;					
				else if (strQ == "_str9")
					outf << str9;					
				else if (strQ == "_str0")
					outf << str0;					
				else if (strQ == "_space")
					outf << " ";					
				else if (strQ == "_underscore")
					outf << "_";					
				else
				{
					if (bPrevDef)
						outf << " ";
					outf << strQ;
					bDef = true;
				}
				bPrevDef = bDef;
			}
			pswio.str();
			outf << endl;
			outf.flush();
		}
		else if (strQ == "setvar")
		{
			strE = "";
			inf.ignore();
			inf >> strW;
			inf.ignore();
			getline(inf, strQ);
			pswio.str();
			pswio.str(strQ);
			bool bPrevDef = false;
			bool bDef;
			while (pswio)
			{
				pswio >> strQ;
				pswio.ignore();
				bDef = false;
				if (strQ == "_str1")
					strE += str1;					
				else if (strQ == "_str2")
					strE += str2;					
				else if (strQ == "_str3")
					strE += str3;					
				else if (strQ == "_str4")
					strE += str4;					
				else if (strQ == "_str5")
					strE += str5;					
				else if (strQ == "_str6")
					strE += str6;					
				else if (strQ == "_str7")
					strE += str7;					
				else if (strQ == "_str8")
					strE += str8;					
				else if (strQ == "_str9")
					strE += str9;					
				else if (strQ == "_str0")
					strE += str0;					
				else if (strQ == "_space")
					strE += " ";					
				else if (strQ == "_underscore")
					strE += "_";					
				else
				{
					if (bPrevDef)
						strE += " ";
					strE += strQ;
					bDef = true;
				}
				bPrevDef = bDef;
			}
			pswio.str();
			strQ = strE;
			if (strW == "_str1")
				str1 = strQ;				
			else if (strW == "_str2")
				str2 = strQ;				
			else if (strW == "_str3")
				str3 = strQ;				
			else if (strW == "_str4")
				str4 = strQ;				
			else if (strW == "_str5")
				str5 = strQ;				
			else if (strW == "_str6")
				str6 = strQ;				
			else if (strW == "_str7")
				str7 = strQ;				
			else if (strW == "_str8")
				str8 = strQ;				
			else if (strW == "_str9")
				str9 = strQ;				
			else if (strW == "_str0")
				str0 = strQ;				
			else
				outf << "Unrecognized variable \"" << strW << "\"." << endl;
		}
		else if (strQ == "start")
		{
			inf >> strQ;
			if (strQ == "comment")
			{
				getline(inf, strQ);
				if (strQ == " block")
					while (strQ != "end comment block")
						getline(inf, strQ);
				else
					outf << "Start does not know \"comment" << strQ << "\"." << endl;
			}
			else
			{
				inf.ignore();
				getline(inf, strQ);
				outf << "Start does not know \"" << strQ << "\"." << endl;
			}
		}
		else if (strQ == "wait")
		{
			cin.clear();
			cin.get();
		}
		else if (strQ == "")
			continue;
		else
			outf << "Unrecognized command: \"" << strQ << "\"" << endl;
	}
}