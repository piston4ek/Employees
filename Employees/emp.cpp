// emp.cpp -- realization of emp's methods
#include "emp.h"
using std::cout;
using std::endl;
using std::cin;
using std::getline;
// abstr_emp methods

abstr_emp::abstr_emp() : abstr_emp("null","null","null") 
{
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j) 
{
}

void abstr_emp::ShowAll() const
{
	cout << "Full Name: " << fname << " " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	while (cin.get()!='\n')
		continue;
	cout << "First name: ";
	getline(cin, fname);
	cout << "Last name: ";
	getline(cin, lname);
	cout << "Job: ";
	getline(cin, job);
}

abstr_emp::~abstr_emp()
{
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname;
	return os;
}

// Employee's methods

employee::employee() : abstr_emp() 
{
}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	: abstr_emp(fn,ln,j) 
{
}

void employee::ShowAll() const
{
	cout << "category: employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

// Manager's methods

manager::manager() : abstr_emp(), inchargeof(0)
{
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	: abstr_emp(fn,ln,j), inchargeof(ico)
{
}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager& m)
	: abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	cout << "category: manager\n";
	abstr_emp::ShowAll();
	cout << inchargeof << " employees in charge" << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter count of employees in charge by this manager: ";
	cin >> inchargeof;
}

// Fink's methods

fink::fink() : abstr_emp(), reportsto("null")
{
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: abstr_emp(fn,ln,j), reportsto(rpo)
{
}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	cout << "category: fink\n";
	abstr_emp::ShowAll();
	cout << "He reports to " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Set mentor person for this employee: ";
	getline(cin, reportsto);
}

// HighFink's methods

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rpo)
{
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), manager(e,ico), fink(e,rpo)
{
}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f,ico), fink(f)
{
}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink(m,rpo)
{
}

highfink::highfink(const highfink& h)
	: abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
	cout << "category: high fink\n";
	abstr_emp::ShowAll();
	cout << "He reports to " << ReportsTo() << endl;
	cout << InChargeOf() << " employees in charge" << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Set mentor person for this employee: ";
	getline(cin, ReportsTo());
	cout << "Enter count of employees in charge by this manager: ";
	cin >> inChargeOf();
	while (cin.get() != '\n')
		continue;
}
