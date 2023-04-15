#pragma once
#include <string>//to perform string operations

//creating student class
class student
{
//declaring student details as private
private:
    int id_= 0;
    std::string name_ = "";
    std::string phone_no_ = "";
    std::string phone_no2_ = "";
    std::string email_id_ = "";

public:

    //Default Constructor
    student(const int in_id, const std::string in_name, const std::string in_phone_no, const std::string in_phone_no2, const std::string in_email_id);
    
    //Getters
    int get_id() const;
    std::string get_name() const;
    std::string get_phone_no() const;
    std::string get_phone_no2() const;
    std::string get_email_id() const;

    //Setters
    void set_id(const int in_id);
    void set_name(const std::string in_name);
    void set_phone_no(const std::string in_phone_no);
    void set_phone_no2(const std::string in_phone_no);
    void set_email_id(const std::string in_email_id);
    
};
