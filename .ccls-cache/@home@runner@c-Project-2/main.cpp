#include<iostream> //to perform input output operation
#include <string> //to perform string operations
#include <regex> //to validate string
#include<algorithm> //to define collection of functions
#include<fstream> //to perform file operations

//including header files
#include "Headers/student.h"
#include "Headers/validation.h"

using namespace std;

//creating vector
vector<student> students;
validaton* validate; 

//login details
bool login()
{
  //initializing the username and password
	std::string username = "";
	std::string password = "";
	cout << "Enter your username: " << endl;
  //Reading the input from user
	cin >> username;
	cout << "Enter your password: " << endl;
  //Reading the input from user
	cin >> password;
  //validating username and password
	if(username == "Admin" && password == "welcome")
	{
		return true;
	}

	return false;
}


//check the student id availability
bool is_id_available(int student_id) {
	for (auto& iterator : students)
	{
		if (iterator.get_id() == student_id) {
			return true;
		}
		
	}
	return false;
}

//create new student record 

void create_student()
{
  //file operations 
  fstream file;
  //timestamp operations
  char* ctime( const std::time_t* time ); 
  std::time_t result = std::time(nullptr); 
  //declaring student details
	int student_id,phone_choice;
	std::string student_name = "";
	std::string student_phone_no = "";
	std::string student_phone_no2 = "";
	std::string student_email_id = "";
	std::cout << "Enter Student Id : \n";
	while (true) {
    //Getting student_id as input from the user
		std::cin >> student_id;
    //validating or checking student_id
		if (is_id_available(student_id)) {
			cout << "Please give the correct No";
		}
		else {
			break;
		}

	}
  std::cout << "\nEnter Student Name :\n";
  //Getting student name as input from the user
	cin.ignore();
  getline(cin,student_name);

  std::cout << "\nEnter Student Phone Number : \n";
  while (true)
	{
    //Getting student_phone_number as input from the user
		std::cin >> student_phone_no;
    //validating phone number
		if (validate->is_valid_phone(student_phone_no))
		{
			break;
		}
		std::cout << "\nEnter correct Phone Number: \n";
	}
  //getting input from user if another phone number need to be added
  cout << "Do you have another phone number \n 1.Yes 2.No\n";
	cin >> phone_choice;
	if (phone_choice == 1) {
		while (true)
		{
      //Reading 2nd phone number as input from user
			std::cin >> student_phone_no2;
      //validating 2nd phone number
			if (validate->is_valid_phone(student_phone_no2))
			{
				break;
			}
			std::cout << "\nEnter correct Phone Number: \n";
		}
	}
  //if phone number-2 not availabe
	if (phone_choice == 2) {
		student_phone_no2 = "-";
	}
std::cout << "\nEnter Student mail id : \n";

	while (true)
	{
    //Getting student_email_id as input from user
		cin >> student_email_id;
    //validating Email_id
		if(validate->is_valid_email(student_email_id))
		{
			students.push_back(student(student_id, student_name, student_phone_no, student_phone_no2, student_email_id));
			break;
		}
		cout << "\nEnter correct EmailId: \n";
	}
  cout << "Record added sucessfully";
  //creating a file to store student records
  /*file.open("studentRecord.txt", ios::app | ios::out);
  file << " "<< "Registration ID :" <<student_id<< "\n"<<" Name : " << student_name <<"\n"<< " MobileNumber :" << student_phone_no  <<"\n"<< " Mail ID: "  <<student_email_id  <<  "\n";
  //closing files
  file.close();*/

  //creating log text
  file.open("log.txt", ios::app | ios::out);
  //writing timestamp
  file << std::ctime(&result);
  file<<"Record added successfully\n";
  //closing file
  file.close();

}


