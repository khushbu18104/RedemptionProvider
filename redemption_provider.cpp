#include<bits/stdc++.h>
#include<conio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
void set_password();
void get_file();
void freplace();
string password="1234";
string tologout;
string file_name;
int main()
{
	 int ch;

	while(1)
	{
		cout<<"\n[1]Programmer\n";
		cout<<"[2]User\n";
		cout<<"[3]exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		fstream fp,fu;
		fp.open("programmer_info.txt");
	//	fu.open("user_info.txt");
		string u_name,pass,str,str1;int flag,invalid_co=0;
		switch(ch)
		{
			case 1:
				    cout<<"\nenter username: ";
				    cin>>u_name;
				    while(invalid_co<3)
				    {flag=0;
				    cout<<"\nenter password: ";
				    cin>>pass;
				   ifstream fp;
		           fp.open("programmer_info.txt");
					 string str;
				     while(fp>>str)
				     {
				     	//fp>>str;
					  string a;
					  a=str;fp>>str;
					  cout<<a;//<<" "<<str<<"\n";
				     	if(a!=u_name || str!=pass)
				     	{ 
				     			flag=1;break;
							 }
					 }
						if(flag==1)
						{
							if(invalid_co<2)
							cout<<"Incorrect password.......Enter again!!!!";
							invalid_co++;
						}
						else
						{
							invalid_co=4;
							cout<<"\nYou are logged in!!!!";
							int ch1;
							 cout<<"\n[1]Create a new file\n";
				                       cout<<"[2]Set password\n";
				                        cout<<"[3]Exit\n";
				                        cout<<"Enter your choice:";
				                        cin>>ch1;
				                       switch(ch1)
				                       {
				       	              case 1:
				       	 	                 break;
				       	               case 2:
				       	 	                set_password();        
							                 break;
						            case 3:
						                   //return 0;
								          break;	
						}
						break;
					 }
					 if(invalid_co==3)
					 {
					 	cout<<"\nAccess Denied........You have entered incorrect password 3 times\n";
					 }
				
					 fp.close();
				}
				    break;
			case 2:
			       flag=0;invalid_co=0;
				   cout<<"\nenter username: ";
				    cin>>u_name;
				    while(invalid_co<3)
				    {
				    	flag=0;
				    cout<<"\nenter password: ";
				    cin>>pass;
				   //ifstream fp;
		           fu.open("user_info.txt");
					 //string str1;
				     while(fu>>str1)
				     {string a;
				        a=str1;fu>>str1;
				     	if(a!=u_name || str1!=pass)
				     	{ 
				     			flag=1;
							 }
					 }
						if(flag==1)
						{
							if(invalid_co<2)
							cout<<"Access Denied!!!!.........Enter again";
							invalid_co++;
						}
						else
						{
							invalid_co=4;
							cout<<"\nYou are logged in!!!!\n";
			            get_file();
			            freplace();
			            break;
			           }
			       }
					break;		
			case 3:
			       return 0;					    
		}
	}
}
void set_password()
{
		 
  fstream myfile,copyfile;
  char ch;
  int flag=0;
  string compare,filename;
  string mroot;
  cout<<"enter path and file name";
  cin>>mroot>>filename;
  string root="D:\\copyfiles\\";
  string cpyfile;
  cpyfile=root+filename;
 
  myfile.open(filename.c_str(), ios::out | ios::app | ios::in);
  copyfile.open(cpyfile.c_str(), ios::out |ios::app | ios::in);
  if (myfile.is_open()&&copyfile.is_open())
  {
    while(!myfile.eof())
    {
    	myfile.get(ch);
    	copyfile<<ch;
	}
    myfile.close();
    copyfile.close();
  }
  


  //searching
	string word1,word2 ;
     string path;
      path=mroot+filename;
     cout << "File '" << path << "' opened.\n" ;
	cout << "Write the starting word and ending word of the part you're searching for\n" ;
	cin >> word1 >>word2;
	
	fstream next;
	next.open(path.c_str());
	string nextstring;
	while(!next.eof())
	{
		next>>nextstring;
		if(nextstring==word2)
		{
			next>>nextstring;
			break;
		}
	}
	next.close();
	
	fstream part;
        string exe=".txt";
         string partname;
         partname=root+word1+exe;
	
	

   copyfile.open(cpyfile.c_str(), ios::out |ios::app | ios::in);
		string str1;
	    //str1=word1;
	while(str1!=word1)
	
	{
		copyfile>>str1;
		
	}
      string line,temp;
      
		while(str1!=word2)
    {
	 
		ostringstream text;
    ifstream in_file( filename.c_str());
   
	if( in_file.is_open() )
	{
		 part.open(partname.c_str(),ios::in|ios::app|ios::out);
	   part<<str1<<" ";
	   part.close(); 
	copyfile>>str1;
     string str_search;
    text << in_file.rdbuf();
    string str = text.str();
    str_search=str1;
    
    string str_replace ="";
    size_t pos = str.find(str_search);
    str.replace(pos, string(str_search).length(), str_replace);
    in_file.close();

    ofstream out_file( filename.c_str());
    out_file << str;
   
		out_file.close();
	
		 
    }
	
	
	}

	
copyfile.close();	
	
	
     
   /*     else
	{
	cerr << "Error! File not found!\n" ;
	}*/
        
	
		//creating file of the searched part
		
	
         part.open(partname.c_str(),ios::out|ios::in|ios::app);
         if(part.is_open())
         {
         part<<nextstring;
          }
          else
          {
          	cout<<"file can not be open";
		  }
         part.close();
	
	


	
	
	string pass;
	/*cout<<"enter the word you want to hide:";
	cin>>word;*/
	cout<<"enter the password you want to set:";
	cin>>pass;
	//search(word);
	fstream f;
	f.open("D:\\copyfiles\\password.txt",ios::app|ios::in|ios::out);
	//cout<<"enter the file in which you have to set password:";
	//cin>>filename;
	f<<pass<<" ";
	f<<word1<<" ";
	f<<filename<<"\n";
    f.close();
    
    //encripat files 
    //password.txt
     fstream infile,outfile;
infile.open ("D:\\copyfiles\\password.txt");
outfile.open ("D:\\copyfiles\\password.txt");

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}

	infile.close();	
	outfile.close();
   
	//copyfiles.txt
     
