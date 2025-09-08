// practica01_time.cpp
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;
class Time {
public:
 Time() = default;
 Time(int hour, int minute, int second) { set(hour, minute,
second); }
 // Observadores
 int hour() const noexcept { return hour_; }
 int minute() const noexcept { return minute_; }
 int second() const noexcept { return second_; }
// Modificadores (validación estricta)
 void hour(int h) { validate(h, minute_, second_); hour_ = h; }
 void minute(int m) { validate(hour_, m, second_); minute_ = m; }
 void second(int s) { validate(hour_, minute_, s); second_ = s; }
 void set(int h, int m, int s) {
 validate(h, m, s);
 hour_ = h; minute_ = m; second_ = s;
 }
 string toMilitary() const {
 ostringstream os;
 os << setw(2) << setfill('0') << hour_ << ':'
 << setw(2) << setfill('0') << minute_;
 return os.str();
 }
 string toStandard() const {
 const int h12 = (hour_ == 0 || hour_ == 12) ? 12 : hour_ % 12;
 const char* ampm = (hour_ < 12) ? "AM" : "PM";
 ostringstream os;
 os << h12 << ':'
 << setw(2) << setfill('0') << minute_ << ':'
 << setw(2) << setfill('0') << second_ << ' ' << ampm;
 return os.str();
 }
private:
 int hour_{0}, minute_{0}, second_{0};
 static void validate(int h, int m, int s) {
 if (h < 0 || h > 23) throw invalid_argument("hour out of range
[0,23]");
 if (m < 0 || m > 59) throw invalid_argument("minute out of
range [0,59]");
 if (s < 0 || s > 59) throw invalid_argument("second out of
range [0,59]");
 }
};
int main() {
 try {
 Time t1(18, 30, 0);
 cout << t1.toMilitary() << " | " << t1.toStandard() << '\n';
 Time t2; // 00:00:00
 t2.minute(5);
 t2.second(7);
 cout << t2.toMilitary() << " | " << t2.toStandard() << '\n';
 // Prueba inválida (descomentar para verificar excepción):
 // Time bad(29, 73, 0);
} catch (const exception& ex) {
 cerr << "Error: " << ex.what() << '\n';
 return 1;
 }
 return 0;
}