//Update student record
void update_student()
{
  //declaring student records
	int student_id,update_choice, updt_phone_choice;
	std::string student_name = "";
	std::string student_phone_no = "";
	std::string student_email_id = ""; 
	std::string student_phone_no2 = "";
	
  //getting input from user
	cout << "Enter student id: ";
	cin >> student_id;
  //declaring files
  fstream file;
  char* ctime( const std::time_t* time );
  std::time_t result = std::time(nullptr);
  //updating student details
	for (auto &iterator : students)
	{
		if (iterator.get_id() == student_id) {
			cout << "1.Update Name\n";
			cout << "2.Update Phone\n";
			cout << "3.Update Email\n";
			cout << "4.Exit\n";
			cin >> update_choice;
      //to update student name
			if (update_choice == 1) 
			{
				cout << "Enter new name: ";
        //getting input from user
				cin.ignore();
        getline(cin,student_name);
				iterator.set_name(student_name);
				break;
			}

			else if (update_choice == 2)
			{
				cout << "1. Update First Phone Number\n";
				cout << "2. Update Second Phone Number\n";
        //getting input from user
				cin >> updt_phone_choice;
        //to update 1st phone number
				if (updt_phone_choice==1){
					while (true) {
						cout << "Enter New Phone Number ";
            //getting input from user
						cin >> student_phone_no;
            //validating
						if (validate->is_valid_phone(student_phone_no)) {
							iterator.set_phone_no(student_phone_no);
							break;
						}
						std::cout << "\nEnter correct Phone Number: ";

					}
				}
        //to update 2nd phone number
				else if (updt_phone_choice == 2) {
					while (true) {
						cout << "Enter New Phone Number ";
            //getting input from user
						cin >> student_phone_no2;
						if (validate->is_valid_phone2(student_phone_no2)) {
							iterator.set_phone_no2(student_phone_no2);
							break;
						}
						std::cout << "\nEnter correct Phone Number: ";
					}
				}
				
			}
      //To update email_id
			else if (update_choice == 3) {
				while (true) {
					cout << "Enter New Email id ";
          //getting input from user
					cin >> student_email_id;
					if (validate->is_valid_email(student_email_id)) {
						iterator.set_email_id(student_email_id);
						break;
					}
					std::cout << "\nEnter correct Mail Id: ";
				}
			}
			else if (update_choice == 4) {
				break;
			}
			else {
				cout << "\nEnter Correct Choice\n";
			}
		}
	}
  //opening log file
  file.open("log.txt", ios::app | ios::out);
  //writing timestamp
  file << std::ctime(&result);
  file<<"Record updated successfully\n";
  //closing file
  file.close(); 

  //student txt
  //opening student record file
  /*file.open("studentRecord.txt", ios::app | ios::out);
  file << " "<< "Registration ID :" <<student_id<< "\n"<<" Name : " << student_name <<"\n"<< " MobileNumber : " << student_phone_no  <<"\n"<< " Mail ID: "  <<student_email_id  <<  "\n";
  //closing file
  file.close();*/

}
/*void list_students()
{
  fstream file;
  char* ctime( const time_t* time );
  time_t result = time(nullptr);
	for(auto &iterator : students)
	{

		std::cout << iterator.get_id() << ","<<iterator.get_name() << "," << iterator.get_phone_no() << ","<<iterator.get_phone_no2() << "," << iterator.get_email_id()<<"\n";

	}
  file.open("studentRecord.txt", ios::in);
  file.open("log.txt", ios::app | ios::out);
  file << std::ctime(&result);
  file<<"Record dispalyed successfully\n";
  //closing file
  file.close(); 
}
*/

//Print the records 
void list_students()
{
  int view_choice;
  //initializing file
  fstream file;
  char* ctime( const std::time_t* time );
  std::time_t result = std::time(nullptr);
  std::cout<<"1. View Records from Memory\n";
  std::cout<<"2. View Records from file\n";
  std::cin>>view_choice;

  if(view_choice==1){
    for(auto &iterator : students)
	{
    
		std::cout << iterator.get_id() << ","<<iterator.get_name() << "," << iterator.get_phone_no() << ","<<iterator.get_phone_no2() << "," << iterator.get_email_id()<<"\n";

	}

  }
  if(view_choice==2){
    std::ifstream myfile;
    std::string myline;
    myfile.open("studentRecord.txt");
    if ( myfile.is_open() ) {
      while ( myfile ) { // equivalent to myfile.good()
        std::getline (myfile, myline);
        std::cout << myline << '\n';
        }
      }
	
  }
  
   //file.open("studentRecord.txt", ios::in);
  file.open("log.txt", ios::app | ios::out);
  file << std::ctime(&result);
  file<<"Record dispalyed successfully\n";
  //closing file
  file.close(); 
}

//delete the records
void delete_students() {
  //declarations
	int student_id;
	int removeindex;
  fstream file;
  char* ctime( const std::time_t* time );
  std::time_t result = std::time(nullptr);
	cout << "Enter student id: ";
	cin >> student_id;
	for (int i = 0; i < students.size();i++)
	{
		if (students[i].get_id() == student_id) {
			removeindex = i;
			students.erase(students.begin() + i);
			cout << "Deleted successfully";
			break;
		}
	}
  file.open("log.txt", ios::app | ios::out);
  file << std::ctime(&result);
  file<<"Record deleted successfully\n";
  file.close(); 
}

void addtotext(){
  fstream file;
  char* ctime( const std::time_t* time );
  std::time_t result = std::time(nullptr);
	for(auto &iterator : students)
	{
    
	file.open("studentRecord.txt", ios::app | ios::out);
  file << " "<< "Registration ID :" <<iterator.get_id()<< "\n"<<" Name : " << iterator.get_name() <<"\n"<< " First MobileNumber : " << iterator.get_phone_no() <<"\n"<<" Second MobileNumber : " << iterator.get_phone_no2() <<"\n"<< " Mail ID: "  <<iterator.get_email_id()  <<  "\n";
  //closing file
  file.close();

	}

}

// Driver code
int main()
{
	bool is_logged =false;
	bool is_running = true;
	while (is_running)
	{
		if(!is_logged)
		{
			is_logged = login();	
		}
		if(is_logged)
		{
			cout << "\n\t\tWelcome to Student Record Management System\n\n";
			cout << "1.NEW STUDENT\n";
			cout << "2.UPDATE STUDENT\n";
			cout << "3.DELETE STUDENT\n";
			cout << "4.VIEW STUDENT\n";
			cout << "5.EXIT\n";

			int choice;

			// Enter Choice
      cout <<"Enter your choice\n";
      //getting input from user
			cin >> choice;

			switch (choice)
			{
				case 1:
        //Function call
					create_student();
					break;
				case 2:
					update_student();
					break;
				case 3:
					delete_students();
					break;
				case 4:
					list_students();
					break;
				case 5:
					is_running = false;
          addtotext();
          cout << "Thank You\n";
					break;
				default:
					cout << "\nEnter Correct Choice\n";
			}
		}
	}
}