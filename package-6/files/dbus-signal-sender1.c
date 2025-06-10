#include <glib.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static gboolean send_ping(DBusConnection *bus)
{
    	if (!bus)
    	{
        	g_warning("Invalid DBusConnection (bus is NULL)");
        	return FALSE;
    	}

    	char input[256];

    	/* Get user input */
    	printf("Enter message to send: ");
    	if (!fgets(input, sizeof(input), stdin))
    	{
        	g_warning("Error reading input.");
        	return TRUE;
    	}

    	/* Remove newline */
    	input[strcspn(input, "\n")] = 0;

    	/* Ensure input is not empty */
    	if (strlen(input) == 0)
    	{
        	g_warning("Empty input, not sending message.");
        	return TRUE;
    	}

    	/* Allocate safe copy of input */
    	char *safe_input = strdup(input);
    	if (!safe_input)
    	{
        	g_warning("Memory allocation failed.");
        	return TRUE;
    	}

    	/* Create first D-Bus signal */
    	DBusMessage *message = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                                   "com.burtonini.dbus.Signal",
                                                   "Ping");
    	if (!message)
    	{
        	g_warning("Failed to create first D-Bus signal message.");
        	free(safe_input);
        	return TRUE;
    	}

    	if (!dbus_message_append_args(message, DBUS_TYPE_STRING, &safe_input, DBUS_TYPE_INVALID))
    	{
        	g_warning("Failed to append arguments to first D-Bus message.");
        	free(safe_input);
        	dbus_message_unref(message);
        	return TRUE;
    	}

    	/* Send first message */
    	if (!dbus_connection_send(bus, message, NULL))
    	{
        	g_warning("Failed to send first D-Bus message.");
    	}
    	dbus_connection_flush(bus);
    	dbus_message_unref(message);

    	/* Create second D-Bus signal */
    	DBusMessage *message1 = dbus_message_new_signal("/com/burtonini/dbus/ping",
                                                    "com.burtonini.dbus.Signal1",
                                                    "Ping");
    	if (!message1)
    	{
        	g_warning("Failed to create second D-Bus signal message.");
        	free(safe_input);
        	return TRUE;
    	}

    	if (!dbus_message_append_args(message1, DBUS_TYPE_STRING, &safe_input, DBUS_TYPE_INVALID))
    	{
        	g_warning("Failed to append arguments to second D-Bus message.");
        	free(safe_input);
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

    	printf("Sent: %s\n", safe_input);
    	free(safe_input);
    	return TRUE;
}

int main(int argc, char **argv)
{
    	GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    	if (!loop)
    	{
        	g_warning("Failed to create GMainLoop");
        	return 1;
    	}

    	DBusError error;
    	dbus_error_init(&error);
    	DBusConnection *bus = dbus_bus_get(DBUS_BUS_SESSION, &error);
    	if (!bus)
    	{
        	g_warning("Failed to connect to the D-BUS daemon: %s", error.message);
        	dbus_error_free(&error);
        	return 1;
    	}

    	dbus_connection_setup_with_g_main(bus, NULL);

    	g_timeout_add(1000, (GSourceFunc)send_ping, bus);
    	g_main_loop_run(loop);

    	g_main_loop_unref(loop);
    	return 0;
}

