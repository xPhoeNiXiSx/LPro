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


SELECT * FROM Membre;
SELECT * FROM Projet;
SELECT * FROM Affectation;


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

--ou--

--UPDATE Membre 
--SET salaire = salaire + 100  
--WHERE salaire <= ALL (SELECT salaire FROM Membre);


-- Interrogations --


-- 1 --
SELECT nom,prenom FROM Membre
WHERE superieur IS NULL;

-- 2 --
SELECT employe 
FROM Affectation JOIN Projet ON (Affectation.projet = Projet.nom_projet)
WHERE Projet.echeance >= '2007-01-01';

-- 3 --
SELECT prenom FROM Affectation 
JOIN Membre ON numero = employe
WHERE projet = 'PRJ2';

-- 4 --
SELECT superieur FROM Membre 
WHERE numero = '3';

-- 5 --
SELECT nom FROM Membre WHERE numero LIKE
(SELECT superieur FROM Membre WHERE numero = '3');

-- ou --

SELECT a.nom 
FROM Membre a JOIN Membre b ON a.numero = b.superieur
WHERE b.numero = 3 ;

-- 6 --
SELECT nom,prenom FROM Membre 
WHERE numero LIKE
	(SELECT superieur FROM Membre 
	WHERE nom = 'Jeremi' AND prenom = 'Simon');
	
-- ou --

SELECT a.prenom, a.nom FROM
Membre a JOIN Membre b ON a.numero = b.superieur
WHERE b.nom = 'Jeremi' AND b.prenom = 'Simon';

-- 7 --
SELECT nom, prenom 
FROM Membre 
WHERE numero 
NOT IN
	(SELECT employe FROM Affectation 
	WHERE projet = 'PRJ2');
	
-- ou --
SELECT *
FROM Membre LEFT JOIN Affectation ON
(Membre.numero = Affectation.employe AND Affectation.projet = 'PRJ2')
WHERE employe IS NULL;

-- 8 --
SELECT nom
FROM Membre 
WHERE superieur LIKE
(SELECT numero FROM Membre WHERE nom = 'Karamazov' AND prenom = 'Serge');

-- ou --

SELECT b.nom 
FROM Membre a JOIN Membre b 
ON a.numero = b.superieur
WHERE a.nom = 'Karamazov' AND a.prenom = 'Serge';

-- 9 --
SELECT m2.nom,m1.nom nom_sup  FROM
Membre m1 JOIN Membre m2 
ON m1.numero = m2.superieur
ORDER BY m2.nom;

-- 10 --
SELECT nom, prenom FROM
Membre WHERE superieur IN
(SELECT b.numero
FROM Membre a JOIN Membre b 
ON a.numero = b.superieur
WHERE a.nom = 'Karamazov' AND a.prenom = 'Serge'); 

-- ou --

SELECT m1.nom
FROM Membre m1 JOIN Membre m2 JOIN Membre m3 
ON (m1.superieur = m2.numero) AND (m2.superieur = m3.numero)
WHERE (m3.nom = 'Karamazov') AND (m3.prenom = 'Serge'); 


SELECT * FROM Membre;
SELECT * FROM Projet;
SELECT * FROM Affectation;