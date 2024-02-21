#include <stdio.h>
#include <time.h>
#include <unistd.h>
void setAlarm(int hours, int minutes);
int checkAlarm(int alarmHours, int alarmMinutes);
void displayMenu();
int main() {
 int alarmHours, alarmMinutes;
 int choice;
 int snoozeDuration = 0;
 printf("Set the alarm (24-hour format):\n");
 printf("Enter hours (0-23): ");
 scanf("%d", &alarmHours);
 printf("Enter minutes (0-59): ");
 scanf("%d", &alarmMinutes);
 setAlarm(alarmHours, alarmMinutes);
 while (1) {
 sleep(5);

 if (snoozeDuration > 0) {
 printf("Snoozing...\n");
 sleep(snoozeDuration * 60);
 snoozeDuration = 0;
 }

 if (checkAlarm(alarmHours, alarmMinutes)) {
 displayMenu();
 scanf("%d", &choice);

 switch (choice) {
 case 1:
 printf("Enter snooze duration (in minutes): ");
 scanf("%d", &snoozeDuration);
 printf("Alarm snoozed for %d minutes.\n", snoozeDuration);
 break;
 case 2:
 printf("Alarm disabled. Goodbye!\n");
 return 0;
 case 3:
 printf("Exiting. Goodbye!\n");
 return 0;
 default:
 printf("Invalid option, try again.\n");
 break;
 }
 }
 }
 return 0;
}
void setAlarm(int hours, int minutes) {
 printf("Alarm set for %02d:%02d\n", hours, minutes);
}
int checkAlarm(int alarmHours, int alarmMinutes) {
 time_t currentTime;
 struct tm *localTime;
 time(&currentTime);
 localTime = localtime(&currentTime);
 if (localTime->tm_hour == alarmHours && localTime->tm_min == alarmMinutes) {
 printf("Alarm! It's time to wake up!\n");
 return 1;
 } else {
 printf("No alarm triggered. Current time: %02d:%02d\n", localTime->tm_hour, localTime->tm_min);
 return 0;
 }
}
void displayMenu() {
 printf("Options:\n");
 printf("1. Snooze the alarm\n");
 printf("2. Disable the alarm\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
}