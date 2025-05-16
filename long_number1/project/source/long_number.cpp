#include "long_number.hpp"
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <string>

using eaa::LongNumber;

LongNumber::LongNumber() {
	numbers = new int[1];
	numbers[0] = 0;
	length = 1;
	sign = 1;
}

LongNumber::LongNumber(const char* const str) {
	int str_length = strlen(str);
	int offset = (str[0] == '-') ? 1 : 0;

	sign = (offset == 1) ? -1 : 1;
	length = str_length - offset;

	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - 1 - i] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; ++i) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) noexcept {
	numbers = x.numbers;
	length = x.length;
	sign = x.sign;

	x.numbers = nullptr;
	x.length = 0;
	x.sign = 1;
}

LongNumber::~LongNumber() {
	delete[] numbers;
	numbers = nullptr;
	length = 0;
	sign = 1;
}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = std::strlen(str);
	int offset = (str[0] == '-') ? 1 : 0;

	sign = (offset == 1) ? -1 : 1;
	length = str_length - offset;

	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - 1 - i] - '0';
	}

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;

	delete[] numbers;
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; ++i) {
		numbers[i] = x.numbers[i];
	}
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) noexcept {
	if (this != &x) {
		delete[] numbers;
		numbers = x.numbers;
		length = x.length;
		sign = x.sign;

		x.numbers = nullptr;
		x.length = 0;
		x.sign = 1;
	}
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (this == &x) return true;
	if (sign != x.sign || length != x.length) return false;
	for (int i = 0; i < length; i++)
		if (numbers[i] != x.numbers[i]) return false;
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) return sign > x.sign;
	if (length != x.length) return (length > x.length) == (sign == 1);
	for (int i = length - 1; i >= 0; --i) {
		if (numbers[i] != x.numbers[i])
			return (numbers[i] > x.numbers[i]) == (sign == 1);
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x) && *this != x;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign == x.sign) {
		int max_len = std::max(length, x.length);
		LongNumber result;
		result.length = max_len + 1;
		result.numbers = new int[result.length]();
		result.sign = sign;

		int carry = 0;
		for (int i = 0; i < max_len; ++i) {
			int a = (i < length ? numbers[i] : 0);
			int b = (i < x.length ? x.numbers[i] : 0);
			int s = a + b + carry;
			result.numbers[i] = s % 10;
			carry = s / 10;
		}
		if (carry) {
			result.numbers[max_len] = carry;
		}
		else {
			result.length = max_len;
		}
		while (result.length > 1 && result.numbers[result.length - 1] == 0)
			result.length--;
		return result;
	}

	LongNumber A = *this; A.sign = 1;
	LongNumber B = x; B.sign = 1;
	if (A == B) return LongNumber("0");
	LongNumber result = (A > B) ? A - B : B - A;
	result.sign = (A > B) ? sign : x.sign;
	return result;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (sign != x.sign) {
		LongNumber A = *this; A.sign = 1;
		LongNumber B = x; B.sign = 1;
		LongNumber result = A + B;
		result.sign = sign;
		return result;
	}

	LongNumber A = *this; A.sign = 1;
	LongNumber B = x; B.sign = 1;
	if (A == B) return LongNumber("0");

	bool resultNegative;
	LongNumber M = (A > B ? A : B), N = (A > B ? B : A);
	resultNegative = (A > B) ? (sign == -1) : (sign == 1);

	LongNumber result;
	result.length = M.length;
	result.numbers = new int[result.length]();
	int borrow = 0;
	for (int i = 0; i < result.length; ++i) {
		int a = (i < M.length ? M.numbers[i] : 0);
		int b = (i < N.length ? N.numbers[i] : 0);
		int d = a - b - borrow;
		borrow = (d < 0) ? 1 : 0;
		result.numbers[i] = (d + 10) % 10;
	}
	while (result.length > 1 && result.numbers[result.length - 1] == 0)
		result.length--;
	result.sign = resultNegative ? -1 : 1;
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	LongNumber result;
	result.length = length + x.length;
	result.sign = sign * x.sign;
	result.numbers = new int[result.length]();

	for (int i = 0; i < x.length; ++i) {
		int carry = 0;
		for (int j = 0; j < length; ++j) {
			int product = result.numbers[i + j] + x.numbers[i] * numbers[j] + carry;
			result.numbers[i + j] = product % 10;
			carry = product / 10;
		}
		result.numbers[i + length] += carry;
	}
	while (result.length > 1 && result.numbers[result.length - 1] == 0)
		result.length--;
	if (result.length == 1 && result.numbers[0] == 0) result.sign = 1;
	return result;
}

