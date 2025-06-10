#include <glib.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to send a message */
static gboolean send_ping(DBusConnection *bus)
{
	if (!bus)
	{
		g_warning("Invalid DBusConnection (bus is NULL)");
		return FALSE;
	}

	char input1[256] = {0};
	char input2[256] = {0};

	printf("Enter message to send for interface 1: ");
	if (!fgets(input1, sizeof(input1), stdin))
	{
		g_warning("Error reading input.");
		return TRUE;
	}

	printf("Enter message to send for interface 2: ");
	if (!fgets(input2, sizeof(input2), stdin))
	{
		g_warning("Error reading input.");
		return TRUE;
	}

	/* Remove newline characters */
	input1[strcspn(input1, "\n")] = 0;
	input2[strcspn(input2, "\n")] = 0;

	/* Ensure inputs are not empty */
	if (strlen(input1) == 0 || strlen(input2) == 0)
	{
		g_warning("Empty input, not sending message.");
		return TRUE;
	}

	/* Allocate safe copy of input */
	char *safe_input1 = g_strdup(input1);
	char *safe_input2 = g_strdup(input2);

	if (!safe_input1 || !safe_input2)
	{
		g_warning("Memory allocation failed.");
		g_free(safe_input1);
		g_free(safe_input2);
		return TRUE;
	}

	/* Create first D-Bus signal */
	/*	DBusMessage *message = dbus_message_new_signal("/com/burtonini/dbus/ping",
		"com.burtonini.dbus.Signal",
		"Ping");*/
	DBusMessage *message = dbus_message_new_signal("/aditya/interface1","aditya.interface1","Ping");
	if (!message)
	{
		g_warning("Failed to create first D-Bus signal message.");
		g_free(safe_input1);
		g_free(safe_input2);
		return TRUE;
	}

	/* Append argument safely */
	if (!dbus_message_append_args(message, DBUS_TYPE_STRING, &safe_input1, DBUS_TYPE_INVALID))
	{
		g_warning("Failed to append arguments to first D-Bus message.");
		dbus_message_unref(message);
		g_free(safe_input1);
		g_free(safe_input2);
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
	/*DBusMessage *message1 = dbus_message_new_signal("/com/burtonini/dbus/ping",
	  "com.burtonini.dbus.Signal1",
	  "Ping");*/
	DBusMessage *message1 = dbus_message_new_signal("/aditya/interface2","aditya.interface2","Ping");
	if (!message1)
	{
		g_warning("Failed to create second D-Bus signal message.");
		g_free(safe_input2);
		return TRUE;
	}

	if (!dbus_message_append_args(message1, DBUS_TYPE_STRING, &safe_input2, DBUS_TYPE_INVALID))
	{
		g_warning("Failed to append arguments to second D-Bus message.");
		dbus_message_unref(message1);
		g_free(safe_input2);
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
	printf("Sent: %s\n", safe_input2);

	/* Free memory */
	g_free(safe_input1);
	g_free(safe_input2);
	return TRUE;
}

static gboolean call_set_volume(DBusConnection *bus)
{
	if (!bus)
	{
		g_warning("Invalid DBusConnection (bus is NULL)");
		return FALSE;
	}

	/*int volume_level;
	printf("Enter volume level (0-100): ");
	if (scanf("%d", &volume_level) != 1 && getchar() != '\n' || volume_level < 0 || volume_level > 100)
	{
		g_warning("Invalid volume level.");
		return TRUE;
	}*/

	char input[16];
	int volume_level;

	printf("Enter volume level (0-100): ");
	if (!fgets(input, sizeof(input), stdin)) {
    		g_warning("Failed to read input.");
    		return TRUE;
	}

	char *endptr;
	volume_level = strtol(input, &endptr, 10);
	if (endptr == input || *endptr != '\n' && *endptr != '\0' || volume_level < 0 || volume_level > 100) {
    		g_warning("Invalid volume level.");
    		return TRUE;
	}


	DBusMessage *msg;
	DBusMessageIter args;
	DBusPendingCall *pending;
	DBusError err;

	dbus_error_init(&err);

	// Create a new method call and check for errors
	msg = dbus_message_new_method_call(
			"aditya.volumeclient",      // target service name
			"/aditya/volumeobject",     // object to call on
			"aditya.volumeinterface",   // interface to call on
			"SetVolume");               // method name

	if (!msg)
	{
		g_warning("Message Null");
		return TRUE;
	}

	// Append arguments
	dbus_message_iter_init_append(msg, &args);
	if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_INT32, &volume_level))
	{
		g_warning("Out Of Memory!");
		dbus_message_unref(msg);
		return TRUE;
	}

	// Send message and wait for a reply
	if (!dbus_connection_send_with_reply(bus, msg, &pending, -1))
	{
		g_warning("Out Of Memory!");
		dbus_message_unref(msg);
		return TRUE;
	}
	if (!pending)
	{
		g_warning("Pending call NULL");
		dbus_message_unref(msg);
		return TRUE;
	}
	dbus_connection_flush(bus);
	dbus_message_unref(msg);

	dbus_pending_call_block(pending);

	// Get the reply
	DBusMessage *reply = dbus_pending_call_steal_reply(pending);
	if (!reply)
	{
		g_warning("Reply Null");
		dbus_pending_call_unref(pending);
		return TRUE;
	}

	dbus_pending_call_unref(pending);

	// Optionally read a reply argument
	dbus_message_iter_init(reply, &args);
	int success = 0;
	if (DBUS_TYPE_INT32 == dbus_message_iter_get_arg_type(&args))
	{
		dbus_message_iter_get_basic(&args, &success);
		printf("SetVolume returned: %d\n", success);
	}

	dbus_message_unref(reply);
	return TRUE;
}


/* Main function */
int main()
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

	//dbus_connection_setup_with_g_main(bus, NULL);

	/* Call send_message function every 5 seconds */
	g_timeout_add(5000, (GSourceFunc)send_ping, bus);
	g_timeout_add(10000, (GSourceFunc)call_set_volume, bus);

	g_main_loop_run(loop);
	g_main_loop_unref(loop);

	return 0;
}

