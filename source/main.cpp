
#include <stdio.h>
#include "App.cpp"
#include "Display.cpp"

int main( int argc, char* args[] ){
	App app;
	app.initializeApp();

	printf("Hello World.\n");

	app.closeApp();

	return 0;
}