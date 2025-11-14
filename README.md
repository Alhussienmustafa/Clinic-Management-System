# Clinic-Management-System
 A comprehensive console-based system developed in C to manage patient records and doctor  appointments in a small clinic. The system operates in two distinct modes: Admin and User.
 
 1. System Architecture Overview
 The system utilizes global arrays for storage (Patient records and reservation slots) and employs
 functions for modularity. Key concepts implemented include:
 • Data Structures (struct): Used to define patient records and reservation slots.
 • Control Flow: Extensive use of if-else and while loops for menus, login trials, and
 input validation.
 • Functions: Modular approach for Admin features (Add, Edit, Reserve, Cancel) and User
 features (View Record, View Reservations).
 
 2. Admin Mode Features
 Accessing the Admin Mode requires a password (1234) with three attempts allowed before
 system closure. Features include:
 2.1 Add New Patient Record: Takes Name, Age, Gender, and ensures the entered ID is
 unique.
 2.2 Edit Patient Record: Allows modification of patient details after verifying the existence
 of the entered ID.
 2.3 ReserveaSlot: Displays 5 default slots (2pm to 2:30pm, 2:30pm to 3pm, 3pmto 3:30pm,
 4pmto4:30pm, and4:30pmto5pm)andassignsanavailableslot toapatient ID, ensuring
 the patient does not have a double reservation.
 2.4 Cancel Reservation: Removes the patient ID from a reserved slot, making the slot avail
able again.

 3. User Mode Features
 The User Mode allows read-only access without a password, focusing on viewing information:
 3.1 ViewPatient Record: Displays Name, Age, Gender, and ID upon successful entry of the
 Patient ID.
 3.2 View Today’s Reservations: Lists all reserved time slots along with the corresponding
 Patient ID for each reservation.
