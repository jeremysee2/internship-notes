#include "DiagnosticsServer.h"
#include "EventHandler.h"
#include <stdio.h>

int main(void) {
	const unsigned int serverPort = 0xC001;
	DiagnosticsServerPtr server = createServer(serverPort);

	if (NULL == server) {
		error("Failed to create the server");
	}

	// Enter the eternal reactive event loop
	for(;;) {
		HandleEvents();
	}
}