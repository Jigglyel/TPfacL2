-- create table Groupe
-- (NomGroupe varchar(5) PRIMARY KEY CHECK (NomGroupe IN('A1', 'A2', 'A3', 'A4', 'A5' ,'A6')),
-- IntituleGroupe varchar(20));

-- create table Enseignant
-- (NumEns integer PRIMARY KEY,
-- NomEns varchar(30)
-- );

-- create table Matiere 
-- (
-- NomMat varchar(15) PRIMARY KEY, 
-- CoefMat integer CHECK(CoefMat BETWEEN 1 AND 8), 
-- NumEns integer REFERENCES Enseignant(NumEns)
-- ON DELETE CASCADE ON UPDATE CASCADE
-- );



-- create sequence Valetud minvalue 1111;
-- create sequence valCont;

-- create table Etudiant
-- (NumEt integer PRIMARY KEY, 
-- NomEt varchar(30), 
-- PrenomEt varchar(30), 
-- AdrEt varchar(50), 
-- DatNais date CHECK(extract (year from age(DatNais)) BETWEEN 16 AND 35), 
-- NomGr char(2) REFERENCES Groupe(NomGroupe) ON DELETE CASCADE ON UPDATE CASCADE
-- );


-- create table Contrôle
-- (NumCont int PRIMARY KEY, 
-- NomMat varchar(20) REFERENCES Matiere(NomMat) ON DELETE CASCADE ON UPDATE CASCADE, 
-- DatCont date, 
-- Coef integer CHECK(Coef BETWEEN 1 AND 3)
-- );

-- create table PassCont 
-- (NumEt integer, 
-- NumCont integer, 
-- Note real CHECK(Note BETWEEN 0 AND 20),
-- PRIMARY KEY(NumEt,NumCont),

-- FOREIGN KEY(NumEt) REFERENCES Etudiant(NumEt)
--     ON DELETE CASCADE ON UPDATE CASCADE,
-- FOREIGN KEY(NumCont) REFERENCES Contrôle(NumCont)
--     ON DELETE CASCADE ON UPDATE CASCADE
-- );


-- INSERT INTO Groupe VALUES
-- ('A1','informatique'),
-- ('A2','Math-info'),
-- ('A3','Bio-info'),
-- ('A4','chimie'),
-- ('A5','Maths');

-- INSERT INTO Enseignant VALUES
-- (1, 'Carter'),
-- (2, 'Clinton'),
-- (3, 'Bush'),
-- (4, 'Paolo'),
-- (5, 'Vissou'),
-- (6, 'Charlemagne'),
-- (7, 'Léandri');
-- INSERT INTO Matiere VALUES
-- ('Algo 2',6,1),
-- ('Algo 3',7,2),
-- ('Math1',6,3),
-- ('Gestion',7,4),
-- ('TE',7,5),
-- ('Math2',6,6),
-- ('Anglais',7,7);
-- INSERT INTO Contrôle VALUES
-- (nextval('valCont'), 'Algo 2', '15/01/2023', 1),
-- (nextval('valCont'), 'Algo 2', '12/12/2022', 3),
-- (nextval('valCont'), 'Algo 3', '17/02/2023', 2),
-- (nextval('valCont'), 'Algo 3', '27/03/2023', 3),
-- (nextval('valCont'), 'Math1', '17/01/2023', 1),
-- (nextval('valCont'), 'Gestion' , '07/02/2023', 2),
-- (nextval('valCont'), 'TE' , '27/03/2023', 2),
-- (nextval('valCont'), 'Math2', '17/01/2023', 1),
-- (nextval('valCont'), 'Anglais' , '17/01/2023', 2);


-- INSERT INTO Etudiant VALUES
-- (nextval('Valetud'), 'AHDJOUDJ', 'Yannick', 'Angers', '18/01/2003', 'A1'),
-- (nextval('Valetud'), 'AMEUR', 'Adil', 'Cholet', '17/02/2002' ,'A1'),
-- (nextval('Valetud'), 'CALVAIRE', 'Isabelle', 'Nantes', '01/03/2004', 'A2'),
-- (nextval('Valetud'), 'GHULAM', 'William', 'Cholet', '27/04/2004', 'A2'),
-- (nextval('Valetud'), 'MIRMONT', 'Jean', 'Paris', '07/05/2002', 'A3'),
-- (nextval('Valetud'), 'TOTO' ,'Sylvie' ,'Tours' ,'17/06/2001' ,'A3'),
-- (nextval('Valetud'), 'WINTERHA' ,'Shahidah' ,'Toulouse' ,'07/07/2003' ,'A3');