infile.open (cpyfile.c_str());
outfile.open (cpyfile.c_str());

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}

	infile.close();	
	outfile.close();
	
	
	//parts files
	
infile.open (cpyfile.c_str());
outfile.open (cpyfile.c_str());

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}


	infile.close();	
	outfile.close();
    

}

void get_file()
{
	//decripts file
	//password file
	 fstream infile2,outfile2;
infile2.open ("D:\\copyfiles\\password.txt");
	outfile2.open ("D:\\copyfiles\\password.txt");
    while (!infile2.eof())
	{
	   
		for (int i=0 ;i<4 ; i++)
		{
				char name;
			infile2.get(name);
			if(!infile2.eof())
	   {
			name = name + password[0];	
			name = name - password[i];
			outfile2<<name;	
			}
	}
	}
	infile2.close();
	outfile2.close();
	//
	//part file


	//s
	
	ifstream fin;
fin.open("D:\\copyfiles\\password.txt");
string c,password1,mfilename;
int co=0;
cout<<"enter the name of the file you want to access:\n";
cin>>mfilename;
tologout=mfilename;
char ch;
cout<<"\nenter password:";
ch= _getch();
 while(ch != 13)
 {
   password1.push_back(ch);
   cout<< '*';
   ch= _getch();
}
//cin>>password;

while(fin>>c)
{   
 
	if(c==password1)
	{
		
		fin>>c;
		co=1;
		break;
    }
}

if(co==0)
 {cout<<"invalid password";}

file_name=c;

fstream tfile;
	ifstream mfile;
    string root="D:\\copyfiles\\";
    string find;
    find=file_name;
    string exe=".txt";
    string tfilename;
    tfilename=root+find+exe;
    
    //decript copyfile
    //copyfile

	infile2.open (tfilename.c_str());
    while (!infile2.eof())
	{
	   
		for (int i=0 ;i<4 ; i++)
		{
				char name;
			infile2.get(name);
			if(!infile2.eof())
	   {
			name = name + password[0];	
			name = name - password[i];
			outfile2 << name;	
			}
	}
	}
	infile2.close();
    outfile2.close();
    //
	tfile.open(tfilename.c_str(), ios::in | ios::out);
	string temp1;
		while(tfile>>temp1)
		{
			break;
		}
		
		tfile.close();
		
		string line;
		tfile.open(tfilename.c_str(), ios::in | ios::out);
			{
				getline(tfile,line);
				
				}	
			tfile.close();
	
	fstream tempfile,mainfile;

	tempfile.open("D:\\copyfiles\\temp.txt",ios::app|ios::in|ios::out);
	mainfile.open(mfilename.c_str());
	while(!mainfile.eof())
	{
		mainfile.get(ch);
		tempfile<<ch;
	}
	tempfile.close();
	mainfile.close();
		
		ostringstream text;
    ifstream in_file( mfilename.c_str());
    if( in_file.is_open() )
	{
		string str_search;
    text << in_file.rdbuf();
    string str = text.str();
    str_search=temp1;
    string str_replace;
    str_replace=line;
    size_t pos = str.find(str_search);
    str.replace(pos, string(str_search).length(), str_replace);
    in_file.close();

    ofstream out_file( mfilename.c_str());
    out_file << str;
		in_file.close();
	}

/*fstream tfile,mfile;
    string root="D:\\copyfiles\\";
    string exe=".txt";
    string tfilename;
    string temp;
    tfilename=root+file_name+exe;
	tfile.open(tfilename.c_str(), ios::in | ios::out|ios::app);
	mfile.open(mfilename.c_str(),ios::in|ios::out|ios::app);
	if(tfile.is_open()&&mfile.is_open())
	{
	
		while(!tfile.eof())
		{
		tfile>>temp;
		mfile <<temp ;
	}
	}
	else
	{
		cout<<"unable to open the file";
	}*/
	//encripat files 
    //password.txt
     fstream infile,outfile;
infile.open ("D:\\copyfiles\\password.txt");
outfile.open ("D:\\copyfiles\\password.txt");

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}

	infile.close();	
	outfile.close();
    
	//copyfiles.txt
    
infile.open (tfilename.c_str());
outfile.open (tfilename.c_str());

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}

	infile.close();	
	outfile.close();
	
	
	//parts files
	 
infile.open ("D:\\copyfiles\\password.txt");
outfile.open ("D:\\copyfiles\\password.txt");

	while (!infile.eof())
	{
		
		for (int i=0 ;i<4 ; i++)
		{
			char name;
			infile.get(name);
			if(!infile.eof())
	   {
			name = name + password[i];
			name = name - password[0];
			outfile << name;
		}}
	
	}


	infile.close();	
	outfile.close();

}
void freplace()
{
	int ch;
	cout<<"are you want to exit press 0";
	cin>>ch;
	if(ch==0)
	{
		string mfilename;
		mfilename=tologout;
		cout<<mfilename;
		char ch;
		fstream mfile,tfile;
		remove(mfilename.c_str());
		mfile.open(mfilename.c_str(),ios::app|ios::in|ios::out);
		tfile.open("D:\\copyfiles\\temp.txt",ios::in|ios::out);
		while(!tfile.eof())
		{
			tfile.get(ch);
			mfile<<ch;
		}
		mfile.close();
		tfile.close();
		remove("D:\\copyfiles\\temp.txt");
		
	}
	
}
