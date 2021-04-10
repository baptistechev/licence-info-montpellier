CREATE TABLE Operateur
(
numero  NUMERIC(5) PRIMARY KEY,
nom CHARACTER(40) NOT NULL,
age NUMERIC(3)
);

CREATE TABLE Machine
(
referenceM NUMERIC(5) PRIMARY KEY,
designationM CHARACTER(40) NOT NULL
);

CREATE TABLE Piece
(
referenceP NUMERIC(5) PRIMARY KEY,
designationP CHARACTER(40) NOT NULL,
reference_machine NUMERIC(5) REFERENCES Machine(referenceM),
numero_operateur NUMERIC(5) REFERENCES Operateur(numero),
quantite NUMERIC(10)
);

CREATE TABLE Qualifie_sur
(
numero_operateur NUMERIC(5) REFERENCES Operateur(numero),
reference_machine NUMERIC(5) REFERENCES Machine(referenceM),
dateM NUMERIC(8),
PRIMARY KEY(numero_operateur,reference_machine)
);


