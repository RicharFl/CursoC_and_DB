

create database PRUEBA1; /*NOS CREA UNA BASE DE DATOS*/
use PRUEBA1; /* DESIMOS QUE QUEREMOS UTILIZAR LA BASE DE DATOS PRUEBA1*/

create table Alumnos(
NombreAlumno varchar(15) not null,
ApellidoAlumno varchar (15) not null,
BoletaAlumno int (10) not null,
Telefono varchar (11),
  primary key (BoletaAlumno)
    );

insert into Alumnos (NombreAlumno,ApellidoAlumno,BoletaAlumno,Telefono) values 
					("CARLOS1","RAMIREZ1",2016301912,55193657559),
                    ("CARLOS2","RAMIREZ2",2016301913,55193657559),
                    ("CARLOS3","RAMIRE3",2016301914,55193657559),
                    ("CARLOS4","RAMIRE4",2016301915,55193657559);
	
  select * from Alumnos;  /* Consulta  de la tabla Alumno */
 
  /* Consulta donde solo nos muestra 
 Los campos que se encuentran entre el Select y el From */
 select NombreAlumno,BoletaAlumno from Alumnos;   

    
                    
                    