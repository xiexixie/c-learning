#include <iostream>
#include "m_s_datastruct.h"

class vector3
{
private:
  float x, y, z;
  int *a;

public:
  vector3()
  {
    a = new int[5];
  }
  vector3(float scalar)
      : x(scalar), y(scalar), z(scalar)
  {
    a = new int[5];
  }
  vector3(float x, float y, float z)
      : x(x), y(y), z(z)
  {
    a = new int[5];
  }
  vector3(const vector3 &other)
      : x(other.x), y(other.y), z(other.z)
  {
    a = other.a;
    std::cout << "copy\n";
  };

  vector3(const vector3 &&other)
      : x(other.x), y(other.y), z(other.z)
  {
    a = other.a;
    std::cout << "move\n";
  };

  ~vector3()
  {
    delete[] a;
    std::cout << "destory\n";
  }
  vector3 &operator=(const vector3 &other)
  {
    std::cout << "copy1\n";
    x = other.x;
    y = other.y;
    z = other.z;
    a = other.a;
    // other.a = nullptr;
    return *this;
  }

  vector3 &operator=(const vector3 &&other)
  {
    std::cout << "move1\n";
    x = other.x;
    y = other.y;
    z = other.z;
    a = other.a;
    // other.a = nullptr;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &stream, const vector3 &v);
};

std::ostream &operator<<(std::ostream &stream, const vector3 &v)
{
  stream << v.x << "," << v.y << "," << v.z;
  return stream;
}

int main()
{
  /*
    array<int, 5> a;

    for (int i = 0; i < a.size(); i++)
    {
      a[i] = i;
      std::cout << a[i] << std::endl;
    }
    std::cout << "===================" << std::endl;
  */
  vector<vector3> v;
  vector3 a(2, 3, 4);
  v.push_back(1.0f);
  v.push_back(a);
  v.emplcae_back(2, 3, 4);
  v.emplcae_back(2, 3, 4);
  v.emplcae_back(2, 3, 4);
  v.emplcae_back(2, 3, 4);
  v.emplcae_back(2, 3, 4);
  v.emplcae_back(5, 6, 7);
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.clear();
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
  std::cout << "===================" << std::endl;

  std::cout << v.size() << std::endl;
}