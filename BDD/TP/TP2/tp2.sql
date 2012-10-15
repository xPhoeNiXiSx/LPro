Employe (id_emp, nom_emp, prenom_emp)
Projet (nom_proj, priorite, date_ech,id_emp,nb_emp)
Affecte (nom_proj, id_emp)

CREATE TABLE Membre (
	numero integer primary key auto_increment,
	nom varchar(20),
	prenom varchar(20),
	superieur integer,
);

CREATE TABLE Projet (
	nom varchar(10) primary key,
	priorite numeric(2),
	dirigeant integer,
	echeance date,
);

CREATE TABLE Affectation (
	employe integer,
	projet varchar(10),
	constraint akey primary key (employe, projet),
);

INSERT INTO Membre (
