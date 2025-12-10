/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/10 12:16:23 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
    : _array(NULL), _size(0)
{
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    for(unsigned int i = 0; i < _size; i++) 
    {
        _array[i] = 0;
    }
    std::cout << "Constructor called with parameter" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size)
{
    for(unsigned int i = 0; i < other.size(); i++) 
    {
        _array[i] = other._array[i];
    }
	std::cout << "Copy constructor called" << std::endl;

}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other) 
    {
        delete [] this->_array;
        this->_array = new T[other._size];
        this->_size = other._size;
        
        for(unsigned int i = 0; i < this->_size; i++) 
        {
            _array[i] = other._array[i];
        }
    }
	std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx < 0 || idx >= _size)
        throw std::out_of_range("index is out of range");
        
    return (_array[idx]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx < 0 || idx >= _size)
        throw std::out_of_range("index is out of range");
        
    return (_array[idx]);
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _array;
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}
