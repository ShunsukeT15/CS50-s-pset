-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE day=28 AND month=7 AND street= "Chamberlin Street";
/*
description
Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
*/

SELECT transcript
FROM interviews
WHERE day=28 AND month=7 AND year=2020;
/*
Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

--who drive away in the courthouse parking within 10 minutes of the theft

 SELECT activity TEXT FROM courthouse_security_logs;
/*exit or entrance*/

SELECT license_plate
FROM courthouse_security_logs
WHERE day = "28" AND month = "7" AND year = "2020" AND hour ="10" AND minute >= "15" AND minute < "25" AND activity = "exit";
/*
5P2BI95
94KL13X
6P58WS2
4328GD8
G412CB7
L93JTIZ
322W7JE
*/

SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = "28" AND month = "7" AND year = "2020" AND hour ="10" AND minute >= "15" AND minute < "25" AND activity = "exit";
/*
Patrick
Ernest
Amber
Danielle
Roger
Elizabeth
Russell
Evelyn
*/

SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day=28 AND month=7 AND year=2020 AND transaction_type = "withdraw" AND atm_location = "Fifer Street";
/*
*Ernest
*Russell
Roy
Bobby
*Elizabeth
*Danielle
Madison
Victoria
*/

SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60";
/*
name
Roger
Evelyn
*Ernest
Evelyn
Madison
*Russell
Kimberly
Bobby
Victoria
*/

SELECT id FROM airports
WHERE city = "Fiftyville";
--id 8

SELECT hour FROM flights
WHERE day = "29" AND month = "7" AND year = "2020" AND origin_airport_id ="8";
/*
16
12
8
9
15
*/

SELECT minute FROM flights
WHERE day = "29" AND month = "7" AND year = "2020" AND hour ="8" AND origin_airport_id ="8";
--minute 20

SELECT id FROM flights
WHERE day = "29" AND month = "7" AND year = "2020" AND hour = "8" AND minute = "20" origin_airport_id ="8";
--id 36

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id ="36";
/*
Doris
Roger
*Ernest
Edward
Evelyn
Madison
Bobby
Danielle
*/

SELECT destination_airport_id
FROM flights
WHERE id = "36";
--destination_airport_id 4

SELECT city FROM airports
WHERE id = "4";
--city London

 SELECT phone_number FROM people
   ...> WHERE name ="Ernest";
--phone_number (367) 555-5533

SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" AND caller = "(367) 555-5533";
--name Berthold