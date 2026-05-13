-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : ven. 12 mars 2021 à 06:49
-- Version du serveur :  5.7.20
-- Version de PHP : 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `l2mpcie_cc_19_php_pret`
--

-- --------------------------------------------------------

--
-- Structure de la table `CREDIT`
--

CREATE TABLE `CREDIT` (
  `ID` int(11) NOT NULL,
  `PRET` enum('auto','habitat') COLLATE utf8mb4_bin NOT NULL,
  `DUREE` int(11) NOT NULL,
  `TAUX` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `CREDIT`
--

INSERT INTO `CREDIT` (`ID`, `PRET`, `DUREE`, `TAUX`) VALUES
(1, 'auto', 12, 3.75),
(2, 'auto', 24, 3.75),
(3, 'auto', 36, 3.7),
(4, 'auto', 48, 3.7),
(5, 'auto', 60, 3.65),
(6, 'habitat', 12, 2.9),
(7, 'habitat', 24, 2.9),
(8, 'habitat', 36, 2.85),
(9, 'habitat', 48, 2.85),
(10, 'habitat', 60, 2.8);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `CREDIT`
--
ALTER TABLE `CREDIT`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `CREDIT`
--
ALTER TABLE `CREDIT`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
