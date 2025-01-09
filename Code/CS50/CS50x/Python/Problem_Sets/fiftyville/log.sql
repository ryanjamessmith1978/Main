-- Keep a log of any SQL queries you execute as you solve the mystery.
-- keep a log of all SQL queries that you run on the database.
-- above each query, label each with a comment describing why you’re running the query

-- Stole a CS50 ducky
-- Took place on July 28th
-- Took place on Humphrey Street
-- Who stole the duck?
-- Where did the thief escape to?
-- Who is the accomplish that helped thief escape?

-- Doing a query in crime_scene_reports table to find a description based on the information given in PSET
-- SELECT description FROM crime_scene_reports
-- WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Time Frame: 10:15am
-- At the bakery
-- 3 witnesses
-- Literring at 4:36pm

-- Query on the transcript from the witnesses on the day of the crime
--SELECT transcript FROM interviews
--WHERE month = 7 AND day >= 28;

-- Left bakery between 1015 and 1025
-- Made a minute phone call during that timespan
-- earliest flight out of Fiftyville tomorrow (7.29) - accomplish buying ticket
-- ATM on Leggett Street earlier in the day on 28th

-- Mr. Windibank came back from France
-- Irene Adler papers
-- German accent. “I told you that I would call!"

-- Query for Bakery security cameras between 1015am and 1025am
--SELECT license_plate FROM bakery_security_logs
-- WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;
--5P2BI95 94KL13X 6P58WS2 4328GD8 G412CB7 L93JTIZ 322W7JE 0NTHK55 | License Plates


-- Query for Activity and Plates at the bakery between 915 and 1025
-- SELECT license_plate FROM bakery_security_logs
-- HERE month = 7 AND day = 28 AND hour = 10 AND minute < 15;

-- Plates between 915 - 10
-- 6P58WS2  | enters bakery | leaves bakery between 1015 and 1025
-- G412CB7 | enters bakery  | leaves bakery between 1015 and 1025

-- SELECT minute FROM bakery_security_logs
-- WHERE month = 7 AND day = 28 AND hour = 9 AND license_plate = '6P58WS2'; -- 920 to 1018
-- WHERE month = 7 AND day = 28 AND hour = 10 AND license_plate = 'G412CB7' -- 928 to 1020

-- query the atm transactions
-- follow the money
--SELECT name, phone_number, passport_number, license_plate FROM people
--WHERE id IN (SELECT person_id FROM bank_accounts
--WHERE account_number IN
--(SELECT account_number FROM atm_transactions
--WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND transaction_type = 'withdraw'));

--SELECT account_number, transaction_type FROM atm_transactions
--WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND
--transaction_type = 'withdraw'

/* One of These people
|  name   |  phone_number  | passport_number | license_plate |
+---------+----------------+-----------------+---------------+
| Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
| Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
| Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       |
| Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| Bruce   | (367) 555-5533 | 5773159633      | 94KL13X

Lic Plates that left the diner between 1015 and 1025
4328GD8 - LUCA
322W7JE - Diana
*/

SELECT passport_number FROM people
WHERE people.phone_number IN
(SELECT phone_number FROM people
WHERE people.license_plate IN
(SELECT license_plate FROM people
WHERE people.phone_number IN (SELECT phone_number FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND transaction_type = 'withdraw')))
INTERSECT
SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)
INTERSECT
SELECT caller FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60
INTERSECT
SELECT phone_number FROM people
WHERE people.license_plate IN
(SELECT license_plate FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))))
INTERSECT
SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT flights.id FROM flights, airports
WHERE airports.id = (SELECT id FROM airports
WHERE city = 'Fiftyville') AND month = 7 AND day = 29);

SELECT * FROM people
WHERE people.passport_number = 5773159633;
-- BRUCE

SELECT * FROM people
WHERE people.phone_number IN
(SELECT receiver FROM phone_calls
WHERE caller = '(367) 555-5533' AND
day = 28 AND month = 7 AND duration < 60); -- (375) 555-8161
-- Robin

SELECT flights.id, destination_airport_id FROM flights, airports
WHERE airports.id = (SELECT id FROM airports
WHERE city = 'Fiftyville') AND month = 7 AND day = 29;

SELECT city FROM airports
WHERE id = 4;

/*
SELECT passport_number FROM passengers
WHERE flight_id = 36;

--3592750733

SELECT city FROM airports
WHERE id IN (SELECT destination_airport_id FROM flights
WHERE id IN (SELECT flights.id FROM flights, airports
WHERE airports.id = (SELECT id FROM airports
WHERE city = 'Fiftyville') AND month = 7 AND day = 29));