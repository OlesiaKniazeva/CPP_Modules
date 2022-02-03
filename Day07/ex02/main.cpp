#include "Array.hpp"

int main()
{
  Array<int> intArr(10);

  std::cout << intArr.size() << std::endl;
  std::cout << intArr[4] << std::endl;
  intArr[4] = 56;
  std::cout << intArr[4] << std::endl;
  // std::cout << intArr[10] << std::endl;
  // std::cout << intArr[-10] << std::endl;
  std::cout << "-----------" << std::endl;
  Array<std::string> strArr;
  std::cout << strArr.size() << std::endl;


  Array<std::string> strArr2(3);
  std::cout << strArr2.size() << std::endl;

  for (unsigned int i = 0; i < 3; ++i) {
      strArr2[i] = "ffff";
      std::cout << strArr2[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "-----------" << std::endl;

  Array<std::string> strArr3(strArr2);
  for (unsigned int i = 0; i < 3; ++i) {
      strArr3[i] = "AAAAA";
      std::cout << strArr3[i] << " ";
  }
  std::cout << std::endl;
  for (unsigned int i = 0; i < 3; ++i) {
      std::cout << strArr2[i] << " ";
  }
  std::cout << std::endl;

}