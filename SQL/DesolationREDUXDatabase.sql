-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema desolationredux
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema desolationredux
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `desolationredux` DEFAULT CHARACTER SET utf8 ;
USE `desolationredux` ;

-- -----------------------------------------------------
-- Table `desolationredux`.`world`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`world` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `name` VARCHAR(45) NULL COMMENT '',
  `map` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  UNIQUE INDEX `uuid_UNIQUE` (`uuid` ASC)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`player`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`player` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `steamid` BIGINT NOT NULL COMMENT '',
  `battleyeid` VARCHAR(32) NULL COMMENT '',
  `firstlogin` TIMESTAMP NULL COMMENT '',
  `firstnick` VARCHAR(45) NULL COMMENT '',
  `lastlogin` TIMESTAMP NULL COMMENT '',
  `lastnick` VARCHAR(45) NULL COMMENT '',
  `bancount` INT NULL DEFAULT 0 COMMENT '',
  `banreason` VARCHAR(100) NULL COMMENT '',
  `banbegindate` TIMESTAMP NULL COMMENT '',
  `banenddate` TIMESTAMP NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  UNIQUE INDEX `uuid_UNIQUE` (`uuid` ASC)  COMMENT '',
  UNIQUE INDEX `steamid_UNIQUE` (`steamid` ASC)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`death_persistent_variables`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`death_persistent_variables` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `persistentvariables` TEXT NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`charactershareables`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`charactershareables` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `classname` VARCHAR(45) NOT NULL COMMENT '',
  `hitpoints` TEXT NULL COMMENT '',
  `variables` TEXT NULL COMMENT '',
  `death_persistent_variables_uuid` BINARY(16) NOT NULL COMMENT '',
  `textures` TEXT NULL COMMENT '',
  `inventoryuniform` TEXT NULL COMMENT '',
  `inventoryvest` TEXT NULL COMMENT '',
  `inventorybackpack` TEXT NULL COMMENT '',
  `uniform` VARCHAR(45) NULL COMMENT '',
  `vest` VARCHAR(45) NULL COMMENT '',
  `backpack` VARCHAR(45) NULL COMMENT '',
  `headgear` VARCHAR(45) NULL COMMENT '',
  `googles` VARCHAR(45) NULL COMMENT '',
  `primaryweapon` TEXT NULL COMMENT '',
  `secondaryweapon` TEXT NULL COMMENT '',
  `handgun` TEXT NULL COMMENT '',
  `tools` TEXT NULL COMMENT '',
  `currentweapon` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  INDEX `fk_charactershareables_death_persistant_variables_uuid_idx` (`death_persistent_variables_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_charactershareables_death_persistant_variables`
    FOREIGN KEY (`death_persistent_variables_uuid`)
    REFERENCES `desolationredux`.`death_persistent_variables` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`character`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`character` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `animationstate` TEXT NULL COMMENT '',
  `direction` FLOAT NULL DEFAULT 0 COMMENT '',
  `positiontype` INT NULL DEFAULT 0 COMMENT '',
  `positionx` FLOAT NULL DEFAULT 0 COMMENT '',
  `positiony` FLOAT NULL DEFAULT 0 COMMENT '',
  `positionz` FLOAT NULL DEFAULT 0 COMMENT '',
  `charactershareables_uuid` BINARY(16) NOT NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  UNIQUE INDEX `uuid_UNIQUE` (`uuid` ASC)  COMMENT '',
  INDEX `playershareables_uuid_idx` (`charactershareables_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_character_charactershareables`
    FOREIGN KEY (`charactershareables_uuid`)
    REFERENCES `desolationredux`.`charactershareables` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`object`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`object` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `classname` VARCHAR(45) NOT NULL COMMENT '',
  `priority` INT NOT NULL COMMENT '',
  `timecreated` TIMESTAMP NOT NULL COMMENT '',
  `timelastused` TIMESTAMP NOT NULL DEFAULT NOW() COMMENT '',
  `visible` TINYINT(1) NULL DEFAULT 1 COMMENT '',
  `accesscode` VARCHAR(45) NULL COMMENT '',
  `locked` TINYINT(1) NULL DEFAULT 0 COMMENT '',
  `player_uuid` BINARY(16) NULL COMMENT '',
  `hitpoints` TEXT NULL COMMENT '',
  `health` TEXT NULL COMMENT '',
  `damage` FLOAT NULL DEFAULT 0 COMMENT '',
  `fuel` FLOAT NULL DEFAULT 1 COMMENT '',
  `fuelcargo` FLOAT NULL DEFAULT 0 COMMENT '',
  `repaircargo` FLOAT NULL DEFAULT 0 COMMENT '',
  `items` TEXT NULL COMMENT '',
  `magazines` TEXT NULL COMMENT '',
  `weapons` TEXT NULL COMMENT '',
  `backpacks` TEXT NULL COMMENT '',
  `magazinesturret` TEXT NULL COMMENT '',
  `variables` TEXT NULL COMMENT '',
  `animationstate` TEXT NULL COMMENT '',
  `textures` TEXT NULL COMMENT '',
  `direction` FLOAT NULL DEFAULT 0 COMMENT '',
  `positiontype` INT NULL DEFAULT 0 COMMENT '',
  `positionx` FLOAT NULL DEFAULT 0 COMMENT '',
  `positiony` FLOAT NULL DEFAULT 0 COMMENT '',
  `positionz` FLOAT NULL DEFAULT 0 COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  UNIQUE INDEX `uuid_UNIQUE` (`uuid` ASC)  COMMENT '',
  INDEX `fk_objects_player1_idx` (`player_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_objects_player1`
    FOREIGN KEY (`player_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`world_is_linked_to_world`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`world_is_linked_to_world` (
  `world_uuid1` BINARY(16) NOT NULL COMMENT '',
  `world_uuid2` BINARY(16) NOT NULL COMMENT '',
  PRIMARY KEY (`world_uuid1`, `world_uuid2`)  COMMENT '',
  INDEX `world_uuid2_idx` (`world_uuid2` ASC)  COMMENT '',
  INDEX `world_uuid1_idx` (`world_uuid1` ASC)  COMMENT '',
  CONSTRAINT `fk_world_is_linked_to_world_worlds1`
    FOREIGN KEY (`world_uuid1`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_world_is_linked_to_world_worlds2`
    FOREIGN KEY (`world_uuid2`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`killinfo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`killinfo` (
  `uuid` BINARY(16) NOT NULL COMMENT '',
  `date` TIMESTAMP NOT NULL COMMENT '',
  `attacker_uuid` BINARY(16) NULL COMMENT '',
  `type` VARCHAR(45) NULL COMMENT '',
  `weapon` VARCHAR(45) NULL COMMENT '',
  `distance` FLOAT NULL COMMENT '',
  PRIMARY KEY (`uuid`)  COMMENT '',
  INDEX `fk_killinfo_user1_idx` (`attacker_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_killinfo_user1`
    FOREIGN KEY (`attacker_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`world_has_objects`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`world_has_objects` (
  `world_uuid` BINARY(16) NOT NULL COMMENT '',
  `object_uuid` BINARY(16) NOT NULL COMMENT '',
  `killinfo_uuid` BINARY(16) NULL COMMENT '',
  `parentobject_uuid` BINARY(16) NULL COMMENT '',
  PRIMARY KEY (`world_uuid`, `object_uuid`)  COMMENT '',
  INDEX `fk_object_uuid_idx` (`object_uuid` ASC)  COMMENT '',
  INDEX `fk_world_uuid_idx` (`world_uuid` ASC)  COMMENT '',
  INDEX `fk_killinfo_uuid_idx` (`killinfo_uuid` ASC)  COMMENT '',
  INDEX `fk_parentobjects_uuid_idx` (`parentobject_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_worlds_has_objects_world`
    FOREIGN KEY (`world_uuid`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_worlds_has_objects_object`
    FOREIGN KEY (`object_uuid`)
    REFERENCES `desolationredux`.`object` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_worlds_has_objects_killinfo`
    FOREIGN KEY (`killinfo_uuid`)
    REFERENCES `desolationredux`.`killinfo` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_worlds_has_objects_parentobject`
    FOREIGN KEY (`parentobject_uuid`)
    REFERENCES `desolationredux`.`object` (`uuid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`player_on_world_has_character`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`player_on_world_has_character` (
  `player_uuid` BINARY(16) NOT NULL COMMENT '',
  `world_uuid` BINARY(16) NOT NULL COMMENT '',
  `character_uuid` BINARY(16) NOT NULL COMMENT '',
  `killinfo_uuid` BINARY(16) NULL COMMENT '',
  PRIMARY KEY (`player_uuid`, `world_uuid`, `character_uuid`)  COMMENT '',
  INDEX `character_uuid_idx` (`character_uuid` ASC)  COMMENT '',
  INDEX `world_uuid_idx` (`world_uuid` ASC)  COMMENT '',
  INDEX `player_uuid_idx` (`player_uuid` ASC)  COMMENT '',
  INDEX `killinfo_uuid_idx` (`killinfo_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_player_on_world_has_character_world`
    FOREIGN KEY (`world_uuid`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_player_on_world_has_character_character`
    FOREIGN KEY (`character_uuid`)
    REFERENCES `desolationredux`.`character` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_player_on_world_has_character_player`
    FOREIGN KEY (`player_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_player_on_world_has_character_killinfo`
    FOREIGN KEY (`killinfo_uuid`)
    REFERENCES `desolationredux`.`killinfo` (`uuid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`player_is_friend_with_player`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`player_is_friend_with_player` (
  `player1_uuid` BINARY(16) NOT NULL COMMENT '',
  `player2_uuid` BINARY(16) NOT NULL COMMENT '',
  PRIMARY KEY (`player1_uuid`, `player2_uuid`)  COMMENT '',
  INDEX `player2_uuid_idx` (`player2_uuid` ASC)  COMMENT '',
  INDEX `player1_uuid_idx` (`player1_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_player_is_friend_with_player_player1`
    FOREIGN KEY (`player1_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_player_is_friend_with_player_player2`
    FOREIGN KEY (`player2_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`player_on_world_has_death_persistent_variables`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`player_on_world_has_death_persistent_variables` (
  `player_uuid` BINARY(16) NOT NULL COMMENT '',
  `world_uuid` BINARY(16) NOT NULL COMMENT '',
  `death_persistent_variables_uuid` BINARY(16) NOT NULL COMMENT '',
  PRIMARY KEY (`player_uuid`, `world_uuid`, `death_persistent_variables_uuid`)  COMMENT '',
  INDEX `fk_death_persistant_variables_uuid_idx` (`death_persistent_variables_uuid` ASC)  COMMENT '',
  INDEX `fk_player_uuid_idx` (`player_uuid` ASC)  COMMENT '',
  INDEX `fk_world_uuid_idx` (`world_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_p_o_w_has_death_persistant_variables_player`
    FOREIGN KEY (`player_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_p_o_w_has_death_persistant_variables_death_persistant_var`
    FOREIGN KEY (`death_persistent_variables_uuid`)
    REFERENCES `desolationredux`.`death_persistent_variables` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_p_o_w_has_death_persistant_variables_worlds`
    FOREIGN KEY (`world_uuid`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `desolationredux`.`whitelist`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `desolationredux`.`whitelist` (
  `world_uuid` BINARY(16) NOT NULL COMMENT '',
  `player_uuid` BINARY(16) NOT NULL COMMENT '',
  PRIMARY KEY (`world_uuid`, `player_uuid`)  COMMENT '',
  INDEX `player_uuid_idx` (`player_uuid` ASC)  COMMENT '',
  INDEX `world_uuid_idx` (`world_uuid` ASC)  COMMENT '',
  CONSTRAINT `fk_whitelist_world`
    FOREIGN KEY (`world_uuid`)
    REFERENCES `desolationredux`.`world` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_wwhitelist_player`
    FOREIGN KEY (`player_uuid`)
    REFERENCES `desolationredux`.`player` (`uuid`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

USE `desolationredux` ;

-- -----------------------------------------------------
-- View `desolationredux`.`characterview`
-- -----------------------------------------------------
USE `desolationredux`;
CREATE  OR REPLACE VIEW `characterview` AS
SELECT `character`.`uuid`, `animationstate`, `direction`, `positiontype`, `positionx`,
 	`positiony`, `positionz`, `classname`, `hitpoints`, `variables`, `persistentvariables`, `textures`, `inventoryuniform`,
 	`inventoryvest`, `inventorybackpack`, `uniform`, `vest`, `backpack`, `headgear`, `googles`, 
	`primaryweapon`, `secondaryweapon`, `handgun`, `tools`, `currentweapon`
FROM `character`
INNER JOIN `charactershareables`
ON `character`.`charactershareables_uuid` = `charactershareables`.`uuid`
INNER JOIN `death_persistent_variables`
ON `charactershareables`.`death_persistent_variables_uuid` = `death_persistent_variables`.`uuid`;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
