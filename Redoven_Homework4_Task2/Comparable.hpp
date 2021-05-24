#pragma once
class Comparable {
	public:
		virtual bool operator==(Comparable* input) = 0;
		virtual bool operator!=(Comparable* input) = 0;
};