-- https://github.com/jesimone57/sql_music_examples

DROP DATABASE IF EXISTS l2_music;
CREATE DATABASE IF NOT EXISTS l2_music DEFAULT CHARACTER SET utf8;
USE l2_music;

-- Album
CREATE TABLE album (
  id 	   bigint unsigned not null auto_increment,
  artist varchar(50) not null,
  name   varchar(50)  not null,
  year   int unsigned not null,
  PRIMARY KEY (id)
);

-- Album data
INSERT INTO album VALUES(1, 'Metallica', '...And Justice For All',1988);
INSERT INTO album VALUES(2, 'Metallica', 'Black Album',1991);
INSERT INTO album VALUES(3, 'Metallica', 'Master of Puppets',1986);
INSERT INTO album VALUES(4, 'Megadeth', 'Endgame',2009);
INSERT INTO album VALUES(5, 'Megadeth', 'Peace Sells',1986);
INSERT INTO album VALUES(6, 'Anthrax', 'The Greater of 2 Evils',2004);
INSERT INTO album VALUES(7, 'Eric Clapton', 'Reptile',2001);
INSERT INTO album VALUES(8, 'Eric Clapton', 'Riding with the King',2000);
INSERT INTO album VALUES(9, 'ZZ Top', 'Greatest Hits',1992);
INSERT INTO album VALUES(10, 'Van Halen', 'Greatest Hits',2004);
INSERT INTO album VALUES(11, 'Lynyrd Skynyrd', 'All-Time Greatest Hits',1975);
INSERT INTO album VALUES(12, 'AC/DC', 'Greatest Hits',2003);
INSERT INTO album VALUES(13, 'The Beatles', 'Sgt. Peppers Lonely Hearts Club Band', 1967);


-- Song table
CREATE TABLE song (
  id       bigint unsigned not null auto_increment,
  album_id bigint unsigned not null,
  name     varchar(50) not null,
  duration real not null,
  PRIMARY KEY (id),
  KEY fk_album_in_song (album_id),
  CONSTRAINT fk_album_in_song FOREIGN KEY (album_id) REFERENCES album (id),
  UNIQUE KEY uk_name_in_song (album_id, name)
);


-- Song data
INSERT INTO song VALUES(1,1,'One',7.25);
INSERT INTO song VALUES(2,1,'Blackened',6.42);

INSERT INTO song VALUES(3,2,'Enter Sandman',5.3);
INSERT INTO song VALUES(4,2,'Sad But True',5.29);

INSERT INTO song VALUES(5,3,'Master of Puppets',8.35);
INSERT INTO song VALUES(6,3,'Battery',5.13);

INSERT INTO song VALUES(7,4,'Dialectic Chaos',2.26);
INSERT INTO song VALUES(8,4,'Endgame',5.57);

INSERT INTO song VALUES(9,5,'Peace Sells',4.09);
INSERT INTO song VALUES(10,5,'The Conjuring',5.09);

INSERT INTO song VALUES(11,6,'Madhouse',4.26);
INSERT INTO song VALUES(12,6,'I am the Law',6.03);

INSERT INTO song VALUES(13,7,'Reptile',3.36);
INSERT INTO song VALUES(14,7,'Modern Girl',4.49);

INSERT INTO song VALUES(15,8,'Riding with the King',4.23);
INSERT INTO song VALUES(16,8,'Key to the Highway',3.39);

INSERT INTO song VALUES(17,9,'Sharp Dressed Man',4.15);
INSERT INTO song VALUES(18,9,'Legs',4.32);

INSERT INTO song VALUES(19,10,'Eruption',1.43);
INSERT INTO song VALUES(20,10,'Hot For Teacher',4.43);

INSERT INTO song VALUES(21,11,'Sweet Home Alabama',4.45);
INSERT INTO song VALUES(22,11,'Free Bird',14.23);

INSERT INTO song VALUES(23,12,'Thunderstruck',4.52);
INSERT INTO song VALUES(24,12,'T.N.T',3.35);

INSERT INTO song VALUES(25,13,'Sgt. Pepper''s Lonely Hearts Club Band', 2.0333);
INSERT INTO song VALUES(26,13,'With a Little Help from My Friends', 2.7333);
INSERT INTO song VALUES(27,13,'Lucy in the Sky with Diamonds', 3.4666);
INSERT INTO song VALUES(28,13,'Getting Better', 2.80);
INSERT INTO song VALUES(29,13,'Fixing a Hole', 2.60);
INSERT INTO song VALUES(30,13,'She''s Leaving Home', 3.5833);
INSERT INTO song VALUES(31,13,'Being for the Benefit of Mr. Kite!',2.6166);
INSERT INTO song VALUES(32,13,'Within You Without You',5.066);
INSERT INTO song VALUES(33,13,'When I''m Sixty-Four',2.6166);
INSERT INTO song VALUES(34,13,'Lovely Rita', 2.7);
INSERT INTO song VALUES(35,13,'Good Morning Good Morning', 2.6833);
INSERT INTO song VALUES(36,13,'Sgt. Pepper''s Lonely Hearts Club Band - Reprise', 1.3166);
INSERT INTO song VALUES(37,13,'A Day in the Life', 5.65);
