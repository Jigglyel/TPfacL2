
--nom des auteurs italiens

l2_tp1=# SELECT nom
FROM auteur
Where pays='ITA'
--auteur et perso par tri
l2_tp1=# SELECT P.nom, L.nomauteur FROM PARTICIPE PA JOIN PERSONNAGE P on PA.idpers=P.refpers JOIN LIVRE L on L.reflivre=PA.idlivre Order By L.nomauteur,P.nom;

--pays des auteur qui ont un perso voyageur
l2_tp1=# SELECT P.nom, L.nomauteur FROM PARTICIPE PA JOIN PERSONNAGE P on PA.idpers=P.refpers JOIN LIVRE L on L.reflivre=PA.idlivre Order By L.nomauteur,P.nom;

-- les autuers dont on connais le nom complet
SELECT nom FROM auteur Where nom_complet is not NULL;

-- nombre par type de livre

SELECT count(reflivre) FROM livre Group By type;

--nb récit par pays

SELECT count(reflivre) FROM livre L JOIN auteur A on A.nom=L.nomauteur Where L.type='récit' Group By A.pays;
--6. Nombre de récits par pays.
--7. Pays et nombre de romans, pour chaque pays, écrits par des auteurs du 19ème siècle.
SELECT A.Pays,count(reflivre) 
FROM livre L 
JOIN auteur A on A.nom=L.nomauteur 
Where A.siecle=19 and L.type='roman' Group By A.pays;
--8. Noms des auteurs qui ont écrit des récits et des romans.
SELECT DISTINCT A.nom
FROM livre L 
JOIN auteur A on A.nom=L.nomauteur 
JOIN auteur B on A.nom=B.nom 
JOIN livre LB on B.nom = LB.nomauteur
Where L.type='récit' and LB.type='roman';
--9. Noms des auteurs ayant écrit au moins trois livres.
SELECT DISTINCT A.nom 
FROM livre L 
JOIN auteur A on A.nom=L.nomauteur
Group By A.nom HAVING count(reflivre)>2;
--10. Noms des auteurs ayant écrit le plus de romans.
SELECT DISTINCT A.nom 
FROM livre L 
JOIN auteur A on A.nom=L.nomauteur
Group By A.nom HAVING count(reflivre)>=(
    SELECT Max(cnt)
    FROM (
        SELECT count(reflivre) as cnt FROM livre L 
        JOIN auteur A on A.nom=L.nomauteur
        Group By A.nom) as subquery
        
);
--11. Titres des livres ayant le plus de personnages cités.
SELECT L.titre 
FROM livre L JOIN PARTICIPE P on L.reflivre=P.idlivre
Group By reflivre HAVING count(idpers)>=ALL(
    SELECT count(idpers)
    FROM livre L JOIN PARTICIPE P on L.reflivre=P.idlivre
    Group By reflivre
);

--12. Noms des auteurs qui ont écrit dans tous les types.
SELECT DISTINCT A.nom
FROM livre L 
JOIN auteur A on A.nom=L.nomauteur Group By A.nom HAVING DISTINCT count(L.type)=;
--13. Noms des auteurs avec les titres de leurs livres (même s'ils n'ont pas écrit de livres).
--14. Couples des titres de livres écrits par le même auteur.
--15. Couples des titres de livres dans lesquels intervient le même personnage.

------------------------------------------------------------
--LIVRE (reflivre, titre, parution, type, nomauteur)
--AUTEUR (nom, nom_complet , pays, siecle)
--PERSONNAGE (refpers, nom, metier, sexe)
--PARTICIPE (idpers, idlivre, nbcitations)
-------------------------------------------------------------