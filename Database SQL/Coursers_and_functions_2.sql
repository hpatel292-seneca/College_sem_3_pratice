-- Coursers
--> it is use to process multiple lines of code.
--> a cursor is a pointer to an context area which contain the result of processed SQL statements.
--> TWO types of cursors
----> - Implicit coursors
---> - Explicit cursors

-- IMPLICIT COURSORS
--> this coursors are automatically created while a statment such as INSERT, UPDATE, DELELTE or SELECT are executed.
--> It is used to determine that if any row have been affected as a result of the execution of SQL statements
-- i.e
---> SQL%FOUND -> TRUE -> if atlease one row is affected by execution of DML statement
---> SQL%NOTFOUND -> TRUE -> if no row is affected by execution of DML statement
---> SQL%ROWCOUNT -> it returns the number of rows affected by execution of DML statement.
---> SQL%ISOPEN -> always return false as SQL always close an closure after execution of SQL statement.

--||-- explict cursor
-->Explicit cursors are programmer-defined cursors for gaining more control over the context area.
set SERVEROUTPUT on;
--EXAMPLE:-
DECLARE 
   c_score game_scores.score%type; 
   c_username game_scores.username%type; 

   CURSOR c_name is 
      SELECT username, score FROM game_scores; 
BEGIN 
   OPEN c_name; 
   LOOP 
-- We can fetch data row by row from a cursor using loop   
   FETCH c_name into c_username, c_score; 
      EXIT WHEN c_name%notfound; 
      dbms_output.put_line(c_username || ' ' || c_score); 
   END LOOP; 
   -- Always close cursor after the loop ends and closing means we are releasing the memore for cursor
   CLOSE c_name; 
END;


-- > explict cursor in for loop for example
DECLARE 
   c_score game_scores.score%type; 
   c_username game_scores.username%type; 

   CURSOR c_name is 
      SELECT username, score FROM game_scores; 
BEGIN  
   FOR item IN c_name 
   LOOP
-- We can fetch data row by row from a cursor using loop   
      dbms_output.put_line(item.username || ' ' || item.score); 
   END LOOP; 
   -- Always close cursor after the loop ends and closing means we are releasing the memore for cursor
   IF c_name%ISOPEN THEN
   CLOSE c_name;
   END IF;
END;

--||-- PL/SQL functions
--> SYNTAX
--CREATE [OR REPLACE] FUNCTION function_name 
--[(parameter_name [IN | OUT | IN OUT] type [, ...])] 
--RETURN return_datatype 
--{IS | AS} 
--BEGIN 
--   < function_body > 
--END [function_name];

CREATE OR REPLACE FUNCTION count_username
(tableName IN VARCHAR)
RETURN INT
AS
count_ins INT;
BEGIN
SELECT count(username) INTO count_ins FROM game_scores;
return count_ins;
END;


DECLARE
ab NUMBER := count_username('abc');
BEGIN
 dbms_output.put_line(ab);
END;

