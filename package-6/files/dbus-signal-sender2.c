/* required header files */
#include <glib.h>			/*	provides event loop and data structures	*/
#include <dbus/dbus-glib-lowlevel.h>	/*	low-level dbus-GLib api functions	*/
#include <dbus/dbus-glib.h>		/*	higher level Dbus-Glib api functions	*/
#include <dbus/dbus.h>			/*	Provides core Dbus api			*/
#include <stdio.h>			/*	provides standard input,output		*/
#include <stdlib.h>			/*	provides malloc,free,exit		*/
#include <string.h>			/*	provides string functions		*/

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

	/* declaring 2 input character arrays */
    	char input1[256];
	char input2[256];

    	/* Get user input for first interface */
    	printf("Enter message to send for interface 1 : ");
    	if (!fgets(input1, sizeof(input1), stdin))
    	{
        	g_warning("Error reading input.");
        	return TRUE;
    	}

	/* Get user input for second interface */
	printf("Enter message to send for interface 2 : ");
        if (!fgets(input2, sizeof(input2), stdin))
        {
                g_warning("Error reading input.");
                return TRUE;
        }

    	/* Remove newline */
    	input1[strcspn(input1, "\n")] = 0;
	input2[strcspn(input2, "\n")] = 0;

    	/* Ensure input is not empty */
    	if (strlen(input1) == 0)
    	{
        	g_warning("Empty input, not sending message.");
        	return TRUE;
    	}
	/* Ensure input is not empty */
	if (strlen(input2) == 0)
        {
                g_warning("Empty input, not sending message.");
                return TRUE;
        }

    	/* Allocate safe copy of input */
    	char *safe_input1 = strdup(input1);
    	if (!safe_input1)
    	{
        	g_warning("Memory allocation failed.");
        	return TRUE;
    	}

	/* Allocate safe copy of input */
	char *safe_input2 = strdup(input2);
        if (!safe_input2)
        {
                g_warning("Memory allocation failed.");
                return TRUE;
        }

    	/* Create first D-Bus signal */
    	DBusMessage *message = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                                   "com.burtonini.dbus.Signal",
                                                   "Ping");
    	/* if the message is not created, it will throw an error */
	if (!message)
    	{
        	g_warning("Failed to create first D-Bus signal message.");
        	free(safe_input1);
        	return TRUE;
    	}

	/* append the user input string to the signal */
    	if (!dbus_message_append_args(message, DBUS_TYPE_STRING, &safe_input1, DBUS_TYPE_INVALID))
    	{
        	g_warning("Failed to append arguments to first D-Bus message.");
        	free(safe_input1);
        	dbus_message_unref(message);
        	return TRUE;
    	}

    	/* Send first message */
    	if (!dbus_connection_send(bus, message, NULL))
    	{
        	g_warning("Failed to send first D-Bus message.");
    	}

	/* to send all the pending messages */
    	dbus_connection_flush(bus);

	/* 
	 * decreasing the reference count of the message
	 * when the message count reaches 0, the message is freed
	 * this is necessasory to avoid memory leaks
	 */
    	dbus_message_unref(message);

    	/* Create second D-Bus signal */
    	DBusMessage *message1 = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                                    "com.burtonini.dbus.Signal1",
                                                    "Ping");
    	if (!message1)
    	{
        	g_warning("Failed to create second D-Bus signal message.");
        	free(safe_input2);
        	return TRUE;
    	}

    	if (!dbus_message_append_args(message1, DBUS_TYPE_STRING, &safe_input2, DBUS_TYPE_INVALID))
    	{
        	g_warning("Failed to append arguments to second D-Bus message.");
        	free(safe_input2);
        	dbus_message_unref(message1);
        	return TRUE;
    	}

    	/* Send second message */
    	if (!dbus_connection_send(bus, message1, NULL))
    	{
        	g_warning("Failed to send second D-Bus message.");
    	}
    	dbus_connection_flush(bus);
    	dbus_message_unref(message1);

    	printf("Sent: %s\n", safe_input1);
    	free(safe_input1);
	printf("Sent: %s\n", safe_input2);
	free(safe_input2);
    	return TRUE;
}

/* start of main function */
int main()
{
    	GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    	if (!loop)
    	{
        	g_warning("Failed to create GMainLoop");
        	return 1;
    	}

    	DBusError error;

	/* initialises a dbus error structure for error handling */
    	dbus_error_init(&error);

	/* connects to the dbus session bus */
    	DBusConnection *bus = dbus_bus_get(DBUS_BUS_SESSION, &error);

	/* if the connection to the bus fails, it will log an error and exit */
    	if (!bus)
    	{
        	g_warning("Failed to connect to the D-BUS daemon: %s", error.message);

		/* free the error message space */
        	dbus_error_free(&error);
        	return 1;
    	}

	/* this allows the application to handle dbus messages asynchroniously */
    	dbus_connection_setup_with_g_main(bus, NULL);

	/* call the send ping function every 1 second */
    	g_timeout_add(1000, (GSourceFunc)send_ping, bus);

	/* starts the main loop which will listen for the messages */
	/* this loop will run infinitely until stopped by user */
    	g_main_loop_run(loop);

	/* frees the main loop resources as the program ends */
    	g_main_loop_unref(loop);
    	return 0;
}

