#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

int main()
{
  Data data;
  data.s = "cat";
  data.num = 5;
  Data *ptr = &data;

  std::cout << ptr << " " << ptr->num
            << " " << ptr->s << std::endl;

  uintptr_t ser = serialize(ptr);
  Data *new_data = deserialize(ser);

  std::cout << new_data << " " << new_data->num
            << " " << new_data->s << std::endl;
}