
drop database if exists PRUEBA1;
create database PRUEBA1; /*NOS CREA UNA BASE DE DATOS*/
use PRUEBA1; /* DESIMOS QUE QUEREMOS UTILIZAR LA BASE DE DATOS PRUEBA1*/

DROP TABLE IF EXISTS  Alumnos;
create table Alumnos(
NombreAlumno varchar(15) not null,
ApellidoAlumno varchar (15) not null,
BoletaAlumno int (10) not null,
Telefono varchar (11),
edad int (2) not null,
  primary key (BoletaAlumno)
    );

insert into Alumnos (NombreAlumno,ApellidoAlumno,BoletaAlumno,Telefono,edad) values 
					("CARLOS1","RAMIREZ1",2016301912,55193657559,15),
                    ("CARLOS2","RAMIREZ2",2016301913,55193657559,18),
                    ("CARLOS3","RAMIRE3",2016301914,55193657559,23),
                    ("MARIANA","RAMIRE3",2016301921,55193657559,19),
                    ("SAMANTA","RAMIRE3",2016301922,55193657559,19),
                    ("JUAN","RAMIRE3",2016301923,55193657559,22),
                    ("EDGAR","RAMIRE3",2016301924,55193657559,20),
                    ("RICARDO","RAMIRE3",2016301925,55193657559,18),
                    ("ALEXIS","RAMIRE3",2016301926,55193657559,17),
                    ("CARLOS4","RAMIRE4",2016301927,55193657559,25),
                    ("CARLOS4","RAMIRE4",2016301929,55193657559,25);
	
  select * from Alumnos;  /* Consulta  de la tabla Alumno */
 
  /* Consulta donde solo nos muestra 
 Los campos que se encuentran entre el Select y el From */
 select NombreAlumno,BoletaAlumno from Alumnos;   
 
select Alumnos.NombreAlumno,Alumnos.BoletaAlumno,Alumnos.BoletaAlumno,Alumnos.Telefono,Alumnos.edad from Alumnos; 
select distinct  NombreAlumno from Alumnos;
select distinct  edad,NombreAlumno from Alumnos;

select *from Alumnos Where edad =18;
select *from Alumnos where edad between 16  and 21;
                    
                    