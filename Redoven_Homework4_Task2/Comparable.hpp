#pragma once
class Comparable {
	public:
		virtual bool operator==(const Comparable* input)const = 0;
		virtual bool operator!=(const Comparable* input)const = 0;
		virtual ~Comparable() = default;
private:

};