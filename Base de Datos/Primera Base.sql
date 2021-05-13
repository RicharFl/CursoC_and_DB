

create database PrimerBase;
use PrimerBase;

create table Alumno(
Nombre varchar (15) not null,
apellido  varchar (15) not null,
boleta int  (10),
telefono int (10),
primary key (boleta)
);

insert into Alumno (Nombre,apellido,boleta,telefono) values ("CARLOS","HERNANDEZ",2016148925,1234567891);
insert into Alumno (Nombre,apellido,boleta,telefono) values
 ("CARLOS2","HERNANDEZ",2016148926,1234567891),
  ("CARLOS3","HERNANDEZ",2016148927,1234567891),
   ("CARLOS4","HERNANDEZ",2016148928,1234567891);
   
   select * from Alumno;
   select Nombre,telefono from Alumno;
    