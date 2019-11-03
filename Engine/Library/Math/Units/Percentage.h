#ifndef PERCENTAGE_H
#define PERCENTAGE_H

struct Percent {
	Percent(int value) {
		this->value = value;
	}

	Percent(float value) {
		this->value = value;
	}

	Percent(double value) {
		this->value = value;
	}

	double operator *(double value) {
		return (this->value / 100.0) * value;
	}
	double operator *(int value) {
		return (this->value / 100.0) * value;
	}

	float operator *(float value) {
		return (this->value / 100.0f) * value;
	}

private:
	double value;
};

Percent operator""percent(long double d) {
	double dd = d;
	return Percent(dd);
}

Percent operator""p(long double d) {
	double dd = d;
	return Percent(dd);
}

#endif // !PERCENTAGE_H