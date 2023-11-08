#pragma once

#include <iostream>
#include <string>

class Contact
{
    public:

        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
        void setNickName(const std::string& nickName);
        void setPhoneNumber(const std::string& phoneNumber);
        void setDarkestSecret(const std::string& darckestSecret);

        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarckestSecret(void);
    private:
        std::string m_FirstName;
        std::string m_LastName;
        std::string m_NickName;
        std::string m_PhoneNumber;
        std::string m_DarkestSecret;
};
