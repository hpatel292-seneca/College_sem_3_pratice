-- Praticing the PL/SQL procedure and Function

-- tableName.ColumnName%type gives me the datatype of that paticular column.
-- RUN TIME EXCEPTION 'no_data_found' will catch no data found error
-- 'too_many_rows' exception is raised if using SELECT INTO which return more than one row of data
-- WHEN OTHER part in EXCEPTION is used to catch every error 
SET SERVEROUTPUT ON;
DECLARE 
   c_id customer.id%type := 80; 
   c_name customer.Name%type; 
BEGIN 
   SELECT  name INTO  c_name 
   FROM customer 
   WHERE id = c_id;  
   DBMS_OUTPUT.PUT_LINE ('Name: '||  c_name); 

EXCEPTION 
   WHEN no_data_found THEN 
      dbms_output.put_line('No such customer!'); 
   WHEN others THEN 
      dbms_output.put_line('Error!'); 
END;

-- 2) Rasing Exceptions
--> The cammand that is used to raise an EXCEPTION is RAISE
-- Example:- 1
DECLARE
    my_except EXCEPTION;
BEGIN
    IF 10 = 11 THEN
        RAISE my_except;
    END IF;
EXCEPTION
    WHEN my_except THEN
         dbms_output.put_line('Custom Exception Raised');
    WHEN others THEN
         dbms_output.put_line('Other Exception'); 
END;      

-- Example :- 2 
CREATE OR REPLACE PROCEDURE my_procedure(custID IN customer.id%type) 
AS
    c_name customer.name%type;
    c_id customer.id%type := custID;
    c_email customer.email%type;
BEGIN
    SELECT name, email INTO c_name, c_email FROM customer WHERE id = c_id;
     dbms_output.put_line('Name' || c_name);
     dbms_output.put_line('Email' || c_email);
EXCEPTION
    WHEN no_data_found THEN
        dbms_output.put_line('No data matched With that ID');
    WHEN too_many_rows THEN
        dbms_output.put_line('Multiple data has been found');
    WHEN OTHERS THEN
        dbms_output.put_line('General Error');
END;    
BEGIN
    my_procedure(100);
END;    

-- For more exception visit this link :- https://www.tutorialspoint.com/plsql/plsql_exceptions.html


-- PARAMETER in procedure 
-- it is of IN/OUT/IN OUT type
-- IN is used to get the value in the procedure while OUT is used to bring value from the procedure to outside
--Example for Out Procedure
CREATE OR REPLACE PROCEDURE my_score(user_name IN game_scores.username%type, user_score OUT game_scores.score%type)
AS
BEGIN
    SELECT score INTO user_score FROM game_scores WHERE username = user_name;
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('General Error');
END;        

DECLARE
    user_name game_scores.username%type := 'nan55';
    user_score game_scores.score%type;
BEGIN
    my_score(user_name, user_score);
    dbms_output.put_line('The score of the username ' || user_name || ' is ' || user_score );
end;    

-- So, OUT parameter is used to get the value out from the procedure.


-- UPDATE or DELETE 
-- so we can also perform update or delete query inside the procedure 
CREATE OR REPLACE PROCEDURE my_score(user_name IN game_scores.username%type, user_score IN game_scores.score%type)
AS 
actual_score game_scores.score%type; 
BEGIN
    SELECT score INTO actual_score FROM game_scores WHERE username = user_name;
    IF user_score > actual_score THEN
        UPDATE game_scores SET score = user_score WHERE username = user_name;
        dbms_output.put_line('User score updated');
    ELSE
        dbms_output.put_line('User score did not updated as the actual score is more than current score');
    END IF;    
EXCEPTION
    WHEN no_data_found THEN
        dbms_output.put_line('There is no user present in the "game_score" table with this username');
    WHEN OTHERS THEN
        dbms_output.put_line('General Error');
END;
BEGIN
    my_score('nan55', 2000);
end; 


-- If your are deleting something, so how to find if the thing got deleted or not??
-- so we can use this 'SQL%ROWCOUNT == 0' if this return 'TRUE' then, it means that it didn't delete the data
-- So if 'SQL%ROWCOUNT == 1' means one row is deleted.
-- so we can check the condition right after the DELETE query and BY this way we can validate the DELETION.

-- So there is AN IF ELSE ladder in SQL as Well
-- IF THEN
-- ELSIF THEN
-- ELSIF THEN
-- ELSE
-- END IF

-- Example:-

DECLARE
    c_username game_scores.username%type := 'nan55';
BEGIN
    DELETE FROM game_scores WHERE username = c_username;
    IF SQL%ROWCOUNT = 0 THEN
        dbms_output.put_line('There is no data found with that username');
    ELSIF SQL%ROWCOUNT = 1 THEN
        dbms_output.put_line('One record has been deleted from the table "game_scores".');
    ELSE
        dbms_output.put_line('More than one reocord has been DELETED from table');
    END IF;
END;        

