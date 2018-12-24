#include "lib.h"

#include <iostream>

#include <spdlog/spdlog.h>

int main() {
	auto logger = spdlog::stdout_logger_mt("console");

	if (logger) {
		logger->info("version {} was started", version());
	}

	std::cout << "Hello, world!" << std::endl;
	return 0;
}
