

create database Practica1;
use Practica1;

create table Alumnos(
NombreAlumno varchar (15) not null,
ApellidoAlumno varchar(15) not null,
Boleta int (10) not null,
Telefono varchar (12) not null,
primary key(Boleta)
);

insert into Alumnos (NombreAlumno,ApellidoAlumno,Boleta) values 
("Jose","Ramirez",2016301976);

select *from Alumnos;
select * from Alumnos where Boleta=2016301978;
select * from Alumnos where NombreAlumno="Jose";