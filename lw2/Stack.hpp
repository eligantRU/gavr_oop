#pragma once

#include <stdexcept>
#include <memory>

template <class T>
class Stack
{
	template <class T>
	struct Node
	{
		Node(T data, std::unique_ptr<Node<T>>&& prev)
			:data(data)
			,prev(std::move(prev))
		{}

		T data;
		std::unique_ptr<Node> prev;
	};

public:
	Stack() = default;

	~Stack() {
		clear();
	}

	void push(T data) {
		m_top = std::make_unique<Node<T>>(data, std::move(m_top));
		++m_size;
	}

	T pop() {
		if (empty()) {
			throw std::underflow_error("Stack underflow");
		}

		const auto data = m_top->data;
		m_top = std::move(m_top->prev);
		--m_size;
		return data;
	}

	T top() const {
		if (empty()) {
			throw std::underflow_error("Stack underflow");
		}
		return m_top->data;
	}

	size_t size() const noexcept {
		return m_size;
	}

	bool empty() const noexcept {
		return !m_size;
	}

	void clear() noexcept {
		while (!empty()) pop();
	}

private:
	size_t m_size = 0;
	std::unique_ptr<Node<T>> m_top = nullptr;
};
