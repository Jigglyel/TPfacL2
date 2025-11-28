create table Groupe
(NomGroupe varchar(5) PRIMARY KEY CHECK (NomGroupe IN('A1', 'A2', 'A3', 'A4', 'A5' ,'A6')),
IntituleGroupe varchar(20));

create table Matiere 
(
NomMat varchar(15) PRIMARY KEY, 
CoefMat integer CHECK(CoefMat BETWEEN 1 AND 8), 
NumEns integer
);

create table Enseignant
(NumEns integer PRIMARY KEY,
NomEns varchar(30)
);

create sequence Valetud minvalue 1111;
create sequence valCont;

create table Etudiant
(NumEt integer PRIMARY KEY, 
NomEt varchar(30), 
PrenomEt varchar(30), 
AdrEt varchar(50), 
DatNais date CHECK(extract (year from age(DatNais)) BETWEEN 16 AND 35), 
NomGr char(2) REFERENCES Groupe(NomGroupe) ON DELETE CASCADE ON UPDATE CASCADE
);


create table Contrôle
(NumCont int PRIMARY KEY, 
NomMat varchar(20) REFERENCES Matiere(NomMat) ON DELETE CASCADE ON UPDATE CASCADE, 
DatCont date, 
Coef integer CHECK(Coef BETWEEN 1 AND 3)
);

create table PassCont 
(NumEt integer, 
NumCont integer, 
Note real CHECK(Note BETWEEN 0 AND 20),
PRIMARY KEY(NumEt,NumCont),

FOREIGN KEY(NumEt) REFERENCES Etudiant(NumEt)
    ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY(NumCont) REFERENCES Etudiant(NumEt)
    ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO Etudiant VALUES
(1200,'Zinedine','ZIDANE','Marseille','23/06/1972','A1'),
(1300,'Kylian','MBAPPÉ','Madrid','20/12/1998','A6')





