#include "Headers/validation.h"//linking headers
#include<iostream>//to perform input output operation
#include <regex>//to validate string

validaton::validaton()
{
}


//validating charecter
bool validaton::is_char(const char character)
{
    return ((character >= 'a' && character <= 'z')
        || (character >= 'A' && character <= 'Z'));
}

bool validaton::is_digit(const char character)
{
    return (character >= '0' && character <= '9');
}

//validating email
bool validaton::validate_email(const std::string email_id)
{
    if (!is_char(email_id[0])) {
        return false;
    }
    int at = -1, dot = -1;

    for (int i = 0;
        i < email_id.length(); i++) {
        if (email_id[i] == '@') {
            at = i;
        }
        else if (email_id[i] == '.') {
            dot = i;
        }
        }
    if (at == -1 || dot == -1)
        return false;
    if (at > dot)
        return false;
    return !(dot >= (email_id.length() - 1));
}

//validating email
bool validaton::is_valid_email(const std::string in_email_id)
{
    return validate_email(in_email_id);
}

//validating phone number
bool validaton::validate_phone(const std::string phone)
{
    const std::regex pattern("(0|91)?[7-9][0-9]{9}");

    if (std::regex_match(phone, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validaton::is_valid_phone(const std::string in_phone)
{
    return validate_phone(in_phone);
}

//validating phone number-2
bool validaton::validate_phone2(const std::string phone2)
{
    const std::regex pattern("(0|91)?[7-9][0-9]{9}");

    if (std::regex_match(phone2, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validaton::is_valid_phone2(const std::string in_phone2)
{
    return validate_phone2(in_phone2);
}