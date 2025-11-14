/*
 * Program.h
 * Author: AlHussien Mustafa
 */

#ifndef PROGRAM_H
#define PROGRAM_H

// Admin functions
void addPatient(void);
void editPatient(void);
void reserveSlot(void);
void cancelReservation(void);

// User functions
void viewPatient(void);
void viewReservations(void);

// Modes
void adminMode(void);
void userMode(void);

#endif 