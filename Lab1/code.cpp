#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Dont forget about moduls
int create_new_file();
int read_file();

int only_w_numbers_file();
int main(){
  // create_new_file();
  read_file();
  only_w_numbers_file();

  return 0;
}

int create_new_file(){

  // fstream File; 
  // FILE *file; 

  ofstream File; //write mode
  string name = "file1.txt";
  string data; 
  File.open(name);

  // File.open(name, ios::out); //write mode
  
  int end_line = 1, finish = 0;
  if (File){
  cout << "Enter the lines you want to write to a file." << endl;
  cout << "*Click ENTER to start writing a new line " << endl; 
  cout << "*If you want to finish - enter ESC at the end of the last line you want to add" << endl << endl; 
    
    do {
      cout << "Enter line: "; // pronpt the user

      getline(cin, data); // getting the line
      end_line = data.length(); 

      if (data[end_line-1]== 27) // if the lsat char entered in esc
      { 
        data.pop_back(); // removing the esc char
        finish = 1; // noting that we want to finish writing
      }
        
      File << data << endl; //writing the line into a file
    
    } while (!finish); 
    
    File.close();
    return 1; 
  }
  else {
    cout << "An error occured when opening the file"<< name <<endl; 
    return 0;
  }  
}

int read_file(){
  ifstream File;  // FILE *file; 

  string name = "file1.txt";    // could be a parameter
  File.open(name);
  // File.open(name, ios::in); //read mode
  
  if (File){
    
    string line;
    cout << endl;
    while(getline(File, line))
    {
      cout << line << endl;
    }

    File.close();
    return 1; 
  }
  else {
    cout << "An error occured when opening the file"<< name <<endl; 
    return 0;
  }
}

int only_w_numbers_file(){
  ifstream File_old; //read mode
  ofstream File_new; //write mode

  string name_old = "file1.txt";
  string name_new = "str_with_nums.txt";

  string data; 

  File_old.open(name_old);
  File_new.open(name_new);


  if (File_old && File_new){
    
    string line;
    
    while(getline(File_old, line))
    {   
      if (string :: npos != line.find_first_of("0123456789"))
      {
        cout << line << endl;
        File_new << line << endl;
      }
    }

    File_old.close();
    File_new.close();
    return 1; 
  }
  else {
    cout << "An error occured when opening the files"<< name_old << name_new <<endl; 
    return 0;
  }

  // File.open(name, ios::out); //write mode
}