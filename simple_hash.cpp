// g++ -o simple_hash.exe -std=c++11 -O2 -Wall simple_hash.cpp
#include <iostream>

#include <sstream>

class HashTable
{
public:
  struct Entry
  {
    std::string Data;
    std::string status = "never used";
  };
  void print()
  {
    for (int i = 0; i < 26; i++)
    {
      // std::cout << m_entry[i].Data << ", " << m_entry[i].status << std::endl;
      if (m_entry[i].status == "occupied")
        std::cout << m_entry[i].Data << " ";
    }
  }
  void add(const std::string &name)
  {
    int unused;
    bool exist = search(name, unused);
    if (exist)
      return;
    int insertIndex = get_insertIndex(name);
    m_entry[insertIndex].Data = name;
    m_entry[insertIndex].status = "occupied";
  }
  void del(const std::string &name)
  {
    int out_index;
    bool exist = search(name, out_index);
    if (!exist)
      return;
    m_entry[out_index].Data = "";
    m_entry[out_index].status = "tombstone";
  }

private:
  Entry m_entry[26];
  int hash_func(const std::string &name)
  {
    return name.back() - 'a';
  }
  bool search(const std::string &name, int &out_index)
  {
    int index = hash_func(name);
    while (1)
    {
      if (m_entry[index].Data == name)
      {
        out_index = index;
        return true;
      }
      if (m_entry[index].status == "never used" || m_entry[index].status == "tombstone")
        return false;
      index = (index + 1) % 26;
    }
  }
  int get_insertIndex(const std::string &name)
  {
    int index = hash_func(name);
    while (true)
    {
      if (m_entry[index].status == "never used" || m_entry[index].status == "tombstone")
        return index;
      index = (index + 1) % 26;
    }
  }
};

int main()
{
  // std::cout << "hello" << std::endl;
  std::string input;
  HashTable hash_table;
  std::getline(std::cin, input);
  std::stringstream ss(input);
  while (ss.good())
  {
    std::string token;
    ss >> token;
    // std::cout << token << std::endl;
    std::string name = token.substr(1);
    if (token[0] == 'A')
    {
      hash_table.add(name);
    }
    else if (token[0] == 'D')
    {
      hash_table.del(name);
    }
  }
  hash_table.print();
  return 0;
}