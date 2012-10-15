USE tp3;

Drop TABLE Stock;
Drop TABLE Commande;
Drop TABLE Client;
Drop TABLE Magazine;

CREATE TABLE Magazine (
	num_mag 
	nom VARCHAR(30) primary key,
	prix numeric(5)
);

CREATE TABLE Client (
	numero integer primary key,
	nom VARCHAR(30),
	prenom VARCHAR(30),
	ville VARCHAR(30)
);

CREATE TABLE Commande (
	numero_client integer,
	nom_mag VARCHAR(30),
	debut numeric(4),
	fin numeric(4),
	FOREIGN KEY numero_client REFERENCES Client(numero) ON DELETE CASCADE
);

CREATE TABLE Stock (
	nom_mag VARCHAR(30),
	numero numeric(4),
	nombre numeric(5),
	FOREIGN KEY nom_mag REFERENCES Magazine(nom) ON DELETE CASCADE
);

INSERT INTO Magazine(nom,prix) VALUES ('BD Hebdo',2);
INSERT INTO Magazine(nom,prix) VALUES ('Oraclemag',4);

INSERT INTO Client(numero,nom,prenom,ville) VALUES (10,'Lenoir','Herve','Angers');
INSERT INTO Client(numero,nom,prenom,ville) VALUES (5,'Rudoux','Patrick','Angers');
INSERT INTO Client(numero,nom,prenom,ville) VALUES (8,'Lebrun','Roland','Nantes');

INSERT INTO Commande(numero_client,nom_mag,debut,fin) VALUES ('8','BD Hebdo','60','60');
INSERT INTO Commande(numero_client,nom_mag,debut,fin) VALUES ('5','BD Hebdo','4','4');
INSERT INTO Commande(numero_client,nom_mag,debut,fin) VALUES ();

INSERT INTO Stock(nom_mag,numero,nombre,) VALUES ();
INSERT INTO Stock(nom_mag,numero,nombre,) VALUES ();	
INSERT INTO Stock(nom_mag,numero,nombre,) VALUES ();	