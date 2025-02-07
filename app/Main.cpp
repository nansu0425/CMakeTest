#include <asio.hpp>

#include "Functions.h"

int main(int argc, char* charv[]) {
	asio::io_context ioContext;

	asio::post(ioContext, []()
			   {
				   PrintHello();
			   });

	ioContext.run();

	return 0;
}
