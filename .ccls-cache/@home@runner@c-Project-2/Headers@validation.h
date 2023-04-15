#pragma once
#include <string>//to perform string operations

//creating vaidation class
class validaton
{
private:
    //validations
    bool is_char(const char character);
    bool is_digit(const char character);
    bool validate_email(const std::string email_id);
    bool validate_phone(const std::string phone);
    bool validate_phone2(const std::string phone2);
    
public:
    validaton();
    bool is_valid_email(const std::string in_email_id);
    bool is_valid_phone(const std::string in_phone);
    bool is_valid_phone2(const std::string in_phone2);
};