LongNumber LongNumber::operator/(const LongNumber& divisor) const {
	// Проверка деления на ноль
	if (divisor.length == 1 && divisor.numbers[0] == 0) {
		throw std::runtime_error("Division by zero");
	}

	// Работаем с абсолютными значениями
	LongNumber dividend = *this;
	dividend.sign = 1;
	LongNumber abs_divisor = divisor;
	abs_divisor.sign = 1;

	// Если делимое меньше делителя, результат 0
	if (dividend < abs_divisor) {
		return LongNumber("0");
	}

	// Инициализация результата
	LongNumber quotient;
	quotient.length = dividend.length;
	quotient.numbers = new int[quotient.length]();
	quotient.sign = sign * divisor.sign;

	// Текущий остаток
	LongNumber remainder;
	remainder.numbers = new int[dividend.length + 1]();
	remainder.length = 0;

	// Алгоритм деления в столбик
	for (int pos = dividend.length - 1; pos >= 0; --pos) {
		// Сдвигаем остаток и добавляем следующую цифру
		if (remainder.length > 0) {
			for (int i = remainder.length; i > 0; --i) {
				remainder.numbers[i] = remainder.numbers[i - 1];
			}
		}
		remainder.numbers[0] = dividend.numbers[pos];
		if (remainder.length == 0 || remainder.numbers[remainder.length] != 0) {
			remainder.length++;
		}

		// Подбираем цифру частного (используем только доступные операторы)
		int digit = 0;
		LongNumber product;
		for (digit = 9; digit >= 0; --digit) {
			LongNumber temp;
			temp.numbers = new int[1] {digit};
			temp.length = 1;
			temp.sign = 1;

			product = abs_divisor * temp;
			delete[] temp.numbers;

			// Заменяем product <= remainder на !(product > remainder) || product == remainder
			if (!(product > remainder) || product == remainder) {
				break;
			}
			delete[] product.numbers;
		}

		quotient.numbers[pos] = digit;

		// Вычитаем произведение из остатка
		if (digit > 0) {
			LongNumber temp;
			temp.numbers = new int[1] {digit};
			temp.length = 1;
			temp.sign = 1;

			product = abs_divisor * temp;
			delete[] temp.numbers;

			LongNumber new_remainder = remainder - product;
			delete[] product.numbers;

			// Обновляем остаток
			delete[] remainder.numbers;
			remainder.length = new_remainder.length;
			remainder.numbers = new int[remainder.length];
			for (int i = 0; i < remainder.length; ++i) {
				remainder.numbers[i] = new_remainder.numbers[i];
			}
			remainder.sign = new_remainder.sign;
			delete[] new_remainder.numbers;
		}
	}

	// Удаляем ведущие нули
	while (quotient.length > 1 && quotient.numbers[quotient.length - 1] == 0) {
		quotient.length--;
	}

	delete[] remainder.numbers;
	return quotient;
}

LongNumber LongNumber::operator%(const LongNumber& divisor) const {
	LongNumber quotient = *this / divisor;
	LongNumber remainder = *this - (quotient * divisor);

	// Корректировка знака остатка
	if (remainder != LongNumber("0")) {
		remainder.sign = sign;
	}

	return remainder;
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	if (rank < 1 || rank >= length) return 0;
	return numbers[rank - 1];
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int length = 0;
	int start = (str[0] == '-') ? 1 : 0;

	while (str[length + start] >= '0' && str[length + start] <= '9') {
		length++;
	}
	return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace eaa {
	std::ostream& operator << (std::ostream& os, const LongNumber& x) {
		if (x.length == 0) return os << "0";
		if (x.sign == -1) os << "-";
		for (int i = x.length - 1; i >= 0; --i)
			os << x.numbers[i];
		return os;
	}
}
