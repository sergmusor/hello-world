#include "lib.h"

#include <cstdlib>
#include <iostream>

#include <spdlog/spdlog.h>

int main() {
	auto const logger{spdlog::stdout_logger_mt("console")};

	if (logger) {
		logger->info("version {} was started", version());
	}

	return std::cout << "Hello, world!" << std::endl && logger ? EXIT_SUCCESS : EXIT_FAILURE;
}
