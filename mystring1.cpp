//File: mystring1.h
// Implementation file for user-defined String class.

#include "mystring1.h"


String::String()
{
	contents = new char[1];
	contents[0] = '\0';
	len = 1;
	assert(contents != 0);
}

String::~String()
{
	delete[] contents;
}

String::String(const char s[])
{
  len = strlen(s);
  contents = new(nothrow) char[len];
  strcpy_s(contents, len, s);
}

String::String(const String& rhs)
{
	this->len = rhs.len;
	contents = new(nothrow) char[len];
	strcpy_s(contents, len, rhs.contents);

}


void String::append(const String &str)
{
  len += str.len;
  strcat_s(contents, len, str.contents);
}


bool String::operator >(const String &str) const
{
  return strcmp(contents, str.contents) > 0;
}

bool String::operator <(const String &str) const
{
  return strcmp(contents, str.contents) < 0;
}


String String::operator +=(const String &str)
{
	append(str);
	return *this;
}

String String::operator =(const String& rhs)
{
	if (this != &rhs)
	{
		this->len = rhs.len;
		delete[] contents;
		contents = new(nothrow) char[len];
		strcpy_s(contents, len, rhs.contents);
	}
	return *this;
}

void String::print(ostream &out) const
{
  out << contents;
}

int String::length() const
{
  return len;
}

char String::operator [](int i) const
{
  if (i < 0 || i >= len) {
    cerr << "can't access location " << i
         << " of string \"" << contents << "\"" << endl;
    return '\0';
  }
  return contents[i];
}

ostream & operator<<(ostream &out, const String & s) // overload ostream operator "<<" - External!
{ 
	s.print(out);
	return out;
}

