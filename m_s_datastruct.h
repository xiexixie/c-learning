#pragma once
#include <iostream>

template <typename T, size_t n>
class array
{
private:
  T m_data[n];

public:
  constexpr size_t size() const { return n; }
  T &operator[](size_t index) { return m_data[index]; }
  const T &operator[](size_t index) const { return m_data[index]; }
  T *data() { return m_data; }
  const T *data() const { return m_data; }
};

template <typename T>
class vector
{
private:
  T *m_data = nullptr;
  size_t m_size = 0;
  size_t m_capacity = 0; // size of memory block

  // function of allocating memory of vector again
  void re_alloc(size_t new_capacity)
  {
    // 1.allocate new block of memory
    // T *new_block = new T[new_capacity];
    T *new_block = (T *)::operator new(new_capacity * sizeof(T));

    // 2.copy or move,small or big
    // copy
    if (new_capacity < m_size)
      m_size = new_capacity;
    for (size_t i = 0; i < m_size; i++)
      new_block[i] = std::move(m_data[i]);
    // 3.delete old memory
    // delete[] m_data;
    for (size_t i = 0; i < m_size; i++)
      m_data[i].~T();
    ::operator delete(m_data, m_capacity * sizeof(T));
    m_data = new_block;
    m_capacity = new_capacity;
  }

public:
  vector()
  {
    re_alloc(2);
  }
  ~vector()
  {
    clear();
    ::operator delete(m_data, m_capacity * sizeof(T));
    // delete[] m_data;
  }
  void push_back(const T &value)
  {
    if (m_size >= m_capacity)
    {
      re_alloc(m_capacity + m_capacity / 2); // everytime increase half capacity
    }
    m_data[m_size] = value;
    m_size++;
  }
  void push_back(const T &&value)
  {
    if (m_size >= m_capacity)
    {
      re_alloc(m_capacity + m_capacity / 2); // everytime increase half capacity
    }
    m_data[m_size] = std::move(value);
    m_size++;
  }
  template <typename... args>
  void emplcae_back(args &&...Args)
  {
    if (m_size >= m_capacity)
    {
      re_alloc(m_capacity + m_capacity / 2); // everytime increase half capacity
    }
    m_data[m_size] = T(std::forward<args>(Args)...);
    // new (&m_data[m_size]) T(std::forward<args>(Args)...);
    m_size++;
  }
  void pop_back()
  {
    if (m_size > 0)
    {
      m_size--;
      m_data[m_size].~T();
    }
  }
  void clear()
  {
    for (size_t i = 0; i < m_size; i++)
      m_data[i].~T();
    m_size = 0;
  }

  T &operator[](size_t index)
  {
    return m_data[index];
  }
  const T &operator[](size_t index) const { return m_data[index]; }

  size_t size() const { return m_size; }
};
