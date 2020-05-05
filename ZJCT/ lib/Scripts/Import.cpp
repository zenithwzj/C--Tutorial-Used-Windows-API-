#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<windows.h>
#define JCLibmain main
using namespace std;
void wf(string filepath,string filecontent)//Write File
{
	fstream  afile;
	afile.open(filepath.c_str(),/*ios::app|*/ios::out|ios::in);
	afile<<filecontent;
	afile.close();
}
void WFCOMMAND(string filepath,const char* content)
{
	fstream  afile;
	afile.open(filepath.c_str(),/*ios::app|*/ios::out|ios::in);
	system(content);
	afile.close();
}
string gfn(string filepath)//Get File Name
{
	string::size_type iPos = filepath.find_last_of('\\') + 1;
	string filename = filepath.substr(iPos,filepath.length() - iPos);
	return filename;
}
string gfp(string filepath)//Get File Prefix
{
	string name = filepath.substr(0,filepath.rfind("."));
	return name;
}
string gfs(string filepath)//Get File Suffix
{
	string suffix_str = filepath.substr(filepath.find_last_of('.') + 1);
	return suffix_str;
}
string rfis(char* filename)//Read File Into String
{
	ifstream ifile(filename);
	ostringstream buf;
	char ch;
	while(buf&&ifile.get(ch))
		buf.put(ch);
	return buf.str();
}
int JCLibmain(int argc,char** argv)
{
	if(argc==2)
	{
		if(gfs((string)(char*)argv[1])!="JCLib")
		{
			MessageBox(GetConsoleWindow(),"Warning:File Suffix Error","Warning",MB_OK|MB_ICONWARNING);
		}
		string str=rfis((char*)argv[1]);
		string name=gfp(gfn((string)(char*)argv[1]));
		WFCOMMAND("RES.tmp",((string)"del ..\\JCLib\\"+name+(string)".JCLib > result.tmp").c_str());
//		system((const char *)((string)"del ..\\JCLib\\"+name+(string)".JCLib > result.tmp").c_str());
		system((const char *)((string)"echo off > ..\\JCLib\\"+name+(string)".JCLib").c_str());
		wf("..\\JCLib\\"+name+(string)".JCLib",str);
		printf("Write file successfully\n");
	}
	printf("Press any key to continue");
	getch();
	return 532;
}
