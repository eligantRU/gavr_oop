#pragma once

#include <stdexcept>
#include <memory>

template <class T>
struct Node
{
	Node(T data, std::unique_ptr<Node<T>>&& prev = nullptr)
		:data(data)
		, prev(std::move(prev))
	{}

	T data;
	std::unique_ptr<Node> prev;
};

template <class T>
void push(std::unique_ptr<Node<T>>& node, T data) {
	node = std::make_unique<Node<T>>(data, std::move(node));
}

template <class T>
T pop(std::unique_ptr<Node<T>>& node) {
	if (empty(node)) {
		throw std::underflow_error("Stack underflow");
	}

	const auto data = node->data;
	node = std::move(node->prev);
	return data;
}

template <class T>
T top(const std::unique_ptr<Node<T>>& node) {
	if (empty(node)) {
		throw std::underflow_error("Stack underflow");
	}
	return node->data;
}

template <class T>
size_t size(const std::unique_ptr<Node<T>>& node) noexcept {
	size_t size = 0;
	for (auto subNode = node.get(); subNode; subNode = subNode->prev.get(), ++size);
	return size;
}

template <class T>
bool empty(const std::unique_ptr<Node<T>>& node) noexcept {
	return !node;
}

template <class T>
void clear(std::unique_ptr<Node<T>>& node) noexcept {
	while (!empty(node)) pop(node);
}
