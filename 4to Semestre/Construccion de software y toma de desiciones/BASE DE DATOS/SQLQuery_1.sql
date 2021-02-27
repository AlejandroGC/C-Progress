-- create table
-- Simple CREATE TABLE Syntax (common if not using options)
-- CREATE TABLE Player (
--     playerID int PRIMARY KEY CLUSTERED,
--     playerName varchar(30) NOT NULL,
--     nickName varchar(30) NULL,
--     role varchar(30) NULL,
--     level int NULL
-- );

-- CREATE TABLE Level (
--     levelID int PRIMARY KEY CLUSTERED,
--     level varchar(30) NOT NULL,
--     description varchar(50)
-- );

-- CREATE TABLE Role (
--     roleID int PRIMARY KEY CLUSTERED,
--     role varchar(30) NOT NULL,
--     type varchar(30)
-- );

-- CREATE TABLE Test(
--     testID int PRIMARY KEY CLUSTERED,
--     test varchar(30) NOT NULL,
-- );

-- DROP TABLE Test;

-- Modificando la tabla player
-- ALTER TABLE Player DROP COLUMN role, level;
-- ALTER TABLE Player ADD roleID int, levelID int;

--Haciendo llaves foraneas
-- ALTER TABLE Player ADD CONSTRAINT FK_Player_roleID FOREIGN KEY (roleID) REFERENCES Role(roleID);
-- ALTER TABLE Player ADD CONSTRAINT FK_Player_levelID FOREIGN KEY (levelID) REFERENCES Level(levelID);

-- INSERT INTO dbo.Role (
--     roleID,
--     role,
--     type
-- )
-- VALUES (
--     1001,
--     'Agente',
--     'Usuario'
-- ), (
--     1002,
--     'Gerente',
--     'Usuario'
-- ), (
--     1003,
--     'Admin',
--     'Admin'
-- )

--select * from dbo.role

-- INSERT INTO dbo.Level (
--     levelID,
--     level,
--     description
-- )
-- VALUES (
--     2001,
--     'Principiante',
--     'Principiante'
-- ), (
--     2002,
--     'Intermedio',
--     'Intermedio'
-- ), (
--     2003,
--     'Avanzado',
--     'Avanzado'
-- )

--select * from dbo.[Level]

-- INSERT INTO dbo.Player (
--     playerID,
--     playerName,
--     nickName,
--     roleID,
--     levelID
-- )
-- VALUES (
--     1,
--     'Pau',
--     'Pau',
--     1001,
--     2002
-- ), (
--     2,
--     'Dany',
--     'Dany',
--     1002,
--     2003
-- ), (
--     3,
--     'Ale',
--     'Ale',
--     1001,
--     2001
-- ), (
--     4,
--     'Hugo',
--     'Hugo',
--     1001,
--     2002
-- ), (
--     5,
--     'Paco',
--     'Paco',
--     1002,
--     2003
-- ), (
--     6,
--     'Luis',
--     'Luis',
--     1001,
--     2001
-- )

--select * from dbo.Player

-- Borrar query
--DELETE FROM dbo.Player WHERE nickName = 'Pau'; 

-- Consulta tabla de player

-- SELECT * from dbo.Player
-- SELECT playerName, nickName, role, type, level, description from Player join dbo.Role on Player.roleID = Role.roleID
-- join dbo.Level on Player.levelID = level.levelID