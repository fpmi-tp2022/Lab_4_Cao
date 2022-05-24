#pragma once
MYSQL mysql;
MYSQL_RES* res;
MYSQL_ROW row;

create table Universities(
    ID int PRIMARY KEY,
    NAME varchar(25),
    FOUNDATION int
);

create table Students(
    ID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    NAME varchar(25),
    University int,
    FOREIGN KEY(University) REFERENCES Universities(ID)
);
