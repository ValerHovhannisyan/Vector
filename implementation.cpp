#include <iostream>
#include "vector.h"

Vector::Vector()
{
    m_capacity = 5;
    m_size = 0;
    m_arr = new int[m_capacity];
}

Vector::~Vector()
{
    m_capacity = 0;
    m_size = 0;
    delete[] m_arr;
    m_arr = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Vector& rhs)
{
    for (int i = 0; i < rhs.m_size; ++i)
    {
        os << rhs.m_arr[i] << " ";
    }
    std::cout << std::endl;
    return os;
}

const int& Vector::operator[](int index) const
{
    if (index >= m_size || index < 0)
    {
        throw std::out_of_range("Invalid Index!");
    }
    return m_arr[index];
}

int& Vector::operator[](int index) 
{
    if (index >= m_size || index < 0)
    {
        throw std::out_of_range("Invalid Index!");
    }
    return m_arr[index];
}

void Vector::push_back(int element)
{
    if (m_size == m_capacity)
    {
        resize();
    }
    m_arr[m_size++] = element;
}

void Vector::resize()
{
     if (m_size == m_capacity)
    {
        m_capacity *= 2;
        int* tmp = new int[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }
}

bool Vector::empty()
{
    return (!m_size);
}

void Vector::print()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::pop_back()
{
    if (empty())
    {
        std::cout << "The Vector has no elements:" << std::endl;
    }
    else 
    m_arr[m_size--] = 0;
}

void Vector::insert(int index, int element)
{
    if (m_size <= m_capacity)
    {
        for (int i = m_size; i > index; --i)
        {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[index] = element;
    }
    else
    {
        m_capacity *= 2;
        int* tmp = new int[m_capacity];
        for (int i = 0; i < index; ++i)
        {
            tmp[i] = m_arr[i];
        }
        tmp[index] = element;
        for (int i = index; i < m_size; ++i)
        {
            tmp[i + 1] = m_arr[i]; 
        }
        delete[] m_arr;
        m_arr = tmp;
        delete[] tmp;
        tmp = nullptr;
    }
    ++m_size;
}

void Vector::print_insert()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::erase(int index)
{
    if(empty())
    {
        delete[] m_arr;
        m_arr = nullptr;
    }
    else 
    {
        int* tmp = new int[m_capacity - 1];
        for (int i = 0; i < m_size; ++i)
        {
            if (i < index)
            {
                 tmp[i] = m_arr[i];
            }
            if (i >= index)
            {
                 tmp[i] = m_arr[i + 1];
            }
        }
        delete[] m_arr;
        m_arr = new int[m_size - 1];
        for (int i = 0; i < m_size - 1; ++i)
        {
            m_arr[i] = tmp[i];
        }
        m_size--;
        delete[] tmp;
        tmp = nullptr;
    }
}

int& Vector::at(int index)
{
    if (index >= m_size || index < 0)
    {
        throw std::out_of_range("Invalid index!!!");
    }
    return m_arr[index];
}

int Vector::front()
{
    return m_arr[0];
}

int Vector::back()
{
    return m_arr[--m_size];
}

int* Vector::data()
{
    return m_arr;
}

void Vector::clear()
{
    m_size = 0;
    m_arr[m_size] = 0;
}

void Vector::swap(Vector& oth)
{
    int* tmp_arr = oth.m_arr;
    int tmp_size = oth.m_size;
    int tmp_capacity = oth.m_capacity;
    oth.m_arr = m_arr;
    oth.m_size = m_size;
    oth.m_capacity = m_capacity;
    m_arr = tmp_arr;
    m_size = tmp_size;
    m_capacity = tmp_capacity;
}

bool Vector::operator==(const Vector& lhs)
{
    if (lhs.m_size > this->m_size)
    {
        return false;
    }
    if (lhs.m_size < this->m_size)
    {
        return false;
    }
    if (lhs.m_size == this->m_size)
    {
        for (int i = 0; i < m_size + this->m_size; ++i)
        {
            if (lhs.m_arr[i] > this->m_arr[i])
            {
                return false;
            }
            if (lhs.m_arr[i] < this->m_arr[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Vector::operator<(const Vector& lhs)
{
    if (lhs.m_size < this->m_size)
    {
        return false;
    }
    if (lhs.m_size > this->m_size)
    {
        return true;
    }
    if (lhs.m_size == this->m_size)
    {
        for (int i = 0; i < m_size + this->m_size; ++i)
        {
            if (lhs.m_arr[i] > this->m_arr[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool Vector::operator>(const Vector& lhs)
{
    if (lhs.m_size > this->m_size)
    {
        return false;
    }
    if (lhs.m_size < this->m_size)
    {
        return true;
    }
    if (lhs.m_size == this->m_size)
    {
        for (int i = 0; i < m_size + this->m_size; ++i)
        {
            if (lhs.m_arr[i] < this->m_arr[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool Vector::operator!=(const Vector& lhs)
{
    if (lhs.m_size > this->m_size)
    {
        return true;
    }
    if (lhs.m_size < this->m_size)
    {
        return true;
    }
    if (lhs.m_size == this->m_size)
    {
        for (int i = 0; i < m_size + this->m_size; ++i)
        {
            if (lhs.m_arr[i] != this->m_arr[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool Vector::operator>=(const Vector& lhs)
{
    if (lhs.m_size > this->m_size)
    {
        return false;
    }
    for (int i = 0; i < lhs.m_size + this->m_size; ++i)
    {
        if (lhs.m_arr[i] > this->m_arr[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator<=(const Vector& lhs)
{
    if (lhs.m_size < this->m_size)
    {
        return false;
    }
    for (int i = 0; i < lhs.m_size + this->m_size; ++i)
    {
        if (lhs.m_arr[i] < this->m_arr[i])
        {
            return false;
        }
    }
    return true;
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->m_capacity = rhs.m_capacity;
    this->m_size = rhs.m_size;
    delete[] m_arr;
    m_arr = new int[m_capacity];
    for (int i = 0; i < this->m_size; ++i)
    {
        this->m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}