#include <iostream>

class TableauInt{

 private:
  int* T;
  size_t n;
  size_t N;

  void extend();

 public:

  TableauInt(size_t n);
  TableauInt(const TableauInt&);
  TableauInt& operator=(const TableauInt&);

  size_t size() const;
  int& at(size_t);
  const int& at(size_t)const;

  void pushback(int);
  
  ~TableauInt();

};

void write(std::ostream&, const TableauInt&);
