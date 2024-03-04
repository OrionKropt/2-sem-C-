#pragma once

#include <iostream>
class Fruction
{
	friend std::ostream& operator<<(std::ostream&, const Fruction& );
	friend std::istream& operator>>(std::istream&, Fruction& ) ;
public:
	Fruction()
	{
		ch = zn = 0;
	}
	Fruction(int ch, int zn)
	{
		this->ch = ch;
		this->zn = zn;
	}

	/*Fruction(Fruction& other)
	{
		ch = other.ch;
		zn = other.zn;
	}*/

	Fruction& operator=(const Fruction& other)
	{
		ch = other.ch;
		zn = other.zn;
		return *this;
	}

	Fruction operator+(const Fruction& other)
	{
		Fruction temp(this->ch + other.ch, this->zn + other.zn);
		return temp;
	}

	Fruction operator-(const Fruction& other)
	{
		return Fruction(this->ch - other.ch, this->zn - other.zn);
	}

	Fruction operator*(const Fruction& other)
	{
		return Fruction(this->ch * other.ch, this->zn * other.zn);
	}

	Fruction operator/(const Fruction& other)
	{
		return Fruction(this->ch * other.zn, this->zn * other.ch);
	}

	bool operator==(const Fruction& other)
	{
		return this->ch == other.ch && this->zn == other.zn;
	}
	bool operator!=(const Fruction& other)
	{
		return !(this->ch == other.ch && this->zn == other.zn);
	}



private:
	int ch;
	int zn;
};

std::istream& operator>> (std::istream& in, Fruction& dt)
{
	in >> dt.ch >> dt.zn;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Fruction& dt)
{
	out << dt.ch << "/" << dt.zn;
	return out;
}