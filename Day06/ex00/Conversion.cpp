#include "Conversion.hpp"

void Conversion::ConvertData() {
  FindActualTypeOfData();
}

void Conversion::FindActualTypeOfData() {
  if (data_.size() == 1 && !isdigit(data_[0])) {
    letter_ = static_cast<char>(data_[0]);
    ConvertChar();
  }
  CheckForInt();
  CheckForFloat();
  CheckForDouble();
  CheckForSpecial();
  throw std::invalid_argument("Wrong data");
}

void Conversion::CheckForSpecial() {
 if (data_ == "+inf" || data_ == "-inf" ||
     data_ == "nanf" || data_ == "+inff" ||
     data_ == "-inff" || data_ == "nan") {
       ConvertSpecial();
     }
}

void Conversion::ConvertSpecial() {
  std::cout << "char: impossible" << '\n';
  std::cout << "int: impossible" << '\n';
  if (data_ == "+inff" || data_ == "+inf") {
    std::cout << "float: +inff" << '\n';
    std::cout << "double: +inf" << '\n';
  }
  else if (data_ == "-inff" || data_ == "-inf") {
    std::cout << "float: -inff" << '\n';
    std::cout << "double: -inf" << '\n';
  }
  else if (data_ == "nanf" || data_ == "nan") {
    std::cout << "float: nanf" << '\n';
    std::cout << "double: nan" << '\n';
  }
  exit(0);
}

void Conversion::ConvertChar() {
  if (!isprint(letter_) || letter_ == ' ') {
      std::cout << "char: Non displayable" << '\n';
  }
  else {
      std::cout << "char: " << letter_ << '\n';
  }
  std::cout << "int: " << static_cast<int>(letter_) << '\n';
  std::cout << "float: " << static_cast<float>(letter_) << ".0f" << '\n';
  std::cout << "double: " << static_cast<double>(letter_) << ".0" << '\n';
  exit(0);
}

void Conversion::CheckForInt() {
  std::stringstream ss(data_);
  int num;
  ss >> num;
  if (ss.fail() && ss.eof()) {
    throw std::invalid_argument("Int out of range!");
  }
  if (!ss.fail() && ss.eof()) {
    int_num_ = num;
    ConvertInt();
  }
}

void Conversion::ConvertInt() {
  std::cout << "char: ";
  if (int_num_ >= 0 && int_num_ < 128) {
    char l = static_cast<char>(int_num_);
    if (!isprint(l) || l == ' ') {
      std::cout << "Non displayable" << '\n';
    }
    else {
      std::cout << l << '\n';
    }
  }
  else {
    std::cout << "impossible" << '\n';
  }
  std::cout << "int: " << int_num_ << '\n';
  std::cout << "float: " << static_cast<float>(int_num_);
  if (int_num_ < 1000000 && int_num_ > -1000000) {
    std::cout << ".0f" << '\n';
  }
  else {
    std::cout << 'f' << '\n';
  }
  std::cout << "double: " << static_cast<double>(int_num_);
  if (int_num_ < 1000000 && int_num_ > -1000000) {
    std::cout << ".0" << '\n';
  }
  else {
    std::cout << '\n';
  }
  exit(0);
}

void Conversion::CheckForFloat() {
  std::stringstream ss(data_);
  float n;
  ss >> n;
  if (!ss.fail()) {
    std::string t;
    ss >> t;
    if (t == "f" && !ss.fail() && ss.eof()) {
      double num = atof(data_.c_str());
      if (errno != ERANGE)
      {
        float_num_ = num;
        ConvertFloat();
      }
    }
  }
}

void Conversion::ConvertFloat() {
  std::cout << "char: ";
  if (float_num_ >= 0 && float_num_ < 128) {
    char l = static_cast<char>(float_num_);
    if (!isprint(l) || l == ' ') {
      std::cout << "Non displayable" << '\n';
    }
    else {
      std::cout << l << '\n';
    }
  }
  else {
    std::cout << "impossible" << '\n';
  }
  std::cout << "int: ";
  if (float_num_ >= std::numeric_limits<int>::min() &&
      float_num_ <= std::numeric_limits<int>::max()) {
        std::cout << static_cast<int>(float_num_) << '\n';
      }
  else {
    std::cout << "impossible" << '\n';
  }
  if (float_num_ == static_cast<int>(float_num_)
    && (float_num_ < 1000000 && float_num_ > -1000000))
  {
    std::cout << "float: " << static_cast<float>(float_num_) << ".0f" << '\n';
    std::cout << "double: " << static_cast<double>(float_num_) << ".0" << '\n';
  }
  else {
    std::cout << "float: " << static_cast<float>(float_num_) << "f" << '\n';
    std::cout << "double: " << static_cast<double>(float_num_) << '\n';
  }
  exit(0);
}

void Conversion::CheckForDouble() {
  std::stringstream ss(data_);
  double n;
  ss >> n;
  if (!ss.fail() && ss.eof()) {
    double_num_ = atof(data_.c_str());
    if (errno != ERANGE) {
      ConvertDouble();
    }
  }
}

void Conversion::ConvertDouble() {
  std::cout << "char: ";
  if (double_num_ >= 0 && double_num_ < 128) {
    char l = static_cast<char>(double_num_);
    if (!isprint(l) || l == ' ') {
      std::cout << "Non displayable" << '\n';
    }
    else {
      std::cout << l << '\n';
    }
  }
  else {
    std::cout << "impossible" << '\n';
  }
  std::cout << "int: ";
  if (double_num_ >= std::numeric_limits<int>::min() &&
      double_num_ <= std::numeric_limits<int>::max()) {
        std::cout << static_cast<int>(double_num_) << '\n';
      }
  else {
    std::cout << "impossible" << '\n';
  }
  std::cout << "float: ";
  if ((double_num_ >= std::numeric_limits<float>::min() &&
      double_num_ <= std::numeric_limits<float>::max()) || double_num_ == 0) {
    std::cout << static_cast<float>(double_num_);
    if (double_num_ == static_cast<int>(double_num_)
          && (double_num_ < 1000000 && double_num_ > -1000000)) {
       std::cout << ".0f" << '\n';
    }
    else {
      std::cout  << "f" << '\n';
    }
  }
  else {
    std::cout << "impossible" << '\n';
  }
  std::cout << "double: " << static_cast<double>(double_num_);
  if (double_num_ == static_cast<int>(double_num_)
        && (double_num_ < 1000000 && double_num_ > -1000000)) {
    std::cout << ".0" << '\n';
  }
  else {
    std::cout << '\n';
  }
  exit(0);
}

Conversion::Conversion(const std::string & data)
: data_(data) {
}

Conversion::~Conversion() {

}

Conversion::Conversion(const Conversion & rhs) {
  *this = rhs;
}

Conversion & Conversion::operator=(const Conversion & rhs) {
  data_ = rhs.data_;
  return *this;
}