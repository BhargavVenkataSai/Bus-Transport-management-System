# Bus-Transport-management-System
This C++ programming focuses on virtual bus trasnport management system where we appoint a new bus driver for the travelling route, displaying the bus details, bookings.. using all the concepts of C++ along with OOPS concepts thoroughly used in this project. 
System Overview

The Bus Transport Management System is a software application designed to manage the operations of a bus transport company. The system allows administrators to manage bus routes, schedules, fares, and passenger information. It also enables passengers to book tickets and view their booking history.

Class Diagram

The system consists of the following classes:

Bus: Represents a bus with attributes such as bus number, route number, departure time, arrival time, and fare.
Route: Represents a bus route with attributes such as route number, starting point, ending point, and distance.
Schedule: Represents a bus schedule with attributes such as schedule ID, bus number, route number, departure time, and arrival time.
Passenger: Represents a passenger with attributes such as passenger ID, name, contact number, and email.
Booking: Represents a ticket booking with attributes such as booking ID, passenger ID, bus number, route number, departure time, and fare.
Administrator: Represents an administrator with attributes such as admin ID, name, and password.
Class Relationships

The classes are related as follows:

A bus can have multiple schedules (one-to-many).
A route can have multiple buses (one-to-many).
A passenger can have multiple bookings (one-to-many).
An administrator can manage multiple buses, routes, and bookings (one-to-many).
Methods

Each class has the following methods:

Bus:
addBus(): adds a new bus to the system.
removeBus(): removes a bus from the system.
updateBus(): updates the details of a bus.
Route:
addRoute(): adds a new route to the system.
removeRoute(): removes a route from the system.
updateRoute(): updates the details of a route.
Schedule:
addSchedule(): adds a new schedule to the system.
removeSchedule(): removes a schedule from the system.
updateSchedule(): updates the details of a schedule.
Passenger:
addPassenger(): adds a new passenger to the system.
removePassenger(): removes a passenger from the system.
updatePassenger(): updates the details of a passenger.
Booking:
bookTicket(): books a ticket for a passenger.
cancelBooking(): cancels a booking.
viewBookingHistory(): displays the booking history of a passenger.
Administrator:
login(): logs in an administrator.
logout(): logs out an administrator.
manageBuses(): manages buses (add, remove, update).
manageRoutes(): manages routes (add, remove, update).
manageBookings(): manages bookings (add, remove, update).
