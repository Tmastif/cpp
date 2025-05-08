/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:44:51 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 18:16:25 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource cntr\n";
    for (int i = 0; i < _slots; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource copy cntr\n";
    for (int i = 0; i < _slots; i++)
    {
        if (other._templates[i] == NULL)
            _templates[i] = NULL;
        else
            _templates[i] = other._templates[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource copy assigment\n";
    if (this != &other)
    {
        this->deleteTemplates();
        for (int i = 0; i < _slots; i++)
        {
            if (other._templates[i] == NULL)
                _templates[i] = NULL;
            else
                _templates[i] = other._templates[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor\n";
    this->deleteTemplates();
}

//FUNCTIONS

void    MateriaSource::deleteTemplates(void)
{
    for (int i = 0; i < _slots; i++)
    {
        if (_templates[i] != NULL)
        {
            delete _templates[i];
            _templates[i] = NULL;
        }
    }
}

void    MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < _slots; i++)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m;
            return ;
        }
    }
    std::cout << "Templates slots are all full\n";
}

    
AMateria*   MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < _slots; i++)
    {
        if ((_templates[i] != NULL) && (_templates[i]->getType() == type))
            return (_templates[i]->clone());
    }
    std::cout << "Type unknown\n";
    return (NULL);
}