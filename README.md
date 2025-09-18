# FLIGHT-RESERVATION-SYSTEM-
This project is a simple airline management system implemented in C++ using object-oriented programming concepts.  
It handles Passenger Management, Flight Management, Booking System, and Main Menu Utilities.
### **Helen: Passenger Management**
- Implemented the `Passenger` class.
- Handled adding, displaying, saving passengers to file.
- Implemented `getPassengerByID()` to retrieve passenger details from CSV.
- Implemented `updatePassengerInfo()` as a friend function to modify passenger data.
- Ensured file I/O for passengers (`passengers.csv`) works correctly.
### **Karthik: Flight Management**
- Implemented the `Flight` class.
- Managed flight details, including departure, arrival, capacities, and bookings.
- Implemented seat booking and cancellation (`bookSeat()`, `cancelSeat()`).
- File handling for flights (`flights.csv`) and updating booked seats.
- Implemented static `loadFlights()` function to load flights from file.
### **Ashitosh: Booking System**
- Implemented the `Booking` class to handle flight bookings.
- Managed companions for a booking with names and ages.
- Implemented `generatePNR()` for unique booking references.
- Saved bookings to `bookings.csv`.
- Displayed full booking details with passenger and flight info.
### **Shivam: Main Menu & Utilities**
- Implemented main menu interface (`main()` function).
- Handled user input validation (`validIntInput()`).
- Integrated all classes into a working menu.
- Implemented helper function `pressEnter()` for smooth navigation.
- Managed the workflow of adding passengers, booking flights, canceling bookings, and updating info.

