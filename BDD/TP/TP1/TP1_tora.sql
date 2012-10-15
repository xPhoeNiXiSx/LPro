DROP TABLE Sinistre ;
DROP TABLE Vehicule ;
DROP TABLE Client ;

CREATE TABLE Client (
	num_secu CHAR (13) PRIMARY KEY ,
	nom varchar(30),
	prenom varchar(30)
);

CREATE TABLE Vehicule (
	num_immat CHAR(9) PRIMARY KEY,
	modele VARCHAR(30) , 
	annee NUMERIC(4),
	num_secu CHAR(13),
);

CREATE TABLE Sinistre (
	num_sinistre NUMERIC(10) PRIMARY KEY ,
	montant NUMERIC(10,2),
	resp NUMERIC(3),
	num_secu CHAR(13),
	num_immat CHAR(9),
);

INSERT INTO Client(num_secu,nom,prenom) VALUES('1710549123456' ,'Rudoux' ,'Patrick');
INSERT INTO Client(num_secu,nom,prenom)  VALUES  ( '1670649234567' ,'Lenoir' ,'Herve' );
INSERT INTO Client(num_secu,nom,prenom)  VALUES  ( '2740749345678' ,'Drabert' ,'Severine' );

INSERT INTO Vehicule(num_immat,modele,annee,num_secu) VALUES ('1234 TZ 49','Twingo','2000','1710549123456');
INSERT INTO Vehicule(num_immat,modele,annee,num_secu) VALUES ('2345 RA 49','R21','1980','1670649234567');
INSERT INTO Vehicule(num_immat,modele,annee,num_secu) VALUES ('3456 RZ 49','Supercinq','1984','1710549123456');

INSERT INTO Sinistre(num_sinistre,montant,resp,num_secu,num_immat) VALUES ('200201','1000','0','1670649234567','2345 RA 49');
INSERT INTO Sinistre(num_sinistre,montant,resp,num_secu,num_immat) VALUES ('200202',null,'50','1710549123456','1234 TZ 49');

//MODIFICATION DE DONNEE\\

UPDATE Vehicule SET num_immat = '4321 TZ 49'
WHERE num_immat = '1234 TZ 49';

UPDATE Vehicule SET annee = annee + 1
WHERE annee > 1983;


//1\\
SELECT Modele 
FROM Client NATURAL JOIN Vehicule 
WHERE num_secu = '1710549123456';

//2\\
SELECT num_secu 
FROM Client
WHERE nom = 'Rudoux';

//3\\
SELECT num_immat, nom, prenom 
FROM Client NATURAL JOIN Vehicule ;

--ou--

SELECT num_immat, nom, prenom 
FROM Client JOIN Vehicule ON Client.num_secu=Vehicule.num_secu;

--ou--

SELECT num_immat, nom, prenom 
FROM Client JOIN Vehicule USING (num_secu);

//4\\
SELECT annee 
FROM Vehicule NATURAL JOIN Client 
WHERE nom = 'Rudoux';

--ou--

SELECT annee
FROM Vehicule, Client
WHERE (Vehicule.num_secu = Client.num_secu) and (Client.nom = 'Rudoux');

//5\\
SELECT num_sinistre 
FROM Sinistre 
WHERE montant IS NULL;

//6\\
SELECT nom 
FROM Client NATURAL JOIN Sinistre 
WHERE num_sinistre BETWEEN '200110' AND '200201';

//SUPRESSIONS\\

//1\\
DELETE FROM Sinistre 
WHERE num_sinistre = '200202';

//2\\
DELETE FROM Client 
WHERE nom LIKE '%o%';
SELECT * FROM Client;

//3\\
DELETE FROM Sinistre;

//4\\
DROP TABLE Client;
DROP TABLE Vehicule;
DROP TABLE Sinistre;

SHOW TABLES;


SELECT * FROM Client;
SELECT * FROM Vehicule;
SELECT * FROM Sinistre;