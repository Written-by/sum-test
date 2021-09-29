#pragma once

#include <cstdint>
#include <string>

struct Ip final{
	static const int SIZE=4;

	Ip(){}
	Ip(const uint32_t r):ip_(r){}
	Ip(const std::string r);

	operator uint32_t() const{return ip_;}
	explicit operator std::string() const;

	bool operator == (const Ip& r) const{return ip_==r.ip_;}
	bool isLocalHost() const{
		uint8_t prefix=(ip_&0xFF000000)>>24;
		return prefix==0x7F;
	}
	bool isBroadcast() const{return ip_==0xFFFFFFFF;}
	bool isMulticast() const{
		uint8_t prefix=(ip_&0xFF000000)>>24;
		return prefix>=0xE0&&prefix<0xF0;
	}

protected:
	uint32_t ip_;
};
