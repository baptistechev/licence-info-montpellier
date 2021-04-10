class Itv{

  //attributs
 private:
  float inf,sup;

  //Constructeurs
 public:

  Itv();
  Itv(float inf, float sup);

  //Methodes

  float getInf() const;
  float getSup() const;
  void setInf(float inf);
  void setSup(float sup);
  float longueur() const;
  bool appartient(float x) const;
  void translater(float x);

  //Methodes avec d'autres intervalles

  bool estEgal(Itv I) const;
  bool estInclusStrc(Itv I) const;
  bool estDisjoint(Itv I) const;
  bool estAccole(Itv I) const;
  bool estImbrique(Itv I) const;

};
