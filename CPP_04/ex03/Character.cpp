#include "Character.hpp"

Character::Character() : _name("")
{
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;
//    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name)
{
    this->_name = name;
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;
//    std::cout << "Character parameter constructor called" << std::endl;
}

Character::Character(const Character &copy)
{
    this->_name = copy._name;
    for (int i = 0; i < 4; ++i)
    {
        if (copy._materia[i] != NULL)
            this->_materia[i] = copy._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
//    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for(int i = 0; i < 4;i++)
        {
            if(this->_materia[i] != NULL)
            {
                delete this->_materia[i];
                this->_materia[i] = NULL;
            }
        }
        for (int i = 0; i < 4; ++i)
            this->_materia[i] = other._materia[i]->clone();
    }
//    std::cout << "Character copy assignment operator called" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        if (_materia[i] != NULL)
        {
            delete _materia[i];
            _materia[i] = NULL;
        }
//    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const { return (_name);}

void Character::equip(AMateria* m)
{
    if (m != NULL)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_materia[i] == NULL)
            {
                _materia[i] = m;
//                std::cout << "Equiped successfully" << std::endl;
                return ;
            }
        }
    }
    // else
    //     std::cout << "Couldn't equip" << std::endl;
}

 void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3 && _materia[idx] != NULL)
    {
        _materia[idx] = NULL;
    //    std::cout << "Unequiped successfully" << std::endl;
        return ;
    }
    // else
    //    std::cout << "Couldn't unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && this->_materia[idx] != NULL)
    {
        _materia[idx]->use(target);
    //    std::cout << "Found and used that index" << std::endl;
    }
    // else
    //    std::cout << "Nothing found at that index" << std::endl;
}