-- Week-1 
-- Select statement in SQL
SELECT * 
FROM contacts
WHERE contact_id = 10;

-- Quotes in SQL
-- single quotes ''
SELECT * 
FROM contacts
WHERE first_name = 'Charlie';

-- double quotes "" use to define table name
SELECT first_name AS "First Name"
FROM contacts
WHERE contact_id = 10;

-- Distinct
SELECT DISTINCT * 
FROM contacts;

-- INSERT tpyes
INSERT INTO contacts (contact_id, first_name, last_name, email, phone, customer_id)
VALUES (1000, 'Harshil', 'Patel', 'harshil@gmail.com', 1234567890, 10);


INSERT INTO contacts VALUES (1001, 'Harshil', 'Patel', 'harshil@gmail.com', 1234567890, 10);

-- Inserting multiple lines
INSERT ALL
INTO contacts VALUES (1002, 'Harshil', 'Patel', 'harshil@gmail.com', 1234567890, 10)
INTO contacts VALUES (1003, 'Harshil', 'Patel', 'harshil@gmail.com', 1234567890, 10)
INTO contacts VALUES (1004, 'Harshil', 'Patel', 'harshil@gmail.com', 1234567890, 10)
select * from dual;

-- UPDATE
UPDATE contacts 
SET first_name = 'Harshiliya'
WHERE contact_id = 1004;

-- DELETE
DELETE FROM contacts
WHERE contact_id = 1004;