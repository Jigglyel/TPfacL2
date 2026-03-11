Create TABLE SOCIETE(
    CodeSoc INTEGER PRIMARY KEY,
    Nom varchar(15) not NULL,
    adresse varchar(50) not NULL;
)

Create TABLE CAMPAGNE(
    CodeCamp varchar(5) PRIMARY KEY,
    Titre varchar(30),
    CodeSoc FOREIGN KEY(SOCIETE)
    REFERCENCES SOCIETE(CodeSoc),
    produit varchar(20),
    cible varchar(5) CHECK (column cible in ("ENF","ADO","MM50","TOUS"));
)

SPOT(
    CodeSpot varchar(3) not null PRIMARY KEY,
    Libellé 
)