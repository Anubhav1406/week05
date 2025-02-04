CREATE TABLE T1(
    Move_Number INT,
    Player CHAR(10),
    Piece CHAR(10),
    Start_Square CHAR(2),
    End_Square CHAR(2),
    Is_Capture TINYINT,
    Is_Castling TINYINT,
    Is_Check TINYINT,
    Is_Check_Mate TINYINT
);

--TASK_04

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Rook";

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Knight";

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Bishop";

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Queen";

SELECT * FROM T1
WHERE Player = "White" AND Piece = "King";

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Rook";

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Knight";

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Bishop";

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Queen";

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "King";

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1;

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1;

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1 AND Piece = "Rook";

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1 AND Piece = "Knight";

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1 AND Piece = "Bishop";

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1 AND Piece = "Queen";

SELECT COUNT(*) FROM T1
WHERE Player = "White" AND Is_Capture = 1 AND Piece = "King";

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1 AND Piece = "Rook";

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1 AND Piece = "Knight";

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1 AND Piece = "Bishop";

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1 AND Piece = "Queen";

SELECT COUNT(*) FROM T1
WHERE Player = "Black" AND Is_Capture = 1 AND Piece = "King";

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Rook" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Knight" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Bishop" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "White" AND Piece = "Queen" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Rook" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Knight" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Bishop" AND Is_Check = 1;

SELECT * FROM T1
WHERE Player = "Black" AND Piece = "Queen" AND Is_Check = 1;

SELECT * FROM T1
WHERE End_Square = "g1" AND Is_Castling = 1;

SELECT * FROM T1
WHERE End_Square = "c1" AND Is_Castling = 1;

SELECT * FROM T1
WHERE End_Square = "g8" AND Is_Castling = 1;

SELECT * FROM T1
WHERE End_Square = "c8" AND Is_Castling = 1;

--TASK-05

SELECT * FROM T1
WHERE End_Square = "d4" OR End_Square = "e4" OR End_Square = "d5" OR End_Square = "e5";