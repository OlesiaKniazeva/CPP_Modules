#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

  class Brain {
    public:
      Brain();
      ~Brain();
      Brain(const Brain & rhs);
      Brain & operator=(const Brain & rhs);

      const std::string GetIdea(const int index) const;
      void  SetIdea(std::string& idea, int index);

    private:
      std::string ideas_[100];

  };

#endif