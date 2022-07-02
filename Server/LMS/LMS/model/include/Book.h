#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#include<iostream>

class Book {
public:
	void setName(std::string name){}
	void setAutho(std::string author) { this->author = author; }
	void setPublisher(std::string publisher) { this->publisher = publisher; }
	void setPrice() {}
	std::string getName() {}
	std::string getAuthor(){}
	std::string getPublisher() {}
	std::string getPrice() {}
protected:
	std::string name;
	std::string author;
	std::string publisher;
	double price;
	std::string uniqueID;
private:
};

#endif