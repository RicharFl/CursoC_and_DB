
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

 /* Creacion de Tabla Materias */

 DROP TABLE IF EXISTS  Materias;
create table Materias(
IdMateria varchar(10)not null,
NombreMateria varchar(15)not null,
primary key(IdMateria)
);



/* Creacion de Tabla PROFESORES */
 DROP TABLE IF EXISTS  PROFESORES;
create table PROFESORES(
    IdProfesor varchar(9)not null,
    Nombre varchar(15)not null,
    Apellido varchar(15)not null,
    primary key(IdProfesor)  
    );
            

                /* INSERTAR REGISTRO A NUESTRAS TABLAS YA CREADAS  */

 insert into PROFESORES(IdProfesor,Nombre,Apellido) values
					("CPF-4020","RICARDO","RAMIREZ"),
                    ("CPF-4021","JOSS","SANCHEZ"),
                    ("CPF-4022","CARMEN","QUIJANO"),
                    ("CPF-4023","ALEJANDRA","PORFIERO"),
                    ("CPF-4024","SANCHEZ","DIAZ");


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
                    
insert into Materias(IdMateria,NombreMateria) values
                    ("HF-402025","CALCULO"),
                    ("HF-402026","INGLES"),
                    ("HF-402027","FISICA"),
                    ("HF-402028","PROGRAMACION"),
                    ("HF-402029","BASE DE DATOS");            
                          
                  
                  
                  
                  
                  
           
                  
     

Select *from Profesores; /* Consulta  de la tabla Profesores */
select *from Materias;/* Consulta  de la tabla Materia */
select * from Alumnos;  /* Consulta  de la tabla Alumno */
 
  /* Consulta donde solo nos muestra 
 Los campos que se encuentran entre el Select y el From */
 select NombreAlumno,BoletaAlumno from Alumnos;   
 
 /* Consulta Completa denonando Tabla.Nombre del Campo */
select Alumnos.NombreAlumno,Alumnos.BoletaAlumno,Alumnos.BoletaAlumno,Alumnos.Telefono,Alumnos.edad from Alumnos; 


/* EJEMPLOS DE CONSULTA USANDO distinct  */

select distinct  NombreAlumno from Alumnos;
select distinct  edad,NombreAlumno from Alumnos;
select distinct edad from Alumnos;

/* EJEMPLOS DE CONSULTA USANDO between   */
select *from Alumnos where edad between 16  and 21;

select *from Alumnos where edad between 20  and 22;

/* EJEMPLOS DE CONSULTA USANDO Where   */
select *from Alumnos Where edad =18;        
                  
/*Desarrolla una consulta que me devuelva los alumnos que sean mayores de 20 años.*/
    select *from Alumnos where edad>=20;
                  
/*GENERA UNA CONSULTA QUE ME RETORNE  SOLO LA MATERIA DE INGLES  */ 
   select *from Materias where NombreMateria="INGLES";
/*GENERA UNA CONSULTA QUE ME RETORNE  EL REGISTRO DE DEL ALUUMNO CARLOS2    */
select *from Alumnos where NombreAlumno="CARLOS2";
/*GENERA UNA CONSULTA QUE ME RETORNE  EL REGISTRO DE DEL ALUUMNO 2016301912 solo me muestre Nombre y Bolete*/
select NombreAlumno,BoletaAlumno from Alumnos where BoletaAlumno=2016301912;
/*GENERA UNA CONSULTA QUE ME RETORNE  EL REGISTRO DE DEL ALUUMNO 2016301912 y
 2016301915 solo me muestre Nombre y Bolete*/
 SELECT Alumnos.NombreAlumno, Alumnos.BoletaAlumno from Alumnos 
 where BoletaAlumno=2016301912 or BoletaAlumno=2016301913 ;
select *from Alumnos;
 /*Genera una consulta que Retorne la materia con id -> HF-402025 */
 select  *from Materias where IdMateria="HF-402025";
 /* Genera una consulta que Retorne los alumnos que sean mayores a 21 y excluya alos de 25 
*/ 
select *from Alumnos where edad >21 and edad <> 25;






/* ----------------------CREACION DE UNA TABLA USANDO LLAVES FORANEAS --------------------------- */

create table Horario(
	IdHorio int (10),
    BoletaIdHorario int (10) not null,
    IdMateriaHorario varchar(10)not null,
    IdProfesorHorario varchar (9) not null,
    primary key (IdHorio),
    foreign key (BoletaIdHorario) references Alumnos (BoletaAlumno),
    foreign key  (IdMateriaHorario) references Materias (IdMateria),
    foreign key (IdProfesorHorario) references Profesores (IdProfesor)
);

insert into horario (IdHorio,BoletaIdHorario,IdMateriaHorario,IdProfesorHorario) values 
(1,2016301921,"HF-402028","CPF-4021");
select *from Horario;
