-- phpMyAdmin SQL Dump
-- version 5.3.0-dev+20220429.4ad66f464f
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 01, 2022 at 06:11 AM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_nepalrailways`
--

-- --------------------------------------------------------

--
-- Table structure for table `admins`
--

CREATE TABLE `admins` (
  `ID` int(11) NOT NULL,
  `Name` varchar(40) NOT NULL,
  `Location` varchar(80) NOT NULL,
  `Age` int(11) NOT NULL,
  `Sex` varchar(8) NOT NULL,
  `Position` varchar(40) NOT NULL,
  `Qualification` varchar(120) DEFAULT NULL,
  `Password` varchar(80) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `admins`
--

INSERT INTO `admins` (`ID`, `Name`, `Location`, `Age`, `Sex`, `Position`, `Qualification`, `Password`) VALUES
(200, 'Manikk', 'Birgunj', 17, 'Male', 'HOD', 'Diploma', 'Hello@world'),
(202, 'Ashish Chauhan', 'Radhemai', 78, 'Other', 'Sweeper', 'Diploma', 'hello@ashish');

-- --------------------------------------------------------

--
-- Table structure for table `trains`
--

CREATE TABLE `trains` (
  `ID` int(11) NOT NULL,
  `Name` varchar(40) NOT NULL,
  `Start` varchar(40) NOT NULL,
  `Destiny` varchar(40) NOT NULL,
  `Total_Seats` int(11) NOT NULL,
  `Av_Seats` int(11) NOT NULL,
  `Cost` int(11) DEFAULT NULL,
  `Time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `trains`
--

INSERT INTO `trains` (`ID`, `Name`, `Start`, `Destiny`, `Total_Seats`, `Av_Seats`, `Cost`, `Time`) VALUES
(200, 'Manikk', 'Askj', 'sdjksdj', 200, 200, 200, '2022-04-26 05:06:00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admins`
--
ALTER TABLE `admins`
  ADD UNIQUE KEY `ID` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;



