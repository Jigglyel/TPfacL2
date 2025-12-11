-- create table Auteur(
--     nom varchar(30) PRIMARY KEY,
--     nom_complet varchar(100),
--     pays char(3),
--     siecle INTEGER
-- );



-- create table Livre(
--     reflivre integer PRIMARY KEY,
--     titre varchar(100),
--     parution integer,
--     typel varchar(10) Default 'autre',
--     nomauteur varchar(30) REFERENCES Auteur(nom) ON UPDATE CASCADE ON DELETE CASCADE
-- );
-- ALTER TABLE Livre
-- ADD constraint valtype
-- CHECK(typel IN ('roman','théâtre','récit','auteur'));

-- CREATE TABLE Personnage(
--     refpers INTEGER PRIMARY KEY,
--     nom varchar(50),
--     metier varchar(50),
--     sexe char(1) CHECK(sexe IN ('F','M'))  
-- );

-- CREATE TABLE PARTICIPE(
--     idpers INTEGER REFERENCES Personnage(refpers) ON UPDATE CASCADE ON DELETE CASCADE,
--     idlivre INTEGER REFERENCES Livre(reflivre) ON UPDATE CASCADE ON DELETE CASCADE,
--     nbcitations INTEGER,
--     PRIMARY KEY(idpers,idlivre)
-- );
-- create sequence sqc_livre;
-- create sequence sqc_perso minvalue 101;
-- INSERT INTO Auteur VALUES
-- ('Hugo','Victor Hugo','FRA',19),
-- ('Shakespeare','William Shakespeare','GBR',16);

-- INSERT INTO Livre VALUES
-- (nextval('sqc_livre'),'Les Misérables',1862,'roman','Hugo'),
-- (nextval('sqc_livre'),'Ruy Blas',NULL,'théâtre','Hugo'),
-- (nextval('sqc_livre'),'Roméo et Juliette',1597,'théâtre','Shakespeare');
-- INSERT INTO Personnage VALUES
-- (nextval('sqc_perso') ,'Juliette' ,'princesse' ,'F'),
-- (nextval('sqc_perso') ,'Roméo' ,'prince' ,'M'),
-- (nextval('sqc_perso') ,'Cosette' ,'femme de ménage' ,'F');

-- INSERT INTO PARTICIPE VALUES
-- (101 ,3 ,134),
-- (102 ,3 ,112);

-- UPDATE  Livre
-- set parution=1400
-- Where parution IS NULL;


-- alter table Livre
-- drop constraint valtype,
-- ADD constraint valtype
-- CHECK(typel IN ('roman','théâtre','récit','auteur','poésie'));

-- INSERT into Livre VALUES
-- (nextval('sqc_livre'),'Le Grand Meaulnes',1913,'roman','Alain-Fournier');
--ajouter l'auteur dans la table auteur
-- INSERT Into PARTICIPE VALUES
-- ((SELECT refpers from Personnage Where nom='Cosette'),
-- (SELECT reflivre from livre where titre='Les Misérables'),
-- 324);

-- DELETE from livre
-- where titre='Roméo et Juliette'

CREATE table LIVRE_AUTEUR(
    titre varchar(100) REFERENCES livre(titre),
    nom varchar(100) REFERENCES auteur(nom_complet),
    PRIMARY KEY(titre,nom)
);