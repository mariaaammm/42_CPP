#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    _size = 0;
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;
//    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    _size = copy._size;
    for (int i = 0; i < 4; ++i)
        _materia[i] = copy._materia[i]->clone();
//    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        this->_size = other._size;
        for (int i = 0; i < 4; ++i)
        {
            if (this->_materia[i] != NULL)
            {
                delete _materia[i];
                _materia[i] = NULL;
            }
        }
        for (int i = 0; i < 4; ++i)
            this->_materia[i] = other._materia[i]->clone();
    }
//    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete _materia[i];
//    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (_size < 4)
        _materia[(_size)++] = materia;
    else    
        std::cout << "No more than 4 materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < _size; ++i)
    {
       if (type == _materia[i]->getType())
            return (_materia[i]->clone());
    }
    return (NULL);
}