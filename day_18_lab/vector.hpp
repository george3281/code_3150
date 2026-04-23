#pragma once

#include <cstddef>
#include <concepts>
#include <new>
#include <stdexcept>
#include <utility>

template <typename T>
concept EqualityComparable = requires(const T& a, const T& b) {
	{ a == b } -> std::convertible_to<bool>;
};

template <EqualityComparable T>
class Vector {
private:
	T* data_;
	size_t size_;
	size_t capacity_;

	void resize_capacity(size_t new_capacity) {
		T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_capacity));
		size_t i = 0;
		try {
			for (; i < size_; ++i) {
				::new (static_cast<void*>(new_data + i)) T(std::move(data_[i]));
			}
		} catch (...) {
			for (size_t j = 0; j < i; ++j) {
				new_data[j].~T();
			}
			::operator delete(static_cast<void*>(new_data));
			throw;
		}
		for (size_t k = 0; k < size_; ++k) {
			data_[k].~T();
		}
		::operator delete(static_cast<void*>(data_));
		data_ = new_data;
		capacity_ = new_capacity;
	}

public:
	class Iterator {
	private:
		T* current_;

	public:
		explicit Iterator(T* ptr) : current_(ptr) {}

		T& operator*() { return *current_; }

		Iterator& operator++() {
			++current_;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return current_ != other.current_;
		}
	};

	class ConstIterator {
	private:
		const T* current_;

	public:
		explicit ConstIterator(const T* ptr) : current_(ptr) {}

		const T& operator*() const { return *current_; }

		ConstIterator& operator++() {
			++current_;
			return *this;
		}

		bool operator!=(const ConstIterator& other) const {
			return current_ != other.current_;
		}
	};

	Vector() : data_(nullptr), size_(0), capacity_(0) {}

	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete;

	~Vector() {
		for (size_t i = 0; i < size_; ++i) {
			data_[i].~T();
		}
		::operator delete(static_cast<void*>(data_));
	}

	size_t size() const { return size_; }

	size_t capacity() const { return capacity_; }

	bool empty() const { return size_ == 0; }

	void push_back(const T& value) {
		if (size_ == capacity_) {
			resize_capacity(capacity_ == 0 ? 1 : capacity_ * 2);
		}
		::new (static_cast<void*>(data_ + size_)) T(value);
		++size_;
	}

	T& at(size_t index) {
		if (index >= size_) {
			throw std::out_of_range("Vector::at: index out of range");
		}
		return data_[index];
	}

	T& operator[](size_t index) { return data_[index]; }

	const T& operator[](size_t index) const { return data_[index]; }

	bool operator==(const Vector<T>& other) const {
		if (size_ != other.size_) {
			return false;
		}
		for (size_t i = 0; i < size_; ++i) {
			if (!(data_[i] == other.data_[i])) {
				return false;
			}
		}
		return true;
	}

	Iterator begin() { return Iterator(data_); }

	Iterator end() { return Iterator(data_ + size_); }

	ConstIterator begin() const { return ConstIterator(data_); }

	ConstIterator end() const { return ConstIterator(data_ + size_); }
};
