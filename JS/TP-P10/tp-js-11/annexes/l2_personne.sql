-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : ven. 12 mars 2021 à 06:50
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
-- Base de données : `l2_personnes`
--

-- --------------------------------------------------------

--
-- Structure de la table `Personne`
--

CREATE TABLE `Personne` (
  `ID` int(10) NOT NULL,
  `GENRE` enum('Homme','Femme','') COLLATE utf8mb4_bin NOT NULL,
  `NOM` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `PRENOM` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `AGE` int(3) NOT NULL,
  `LOGIN` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `MOTDEPASSE` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `PAYS` enum('ANGLETERRE','FRANCE','ETATS-UNIS','') COLLATE utf8mb4_bin NOT NULL,
  `NEWSLETTER` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `Personne`
--

INSERT INTO `Personne` (`ID`, `GENRE`, `NOM`, `PRENOM`, `AGE`, `LOGIN`, `MOTDEPASSE`, `PAYS`, `NEWSLETTER`) VALUES
(12, 'Homme', 'Morricone', 'Ennio', 89, 'morri', 'mdp123', 'ETATS-UNIS', 1),
(17, 'Homme', 'Coppola', 'Francis Ford', 79, 'ffcop', 'motdepasse', 'ANGLETERRE', 0),
(18, 'Homme', 'Morricone', 'Francis Ford', 79, 'enmo', '123456', 'FRANCE', 1);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Personne`
--
ALTER TABLE `Personne`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Personne`
--
ALTER TABLE `Personne`
  MODIFY `ID` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
