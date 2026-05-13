-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : jeu. 23 fév. 2023 à 11:01
-- Version du serveur : 10.10.2-MariaDB
-- Version de PHP : 8.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `l2_sportifs`
--

-- --------------------------------------------------------

--
-- Structure de la table `personne`
--

CREATE TABLE `personne` (
  `id_personne` int(11) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `prenom` varchar(20) DEFAULT NULL,
  `depart` int(2) NOT NULL,
  `mail` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `personne`
--

INSERT INTO `personne` (`id_personne`, `nom`, `prenom`, `depart`, `mail`) VALUES
(1, 'Bart', 'Jean', 59, 'jean.bart@en.guerre'),
(2, 'Surcouf', 'Robert', 66, 'surcouf@catch.me'),
(3, 'Azerty', '', 13, 'azerty@no.clue'),
(4, 'Do', 'You', 84, 'know@what'),
(5, 'Anywhere', 'Out', 99, 'of@the.world'),
(7, 'Jacques', '', 49, 'jacques@a.dit'),
(8, 'Mel', 'E', 49, 'm.a@i.l'),
(9, 'Loeb', 'Sébastien', 67, 'loeb@mille.lacs'),
(10, 'Prost', 'Alain', 6, 'prost@ffsa.fr');

-- --------------------------------------------------------

--
-- Structure de la table `pratique`
--

CREATE TABLE `pratique` (
  `id_personne` int(11) NOT NULL,
  `id_sport` int(11) NOT NULL,
  `niveau` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `pratique`
--

INSERT INTO `pratique` (`id_personne`, `id_sport`, `niveau`) VALUES
(2, 2, 3),
(2, 3, 3),
(4, 2, 3);

-- --------------------------------------------------------

--
-- Structure de la table `sport`
--

CREATE TABLE `sport` (
  `id_sport` int(11) NOT NULL,
  `design` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `sport`
--

INSERT INTO `sport` (`id_sport`, `design`) VALUES
(1, 'Badminton'),
(2, 'Tennis'),
(3, 'Tennis de table'),
(4, 'Volley-Ball'),
(5, 'Handball'),
(6, 'Football');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `personne`
--
ALTER TABLE `personne`
  ADD PRIMARY KEY (`id_personne`);

--
-- Index pour la table `pratique`
--
ALTER TABLE `pratique`
  ADD UNIQUE KEY `id_personne` (`id_personne`,`id_sport`);

--
-- Index pour la table `sport`
--
ALTER TABLE `sport`
  ADD PRIMARY KEY (`id_sport`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `personne`
--
ALTER TABLE `personne`
  MODIFY `id_personne` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `sport`
--
ALTER TABLE `sport`
  MODIFY `id_sport` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
