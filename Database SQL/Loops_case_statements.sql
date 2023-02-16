-- PL/SQL Functions:-

-- Syntax
--CREATE [OR REPLACE] FUNCTION function_name 
--[(parameter_name [IN | OUT | IN OUT] type [, ...])] 
--RETURN return_datatype 
--{IS | AS} 
--BEGIN 
--   < function_body > 
--END [function_name];

-- Example:-
CREATE OR REPLACE FUNCTION my_count
RETURN NUMBER 
AS
total number(2) := 0;
BEGIN
    
    SELECT count(username) INTO total FROM game_scores;
    
    RETURN total;
END;    

-- Calling a function
DECLARE 
   c number(2); 
BEGIN 
   c := my_count(); 
   dbms_output.put_line('Total no. of User inside "game_score" table is : ' || c); 
END;

-- There is a different syntax for function that we dont want to store and only use once.
-- Example:-2


DECLARE 
   a number; 
   b number; 
   c number; 
   d number;
FUNCTION findMax(x IN number, y IN number)  
RETURN number 
IS 
    z number; 
BEGIN 
   IF x > y THEN 
      z:= x; 
   ELSE 
      Z:= y; 
   END IF;  
   RETURN z; 
END; 

FUNCTION findMin(x IN NUMBER, y IN NUMBER)
RETURN NUMBER
Is
    z number;
BEGIN
    IF x < y THEN
        z:= x;
    ELSE
        Z:= y;
    END IF;
    RETURN z;
END;
BEGIN 
   a:= 23; 
   b:= 45;  
   c := findMax(a, b); 
   d := findMin(a, b);
   dbms_output.put_line(' Maximum of (23,45): ' || c); 
      dbms_output.put_line(' Minimum of (23,45): ' || d); 
END;

-- Exception of case Statement is 'case_not_found' got raised when no when part got match the condition

-- Iteration statement
-- A loop executes the statements until it hit EXIT or an exception got raised
-- Example:-

DECLARE 
counter NUMBER:= 3;
BEGIN
 dbms_output.put_line('---loop begins counter of 3 ---');
 LOOP
    dbms_output.put_line('- counter:= ' || counter );
    counter := counter - 1;
    if counter < 1 THEN 
        EXIT;
    END IF;
END LOOP;
END;

-- We can also use EXIT WHEN to exit the loop.


DECLARE 
counter NUMBER:= 3;
BEGIN
 dbms_output.put_line('---loop begins counter of 3 ---');
 LOOP
    dbms_output.put_line('- counter:= ' || counter );
    counter := counter - 1;
    EXIT WHEN counter < 1;
END LOOP;
END;

-- 'continue' exit the loop for current iteration and get in for next iteration


DECLARE 
counter NUMBER:= 5;
BEGIN
 dbms_output.put_line('---loop begins counter of 5 ---');
 LOOP
    counter := counter - 1;
    CONTINUE WHEN counter = 3;
    dbms_output.put_line('- counter:= ' || counter );
    
    
    exit when counter < 1;
END LOOP;
END;

-- FOR loop, we can give range and execute it in sequence and in reverse format using "REVERSE" after IN part
BEGIN
 FOR i IN REVERSE 1..5 LOOP
     dbms_output.put_line('- counter:= ' || i );
 END LOOP;
 END;
 
-- -- WHILE LOOP
-- WHILE BOOL LOOP
--    LOGIC
--END LOOP; 

DECLARE 
    run BOOLEAN:= true;
    round NUMBER := 1;
BEGIN
    dbms_output.put_line('Inside the first loop');
    WHILE run LOOP
        dbms_output.put_line('- counter:= ' || round );
        round := round + 1;
        IF round > 5 THEN
            run := false;
        END IF;    
    END loop;
        dbms_output.put_line('Inside the Second loop');
    WHILE NOT run LOOP
        dbms_output.put_line('- counter:= ' || round );
        round := round - 1;
        if round < 1  THEN
            run := TRUE;
        END IF;    
    END loop;    
    
END;    