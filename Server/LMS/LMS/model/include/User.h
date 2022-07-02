#pragma once
#ifndef _USER_H_
#define _USER_H_

#include<iostream>

class User {
public:
	void setName(std::string name) { this->name = name; }
	void setEmail(std::string) { this->email = email; }
protected:
	std::string name;
	std::string email;
	std::string phone;
	uint16_t bookRequested;
private:
};
#endif