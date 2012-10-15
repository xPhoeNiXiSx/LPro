USE tp2;

DROP TABLE Affectation;
DROP TABLE Membre;
DROP TABLE Projet;

CREATE TABLE Membre (
	numero integer primary key auto_increment,
	nom varchar(20),
	prenom varchar(20),
	superieur integer
);

CREATE TABLE Projet (
	nom_projet varchar(10) primary key,
	priorite numeric(2),
	dirigeant integer,
	echeance date
);

CREATE TABLE Affectation (
	employe integer,
	projet varchar(10),
	constraint akey primary key (employe, projet)
);

INSERT INTO Membre (nom,prenom,superieur) VALUES 
('Karamazov','Serge',null),
('Deray','Odile',1),
('Gilet','Gilles',2),
('Jeremi','Simon',1),
('Lamar','André',2);

INSERT INTO Projet (nom_projet,priorite,dirigeant,echeance) VALUES
('PRJ1',5,2,'2006-10-14'),
('PRJ2',7,5,'2007-04-22');

INSERT INTO Affectation (employe,projet) VALUES
(1,'PRJ1'),
(2,'PRJ1'),
(3,'PRJ1'),
(4,'PRJ1'),
(5,'PRJ1'),
(5,'PRJ2');



-- Modification des tables --


-- 1 --
ALTER TABLE Membre
ADD salaire numeric(10,2);

-- 2 --
UPDATE Membre 
SET salaire = 10000 - 1000 * numero;

-- 3 --
ALTER TABLE Projet
MODIFY priorite numeric(4,2);

-- 4 --
UPDATE Projet
SET priorite = priorite * 100;

-- 5 --
UPDATE Membre 
SET salaire = salaire + 100  
ORDER BY salaire limit 1;

SELECT * FROM Membre;
SELECT * FROM Projet;
SELECT * FROM Affectation;

-- Quelques requetes surplémentaires sur le TP2 --

-- 1
SELECT nom FROM Membre WHERE numero%2 = 0;

-- ou --

SELECT nom FROM Membre WHERE mod(numero,2) = 0;

-- 2
SELECT nom, if (salaire >7000, 'Bien payé', 'Mal payé') AS NiveauSalaire 
FROM Membre;

-- 3
SELECT AVG(salaire) AS Moyenne_Salaire FROM Membre;

-- 4
SELECT employe, COUNT(projet) as Nombre_projet 
FROM Affectation 
group by employe;

-- 5
SELECT projet, MAX(salaire) as Plus_gros_salaire 
FROM Membre JOIN Affectation ON numero=employe 
group by projet ;

-- 6
SELECT nom, COUNT(projet) as Nombre_projet
FROM Membre m JOIN Affectation a ON m.numero=a.employe
GROUP BY numero;

-- ou --
SELECT nom, nb
FROM (SELECT employe, count(*) AS nb
	FROM Affectation GROUP BY employe) table_temp
      JOIN Membre ON (numero=employe);
      
-- 7

SELECT m1.nom,count(m2.numero) as Nb_Dependance 
FROM Membre m1 JOIN Membre m2 
ON (m1.numero=m2.superieur) 
GROUP BY m1.nom;

SELECT * FROM Membre m1 JOIN Membre m2 
ON (m1.numero=m2.superieur);

-- 8

SELECT m1.nom,count(m2.numero) as Nb_Dependance 
FROM Membre m1 LEFT JOIN Membre m2 
ON (m1.numero=m2.superieur) 
GROUP BY m1.nom order by Nb_Dependance desc;

SELECT * FROM Membre m1 LEFT JOIN Membre m2 
ON (m1.numero=m2.superieur);




SELECT * FROM Membre;
SELECT * FROM Projet;
SELECT * FROM Affectation;