-- INSERT INTO PassCont VALUES
-- (1111,1,10),
-- (1112,1,20),
-- (1113,1,11.5),
-- (1114,1,3),
-- (1115,1,10.5),
-- (1116,1,2),
-- (1111,2,10.5),
-- (1112,2,6.6),
-- (1113,2,4.5),
-- (1114,2,9),
-- (1115,2,8.5),
-- (1116,2,2.5),
-- (1111,3,14.5),
-- (1112,3,11.5),
-- (1113,3,3.5),
-- (1114,3,12.5),
-- (1115,3,20),
-- (1116,3,9.5);

-- INSERT INTO Etudiant VALUES
-- (1300,'Kylian','MBAPPÉ','Madrid','20/12/1998','A6');

-- INSERT INTO Groupe VALUES
-- ('A6','Football');

-- INSERT INTO Etudiant VALUES
-- (1300,'Kylian','MBAPPÉ','Madrid','20/12/1998','A6');

-- INSERT INTO PassCont VALUES
-- (1118,1,15);

-- INSERT INTO Etudiant VALUES
-- (nextval('Valetud'),'DOUÉ','Désiré','Paris','03/06/2005','A1');

-- INSERT INTO PassCont VALUES
-- (1118,1,15);


-- UPDATE Enseignant 
-- Set NumEns='101'
-- Where NomEns='Carter';

-- INSERT INTO Etudiant VALUES
-- (nextval('Valetud'),'CAMAVINGA','EDUARDO','Madrid','10/11/2002','A1');

-- ALTER table Groupe
-- ADD salle varchar(5);

-- UPDATE Groupe
-- Set salle='L00'||substring(NomGroupe,2,1);

-- UPDATE PassCont
-- Set Note=Note+1
-- Where NumCont in (
--     SELECT NumCont from PassCont
--     Group by NumCont 
--     HAVING AVG(NOTE)<8
-- )

-- SELECT NomEt,NumEt,nomgr FROM Etudiant order by NomGr;


-- SELECT NomEt,SUM(Note)/count(Note),NomMat 
-- from PassCont 
-- join Contrôle ON PassCont.NumCont =Contrôle.NumCont natural join Etudiant 
-- Group by NomEt,NomMat
-- order by NomEt;


-- SELECT Note
-- from PassCont 
-- join Contrôle ON PassCont.NumCont =Contrôle.NumCont natural join Etudiant
-- Where NomEt='TOTO' and NomMat='Algo 2' and DatCont='12/12/2022';



-- SELECT NomEt from Etudiant
-- Where substring(NomEt,1,1)='a' or substring(NomEt,1,1)='A';


-- SELECT Coef
-- from PassCont 
-- join Contrôle ON PassCont.NumCont =Contrôle.NumCont
-- Where Note=20;

-- SELECT NomEt
-- from PassCont 
-- join Contrôle ON PassCont.NumCont =Contrôle.NumCont natural join Etudiant
-- Where NomMat='Algo 2' and DatCont='12/12/2022' and note>=10;

-- SELECT DISTiNcT NomEns
-- from PassCont 
-- join Contrôle ON PassCont.NumCont =Contrôle.NumCont  join Matiere on Matiere.NomMat=Contrôle.NomMat join Enseignant on Matiere.NumEns =Enseignant.NumEns;

-- SELECT DISTiNcT NomEt,AdrEt from Etudiant
-- Where AdrEt not in('Angers','Cholet','Tours');

SELECT DISTiNcT NomEt from
Etudiant natural join PassCont  natural join Contrôle
Where NomMat='Algo 3' and DatCont='12/12/2022' and note>(
    SELECT note from
    Etudiant natural join PassCont natural join Contrôle
    Where NomMat='Algo 3' and DatCont='12/12/2022' and NomEt='GHULAM'
);



