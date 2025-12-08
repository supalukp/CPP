/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/08 17:09:14 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
    : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other)
{
    for(int i = 0; i < other.size(); i++) 
    {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other) 
    {
        for(int i = 0; i < other.size(); i++) 
        {
            _array[i] = other._array[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}
