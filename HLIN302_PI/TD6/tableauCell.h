#include <iostream>
#include "cellule.h"

class TableauCell{

 private:
  Cellule* T;
  size_t n;
  size_t N;

  void extend();

 public:

  TableauCell();
  TableauCell(size_t n);
  TableauCell(const TableauCell&);
  TableauCell& operator=(const TableauCell&);

  size_t size() const;
  Cellule& at(size_t);
  const Cellule& at(size_t)const;

  void read(std::istream&);
  void write(std::ostream&)const;

  
  void pushback(Cellule);
  void erase(size_t);
  int find(const Cellule&) const;
  
  ~TableauCell();

};

void read_cell(std::istream&, Cellule&);
void write_cell(std::ostream&, const Cellule&);
