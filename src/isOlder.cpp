/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int getInt(char *, int, int);
bool isValidInput(char *);
int compare(int, int);
// INST CODE END //
int isOlder(char *dob1, char *dob2) {
	// INST CODE START //
	if (isValidInput(dob1) && isValidInput(dob2)) {
		int y1, m1, d1, y2, m2, d2, compareValue;
		y1 = getInt(dob1, 6, 9);
		y2 = getInt(dob2, 6, 9);
		compareValue = compare(y1, y2);
		if (compareValue != 0) return compareValue;
		m1 = getInt(dob1, 3, 4);
		m2 = getInt(dob2, 3, 4);
		compareValue = compare(m1, m2);
		if (compareValue != 0) return compareValue;
		d1 = getInt(dob1, 0, 1);
		d2 = getInt(dob2, 0, 1);
		compareValue = compare(d1, d2);
		if (compareValue != 0) return compareValue;
	}
	else {
		return -1;
	}
	// INST CODE END //
}
// INST CODE START //
int compare(int value1, int value2) {
	if (value1 < value2) {
		return 2;
	}
	if (value1 > value2) {
		return 1;
	}
	return 0;
}

int getInt(char *p, int from, int to) {
	int value = 0;
	while (from <= to) {
		value = value * 10 + p[from] - '0';
		from++;
	}
	return value;
}

bool isValidInput(char *inp) {
	int y, m, d;
	bool valid = false;
	int daysinmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	y = getInt(inp, 6, 9);
	m = getInt(inp, 3, 4);
	d = getInt(inp, 0, 1);
	// leap year checking, if ok add 29 days to february
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		daysinmonth[1] = 29;
	if (m < 13)
	{
		if (d <= daysinmonth[m - 1])
			valid = true;
	}
	if (!(inp[2] == '-' && inp[5] == '-' && inp[2] == '-' && inp[10] == '\0')) {
		valid = false;
	}
	return valid;
}