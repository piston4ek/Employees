// emp.h -- header file for abstr_emp class and him subsidiaries classes
#include <iostream>
#include <string>
class abstr_emp
{
private:
	std::string fname;					// first name
	std::string lname;					// last name
	std::string job;

public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual void ShowAll() const;	// out all data with names
	virtual void SetAll();			// request all data in user
	// Out only first & last name
	friend std::ostream&
		operator<<(std::ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;		// virtual based class
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;										// the number of managed abstr_emp
protected:
	int InChargeOf() const { return inchargeof; }		// out
	int& inChargeOf() { return inchargeof; }			// inp
public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
	std::string reportsto;								// to whom bring out reports
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);
	virtual void ShowAll() const;
	virtual void SetAll();
};
// Multiple inheritance from manager & fink
class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo,
		int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
};