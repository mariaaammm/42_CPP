#include "PMergeMe.hpp"

PMergeMe::PMergeMe() : _size(0), _isSorted(false) {}

PMergeMe::PMergeMe(const PMergeMe &copy) {*this = copy;}

PMergeMe& PMergeMe::operator=(const PMergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _size = other._size;
        _isSorted = other._isSorted;
    }
    return (*this);
}

PMergeMe::~PMergeMe() {}

template <typename Container>
bool isSorted(const Container &container) {
    typename Container::const_iterator prev = container.begin();
    typename Container::const_iterator cur = prev;
    ++cur;

    while (cur != container.end()) {
        if (*prev > *cur) {
            return (false);
        }
        ++prev;
        ++cur;
    }
    return (true);
}

bool PMergeMe::isDuplicate()
{
    std::set<int> args;
    int n;

    for (std::vector<int>::iterator iter = _vector.begin(); iter != _vector.end(); ++iter)
    {
        n = *iter;
        if (args.find(n) == args.end())
            args.insert(n);
        else
        {
            std::cerr << "Duplicate error" << std::endl;
            return (0);
        }
    }
    return (1);
}

bool PMergeMe::isDigit(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        char *arg = av[i];
        std::stringstream ss(arg);
        int val;
        ss >> val;

        if (!ss.eof() || ss.fail())
        {
            std::cerr << "Error" << std::endl;
            return (false);
        }
    }
    return (true);
}

void PMergeMe::fillArgs(int ac, char **av)
{
    int val;

    
    double diff1 = 0;
    double diff2 = 0;

    for (int i = 1; i < ac; ++i)
    {
        std::string arg = av[i];
        val = atoi(arg.c_str());
        if (val <= 0)
        {
            throw std::out_of_range("Error");
        }
        _vector.push_back(val);

    }
    // if (isDuplicate() == 0)
    //     return ;
    _deque = std::deque<int>(_vector.begin(), _vector.end());
    
    // bool isSorted1 = isSorted(_vector);
    // bool isSorted2 = isSorted(_deque);

    _size = _vector.size();

    std::cout << "Before:  ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

   //  std::sort(_vector.begin(), _vector.end());

    // if (isSorted1 == false)
    // {
        clock_t start1 = clock();
        mergeInsertionSort(_vector, 0, _vector.size() - 1);
        clock_t end1 = clock();
        diff1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    // }

    // if (isSorted2 == false)
    // {
        clock_t start2 = clock();
        mergeInsertionSort(_deque, 0, _deque.size() - 1);
        clock_t end2 = clock();
        diff2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    // }

    std::cout << "After   ";
    if (typeid(_vector) == typeid(std::vector<int>)) {
        for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
            std::cout << " " << *it;
        }
    }

    else if (typeid(_deque) == typeid(std::deque<int>)) {
        for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it) {
            std::cout << " " << *it;
        }
    }
    else {
        std::cout << "Unknown container type." << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Time to process a range of " <<  _vector.size() << " elements with std::vector : " << std::fixed << diff1 << " us" << std::endl;
    std::cout << "Time to process a range of " <<  _deque.size() << " elements with std::deque : " << std::fixed << diff2 << " us" << std::endl;
}

