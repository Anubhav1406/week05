CREATE DATABASE week05 ;
use week05;

CREATE TABLE Chess(
    move_number INT,
    player CHAR(10),
    piece CHAR(10),
    start_square CHAR(2),
    end_square CHAR(2),
    is_capture TINYINT,
    is_castling TINYINT,
    is_check TINYINT,
    is_checkmate TINYINT,
    is_promoted CHAR -- if i would have declared it as tinyint i couldn't have retrieved the information of piece to which it is being promoted
);

SELECT *
FROM Chess
WHERE player="White" AND piece="Rook";

SELECT *
FROM Chess
WHERE player="White" AND piece="Knight";

SELECT *
FROM Chess
WHERE player="White" AND piece="Bishop";


SELECT *
FROM Chess
WHERE player="White" AND piece="Queen";

SELECT *
FROM Chess
WHERE player="White" AND piece="King";

SELECT *
FROM Chess
WHERE player="Black" AND piece="Rook";

SELECT *
FROM Chess
WHERE player="Black" AND piece="Knight";

SELECT *
FROM Chess
WHERE player="Black" AND piece="Bishop";


SELECT *
FROM Chess
WHERE player="Black" AND piece="Queen";

SELECT *
FROM Chess
WHERE player="Black" AND piece="King";

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1;

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1;

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1 AND piece="Rook";

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1 AND piece="Knight";

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1 AND piece="Bishop";

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1 AND piece="Queen";

SELECT COUNT(*)
FROM Chess
WHERE player="White" AND is_capture=1 AND piece="King";

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1 AND piece="Rook";

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1 AND piece="Knight";

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1 AND piece="Bishop";

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1 AND piece="Queen";

SELECT COUNT(*)
FROM Chess
WHERE player="Black" AND is_capture=1 AND piece="King";

SELECT *
FROM Chess
WHERE player="White" AND piece="Rook" AND is_check=1;

SELECT *
FROM Chess
WHERE player="White" AND piece="Knight" AND is_check=1;

SELECT *
FROM Chess
WHERE player="White" AND piece="Bishop" AND is_check=1;

SELECT *
FROM Chess
WHERE player="White" AND piece="Queen" AND is_check=1;

SELECT *
FROM Chess
WHERE player="Black" AND piece="Rook" AND is_check=1;

SELECT *
FROM Chess
WHERE player="Black" AND piece="Knight" AND is_check=1;

SELECT *
FROM Chess
WHERE player="Black" AND piece="Bishop" AND is_check=1;

SELECT *
FROM Chess
WHERE player="Black" AND piece="Queen" AND is_check=1;

SELECT *
FROM Chess
WHERE player="White" AND end_square="g1" AND is_castling=1;

SELECT *
FROM Chess
WHERE player="White" AND end_square="c1" AND is_castling=1;

SELECT *
FROM Chess
WHERE player="Black" AND end_square="g8" AND is_castling=1;

SELECT *
FROM Chess
WHERE player="Black" AND end_square="c8" AND is_castling=1;

SELECT *
FROM Chess
WHERE player="White" AND promoted='Q';

SELECT *
FROM Chess
WHERE player="White" AND promoted='R';

SELECT *
FROM Chess
WHERE player="White" AND promoted='N';

SELECT *
FROM Chess
WHERE player="White" AND promoted='B';

SELECT *
FROM Chess
WHERE player="Black" AND promoted='Q';

SELECT *
FROM Chess
WHERE player="Black" AND promoted='R';

SELECT *
FROM Chess
WHERE player="Black" AND promoted='N';

SELECT *
FROM Chess
WHERE player="Black" AND promoted='B';


--TASK 5(1)
SELECT * FROM Chess WHERE (ASCII(SUBSTRING(START_SQUARE, 1, 1)) - ASCII('a') + 1 + CAST(SUBSTRING(START_SQUARE, 2, 1) AS UNSIGNED)) % 2 = 0;

-- TASK 5(2)
SELECT *
FROM Chess
WHERE end_square="d4" OR end_square="d5" OR end_square="e4" OR end_square="e5";

-- TASK 5(3)
SELECT DISTINCT start_square FROM Chess
UNION
SELECT DISTINCT end_square FROM Chess;

-- TASK 5(4)
SELECT DISTINCT start_square
FROM Chess
WHERE start_square NOT IN(SELECT DISTINCT end_square FROM Chess);