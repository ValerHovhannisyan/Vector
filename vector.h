#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
        Vector();
        ~Vector();
public:
    friend std::ostream& operator<<(std::ostream&, const Vector&);
    const int& operator[](int) const;
    int& operator[](int);
    Vector& operator=(const Vector&);
public:
    void push_back(int);
    void pop_back();
    bool empty();
    void print();
    void resize();
    void insert(int, int);
    void erase(int);
    void print_insert();
    int& at(int);
    int front();
    int back();
    int* data();
    void clear();
    void swap(Vector&);
    bool operator==(const Vector&);
    bool operator<(const Vector&);
    bool operator>(const Vector&);
    bool operator!=(const Vector&);
    bool operator>=(const Vector&);
    bool operator<=(const Vector&);
private:
    int m_capacity;
    int m_size; 
    int* m_arr;
};

#endif // VECTOR_H