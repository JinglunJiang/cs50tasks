-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get all the information with the provided pices of information.
select * from crime_scene_reports
where year = 2021
and month = 7
and day = 28
and street = 'Humphrey Street';
-- The id in crime_scene_reports for the crime is 295, time is 10:15am, "bakery"
-- Get a brief idea of the bakery table
select * from bakery_security_logs;
-- select the part of table on the day
select * from bakery_security_logs
where year = 2021
and month = 7
and day = 28
-- Nothing I can use, check the interviews instead
select * from interviews
where year = 2021
and month = 7
and day = 28;
and transcript like '%bakery%'
-- From the transcript, the theif is leaving Fiftyville tmr by earliest flight, the person on the phone is buying tickets.
-- The thief is withdrawing money from atm -- Leggett Street
-- The thief is calling someone
-- Within 10 mins you can see the thief's car leaving the parking lot
select * from flights
where year = 2021
and month = 7
and day = 29;
-- The flight is with id = 36, destination airport_id = 4
select * from airport
where id = 4;
-- The thief is going to LGA, LaGuardia Airport, New York City
select * from bakery_security_logs
where year = 2021
and month = 7
and day = 28
and hour = 10
and minute <= 25
and minute >= 15;
-- 260 - 267 in the bakery seurity log
select * from bakery_security_logs
where year = 2021
and month = 7
and day = 28
and hour = 10
and minute <= 25
and minute >= 15
and license_plate in
(select license_plate
from people
where passport_number in
(select passport_number from passengers
where flight_id = 36));
-- only 4 cars left
-- Get the specific phone call YEAHHHHH
select* from phone_calls
where caller in
(select phone_number from people
where passport_number in
(select passport_number from passengers
where flight_id = 36))
and receiver in
(select phone_number from people
where passport_number in
(select passport_number from passengers
where flight_id = 36));
-- know the thief
select * from people
where phone_number = '(826) 555-1652'; 
select * from people
where phone_number = '(066) 555-9701';