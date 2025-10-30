FLIGHT RESERVATION SYSTEM

This project is a C++ based airline management system implemented using Object-Oriented Programming principles.
It includes modules for Admin, Customer, Passenger, Flight, Booking, and Cancellation management with persistent file storage.

Helen: Passenger Management

Implemented the Passenger class.

Handles passenger details (ID, name, age, gender).

Saves passenger data to PASSENGER_Details.txt and prevents duplicates.

Displays all passengers through SHOW_ALL_PASSENGERS().

Karthik: Flight Management

Implemented the FLIGHT class.

Stores and manages flight details (number, airline, route, date, time, price).

Saves flights to FLIGHT_details.txt and checks for duplicates.

Displays all flights via SHOW_ALL_FLIGHTS().

Ashitosh: Booking System

Implemented the BOOKING class, inheriting from both Passenger and FLIGHT.

Generates unique booking IDs using a static counter saved in BOOKING_COUNTER.txt.

Saves confirmed bookings to BOOKING_DETAILS.txt.

Displays all bookings and supports operator overloading for comparison.

Implemented the CANCEL_BOOKINGS class to handle cancellations and move data to CANCEL_BOOING_DETAILS.txt.

Shivam: Main Menu & Utilities

Implemented the main user interface (main() function).

Added complete Admin and Customer menus:

Admin: add/view flights, view passengers, bookings, cancellations.

Customer: add passenger, view flights, book/cancel tickets.

Integrated login/registration via abstract base class USER (for both ADMIN_CLASS and CUSTOMER_USER).

Used exception handling for invalid inputs and file I/O for persistent storage.

File Structure
File Name	Description
ADMIN_DETAILS.txt	Admin credentials
CUSTOMER_DETAILS.txt	Customer credentials
PASSENGER_Details.txt	Passenger records
FLIGHT_details.txt	Flight records
BOOKING_DETAILS.txt	Booking records
CANCEL_BOOING_DETAILS.txt	Canceled bookings
BOOKING_COUNTER.txt	Booking ID tracker
