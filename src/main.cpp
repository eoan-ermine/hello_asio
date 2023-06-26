// Подключаем заголовочный файл <sdkddkver.h> в системе Windows,
// чтобы избежать предупреждения о неизвестной версии Platform SDK,
// когда используем заголовочные файлы библиотеки Boost.Asio
#ifdef WIN32
#include <sdkddkver.h>
#endif

#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <thread>

namespace net = boost::asio;
namespace sys = boost::system;
using namespace std::chrono;
using namespace std::literals;

int main() {
	net::io_context io;
	const auto start_time = steady_clock::now();
	{
		net::steady_timer t(io, 5s);
		std::cout << "Brew coffee"sv << std::endl;
		t.wait();
		std::cout << "Pour coffee in the cup"sv << std::endl;
	}
	{
		std::cout << "Fry eggs"sv << std::endl;
		net::steady_timer t(io, 3s);
		t.wait();
		std::cout << "Put eggs onto the plate" << std::endl;
	}
	const auto cook_duration = duration<double>(steady_clock::now() - start_time);
	std::cout << "Breakfast has been cooked in "sv << cook_duration.count() << "s"sv << std::endl;
	std::cout << "Enjoy your meal"sv << std::endl;
}