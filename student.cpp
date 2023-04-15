#include "Headers/student.h"//linking headers
using namespace std;

//Default Constructor
student::student(const int in_id, const string in_name, const string in_phone_no, const string in_phone_no2,const string in_email_id)
{
    id_ = in_id;
    name_ = in_name;
    phone_no_ = in_phone_no;
    phone_no2_ = in_phone_no2;
    email_id_ = in_email_id;
}

int student::get_id() const
{
    return id_;
}

string student::get_name() const
{
    return name_;
}

string student::get_phone_no() const
{
    return phone_no_;
}

string student::get_phone_no2() const
{
    return phone_no2_;
}

string student::get_email_id() const
{
    return email_id_;
}

void student::set_id(const int in_id)
{
    id_ = in_id;
}

void student::set_name(const string in_name)
{
    name_ = in_name;
}

void student::set_phone_no(const string in_phone_no)
{
    phone_no_ = in_phone_no;
}

void student::set_phone_no2(const string in_phone_no2)
{
    phone_no2_ = in_phone_no2;
}

void student::set_email_id(const string in_email_id)
{
    email_id_ = in_email_id;
}


