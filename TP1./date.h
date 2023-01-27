#include <iostream>

#ifndef DATE_H
#define DATE_H

namespace date {
   class Date {
   public:
      Date(int day=1, int month=1, int years=0);
      int years() const;
      int month() const;
      int day() const;
      void updateYears(int years);
      void updateMonth(int month);
      void updateDay(int day);
      void next();
      void back();

   private:
      int _years;
      int _month;
      int _day;

   };

   bool isDate(int day, int month, int years);
   int getDaysInMonth(int month);
   int dayOfYear(Date d);
   std::string toString(Date d);

   std::ostream& operator<<(std::ostream& os, const Date& date);

} // date

#endif // DATE_H