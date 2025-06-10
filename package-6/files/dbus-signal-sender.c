/* required header files */
#include <glib.h>			/* provides event loops and data structures */
#include <dbus/dbus-glib-lowlevel.h>	/* low level Dbus-Glib api functions */
#include <dbus/dbus-glib.h>		/* higher level Dbus-Glib api functions */
#include <dbus/dbus.h>			/* Provides core Dbus api */
#include <stdio.h>			/* provides standard input,output */
#include <stdlib.h>			/* provides malloc,free,exit */
#include <string.h>			/* provides string functions */

/* start of send ping function */
static gboolean send_ping(DBusConnection *bus) 
{
	/* bus in the dbus connection object used to send messages */
	/* check if the bus is valid */
    	if (!bus) 
	{
        	g_warning("Invalid DBusConnection (bus is NULL)");
        	return FALSE;
    	}

	/* initialised a dbus message */
    	DBusMessage *message;
	DBusMessage *message1;
    	/* Buffer for user input */
	char input[256];

    	/* Get user input */
    	printf("Enter message to send: ");
    	if (!fgets(input, sizeof(input), stdin)) 
	{
        	g_warning("Error reading input.");
        	return TRUE;
    	}

    	/* Remove the newline character from the input */
    	input[strcspn(input, "\n")] = 0;

    	/* Ensure the input is not empty */
    	if (strlen(input) == 0) 
	{
        	g_warning("Empty input, not sending message.");
        	return TRUE;
    	}

    	/* Create the D-Bus signal message */
	/* dbus_message_new_signal(path, interface, name); */
    	message = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                      "com.burtonini.dbus.Signal",
                                      "Ping");
	message1 = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                      "com.burtonini.dbus.Signal1",
                                      "Ping");
    	if (!message && !message1) 
	{
        	g_warning("Failed to create D-Bus signal message.");
        	return TRUE;
    	}

    	/* Ensure the string is properly allocated before passing to dbus_message_append_args */
    	char *safe_input = strdup(input);
    	if (!safe_input) 
	{
        	g_warning("Memory allocation failed.");
        	dbus_message_unref(message);
		dbus_message_unref(message1);
        	return TRUE;
    	}

    	/* Append the user input string to the signal */
    	if (!dbus_message_append_args(message, DBUS_TYPE_STRING, &safe_input, DBUS_TYPE_INVALID)) 
	{
        	g_warning("Failed to append arguments to D-Bus message.");
        	free(safe_input);
        	dbus_message_unref(message);
        	return TRUE;
    	}

	if (!dbus_message_append_args(message1, DBUS_TYPE_STRING, &safe_input, DBUS_TYPE_INVALID))
        {
                g_warning("Failed to append arguments to D-Bus message.");
                free(safe_input);
                dbus_message_unref(message1);
                return TRUE;
        }
    	/* Send the signal */
    	if (!dbus_connection_send(bus, message, NULL) && !dbus_connection_send(bus, message1, NULL)) 
	{
        	g_warning("Failed to send D-Bus message.");
    	}

	

    	/* Ensure the message is flushed */
    	dbus_connection_flush(bus);
    	printf("Sent: %s\n", safe_input);

    	/* Free allocated resources */
    	free(safe_input);
    	dbus_message_unref(message);
	dbus_message_unref(message1);
    	return TRUE;
}
/* end of send ping function */



/* start of main function */
int main() 
{
	/* this functionality is provided by GLib */
    	GMainLoop *loop;

    	DBusConnection *bus;
    	DBusError error;

    	/* Create a new event loop */
    	loop = g_main_loop_new(NULL, FALSE);
    	if (!loop) 
	{
        	g_warning("Failed to create GMainLoop");
        	return 1;
    	}

    	/* Connect to the session bus */
    	dbus_error_init(&error);
    	bus = dbus_bus_get(DBUS_BUS_SESSION, &error);
    	if (!bus) 
	{
        	g_warning("Failed to connect to the D-BUS daemon: %s", error.message);
        	dbus_error_free(&error);
        	return 1;
    	}

    	/* Set up this connection to work in a GLib event loop */
	/* functionality provided by GLib */
    	dbus_connection_setup_with_g_main(bus, NULL);

    	/* Call send_ping() every second */
    	g_timeout_add(1000, (GSourceFunc)send_ping, bus);

    	/* Start the event loop */
    	g_main_loop_run(loop);

    	/* Cleanup */
    	g_main_loop_unref(loop);
    	return 0;
}
/* end of main function */
