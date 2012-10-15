use tp3;

DROP TABLE commande;
DROP TABLE invendus;
DROP TABLE abonnement;
DROP TABLE client;
DROP TABLE magazine;

-- Creation
create table magazine(
	nom varchar(20) primary key,
	prix numeric(4,2)
);
create table client(
	numero integer primary key,
	prenom varchar(20),
	nom varchar(20),
	ville varchar(20)
);
create table abonnement(
	numeroclient integer,
	nommagazine varchar(20),
	echeance integer,
	constraint akey primary key(numeroclient, nommagazine),
	constraint fk_client foreign key(numeroclient) references client(numero),
	constraint fk_magazine foreign key(nommagazine) references magazine(nom)
);
create table invendus(
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	stock integer,
	constraint ikey primary key(nommagazine, numeromag)
);
create table commande(
	numeroclient integer references client(numero),
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	constraint cokey primary key(numeroclient, nommagazine, numeromag)
);

-- Insertion

insert into magazine values ('BD Hebdo', 2);
insert into magazine values ('Oraclemag', 4);
insert into magazine values ('Naruto', 6);
insert into client values (1, 'Thomas', 'Fraquet', 'Angers');
insert into client values (5, 'Patrick', 'Rudoux', 'Angers');
insert into client values (8, 'Roland','Lebrun', 'Nantes');
insert into client values (10, 'Herve','Lenoir', 'Angers');
insert into abonnement values (1, 'Oraclemag', 27);
insert into abonnement values (1, 'Naruto', 150);
insert into abonnement values (5, 'Oraclemag', 27);
insert into abonnement values (8, 'Oraclemag', 30);
insert into abonnement values (8, 'BD Hebdo', 78);
insert into commande values (1, 'Naruto', 4);
insert into commande values (5, 'BD Hebdo', 4);
insert into commande values (8, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 61);
insert into invendus values ('Naruto', 122, 50);
insert into invendus values ('BD Hebdo', 60, 10);
insert into invendus values ('BD Hebdo', 61, 3);
insert into invendus values ('Oraclemag', 22, 6);


select * from client;
select * from invendus;
select * from commande;
select * from abonnement;
select * from magazine;


-- Droits d'acces
-- 1
grant select on magazine to utiltest;
-- 2
grant select, update(echeance) on abonnement to utiltest;


-- Requêtes

-- 1
select count(distinct ville) 
from client join commande on numero=numeroclient 
where nommagazine = 'BD Hebdo';

-- 2
select nommagazine,count(*) as nb_abo 
from abonnement 
group by nommagazine order by nb_abo desc; 

-- 3
select numeroclient from commande natural join abonnement;

-- 4
select nom from client natural join
(select numero 
from client join abonnement on (numero=numeroclient) 
where ville = 'Nantes' 
group by numero having count(*) >= 2) as temp;

-- 5
select nom, prenom from client join abonnement on (client.numero=abonnement.numeroclient)
where numero not in (select numeroclient
from abonnement join commande using (nommagazine,numeroclient));

-- 6
select SUM(prix) 
from magazine join commande on magazine.nom=commande.nommagazine 
group by magazine.nom;

-- 7
select nom,prenom from abonnement join client on numeroclient=numero where (nommagazine,ville) in
(select abonnement.nommagazine,client.ville from abonnement join client on numeroclient=numero
 where nom='Rudoux' and prenom='Patrick') and nom <> 'Rudoux' and prenom <> 'Patrick';
 
-- 8
--select nom from client max()

select * from client;
select * from invendus;
select * from commande;
select * from abonnement;
select * from magazine;