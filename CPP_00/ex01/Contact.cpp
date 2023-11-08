#include "PhoneBook.hpp"

void Contact::setFirstName(const std::string& firstName) {m_FirstName = firstName;}
void Contact::setLastName(const std::string& lastName) {m_LastName = lastName;}
void Contact::setNickName(const std::string& nickName) {m_NickName = nickName;}
void Contact::setPhoneNumber(const std::string& phoneNumber) {m_PhoneNumber = phoneNumber;}
void Contact::setDarkestSecret(const std::string& darkestSecret) {m_DarkestSecret = darkestSecret;}

std::string Contact::getFirstName(void) {return (m_FirstName);}
std::string Contact::getLastName(void) {return (m_LastName);}
std::string Contact::getNickName(void) {return (m_NickName);}
std::string Contact::getPhoneNumber(void) {return (m_PhoneNumber);}
std::string Contact::getDarckestSecret(void) {return (m_DarkestSecret);}
