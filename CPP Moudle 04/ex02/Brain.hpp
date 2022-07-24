#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  private:
    std::string ideas[100];

  public:
    Brain();
    ~Brain();
    Brain(const Brain &brain);
    Brain &operator=(const Brain &brain);
    std::string getIdeaStr(int index) const;
    void setIdeaStr(int index, std::string tmp);
};
#endif // !BRAIN_HPP