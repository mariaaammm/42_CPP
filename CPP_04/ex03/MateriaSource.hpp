#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource& operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);

    private:
        int _size;
        AMateria *_materia[4];
};